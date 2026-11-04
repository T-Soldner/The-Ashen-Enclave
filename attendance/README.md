# TAE attendance - initial dry-run collector

## Server deployment folder

Use `service\finalized` for copying files to the server, not the development
service folder. Generate/refresh it with `attendance\Build-ServiceBundle.ps1`.
The explicit allowlist includes runtime modules, requirements and a server README,
but excludes tests, credentials, databases, logs and addon files. It is generated
and Git-ignored; source files and tests remain in service for development.
Copy its CONTENTS into `D:\TAEAttendance\service`, without nesting finalized there.
Stop bot/watcher and back up the separate database before replacing runtime files.
Rebuild the bundle after every source change; generated copies do not auto-update.

Separate server-only addon, excluded from the normal TAE build. No downloads,
credentials, Discord changes or Google Sheet writes are performed.

## Implemented

- UTC join/leave events and a compact presence snapshot every 60 seconds.
- Saturdays 14:00-17:00 and 19:00-22:00 America/New_York, current US DST rules.
- Connected-user snapshots include the lobby while a mission is running.
- Headless clients/invalid Steam IDs excluded; identities stored as text.
- Local SQLite importer, durable offsets, duplicate protection and backups.
- Manual logging: execute `TAEAttendance_manual = true;` on the server;
  false returns to the schedule. Resets at mission restart. No public remote API.

## Local linking and attendance previews

The importer now adds a `tracking_since` member field automatically. Keep the
existing database; do not delete it or rerun the test into a replacement database.
Copy BOTH `collector.py` and `attendance.py` to `D:\TAEAttendance\service` while
the watcher is stopped. This update does not require rebuilding the addon.

Staff link identities locally using numeric IDs, not Discord names. Example only:

```powershell
python D:\TAEAttendance\service\collector.py --db D:\TAEAttendance\data\attendance.sqlite3 link-member --steam-id 76561198000000001 --discord-id 123456789012345678 --name "Example Member" --since 2026-11-07 --baseline 20
python D:\TAEAttendance\service\collector.py --db D:\TAEAttendance\data\attendance.sqlite3 members
python D:\TAEAttendance\service\collector.py --db D:\TAEAttendance\data\attendance.sqlite3 report --from 2026-11-07 --through 2026-11-07
```

Replace the example IDs/name/total. `--since` is an Eastern calendar date: baseline
must include only ops BEFORE that date, and automatic new credit starts on that
date. November 7 is the first Saturday after the November 2 manual test. Existing
links/baselines cannot be overwritten silently. No bulk Sheet import is done.
Reports are JSON printed in PowerShell, recomputed without changing totals.

- Saturday main/fun windows use Eastern DST, independent of the server timezone.
- Only linked active members can activate an operation. Empty windows and visitors
  alone do not create one. More than 300 confirmed seconds earns credit.
- Reconnect intervals combine within the same window. Overlaps do not double-count.
- Presence is bridged only up to 90 seconds, with consecutive event sequences.
  Missing records, long gaps and mission changes never manufacture connected time.
- A valid disconnect or END can confirm up to 90 seconds since last presence.
  A crash grants no assumed tail after the final confirmed event.
- Only windows that have finished can earn a preview credit. Earned evidence is
  retained despite interruption, but warnings prohibit treating the report as final.
- Baselines are shown separately from NEW credits in the requested report range;
  those range credits are NOT a lifetime total. Repeated reports do not add credits.
- Last-four results cover the last four qualifying, closed operations IN THE REPORT
  RANGE and since the member's tracking date. Use a sufficiently broad date range.
  Accepted LOAs show `excused` without adding ops; other nonattendance is
  `review-no-credit`, never an automatic absence or missed-op alert.
- Monday manual logging tests do not count automatically. Explicit manual-operation
  scheduling/credit is not implemented yet. V1 records do not identify manual vs
  automatic logging; manual logging inside a Saturday window is eligible normally.

The Eastern helper implements US rules since 2007 without an extra tzdata download;
if US DST law changes it must be updated. No external packages are required.

## Read-only Google Sheets connection test

`sheets_read_test.py` is separate from the watcher and never opens SQLite. It
requests only the Sheets read-only OAuth scope and uses GET requests for sheet
metadata and the first two tracker columns (maximum 1000 rows). It resolves the
tracker by tab ID before using its actual title. No Drive API is required.

On the server, `google-auth` and `requests` were installed with user approval.
Keep the service account's Sheet sharing permission at Viewer for this test.
Copy `sheets_read_test.py` to `D:\TAEAttendance\service` and run:

```powershell
python D:\TAEAttendance\service\sheets_read_test.py
```

Default key file: `D:\TAEAttendance\secrets\google-service-account.json`.
For a different filename use `--credentials "D:\TAEAttendance\secrets\ACTUAL-FILENAME.json"`.
Never paste keys into chat or commit them. This test prints the first ten named
rows plus any Edonn name match for manual comparison with baseline 39; it does
not infer identity links or import totals. Share only the needed output.
Authentication/network errors are summarized without printing credentials.
The remote server connection must be tested by the user; local mocked tests do
not establish access from the server or prove the key/API setup works.

## Discord pilot

See [DISCORD_SETUP.md](DISCORD_SETUP.md) for application creation, least-privilege
installation, staff-approved account claims and private preview commands. Bot code
is separate from the watcher; no bot has been connected by the developer. Installing
the SDK requires download approval. Do not share a bot token in chat or Git.

## Finalization and live workflow (off by default)

The operation ledger, guarded Discord role/nickname updates, successful-promotion
announcements and attendance recaps are implemented. They remain disabled unless
the operator explicitly supplies `--enable-live-workflow`. Read DISCORD_SETUP.md
before enabling; unchanged start commands remain preview-only. Google Sheet writes
are still disabled. Local simulated tests are not a live deployment confirmation.

## Remaining work

Explicit manual operations, verified self-service account linking,
bulk initial totals import, unattended absence posting, ledger correction tooling
remain next-stage work. Google exports and applications now exist behind explicit
configuration; see SHEETS_AND_APPLICATIONS.md for read-only binding first, approved
new last-four tab, least-privilege write activation and the Apply button workflow.
The Discord pilot defaults to
staff-approved links, private reports and optional LOA listening. Real rank changes
and operation posts are separately opt-in. See DISCORD_SETUP.md for Message Content Intent and the
LOA channel option; ambiguous posts remain pending for staff review.
Linking here is a trusted
staff entry, not proof of account ownership. No Windows service or backup task yet.
Never infer uninterrupted attendance across mission changes or missing records.
Snapshots can drift under load; only events flushed to disk survive a crash.
Collector requires a running mission, not a server sitting at mission selection.

## Build and server setup

Requires existing Arma 3 Tools. Use a fresh output directory per build:

```powershell
& 'D:\GitHub\The-Ashen-Enclave\attendance\Build-Attendance.ps1' -OutputMod 'D:\TAEAttendanceTest\@TAEAttendance'
```

Copy the resulting @TAEAttendance folder to the server. Append its absolute path
to the EXISTING `-serverMod` list, separated with a semicolon; preserve other mods.
Clients do not install it. Restart the server and start a mission. Keep RPT logging
enabled (no `-noLogs`) and the Windows clock synchronized. Unsigned server test build.

## SQLite setup on the Windows server

SQLite is a database FILE, not a database server. The importer uses Python's
standard-library sqlite3 module. No pip packages are required for this stage.
If Python is not installed, request approval before downloading/installing it.

Copy `attendance\service` to `D:\TAEAttendance\service`. Keep data outside Git,
Workshop, network and synchronized folders; restrict access to server staff and
the eventual service account. Run:

```powershell
python --version
python -c "import sqlite3; print(sqlite3.sqlite_version)"
python D:\TAEAttendance\service\collector.py --db D:\TAEAttendance\data\attendance.sqlite3 init
python D:\TAEAttendance\service\collector.py --db D:\TAEAttendance\data\attendance.sqlite3 watch --rpt-dir 'D:\ArmA3\A3Master'
```

Replace the RPT directory with the folder containing this server instance's RPTs.
Use one directory per instance. Ctrl+C stops the watcher; the same command resumes.
The init command creates all tables. Watch imports existing RPTs once and reads
only appended bytes thereafter; RPTs are never modified. Keep logs until imported
and backed up. Malformed attendance entries are preserved in `rejected_events`
with a warning and file/byte offset; importing valid records continues. Rejected
records require review before future attendance/absence decisions are finalized.
The status command reports how many need review. Existing databases gain the
new table automatically; do not delete or recreate the database to update.

```powershell
python D:\TAEAttendance\service\collector.py --db D:\TAEAttendance\data\attendance.sqlite3 status
python D:\TAEAttendance\service\collector.py --db D:\TAEAttendance\data\attendance.sqlite3 backup --output D:\TAEAttendance\backups\attendance-test.sqlite3
```

Use the backup command, not a copy of the active database file alone: WAL sidecars
may contain committed data. Arrange scheduled backups to separate storage before
production. Do not delete WAL/SHM files while the importer is running.

## Test

```powershell
Set-Location 'D:\GitHub\The-Ashen-Enclave\attendance\service'
py -3 -B -m unittest -v
```

In a dedicated-server mission enable manual logging, connect/disconnect a player,
wait for snapshots, and look for `TAE_ATTENDANCE_V1|` in the RPT. Import it twice
and confirm the event count does not double. Test mission restart and interrupted
server recovery before enabling any future integrations.
