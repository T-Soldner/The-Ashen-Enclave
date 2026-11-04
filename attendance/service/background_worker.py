"""Windows scheduled-task entry point. No installers or network downloads."""
import argparse
import base64
import contextlib
import io
import json
import logging
from logging.handlers import RotatingFileHandler
import os
from pathlib import Path
import subprocess
import sys


class LogStream(io.TextIOBase):
    def __init__(self, logger):
        self.logger = logger
        self.pending = ""

    def write(self, value):
        self.pending += value
        while "\n" in self.pending:
            line, self.pending = self.pending.split("\n", 1)
            if line.strip():
                token = os.environ.get("TAE_DISCORD_TOKEN", "")
                self.logger.info(line.replace(token, "[REDACTED]") if token else line)
        return len(value)

    def flush(self):
        if self.pending:
            self.write("\n")


def load_token(path):
    # DPAPI decryption occurs in a short hidden child; token travels only in a pipe.
    literal = str(path).replace("'", "''")
    script = "$ErrorActionPreference='Stop'; $s=Import-Clixml -LiteralPath '" + literal + "'; [Console]::Write(([System.Net.NetworkCredential]::new('', $s)).Password)"
    encoded = base64.b64encode(script.encode("utf-16-le")).decode("ascii")
    powershell = Path(os.environ["SystemRoot"])/"System32/WindowsPowerShell/v1.0/powershell.exe"
    environment = dict(os.environ)
    environment["PSModulePath"] = str(powershell.parent/"Modules")
    result = subprocess.run([str(powershell), "-NoProfile", "-NonInteractive", "-EncodedCommand", encoded],
                            capture_output=True, timeout=30, creationflags=subprocess.CREATE_NO_WINDOW,env=environment)
    if result.returncode:
        raise ValueError("Could not decrypt bot token. Use the same Windows account and server that ran setup.")
    from discord_bot import validate_token
    return validate_token(result.stdout.decode("utf-8-sig").strip())


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--config",type=Path,required=True)
    parser.add_argument("--component",choices=("Bot","Watcher"),required=True)
    args = parser.parse_args()
    if os.name != "nt":
        parser.error("Background tasks require Windows.")
    config = json.loads(args.config.read_text(encoding="utf-8-sig"))
    root = Path(config["root"])
    logs = root/"logs"
    logs.mkdir(exist_ok=True)
    import msvcrt
    lock = (logs/(args.component.lower()+".lock")).open("a+b")
    lock.seek(0)
    if not lock.read(1):
        lock.write(b"0")
        lock.flush()
    lock.seek(0)
    try:
        msvcrt.locking(lock.fileno(),msvcrt.LK_NBLCK,1)
    except OSError:
        lock.close()
        return
    logger = logging.getLogger("tae.background."+args.component)
    logger.setLevel(logging.INFO)
    handler = RotatingFileHandler(logs/(args.component.lower()+".log"),maxBytes=5*1024*1024,backupCount=5,encoding="utf-8")
    handler.setFormatter(logging.Formatter("%(asctime)s %(message)s"))
    logger.addHandler(handler)
    output = LogStream(logger)
    with contextlib.redirect_stdout(output),contextlib.redirect_stderr(output):
        try:
            live = "--enable-live-workflow" in config.get("bot_args",[])
            logger.info("Starting %s; operation workflow configured %s.",args.component,"LIVE" if live else "disabled")
            if args.component == "Bot":
                os.environ["TAE_DISCORD_TOKEN"] = load_token(config["token_file"])
                from discord_bot import main as run
                sys.argv = ["discord_bot.py",*config["bot_args"]]
            else:
                from collector import main as run
                sys.argv = ["collector.py","--db",str(root/"data/attendance.sqlite3"),
                            "watch","--rpt-dir",config["rpt_dir"]]
            run()
        except SystemExit:
            raise
        except Exception:
            # Avoid logging library tracebacks that might include credentials.
            logger.error("Worker failed. Check configuration, file access, connection and credentials; restart scheduled by Windows.")
            raise SystemExit(1)
        finally:
            output.flush()
            os.environ.pop("TAE_DISCORD_TOKEN",None)
            lock.close()
            handler.close()


if __name__ == "__main__":
    main()
