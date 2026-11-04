import logging
import base64
import os
from pathlib import Path
import subprocess
import tempfile
import unittest
from unittest.mock import patch

from background_worker import LogStream, load_token


class BackgroundTests(unittest.TestCase):
    def test_log_stream_redacts_token_and_buffers_lines(self):
        logger = logging.getLogger("background-test")
        output = LogStream(logger)
        with patch.dict(os.environ,{"TAE_DISCORD_TOKEN":"secret.test"}):
            with self.assertLogs(logger,level="INFO") as captured:
                output.write("partial ")
                output.write("secret.test\nlast line")
                output.flush()
        self.assertEqual(len(captured.output),2)
        self.assertNotIn("secret.test","\n".join(captured.output))
        self.assertIn("[REDACTED]",captured.output[0])

    @unittest.skipUnless(os.name == "nt","Windows DPAPI test")
    def test_dpapi_roundtrip_with_dummy_token(self):
        with tempfile.TemporaryDirectory() as root:
            path = Path(root)/"dummy token.xml"
            powershell = Path(os.environ["SystemRoot"])/"System32/WindowsPowerShell/v1.0/powershell.exe"
            script = "$ErrorActionPreference='Stop'; $s=ConvertTo-SecureString 'dummy.test_token' -AsPlainText -Force; $s | Export-Clixml -LiteralPath '" + str(path).replace("'","''") + "'"
            encoded = base64.b64encode(script.encode("utf-16-le")).decode("ascii")
            environment = dict(os.environ)
            environment["PSModulePath"] = str(powershell.parent/"Modules")
            result = subprocess.run([str(powershell),"-NoProfile","-NonInteractive","-EncodedCommand",encoded],
                                    capture_output=True,timeout=30,creationflags=subprocess.CREATE_NO_WINDOW,env=environment)
            self.assertEqual(result.returncode,0,result.stderr.decode("utf-8",errors="replace"))
            self.assertTrue(path.is_file())
            self.assertEqual(load_token(path),"dummy.test_token")
