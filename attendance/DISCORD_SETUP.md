# Discord attendance pilot

This version defaults to slash commands, pending Steam ID submissions, staff approval,
private attendance previews and optional LOA listening. Real Discord role/nickname
updates and operation posts require explicit live-mode flags (below). Google Sheet
writes remain disabled. Existing links/baselines remain in the same SQLite database.

## Prepare the server

Back up the database using the collector's backup command. Stop the watcher briefly
while copying these files into `D:\TAEAttendance\service`, keeping the database:

- collector.py
- attendance.py
- discord_store.py
- discord_bot.py
- requirements-discord.txt
- loa.py (required by the updated discord_store.py and discord_bot.py)

Restart the watcher normally. The bot runs separately and shares SQLite in WAL mode;
it does not import RPTs. Staff approvals and pending submissions update only local
tables. New bot tables are added automatically; no database recreation is needed.

After explicit download approval, install the Discord SDK into the server's Python:

```powershell
python -m pip install -r D:\TAEAttendance\service\requirements-discord.txt
```

No voice extras are needed. Package/runtime compatibility must be checked on the
server; no Discord SDK was downloaded into the development environment for this
initial build. Core workflow tests are offline and do not prove live Discord access.

## Create the Discord application

1. Open https://discord.com/developers/applications and choose New Application.
2. Name it TAE Attendance. Confirm its Bot page has a bot user.
3. Keep Presence, Server Members, and Message Content privileged intents OFF.
4. In Installation, use Guild Install with `bot` and `applications.commands` scopes.
   Use only View Channels and Send Messages for the initial pilot. Do NOT grant
   Administrator, Manage Roles, Manage Nicknames, or Read Message History yet.
5. Use the generated install link to add the bot to the TAE Discord server.
6. In your Discord client enable Settings > Advanced > Developer Mode; right-click
   the TAE server icon and Copy Server ID. This is NOT a channel ID or bot ID.
7. On the app's Bot page create/reset the token. Treat it as a password. Never paste
   it into chat, Git, command arguments, screenshots or the Google credential file.

The bot asks for the token in a hidden PowerShell prompt. Alternatively an operator
may securely supply `TAE_DISCORD_TOKEN` in the process environment. This version has
an unattended Task Scheduler setup described in SERVER_SERVICE_README.txt. It uses
Windows DPAPI for the same account/server; do not embed tokens in BATs.

## Validate and start

Replace YOUR_SERVER_ID with the numeric server ID (no angle brackets):

```powershell
python D:\TAEAttendance\service\discord_bot.py --guild-id YOUR_SERVER_ID --check
python D:\TAEAttendance\service\discord_bot.py --guild-id YOUR_SERVER_ID
```

`--check` opens the existing database/adds bot tables and builds command definitions
but makes NO Discord connection. It needs the installed SDK. Live startup registers
only this application's commands in the configured server, never globally. All
command responses are private (ephemeral); message content is not listened to.
Only one bot process should be running. Ctrl+C stops it; the RPT watcher can continue.

## Commands

- `/tae status`: view your own existing link and attendance preview.
- `/tae register steam:...`: submit a SteamID64 or numeric Steam profile URL.
  This is a CLAIM for staff verification, not proof of Steam account ownership.
  Vanity `/id/` links are rejected rather than resolved by downloading a profile.
- `/tae-admin pending`: list up to 20 pending claims privately, oldest first.
  Each entry shows the current server nickname, Discord username, Discord ID,
  SteamID64 and submission time. Names are read from Discord at request time, not
  used as identity keys. If a member left or lookup fails, IDs remain visible.
  Long lists are split into private replies rather than silently truncated.
- `/tae-admin approve member:... name:... since:2026-11-07 baseline:...`:
  approve only after verifying the submitted Steam ID belongs to that Discord user.
  The optional `joined` date is separate from the counting date. Example membership
  date 2026-03-10 does not change the baseline counting cutoff.
- `/tae-admin reject member:...`: reject an unverified/incorrect claim.
- `/tae-admin member member:...`: inspect one member's preview privately.
- `/tae-admin health`: event/rejection/pending counts and latest event time.

Staff commands enforce Discord Administrator permission at runtime, not merely a
visible role name. They leave Enclave Elder and all rank roles untouched. The bot
refuses other Discord servers and DMs. Members can only query their own account.
Existing account links cannot be overwritten with a request/approval. An audit table
records submissions, approvals and rejections. No account-ownership verification
code or Steam OpenID login is implemented yet; staff verification is required.

## First test

Edonn is already linked with baseline 39 and counting date 2026-11-07. Do NOT submit
a new registration for Edonn. Run `/tae status`, then an admin can run health.
Check a non-admin cannot use staff commands. Next test another consenting member's
claim/approval with verified identifiers. No real attendance is awarded or announced.

Read-only Sheet access was tested separately. Keep the Google service account at
Viewer; the Discord process never loads its credential. Automatic promotions and
absence alerts remain disabled until those workflows are implemented/tested.

## Promotion preview and announcement wording

Add `promotions.py` and replace `discord_bot.py` while the bot is stopped. Existing
start commands still work. No additional packages or Google permissions are needed.
`/tae-admin promotion-preview member:...` reads the member's current Discord
roles/nickname and local attendance, then privately previews changes. It does NOT
apply roles, rename anyone or send the announcement. No extra bot permissions yet.

Configured progression roles:

| Rank | Role ID | Prefix | Ops | Custom reward |
| --- | --- | --- | --- | --- |
| Foundling | 1477486340072276115 | FD | 0 | none |
| Mandalorian Recruit | 1477486340072276116 | MR | 1 main or fun op | none |
| Mandalorian Apprentice | 1477486340072276117 | MA | 5 | helmet |
| Mandalorian | 1477486340072276118 | MM | 10 | armor |
| Mandalorian Veteran | 1477486340072276119 | MV | 20 | backpack |

Individual promotion announcements belong in channel `1477486340625924209`, not
bot-spam. The exact template is:

```text
Congratulations to @user on promoting to <rank>.
```

For Apprentice/Mandalorian/Veteran append to that same paragraph:

```text
You can now submit a request for custom <helmet/armor/backpack> by creating a new post in [custom-assets](https://discord.com/channels/1477486339984199932/1483591827041812745).
```

The bot links to the custom-assets forum; it does not create a request post there.
The private preview never pings anyone. Future live announcements should allow
only the promoted user mention, never @everyone or role mentions. Public recap
posts in bot-spam may summarize successful promotions once that workflow exists.

Protected: Edonn user ID `248567812203872257`, WC/RM prefixes, War Chief/Rally
Master role names, the server owner and bots. Permanent protected role IDs:
War Chief `1477486340080799938`; Rally Master `1477486340080799946`.
HC was a typo, not an appointed rank. These two IDs need no startup arguments.
Additional future protected roles can use repeated `--protected-rank-role-id ROLE_ID`.
Only the five listed progression roles may change; all other roles stay untouched.
No demotions, no truncating names, no replacing unknown prefixes, and no automatic
role reconciliation when multiple progression roles are present.

Baseline-only eligibility is held for staff review instead of announcing a backlog
of historical promotions. New-op eligibility with missing evidence is held too.
Recruit requires one completed main OR fun operation, per the user's clarification.
Both types count toward every later threshold too. LOAs never add attended-op totals. Evidence-derived plans are
not final promotions. Actual edits/announcements now exist behind the explicitly
disabled-by-default workflow described below; preview commands never mutate roles.

## Finalization and real Discord workflow

Implemented and tested with a simulated Discord transport, NOT enabled or deployed
by the developer. No token, Google credential or live Discord API was used in tests.

### Update safely

1. Stop bot and watcher with Ctrl+C. Run the existing collector backup command to
   create a separate SQLite backup before copying files.
2. Copy updated `promotions.py`, `discord_store.py`, `discord_bot.py`, plus new
   `finalization.py` and `discord_transport.py` into `D:\TAEAttendance\service`.
   Keep attendance.py, absence.py, loa.py, collector.py and the existing database.
3. Restart watcher and bot using their SAME previous commands. Do not add live flags
   yet. New ledger/receipt tables are created automatically, preserving existing data.
4. `/tae-admin workflow-status` should say disabled with zero finalized ops.
   This migration is local; it does not grant permissions or change Discord roles.

### Read-only permission test

When ready, grant the bot role Manage Roles and Manage Nicknames, NOT Administrator.
Position its highest role above the five progression roles AND any members it must
rename. Leave protected WC/RM roles alone; their holders are never changed. Grant
View Channel and Send Messages in announcements (`1477486340625924209`) and bot-spam
(`1477486342169432118`), and Read Message History in LOA.

Run `/tae-admin live-check`. It only reads role hierarchy, permissions and
channels, even when live mode is disabled. Passing it does NOT turn live changes on.
The bot cannot rename the guild owner or equal/higher members; those are protected
or reported for review. It never needs forum-post permissions in custom-assets.

### Explicit live activation - do not use until reviewed

The following command enables real changes. It is documented for the final rollout,
not a replacement for the current preview startup command during testing:

```powershell
python D:\TAEAttendance\service\discord_bot.py --guild-id 1477486339984199932 --loa-channel-id 1477486341469241549 --bot-spam-channel-id 1477486342169432118 --enable-live-workflow --auto-from 2026-11-07
```

Without `--auto-from`, live mode enables only the staff `/tae-admin finalize`
command, not the automatic scheduler. Without `--enable-live-workflow`, finalization
refuses to run and no rank/announcement/recap changes occur.

Automatic mode checks every five minutes after a 15-minute end-of-window grace
period. It considers event-bearing Saturdays from the explicit cutover date with
at most seven days of catch-up. Older missed windows need a staff finalize command.
It never makes an empty/offline window an operation. Manual operations outside
Saturday's two windows are still not supported by finalization.

Before each LIVE run, it silently reconciles the LOA channel history (up to 1000
messages including bot acknowledgements) and stored-source deletions. It does not
spam old acknowledgements or retain reasons. If the channel exceeds this cap or
history access fails, it holds finalization rather than assuming missing LOAs.
Resolve relevant pending/invalid LOAs before proceeding.

### What is finalized

- One frozen operation record and one outcome per eligible linked active member.
- Only confirmed >300 seconds gets one `attended` credit. LOA grants zero credit.
- Baselines remain separate. Unique database keys prevent repeated credits when a
  command is repeated or a bot restarts. Live promotions use these FINALIZED credits,
  never provisional future/unfinalized raw evidence.
- Full window coverage and no evidence warnings are required automatically. Staff
  may explicitly use `reviewed_evidence:True` after inspecting an interruption.
  Confirmed earned credits survive; uncertain absences remain `review`, never guessed.
  Pending LOAs still block even this override.
- Late links, raw evidence changes or retroactive LOAs do not silently rewrite a
  frozen ledger or reverse a promotion. Previews may then differ from the ledger.
  Staff correction/reconciliation tooling is not yet implemented; resolve roster
  and LOAs before rollout and flag corrections for deliberate follow-up.

### Discord actions and recovery

Preflight requires the known protected roles, correct server/channels, Manage Roles,
Manage Nicknames and editable progression hierarchy. Protected WC/RM holders, Edonn,
server owner and bots are skipped. The adapter re-fetches member state before any
change and modifies only the specific progression roles via per-role endpoints,
preserving unrelated roles, then changes only the nickname prefix. It verifies
role/nickname results before recording success.

A promotion job is reserved before the API call. Partial failures or crashes leave
an `uncertain`/`applying` receipt; it does NOT blindly retry. No success announcement
is generated for an unverified promotion. Once verified, the announcement goes to
announcements in the approved wording, allowing only the promoted user's mention.

The recap goes to bot-spam listing all credited attendees and actual successful
promotions. Long lists are split across posts. There is no automatic absence alert
scheduler in this release; that remains separately guarded staff posting.

Every external post is reserved before sending. A network failure or crash can
leave `sending`/`uncertain` state, even if Discord accepted it. Such posts are NOT
resent automatically. This favors avoiding duplicates over guaranteed delivery.
Review `/tae-admin workflow-status` and the actual Discord channel before
recovery. There is no automatic rollback, retraction, retry/reset or ledger-edit
command yet. An existing recap is not rewritten after later manual corrections.

Only ONE bot process should run. Do not run old/new bot versions simultaneously.
Sheet writes have their separate opt-in. Background tasks and encrypted unattended
token storage are available through Install-Background.ps1; see the bundled README.
Scheduled backups remain a separate next step.

## Missed-operation preview and optional staff-confirmed alerts

`/tae-admin recap day:2026-11-07 session:main` privately previews the attendee
list for one operation (`fun` selects the evening session). It never posts publicly.
All qualifying linked names are included; large rosters are attached as a private
text file instead of silently truncated. The recap explicitly says promotions are
not enabled: qualification is NOT a successful Discord promotion. Automatic
post-operation recaps to bot-spam and actual promotion results remain planned after
operation finalization and role-change handling are implemented and validated.
No extra packages are needed: update `absence.py` and `discord_bot.py`.

Stop the bot and watcher while adding `absence.py` and replacing
`discord_store.py` and `discord_bot.py`. Keep all other service files/database.
No new packages or addon rebuild. Start the watcher normally. Start the bot:

```powershell
python D:\TAEAttendance\service\discord_bot.py --guild-id 1477486339984199932 --loa-channel-id 1477486341469241549 --bot-spam-channel-id 1477486342169432118
```

This does NOT enable posting. `/tae-admin missed` displays a private preview;
use its optional member picker for one individual. It distinguishes attended,
excused, missed and review. Four consecutive unexcused operations (not four days)
qualify, with attendance or accepted LOA breaking the streak. Empty windows do not
create operations. Only linked, active members since their counting date count.

Missing-op decisions require presence snapshots across the full scheduled window,
no spacing over 90 seconds, first/last within 90 seconds of boundaries, no evidence
warnings, no unresolved relevant LOA and at least 15 minutes after window end.
This intentionally holds early endings/short runs/crashes for review rather than
calling other members absent. Evidence warnings currently block missing-op decisions
globally until resolved; an old incomplete session may therefore hold new reports.

After the preview is tested, adding `--allow-absence-posts` enables ONLY the explicit
staff command `/tae-admin absence-post member:... reviewed_loa_history:True`.
Staff must verify/import old LOAs and reconcile edits/deletions missed while the bot
was offline before confirming. The bot must have View Channel/Send Messages in the
configured bot-spam channel. It posts no pings or reasons and never changes ranks.
There is no unattended automatic posting scheduler yet. That remains a later step
after preview and historical-LOA reconciliation are validated.

Durable receipts suppress repeat alerts for the same uninterrupted absence streak,
including after a fifth miss or bot restart. A reserved/uncertain send is NOT retried
automatically, avoiding duplicates after a network failure. Staff must inspect the
channel and receipt before deciding how to recover an uncertain send. Late data/LOA
corrections change the preview; already-posted messages are not auto-edited/deleted.

## LOA listener update

Stop the bot and watcher before replacing `attendance.py`, `discord_store.py`,
`discord_bot.py`, and adding `loa.py` from the service folder. Keep the database.
No addon rebuild or new Python packages are needed. Restart the watcher normally.

In the Developer Portal, Bot > Privileged Gateway Intents, enable ONLY Message
Content Intent in addition to the previous setup. Server Members/Presence can
remain off. In #LOA allow View Channel, Read Message History and Send Messages.
No Manage Messages or Administrator permission is needed for the bot.

```powershell
python D:\TAEAttendance\service\discord_bot.py --guild-id 1477486339984199932 --loa-channel-id 1477486341469241549
```

Supply the token privately as before. Omitting `--loa-channel-id` disables message
listening and keeps slash commands available. The bot requests message events
when LOA is enabled but filters out every other channel before parsing/storing.

Existing format, with an actual Discord member mention (not a typed name):

```text
Name: @member
Duration: 11/07/2026
Reason: optional
```

Supported inclusive ranges include `11/07-11/14`, `11/07/2026 to 11/14/2026`, and
`2026-11-07 through 2026-11-14`. A single date covers BOTH Saturday sessions.
Yearless dates use the original post's Eastern calendar year, stated in the
acknowledgement. Dates more than 183 days from posting are considered ambiguous
without a year. Cross-New-Year ranges require explicit years. Invalid dates or
free-form text such as 'next weekend' stay pending; the bot never invents dates.

Self-posted valid LOAs are accepted automatically. Posts naming someone other than
the author need staff review, including posts made by an administrator. The bot
acknowledges the resolved dates in #LOA without quoting the reason or pinging anyone.
Optional reasons/full source messages are NOT retained in SQLite.

Staff commands:

- `/tae-admin loa-list`: inspect up to ten most recently updated entries.
- `/tae-admin loa-refresh message_id:...`: read one old/missed/edited post.
  Use Discord Developer Mode > right-click the source post > Copy Message ID.
- `/tae-admin loa-review message_id:... accept:True`: approve a fully parsed
  pending third-party submission after verifying it. False rejects it. Incomplete
  posts must be corrected at source first, not approved with invented dates.

New messages are monitored live; there is no automatic historical channel scrape.
Live edits reparse the latest message, replacing old dates; deletions cancel the
stored excuse. Posts changed/deleted while the bot is offline need manual refresh.
For earlier LOAs, refresh the relevant message IDs explicitly. Review stale/pending
records before final attendance/absence processing (not yet enabled).

An accepted LOA changes a recent-op result to `excused` but grants ZERO attendance
credit and never creates an operation itself. Actual attendance still wins over
an overlapping LOA: more than five confirmed minutes earns the normal one-op credit,
even if the member leaves their post up. Other sessions/dates remain excused; the
bot does not delete or cancel a whole multi-date LOA because the member attended one.
Accepted messages say: `LOA accepted for the dates: <date range>. Excused absence logged.`
Excused statuses are ready for future missed-op streak logic;
the bot does not yet calculate/post absence streaks or promotions.

First live test: post a self-LOA for a specific date, verify the bot acknowledgement
and loa-list, edit its date, then delete the TEST post and confirm it is cancelled.
This creates local LOA records/acknowledgements only, not a real attended op.
