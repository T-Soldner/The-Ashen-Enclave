# Current Discord Commands

This replaces the command paths shown in older setup notes. The bot registers
the new layout when it restarts; existing database records and button IDs are
unchanged. The old paths are not retained as duplicate aliases.

## Members

- `/tae help`: private guide, including staff commands appropriate to your roles.
- `/tae status`: your attendance and account-link status.
- `/tae register`: fallback SteamID submission for staff approval.
- `/tae clan-apply`: apply to Acklay, Rook or Shyyyo.

## Everyday Staff Tools

- `/tae-admin help`: private staff/recovery guide appropriate to your roles.
- `/tae-admin health`: collector status and pending/uncertain issues; admins only.
- `/tae-admin member`: inspect another member's attendance; admins only.
- `/tae-admin transfer`: manually move a House Karr member to Acklay, Rook,
  Shyyyo or Freelancers; Administrator and a reason are required.
- `/tae-admin training edit`: edit qualifications and primary roles.
- `/tae-admin training status`: inspect qualifications and outstanding receipts.

Training still permits administrators, Clan Leaders, Seconds and Combat Advisors.
Pilot changes still require an administrator or Shyyyo's Clan Leader.
The staff root is not globally Administrator-only, because that would exclude
authorized trainers. Individual command handlers enforce their existing checks.
Discord integration-level custom restrictions can still hide a root from trainers;
review those if a permitted trainer cannot see the new training path.

Transfers are never triggered by inactivity or missed operations. A group change
removes previous clan/Freelancer membership and Clan Leader/Second roles; a
same-group no-op preserves leadership. Clan caps still apply, including places
reserved by uncertain decisions. Rank, nickname, House Karr membership,
attendance and qualifications are not changed. Successful transfers refresh the
roster automatically and close older pending clan applications. The reason and
role changes are recorded locally. A partial failure is held for reconciliation,
not blindly repeated. Transfers require the existing --enable-clan-training flag.

## Maintenance / Recovery

Use buttons for routine link, member-application and clan-application decisions.
These recovery commands remain available for exceptional cases:

- `/tae-maintenance links pending|approve|reject`: manual account-link recovery.
- `/tae-maintenance sheets bind|preview|init|sync`: attendance Sheet recovery.
- `/tae-maintenance training legacy-map|legacy-auto-map|legacy-import`: old training imports.
- `/tae-maintenance roster-sync`: preview/confirm Unit Roster and training Sheet. Freelancers use current Discord rank-role prefixes, ordered MV, MM, MA, MR, FD, then alphabetically within rank. Missing rank roles sort last; conflicting rank roles block writes. Clan leader/2IC ordering is unchanged. Once the roster has been explicitly adopted, normal attendance Sheet syncs also refresh its names and order without modifying training records.
- `/tae-maintenance roster-check`: audit House Karr membership against attendance.
- `/tae-maintenance personnel-check`: check clan/training permissions and layout.
- `/tae-maintenance clan-pending|clan-review`: inspect/recover clan decisions.
- `/tae-maintenance application-panel`: create/recover the public Apply panel.
- `/tae-maintenance application-pending|application-review|application-role-check`: application recovery.
- `/tae-maintenance loa-refresh|loa-list|loa-review`: inspect/correct LOA processing.
- Use `/tae-maintenance loa-list pending_only:True` for the pending queue or `/tae-maintenance loa-list day:2026-11-21` for blockers on a specific date. Use `page:2` for the next page when prompted. Hold notices include the first ten blocking message IDs.
- `/tae-maintenance missed|absence-post`: inspect/explicitly post absence alerts.
- `/tae-admin review [member]`: audit Discord rank roles and nickname prefixes against starting totals plus finalized attendance. Omit member for everyone. Selecting one member offers private approve/deny/correct controls in live mode: approval updates BOTH the eligible rank role and nickname. Attendance totals and unrelated roles stay unchanged. Never demotes; missing/conflicting roles and uncertain earlier edits need manual review. Appointed ranks stay protected. Historical corrections do not send promotion announcements.
- Last-four attendance and four-consecutive-miss alerts use MAIN operations only. Fun operations still add attended credits to lifetime totals and promotion eligibility, but neither add to nor reset the main-operation absence streak. Accepted LOAs continue to excuse main operations without increasing attended totals. Existing finalized credits are preserved.
- `/tae-maintenance recap|promotion-preview`: read-only operation/promotion previews. Recap, finalize, and LOA dates accept `YYYY-MM-DD`, month-first slash dates (`11/14/2026` or `11/14/26`), and written dates (`Nov 14, 26` or `14 November 2026`). Two-digit years mean 2000-2099. LOAs still accept `MM/DD` when the posting year is unambiguous and support inclusive ranges such as `Nov 14, 26 to 21 November 2026`.
- The bot listens for new LOA posts while online and updates tracked posts on live edits/deletions. It does not scan channel history. Use `/tae-maintenance loa-refresh message_id:<ID>` to explicitly import an older or missed post. Existing records are preserved.
- A qualifying operation held for LOA or evidence review gets one automatic notice in bot-spam. Finalized recaps are posted separately.
- Finalized operations post a **Review ranks and names** button in bot-spam with the same attendance-based per-person approval. WC/RM remain protected. Failed/uncertain edits require receipt review, not blind retry. Existing recap messages are not rewritten; new recaps/previews use current Discord names.
- `/tae-maintenance finalize|workflow-status|live-check`: operation workflow recovery/checks.
- `/tae-holiday day:2026-11-28` (administrators only): make both Eastern operation windows optional. Qualifying attendees earn credit; no misses, last-four entries, or scheduled previews. Use `enabled:False` to clear it before finalization. Dates with finalized attendance cannot be changed.
- `/tae-maintenance archive-member`: explicit member deactivation with preserved history.

The `|` above means choose one subcommand, not text to type literally.
Maintenance retains existing permissions: trainers may roster-sync; own-clan
leaders may inspect/review their clan applications; Recruitment Officers may
application-review/application-role-check. Other maintenance tools require admins.
Every command retains the configured-server guard and existing opt-in flags.

## Updating The Server

Stop the bot, copy the updated finalized service bundle, run the bot `--check`,
then restart it. The existing startup arguments, saved credentials, background
tasks and database do not need resetting. Discord may need a client refresh to
show the synchronized commands. No addon rebuild is needed just for command moves.
The automatic identity-detection feature separately needs its updated server-only
addon and `--enable-link-queue`; rearranging commands does not enable that flag.
