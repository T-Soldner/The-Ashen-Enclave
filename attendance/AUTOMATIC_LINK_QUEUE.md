# Automatic Attendance Link Queue

The server-only addon now logs SteamID64 and in-game name separately from
attendance evidence. Identity detections never award attendance, including on
training days or the other group's Mondays. Existing Saturday windows still apply.
Name records use numeric character codes, so player-controlled names cannot
inject attendance delimiters or Discord mentions. The collector reads them using
its existing incremental RPT cursor; no polling of players or remote API added.

## Staff Workflow

With `--enable-link-queue`, the bot checks once per minute and posts up to five
new unknown identities in the configured **submitted-applications** channel.
Existing `/tae register` claims enter the same button queue automatically.
Each SteamID64 gets one durable queue entry; dismissed detections do not repost.
Only Discord administrators in the configured server can review or approve links.
No rank, nickname, clan or training roles are changed by identity approval.

1. Click **Review / choose member**.
2. Check the suggested Discord member, or select the correct member.
3. Click **Preview link**. Leave the tracker-row field blank for an exact
   rank-prefix-insensitive name match, or supply the known master tracker row.
4. Verify Steam identity against the actual person, name, row, total and start date.
5. Click **Approve link**. The preview expires after ten minutes.

Existing tracker totals are adopted as the starting baseline without rewriting
them. Counting starts on the approval date in Eastern time; earlier operations
are not retroactively added. A new row starts at zero ONLY after an explicit
preview warning and approval. If the person already has an old row, stop and
specify that row rather than creating another. Multiple exact name matches,
formula totals, occupied rows, conflicting claims and archived/existing links
stop for manual review. A name or registration claim alone is never proof.

Approval creates the verified local link and sheet binding, then automatically
exports attendance/history and refreshes the clan display. No routine `pending`,
`sheet-bind` or `sheet-sync` commands required. If another old unmapped account
or an uncertain export blocks the global sheet refresh, the link remains saved
and the reviewer is told the refresh needs review. Never approve again to retry
an uncertain link. Advanced commands remain available for exceptional recovery.

Delivery/approval receipts live in `detected_links`. Sending or uncertain results
are not blindly repeated after a crash. `/tae-admin health` includes pending and
uncertain detection counts. Dismiss only removes the suggestion from this queue;
it does not archive a member or change attendance. Staff can still use the
existing registration/approval workflow for intentionally dismissed cases.

## Deployment On The Server

Back up the database and stop the bot/watcher before copying service files.
Copy the contents of `service/finalized` to `D:\TAEAttendance\service`.
Do not overwrite the data, secrets, logs or backup folders.

Replace the server-only `TAEAttendance.pbo` with the freshly built version while
the Arma server is stopped. It remains a separate server-only addon, not a normal
TAE mod update. Restart Arma/a mission with the new addon. Old addons still log
attendance but do not supply names; explicit registration claims still work.

Preserve all existing background flags and add one flag in Administrator PowerShell:

```powershell
$path = 'D:\TAEAttendance\secrets\background.json'
$config = Get-Content -LiteralPath $path -Raw | ConvertFrom-Json
if ('--enable-link-queue' -notin $config.bot_args) {
    $config.bot_args = @($config.bot_args) + '--enable-link-queue'
    [IO.File]::WriteAllText($path, ($config | ConvertTo-Json -Depth 8), [Text.UTF8Encoding]::new($false))
}
```

This requires the existing TAE guild, roster-scan/member intent, sheet-write
settings, Google credentials and staff application-review channel. The queue
refuses a channel visible to @everyone or a non-staff member. Staff means an
administrator, Recruitment Officer, Clan Leader, Second or Combat Advisor (link
approval itself remains administrator-only). Check all other channel overrides too;
do not expose Steam/account-link data in public bot-spam.

Run the existing bot `--check`, restart the background tasks, and test using an
unlinked consenting member. Confirm one queue post, correct original total, one
local account link, automatic sheet refresh, no duplicate after restart, and no
attendance credit for the identity record itself. No new Python packages,
Discord token or Google credentials are required. The queue and updated SQF have
offline coverage/build validation but still need this real-server test.
