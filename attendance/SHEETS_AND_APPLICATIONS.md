# Google exports and member applications

Source implementation only. Default startup does not write Google or post an Apply
panel. No application roles, admissions, private channels or attendance links are
automatically granted. SDK/API behavior still needs live server testing.

## Update the server

Back up SQLite. Stop bot/watcher and copy the updated service folder's contents
over `D:\TAEAttendance\service` (do not delete the separate data/secrets folders).
New files: sheets_sync.py, applications.py, application_ui.py. Updated files:
discord_bot.py, discord_store.py, finalization.py. Keep sheets_read_test.py and all
existing service modules. No additional packages beyond those already installed.

Start the bot in READ-ONLY Sheet mode and enable applications:

```powershell
python D:\TAEAttendance\service\discord_bot.py --guild-id 1477486339984199932 --loa-channel-id 1477486341469241549 --bot-spam-channel-id 1477486342169432118 --sheets-credentials "D:\TAEAttendance\secrets\google-service-account.json" --applications-review-channel-id 1477486342471680236
```

Use the actual credential filename if different. First append `--check` for a local
command-definition check. Remove it to connect. No token/key in chat or Git.
Restart the RPT watcher as usual. Keep live workflow and Sheet writes OFF initially.

## Explicit Sheet bindings

Service-account access remains Viewer for this first stage. The bot never matches
sheet rows by fuzzy names or Discord nicknames. For each active linked member:

1. Inspect the existing operations tracker and note its exact row/name.
2. Run `/tae-admin sheet-bind member:... row:... exact_sheet_name:...`.
3. Run `/tae-admin sheet-preview` and verify the baseline and target total.

Binding is a LOCAL database change only; it checks the exact row label and that the
sheet total agrees with baseline or finalized total. Duplicate row/member mappings
are refused, never silently overwritten. Row/name changes or formulas in column B
block exporting instead of risking another member's total. Rebinding/correction
tools are not implemented yet; verify row choices before saving them.

Only mapped, active linked members are managed. Unregistered sheet rows remain
untouched. Exports refuse to run while any active linked member lacks a mapping.

## Enable Google writes only after preview validation

Change JUST the service account's spreadsheet sharing permission from Viewer to
Editor. No Cloud Project Editor/Owner role is needed. Restart with the same command
plus `--enable-sheet-writes`. This requests Sheets write scope, not Google Drive.
It does not enable live Discord promotions by itself.

Run `/tae-admin sheet-init confirm:True` to create the specifically approved
new tab `Attendance last four`. Creation and its header initialization use one
atomic Sheets batch request. No existing tracker columns are added/removed. If an
existing tab of that title has unexpected contents, stop and review it; the bot
does not overwrite or delete it. The new tab reserves sheet ID 1483591827; an ID
collision fails without changing the tracker.

Run sheet-preview again, then `/tae-admin sheet-sync confirm:True` for the
first verified export. The bot writes ONLY mapped column-B totals in the tracker
and mapped A:F rows in the separate history tab. It never writes the tracker's
extra columns, names, flags or formulas. History contains display names/statuses,
not Steam/Discord IDs; the spreadsheet's existing viewers can see it.

Totals are baseline plus UNIQUE finalized attended-op credits. LOA never adds a
total. The last four columns show finalized outcomes most-recent first; `attended`
and `excused` both satisfy the recent-four counter. A member with fewer recorded
operations shows e.g. 2/2, not four invented historical results. No old history can
be reconstructed from lifetime totals alone.

When BOTH live finalization and Sheet writes are enabled, a successful operation
workflow triggers this export after its Discord actions. Google failure does not
erase attendance or reverse Discord roles. Repeated exports set absolute totals,
not increments. Failed/ambiguous requests leave an uncertain local receipt and
block automatic retries until staff inspects the result. Recovery/reset tooling is
not implemented yet. API read-back verifies exports, not a distributed transaction.

Google Sheets does not offer an atomic cell compare-and-set for this workflow.
Use the bot as the single writer for managed totals; avoid simultaneous manual
edits/re-sorting during export. Unexpected prior edits are detected, but a human
edit between the last read and request cannot be guaranteed safe. No formulas are
intentionally overwritten. Keep backups and sheet version history available.

## Apply button and private form

Public panel channel: tickets-applications-feedback `1477486340625924214`.
Review channel: submitted-applications `1477486342471680236`.

The bot needs View Channel/Send Messages in the public channel. New members must
be able to view it. In submitted-applications, grant bot View Channel, Send Messages
and Embed Links. Deny @everyone View Channel and allow ONLY intended staff roles.
The bot refuses delivery when @everyone can view the review channel, but the owner
must also audit other role overrides; code cannot infer which custom roles are staff.
No Administrator, Manage Channels or Message Content access is needed for forms.

Run `/tae-admin application-panel` once to post the persistent Apply button.
Its handler is registered on restart, so the posted button keeps working while the
updated bot is running. Receipt prevents accidental duplicate panels. If the first
attempt failed due to permissions, fix access and run application-panel with
`recover_failed:True`. Recovery also needs Read Message History in the public
channel. It reuses an existing own-bot panel when found, ignores other bots' panels,
and clears only the stale local receipt when it confirms no own panel exists.
A scan reaching its 100-message cap without finding one stops for staff review.

Participation choices:

- Active member: Yes/No streaming/recording dropdown, followed by how they found
  the unit, Arma hours, introduction, and SteamID64 (17 digits).
- Other Unit Liaison: unit name, how they found us, and a Discord invite link.
- Friend of the unit: skip ALL follow-up questions and confirm submission.

Replies are private ephemeral forms, not DMs, so closed DMs do not block applying.
Only one pending application per Discord user is allowed. Steam ID is a claim for
staff verification, not proof of ownership. Submission never grants roles or adds
attendance. Only members holding Unassigned (1477486339984199936) may apply;
this is checked again at submission, with no administrator bypass.

Before accepting applications, run `/tae-admin application-role-check`. After its
permission/hierarchy checks pass, restart with `--enable-application-roles` added
to the existing command. This does not enable live attendance or promotions.
The bot needs Manage Roles and must be above every role it adds or removes.
Acceptance grants and verifies category roles BEFORE removing Unassigned:

- Active: Foundling, House Karr, Freelance Mandalorians and the six specified
  visual organization roles. Streaming Yes also adds 1477486340022206602.
- Friend: 1477486340022206599.
- Liaison: 1477486340022206603.

Other roles are preserved. Denial does not change roles. Failed or uncertain role
updates leave the application pending for staff inspection, not blind retries.
An already-complete role update can be verified on another Accept click without
repeating mutations. Older pending applications must satisfy the new answer rules.

Submitted answers go into local SQLite and the staff-only review channel. No
answers go to the public panel or third-party application bot. Personal introductions
may contain sensitive information: restrict database/backups, audit channel access,
and set a retention/deletion policy before broad rollout. No automatic purge or
privacy-delete command is implemented yet.

Staff review posts now have persistent Accept/Deny buttons. Discord administrators
OR Recruitment Officers (role ID `1477486340101902517`) in the configured
submitted-applications channel may use them. The exception applies only to application
accept/deny and the application-review command; attendance approval, Sheet actions,
archiving, panel management and other staff commands remain Administrator-only.
Deny opens a required reason form (1-800 nonblank characters); permission is checked
again when submitted. The reason and reviewer are saved locally and the decision
is shown on the staff-only source post. No automatic applicant DM is sent.

Grant Recruitment Officers View Channel and Read Message History in the staff review
channel. Buttons need no slash-command visibility changes. If they also need the
application-review slash command, Discord may hide the /tae-admin group because it
defaults to Administrator. A server admin can add a Recruitment Officer command
override under Server Settings > Integrations > this bot > /tae-admin. Runtime
checks still reject every unrelated admin action, even if the group is visible.
Do not grant Administrator to recruiters merely to expose the review command.
Accept saves approval. A completed decision removes the post's buttons; duplicate
or competing clicks cannot overwrite the first decision. If the message edit
fails, the database decision still stands and stale buttons cannot save another.

For older PENDING posts without buttons, run `/tae-admin application-pending
attach_buttons:True`. The bot requires Read Message History in the staff channel
to fetch/edit old posts; it only modifies its own saved review-message IDs. Up to
ten pending posts are handled per call. New submissions get buttons automatically.

Staff commands remain: application-pending (IDs/delivery states), application-review
with application ID and accept True/False. Denying via the command also prompts for
a reason when omitted. Approval of Active member queues the supplied
Steam ID as a pending attendance link if it conflicts with no existing account.
Use attendance-admin pending/approve to verify it and assign the correct baseline,
counting date and membership date. They need not run register again if queued.
Liaisons/Friends do not get attendance claims. Their accepted category roles use
the explicit application-role flag described above.

No ticket creation or applicant DM notification yet. Failed
staff-channel deliveries remain saved with pending/uncertain delivery state and are
not blindly resent. Staff inspect application-pending/local records before recovery.

## Archiving departed members

### Human-readable clan tracker

The live workbook now has `Operations Tracker` (display only), while the stable
backend is `Operations Tracker Main` (sheet ID 1178516523). The bot resolves that
ID, not its title, so the rename does not break exports or bindings. Never sort
or move backend rows. The new display sorts its own output and leaves them intact.

Hondo and Edonn appear first using the WC/RM backend labels, with live totals and
the same last-four results as other members. This is display grouping only: each
still needs an attendance account link/mapping to earn new automatic credits.
Protected ranks remain protected from role/nickname updates, not attendance.

The hidden `Attendance clan groups` helper is bot-owned. After copying the bundle
and restarting with existing Sheet-write/roster-scan flags, run
`/tae-admin sheet-sync confirm:True` to populate it from Discord roles for linked,
mapped active members. It also refreshes after successful auto-onboarding and
future enabled operation exports. Membership changes appear on the next refresh,
not immediately. No new startup flag or package is required for this view.

Current recognized role names: Clan Acklay, Clan Rook, Shyyyo Flight, Freelance
Mandalorians. A specific clan/flight takes precedence over the default Freelancer
role. Conflicting specific groups, unknown roles, absent Discord members and
unlinked tracker entries display `Needs clan assignment` rather than guessed
membership. Register/link/map those existing users with their preserved totals;
do not send them through zero-baseline new-member onboarding to force grouping.
Keep the helper hidden and do not manually edit its data. The display is a live
formula over the backend/history/helper; do not type into its spilled results.

### Automatic application onboarding

Append `--enable-auto-onboarding` to the existing bot command only after copying
the updated finalized bundle. This requires application roles and Sheet writes
to be enabled. Accepting an Active member then creates a new `[FD]` tracker entry
at zero, links their submitted SteamID and Discord account, and saves the row
mapping. Counting begins on the acceptance date in Eastern time. The separate
ORBAT is not edited. Friends and liaisons receive no attendance entries.

Staff acceptance now approves the applicant's SteamID claim; review it before
clicking Accept. This does not prove Steam account ownership. Existing linked,
mapped members retain their totals. Existing unlinked names, archived members,
conflicting IDs and unmapped existing accounts stop for manual reconciliation.
Do not manually edit/re-sort the tracker during onboarding: Google has no atomic
compare-and-set, so the bot must be the single writer for these rows.

Roles may already have been assigned when Sheet onboarding fails; the application
stays pending and is not denied automatically. A failed/uncertain Sheet receipt
blocks repeated writes and needs staff inspection. No receipt-reset tool exists
yet. Successful verified onboarding can be retried without resetting totals.
This flag does not enable automatic operation finalization/promotions. Existing
accepted applications are not retroactively enrolled.

Use `/tae-admin roster-check` for a read-only membership audit instead of handling
each person individually. Enable Server Members Intent on the Developer Portal's
Bot page and restart with `--enable-roster-scan`. Presence Intent is not required.
The private attached report lists House Karr members missing active linked
attendance, tracked members absent from Discord, and tracked members still in
Discord without House Karr. Pending registrations are marked. A failed full-list
fetch produces no departure report. No automatic archive, role or Sheet changes
occur; unlinked spreadsheet/ORBAT rows still need manual checking. The individual
archive command remains available for separately confirmed cleanup.

`/tae-admin archive-member confirm:True member:...` deactivates a LINKED attendance
member while retaining identity, baseline, all RPT evidence, finalized credits and
audit history. If they already left Discord, use `discord_id:...` instead of the
member picker. Give exactly one of member/discord_id. Staff Administrator permission
is required. No Discord roles or nicknames are changed.

By default it also attempts the mapped Sheet archive, requiring existing Sheet-write
opt-in and Editor access. It creates/validates `Archived Members`, preserves their
finalized total and recent results, then clears ONLY the mapped tracker's A:B cells
and history row's A:F cells. It NEVER deletes a row, shifts other bindings, or clears
the original tracker's extra columns. The archive/create/clear operation is one
atomic Google batch request, followed by read-back verification. Names/IDs are
validated before any clear. It exports names/totals, not Steam/Discord IDs.

The separately maintained unit roster/ORBAT has no verified binding and is NOT
edited automatically. Handle that entry manually for now. Unlinked members cannot
be safely identified from names alone; handle those sheet entries manually too.

Use `update_sheet:False` for local-only archiving. If the sheet is unavailable,
deactivation still completes and the command reports that its Sheet part was not
confirmed. Repeating is safe, but uncertain/sending Sheet receipts require staff
inspection rather than blind retry. No automatic unarchive/rebinding tool exists
yet; do not test this command on an active member unless you intend to archive them.
Archived tracker bindings remain reserved; do not reuse those blank rows manually.

## Live test order

1. Existing bot command check (with --check) after copying files.
2. Explicitly bind Edonn and Jimothy, preview Google totals in Viewer mode.
3. Enable Editor/write flag, initialize the new history tab, preview and verify sync.
4. Test the public panel with a consenting user; verify Active and skipped-question
   flows, private review delivery, duplicate prevention and staff review.
5. Keep automatic finalization/promotion flags off until these tests are accepted.
