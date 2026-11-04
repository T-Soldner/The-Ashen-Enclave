# Clan applications and specialization training

Built locally on November 2, 2026. Not deployed or live-tested. These features
are separate from attendance finalization and do not integrate with Arma.

## What Players Get

- `/tae clan-apply`: choose Acklay, Rook or Shyyyo, then explain why they want to
  join. The private selection screen and form warn that the entire destination
  clan can see the application and answer.
- Applications appear with persistent Accept/Deny buttons in the configured
  barracks. Denial requires a reason, also visible in that barracks.
- Only House Karr members can apply. There is one open application per member.
  Applications are allowed when a group is full, but cannot be accepted then.

## Clan Review

Administrators can review any application. A Clan Leader must also hold the
destination clan/flight role. Recruitment Officers, Seconds and Advisors do not
gain clan-acceptance powers from those roles alone.

| Group | Capacity, including leaders | Application channel |
| --- | --- | --- |
| Acklay | 8 | Acklay Barracks, 1549895011401728030 |
| Rook | 8 | Rook Barracks, 1477486341469241555 |
| Shyyyo | 4 | flight-barracks, 1510405139746525184 |

The destination role is added and verified before old clan/Freelancer roles are
removed. Rank, training and unrelated roles are preserved. Clan Leaders/Seconds
must have leadership duties explicitly reviewed/removed by an administrator
before transferring: a group change must not transfer leadership authority.

Capacity uses a complete Discord member fetch, not a partial cache. Acceptances
are serialized and uncertain role updates reserve a slot until reconciled.
Manual Discord role assignments by other administrators can still bypass the
bot's limits; the bot refuses an over-capacity roster rather than dropping names.

- `/tae clan-pending`: administrators/own-clan leaders inspect open applications,
  including delivery and role-change problems.
- `/tae clan-review application_id:... accept:True`: alternate review path and
  verified recovery after a completed role change whose response was lost.
- Deny with `accept:False`; omitted reasons open the reason form.

Persistent button handlers survive restarts. A failed/uncertain send is saved but
not blindly posted again. A partial role update is not blindly repeated or denied.
Staff must inspect Discord and the receipt, reconcile the roles, and use Accept
again only once the requested final role state is correct. There is no automatic
rollback or destructive receipt-reset command.

## Training Permissions and Rules

Administrators, Clan Leaders (1477486340051570794), Seconds
(1477486340051570793), and Combat Advisors (1477486340030333094) can update any
human House Karr member, regardless of clan.

`/tae training edit member:...` opens two private multiselect controls:

1. Certified specializations: any number, no point cap.
2. Primary specializations: must also be certified, maximum **9 points inclusive**.

Save validates the full selection and updates Discord roles for PRIMARIES ONLY.
The managed Sheet tracks both states. Old primary roles removed from the selection
are removed; certification-only choices do not grant roles. Unrelated roles and
the member's nickname/rank are not changed. Concurrent/stale editors are refused.

| Specialization | Primary cost | Discord primary role |
| --- | --- | --- |
| Rising Phoenix | 4 | 1477486340051570792 |
| Lancer | 8 | 1505320345807229109 |
| Medic | 5 | 1477486340051570791 |
| Marksman | 3 | 1477486340051570790 |
| AT/AA | 6 | 1477486340038856904 |
| Grenadier | 3 | 1477486340038856903 |
| CQC | 3 | 1477486340038856902 |
| Demolitions | 5 | 1477486340038856901 |
| Sniper | 5 | 1477486340038856900 |
| Communications | 2 | 1477486340038856899 |
| Heavy Weapons | 5 | 1477486340038856898 |
| SUAS | 3 | 1541884796144459807 |
| CSW | 9 | 1541884859473993789 |
| Rifleman | 0 | Sheet-only, no supplied Discord role |
| Dropship Pilot | 9 | 1477486340030333099 |
| Starfighter Pilot | 9 | 1477486340030333098 |

Only administrators or members holding BOTH Clan Leader and Shyyyo may change
either pilot certification or pilot primary. A pilot primary uses all 9 points;
Rifleman may coexist because it costs zero. Non-pilot trainers may change unrelated
qualifications while leaving an existing pilot qualification unchanged.

The first editor prefills existing Discord primary roles as certified/primary for
explicit staff review. It does NOT infer other certifications from the legacy
Specializations tab. The administrator-only legacy import below avoids retyping
historical marks. Subsequent edits use the saved record and stop if someone
manually changed the managed Discord primary roles outside this workflow.

## Import Existing Specialization Marks

The existing Specializations tab (ID 193478047) remains the untouched historical
source. The bounded reader checks its row-23 headers and reads values plus resolved
font colors: a yellow X is primary AND certified; a green X is certified only.
Blank cells do not count even when formatted yellow. Unknown marks, formulas or
unrecognized colors block that row instead of guessing.

1. After updating the runtime bundle, run `/tae training legacy-import` as an admin.
   This reads the old tab and produces a private preview; no roles or Sheets change.
2. Exact normalized current Discord names and previously explicit attendance Sheet
   bindings can identify members. Abbreviations, renamed users and multiple matches
   require `/tae training legacy-map legacy_row:... member:...`. This saves a LOCAL
   identity mapping only, not a qualification or role change. Never guess aliases.
   To avoid mapping each abbreviation manually, run `/tae training legacy-auto-map`.
   It proposes unique name-part, username and conservative spelling matches in ONE
   attachment. Review every proposed pairing; suggestions are not identity proof.
   `/tae training legacy-auto-map confirm:True` saves the reviewed batch within
   15 minutes, without importing qualifications or changing Discord roles/Sheets.
   Ties, duplicate target suggestions and weak matches remain unresolved. Existing
   explicit mappings are not replaced. Then rerun legacy-import to preview marks.
3. Run legacy-import again after any mappings. Inspect ready rows, unresolved
   identities, duplicate-member rows, existing-record skips, and primary totals.
4. Within 15 minutes, the SAME administrator can run
   `/tae training legacy-import confirm:True`. The current source/data must still
   match that preview. Only ready rows are imported; other rows remain untouched.
5. Run a NEW `/tae roster-sync` preview and confirm it to populate the managed
   Training Tracker. Import and roster preview receipts share the same latest
   preview slot, so an older roster preview must be regenerated.

This is a RECORDS-ONLY migration: no Discord roles, announcements or source Sheet
cells are changed. Existing bot-managed training records are never overwritten.
The original source marks and import evidence are retained locally, including
unmatched/departed rows. Bean, Oracle, Lanval and THE_SAM were confirmed departed by
the user on November 3, 2026 and are not mapped/imported to current namesakes.

Historical primary selections above 9 points are preserved, flagged in the preview
and highlighted in the new tracker. They are not silently trimmed or granted as
Discord roles. The importer's name/time is an import audit, not an invented claim
about who originally trained the member; the Sheet labels original trainer unknown.

User-confirmed corrections on November 3: JIMBO is Jimothy; BAUER is Baur; Nova's
Lancer is certified only (7 primary points remain). These specific corrections were
also applied to the live historical Sheet with no unrelated edits. Baur's rows 40
and 68 are one identity: retain the union of their certifications, use the explicitly
confirmed Rising Phoenix + Medic primaries (9 points), and import just one record.
Both original row payloads are retained in the merged import evidence. Heavy Weapons
remains certified, not primary. No other duplicate identities are merged by guesswork.

Further user confirmations: historical KNIGHT is Discord member
1352461545501757480 ([MR] Knight Rook), NOT Goldie. Jerry, Wendigo, Sora, Postal,
Carolina, Jester, Shepard, Wax and Eliza also left the unit. All 13 confirmed departed
legacy identities (these nine plus Bean/Oracle/Lanval/THE_SAM) are archived locally
when legacy-import is confirmed. Their original Xs/colors and qualification lists
are retained in legacy_training_archives and source snapshots, not created as active
training records. The old source Sheet stays intact as historical evidence; it is
not silently row-deleted or used to change unrelated attendance accounts. Archive
inserts are idempotent and do not remove Discord roles or existing attendance data.

An authorized trainer must explicitly review each imported member through
`/tae training edit` and Save before reconciling their Discord primary roles. This
enforces the current 9-point and pilot restrictions. The original colors remain
available for comparison. A legacy-pending record permits this one reviewed role
reconciliation; afterward external role drift is blocked as usual. Existing pilot
Discord roles cannot be removed by an ordinary trainer during reconciliation.

Verified saves record the trainer/date and post a summary to operation-planning
(1477486341691408487), with a durable notification receipt. A failed post or Sheet
refresh does not undo a verified role/record change or justify submitting it again.
`/tae training status member:...` shows records and outstanding receipts privately.

## Sheets

The managed tab is now named **Specialization Tracker**, ID 1483591831. Existing
tabs are resolved by that fixed ID and their current title, so renaming/reordering
this tab no longer blocks synchronization. Names with apostrophes are quoted safely.
The historical **Specializations** tab remains separate (ID 193478047), read-only
to the importer. A same-named tab with the wrong ID is never silently adopted.
Earlier references below to Training Tracker mean this same renamed managed tab.

- Existing Unit Roster: update only B12:B19 (Acklay), E12:E19 (Rook), B35 and
  B38:B40 (Shyyyo lead/members), N4:N44 (Freelancers), G7/G9 (WC/RM).
- The Shyyyo heading spans rows 36-37; B37 is not a member cell. The three member
  rows plus Flight Lead hold four people total. The Flight Lead cell requires the Shyyyo leader
  role; other members are not labelled leader just because they sort first.
- Preserve radio frequencies, other clan placeholders, headers, layout and all
  cells outside those explicit anchors. Existing leadership labels remain if no
  replacement role holder is found. Multiple WC/RM holders or flight leaders stop
  synchronization rather than choosing someone by guesswork.
- If an existing roster name is recognizably still in Discord but lacks House
  Karr, synchronization stops instead of treating the missing role as a departure.
  Renamed/abbreviated identities must still be reviewed in the before/after preview.
- Create a separate Training Tracker tab, ID 1483591831, with primary yellow Xs,
  certified-only green Xs, point totals, trainer and UTC update time. Existing
  Specializations content, colors and legacy qualifications are left untouched.
- Do not alter the stable attendance backend or its row mappings.

Before the FIRST personnel Sheet write, run `/tae roster-sync` and inspect the
attached before/after preview. Then run `/tae roster-sync confirm:True` within
15 minutes. The preview must belong to the same authorized trainer and still
match the current data. Other authorized trainers cannot approve your preview.

Shyyyo layout correction: an earlier build targeted B37 inside the merged B36:D37
heading, causing the Jet entry to be absent while the other roster/training writes
succeeded. The corrected targets are B38:B40. Preparation now checks actual merge
ranges and rejects any non-anchor target before writing. For the old uncertain
receipt, recovery is allowed ONLY after a new explicit preview/confirmation, when
the merged heading is verified, B37 is empty, and every other managed cell matches
the saved receipt. No receipt reset, re-import, or ignored real mismatch is needed.
Read-back errors now identify which tab/roster coordinates differ.

After adoption, verified clan/training changes attempt an automatic refresh.
`roster-sync` also supports later explicit preview/confirmation. Manual changes to
managed Sheet values, unexpected headers, capacity/layout issues and uncertain
receipts block overwrites. Google does not offer atomic compare-and-set for this
flow: use the bot as the single writer for the managed areas, and do not manually
edit/rearrange them during synchronization. Both roster and training changes use
one native Sheets batch, followed by read-back verification.

More than 41 Freelancers needs an approved layout expansion. Future clans can be
added in the central CLANS configuration, but also need an explicit roster mapping
and display styling before personnel Sheet writes resume; no names are silently
discarded when adding a group.

## Deployment Tomorrow

No server or live Sheet changes were made while building this feature. No PBO or
new Python package is needed. Preserve the existing live-operation flags and
November 7 attendance start date when updating the background configuration.

1. Back up SQLite using the collector backup command. Stop both background tasks
   with Manage-Background.ps1 -Action Stop.
2. Copy ALL contents of attendance/service/finalized into D:\TAEAttendance\service.
   Do not overwrite/delete data, secrets, backups, or the attendance addon.
3. Validate locally on the SERVER (no Discord connection):

   `python D:\TAEAttendance\service\discord_bot.py --guild-id 1477486339984199932 --check`

4. Start the existing tasks with their existing configuration. Run
   `/tae personnel-check`. It is read-only and works while the new feature is off.
   Check role hierarchy, all three barracks, operation-planning, and capacities.
5. Once checks pass, stop the tasks again and add ONLY `--enable-clan-training`
   to bot_args in secrets/background.json. Keep all existing flags, IDs, paths
   and --auto-from date unchanged. Back up that JSON before editing. Restart tasks.
6. Preview/adopt the personnel Sheets as described above, then perform live tests
   with consenting members. Do not use existing historical qualifications as
   disposable tests or clear their current primary roles without reviewing them.

The bot needs Manage Roles and must be above every clan/Freelancer and primary
specialization role, and above members whose roles it changes. Configured grant
roles with administrator/moderation powers are rejected. It needs View Channel,
Send Messages and Embed Links in all destinations, plus Read Message History to
refresh older application posts. Barracks must be visible to the destination clan
and not @everyone; separately audit other role overrides for intended access.
Existing Server Members Intent/--enable-roster-scan and Sheet-write access are
required. No new privileged intent or Administrator permission for the bot.

The new commands live under /tae with fresh runtime staff checks. Existing
/tae-admin already has Discord's maximum 25 subcommands; it was not expanded.

## First Live Checks

- Submit Acklay, Rook and Shyyyo applications; verify destination and visibility.
- Verify admins and own-clan leaders can decide, but other clan leaders cannot.
- Verify full groups cannot accept; related leaders count toward capacity.
- Verify clan roles replace old group/Freelancer roles, leaving rank unrelated.
- Save Phoenix + Marksman + Communications = 9, reject totals above 9.
- Verify certifications alone add no Discord roles; only primaries grant them.
- Verify pilot restrictions apply to both certification and primary changes.
- Inspect yellow/green Sheet marks, trainer/date, operation-planning receipt, and
  preserved leadership/radio/legacy Specializations cells.
- Restart the bot and verify persistent clan-review buttons still function.

Live Discord SDK command registration and Google rendering still need validation
on the server. No package was downloaded to perform development checks.
