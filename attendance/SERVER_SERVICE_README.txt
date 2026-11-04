TAE ATTENDANCE - SERVER SERVICE FILES

This is the runtime-only deployment bundle, NOT the development/test folder.
Built locally by attendance\Build-ServiceBundle.ps1. Do not edit generated copies;
edit/test the service sources and rebuild this bundle before deploying updates.

SERVER DESTINATION
D:\TAEAttendance\service

Copy this folder's CONTENTS into that destination, not the finalized folder itself.
Stop the bot and watcher before replacing program files. Back up SQLite first.
Keep these existing server folders and all their contents:
  D:\TAEAttendance\data
  D:\TAEAttendance\secrets
  D:\TAEAttendance\backups
  D:\TAEAttendance\@TAEAttendance

Do not place databases, credentials, tokens, backups or RPTs in this service folder.
MANIFEST.sha256 records the bundled files' SHA-256 hashes. README and requirements
files are deployment aids, not background programs.

Programs:
  collector.py         RPT watcher, database setup/status/backup and local reports
  discord_bot.py       Discord bot (live promotions/Sheet writes OFF by default)
  sheets_read_test.py  Read-only Google connection diagnostic; also a shared helper

Other .py files are required runtime imports. Keep ALL of them, including
sheets_read_test.py despite its diagnostic name. Do not remove requirements files.
No test_*.py, __pycache__, development docs, keys, databases or PBOs belong here.

Packages were already installed on this server. Do not reinstall for a normal
code update. requirements-server.txt records all dependencies for future recovery;
using pip install will download packages and requires approval.

Use your existing startup commands/approved flags after copying. Copying this
bundle does not turn on live processing, post panels, initialize Sheet tabs or
change permissions. No Windows service/startup task is installed automatically.

Full setup instructions remain in the local attendance development folder:
  DISCORD_SETUP.md
  SHEETS_AND_APPLICATIONS.md
  CLANS_AND_TRAINING.md

PREPARED CLAN/TRAINING FEATURE (NOT ENABLED BY COPYING FILES)
New commands: /tae clan-apply, clan-pending, clan-review, training edit/status,
roster-sync and personnel-check. All actual writes require --enable-clan-training.
Admins can use training legacy-import to preview/import old colored Xs as records
only, and training legacy-map to explicitly resolve abbreviated identities. No
Discord roles or historical Sheet cells change during import. Review before any
confirmation. Primary role reconciliation is a separate, explicit training Save.
training legacy-auto-map proposes unresolved name matches in one reviewed batch;
confirming it saves identity mappings ONLY, not qualifications or roles.
Keep this flag OFF until the read-only personnel-check and deployment review pass.
First roster-sync writes require the same trainer's fresh, unchanged preview.
Legacy Specializations stays intact; new records use a separate Training Tracker.
Keep existing live attendance/auto-from flags unchanged. Full rollout instructions
are in attendance\CLANS_AND_TRAINING.md in the development repository.

BACKGROUND RUNNING (WINDOWS TASK SCHEDULER)
Run setup ON THE SERVER, as the same Windows account used for Python and Google
access. This account needs a Windows password, not just a PIN. Do not run this
installer on the development PC. No software download or service manager needed.

1. Back up SQLite. Stop any foreground bot and watcher with Ctrl+C.
2. Open PowerShell as administrator on the server (same Windows account).
3. Run:
   powershell -NoProfile -ExecutionPolicy Bypass -File D:\TAEAttendance\service\Install-Background.ps1
   Add -EnableAutoOnboarding only if you want to preserve that enabled feature.
4. Enter the server Windows password and Discord bot token in the hidden prompts.
   Never send either in chat. A PIN is not a Windows account password.
5. After setup succeeds, start:
   powershell -NoProfile -ExecutionPolicy Bypass -File D:\TAEAttendance\service\Manage-Background.ps1 -Action Start
6. Check the bot is online and run /tae-admin health. Check recent log output:
   Get-Content D:\TAEAttendance\logs\bot.log -Tail 15
   Get-Content D:\TAEAttendance\logs\watcher.log -Tail 15

Status: Manage-Background.ps1 -Action Status
Stop for updates: Manage-Background.ps1 -Action Stop (disables automatic restart).
Start again: Manage-Background.ps1 -Action Start (re-enables automatic startup).
Do not also run foreground copies while background workers are enabled.

Tasks: TAE Attendance Bot and TAE Attendance Watcher, run with limited privileges
under the installing account whether signed in or not. Setup initially leaves
them disabled. Start enables boot startup, failure retries and a five-minute
recovery trigger. A running worker is not restarted by that trigger. Logs rotate
at 5 MB, with five older files per worker. Task Running means process running,
not proof of Discord connectivity or successful RPT ingestion: verify health/logs.
Operation finalization and promotions remain disabled. This runs the existing
programs in the background; it does not enable automatic attendance crediting.

Token: secrets\discord-token.xml, encrypted by Windows DPAPI for this Windows user
on THIS server only. secrets\background.json contains paths and approved flags,
never the token/password. Setup restricts the secrets directory to this account,
SYSTEM and local administrators. Those privileged accounts can still access it;
DPAPI does not protect against a compromised account or administrator.
Task Scheduler stores the Windows logon credential, not our configuration files.
After changing the Windows password, update BOTH tasks' saved credentials in Task
Scheduler. A different user/server requires saving the bot token again. Keep the
Google credential and database outside service as before. Do not commit secrets.
If registration fails, inspect preserved config/token and credentials before
retrying the installer with -ResumeSetup. This reuses the encrypted token and
saved flags, asks only for the Windows password, and displays the underlying
Windows Task Scheduler error. Do not combine -ResumeSetup with -EnableAutoOnboarding.
Never delete data, tokens or Google credentials as a troubleshooting step.

AUTOMATIC DATABASE BACKUPS (optional separate task)
Copy backup_database.py and Install-Backups.ps1 into the server service folder.
In Administrator Windows PowerShell, as the same user as the existing tasks:
  powershell -NoProfile -ExecutionPolicy Bypass -File D:\TAEAttendance\service\Install-Backups.ps1
The installer verifies an initial live backup, then asks for the Windows PASSWORD
(not PIN). No bot token, Google credential, package install or bot restart needed.
It adds TAE Attendance Backup without changing existing bot/watcher settings.
Schedule: Saturdays at 3 AM SERVER LOCAL TIME, with missed-run recovery; no
additional startup backup. This uses the server's time zone, not Eastern time.
If the backup task is already installed, update only its schedule without a
password prompt (existing credentials/action/settings are preserved):
  powershell -NoProfile -ExecutionPolicy Bypass -File D:\TAEAttendance\service\Install-Backups.ps1 -UpdateSchedule
The task uses limited privileges, prevents overlapping scheduled runs and retries
failures three times at five-minute intervals. Each run has a ten-minute limit.
Snapshots go in D:\TAEAttendance\backups, with UTC in automatic filenames only.
SQLite's online backup API includes committed WAL data while the bot is running.
A snapshot must pass SQLite quick_check before publishing or rotating old copies.
Only the newest 30 auto-<timestamp>.sqlite3 snapshots are retained; manually named
backups are untouched. Logs rotate in D:\TAEAttendance\logs\backup.log.
These contain member IDs/training/attendance data. Keep private; local snapshots
do NOT protect against loss of the server drive. No files are uploaded anywhere.
Check installation:
  Get-ScheduledTask -TaskName 'TAE Attendance Backup'
  Get-Content D:\TAEAttendance\logs\backup.log -Tail 5
Manual run of the scheduled task:
  Start-ScheduledTask -TaskName 'TAE Attendance Backup'
Manage-Background.ps1 continues to control ONLY the bot and watcher. Backups run
independently, including while those workers are stopped for maintenance.
If the Windows password changes, update the backup task credential too.
For restoration, stop bot/watcher first and preserve the current database plus
any WAL/SHM files. Review the chosen snapshot before replacement; never restore
over a running database. A live restoration/reboot test has not been performed.

AUTOMATIC ACCOUNT-LINK APPROVAL QUEUE
The optional --enable-link-queue flag sends unknown Steam identities and pending
registrations to the configured staff submitted-applications channel once/minute.
Only administrators can use Review / choose member, Preview link and Approve.
Existing member totals/rows are preserved; the row is automatically bound and
attendance/history/clan display refreshed. No routine pending/sheet-sync needed.
Names only suggest an identity; staff must verify the actual Steam/Discord pairing.
If preview proposes a new zero-total row for an existing member, stop and enter
their existing Operations Tracker Master row number. Never approve a duplicate.
Names require the updated SERVER-ONLY TAEAttendance addon and a server restart.
The normal TAE mod is not the attendance addon. Existing addon versions continue
logging attendance; name detection requires the newer PBO. No new packages needed.
Preserve existing background.json flags; add --enable-link-queue to bot_args.
Requires roster scan/member intent, Sheet writes/credentials and a staff-only
application-review channel. Do not put the queue in public bot-spam.
Link conflicts and sending/uncertain receipts stop for review, not blind retries.
Health includes pending/uncertain queue counts. Tests with real Discord/Arma/Sheets
are still needed after deployment. See attendance/AUTOMATIC_LINK_QUEUE.md in source
for the full update and approval procedure. This flag is not enabled by copying.

CURRENT COMMAND LAYOUT (replaces paths in older setup notes)
Members: /tae help, status, register, clan-apply.
Staff: /tae-admin help, health, member, transfer, training edit, training status.
Transfer requires Administrator, a member, a destination and a reason. Group
changes clear Clan Leader/2IC roles and refresh the roster. Clan limits apply.
Attendance, ranks and training are preserved. No automatic inactivity removals.
Recovery: /tae-maintenance, with links pending/approve/reject, sheets
bind/preview/init/sync and training legacy-map/legacy-auto-map/legacy-import.
All other former admin recovery commands live directly under /tae-maintenance,
including roster-sync, roster-check, personnel-check, clan-review, clan-pending,
application-panel/review/pending/role-check, LOA and operation recovery commands.
Existing permissions and feature flags are preserved. Trainers can still use
training and roster-sync without Administrator. Legacy duplicate aliases removed.
Routine application/account decisions use the existing buttons.
Restart the bot after copying to synchronize the layout; refresh Discord if old
paths remain visible. No database reset or credential changes required.
See attendance/COMMANDS.md in source for the complete current command guide.

AUTOMATIC ABSENCE ALERTS
With live workflow AND --allow-absence-posts, finalized operation processing posts
an informational alert to the configured bot-spam channel after four consecutive
confirmed unexcused misses. Main and fun ops count separately. Attended/excused/
review/missing records break the streak; current accepted/pending LOAs hold alerts.
One alert per continuing streak, shared receipts with manual absence-post.
Uncertain sends are not resent automatically. No role/clan/rank removals occur.
Add --allow-absence-posts to existing background.json bot_args to opt in, preserving
all other flags. Copying updated files alone does not enable this flag.

REBOOT RECOVERY CHECK (no password needed for existing installed tasks)
Only reboot when the Arma server is idle and the owner approves. After reboot,
wait about two minutes. Do NOT manually start the workers before checking:
  Get-ScheduledTask -TaskName 'TAE Attendance*' | Select-Object TaskName,State
  Get-Content D:\TAEAttendance\logs\bot.log -Tail 10
  Get-Content D:\TAEAttendance\logs\watcher.log -Tail 10
Then /tae-admin health in Discord. Verify a NEW startup/connected entry and watcher
startup after the reboot, not merely old healthy logs. Task Running alone does
not prove connectivity. Existing Bot/Watcher tasks can be tested now. Installing
the NEW weekly Backup task remains pending until the Windows password is available.
