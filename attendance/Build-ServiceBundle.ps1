# Build the server deployment folder from an explicit runtime-only allowlist.
[CmdletBinding()]
param()
$ErrorActionPreference = 'Stop'
$source = (Resolve-Path -LiteralPath (Join-Path $PSScriptRoot 'service')).ProviderPath.TrimEnd('\')
$output = [IO.Path]::GetFullPath((Join-Path $source 'finalized')).TrimEnd('\')
if ([IO.Directory]::GetParent($output).FullName -ine $source -or (Split-Path $output -Leaf) -ne 'finalized') {
    throw 'Deployment output must be the direct service\finalized child.'
}
function Assert-NoReparsePath([string]$Path) {
    $cursor = $Path
    while ($cursor) {
        if (Test-Path -LiteralPath $cursor) {
            if ((Get-Item -LiteralPath $cursor -Force).Attributes -band [IO.FileAttributes]::ReparsePoint) {
                throw "Bundle paths must not traverse links/junctions: $cursor"
            }
        }
        $parent = [IO.Directory]::GetParent($cursor)
        if ($null -eq $parent) { break }
        $cursor = $parent.FullName
    }
}
Assert-NoReparsePath $source
Assert-NoReparsePath $output
$runtime = @(
    'absence.py', 'application_ui.py', 'application_roles.py', 'applications.py', 'attendance.py',
    'clan_tracker.py', 'clan_training.py', 'personnel_workflow.py', 'personnel_sheets.py', 'personnel_ui.py',
    'legacy_training.py',
    'link_queue.py', 'link_queue_ui.py',
    'collector.py', 'discord_bot.py', 'discord_store.py', 'discord_transport.py',
    'finalization.py', 'loa.py', 'membership.py', 'onboarding.py', 'promotions.py', 'sheets_read_test.py', 'sheets_sync.py',
    'background_worker.py', 'Install-Background.ps1', 'Manage-Background.ps1',
    'backup_database.py', 'Install-Backups.ps1',
    'requirements-discord.txt', 'requirements-server.txt'
)
foreach ($name in $runtime) {
    $path = Join-Path $source $name
    Assert-NoReparsePath $path
    if (!(Test-Path -LiteralPath $path -PathType Leaf)) { throw "Required runtime file missing: $name" }
}
$readme = Join-Path $PSScriptRoot 'SERVER_SERVICE_README.txt'
Assert-NoReparsePath $readme
if (!(Test-Path -LiteralPath $readme -PathType Leaf)) { throw 'Server README missing.' }
if (Test-Path -LiteralPath $output) {
    $allowed = $runtime + @('README.txt', 'MANIFEST.sha256')
    foreach ($item in Get-ChildItem -LiteralPath $output -Force) {
        if ($item.PSIsContainer -or $item.Name -notin $allowed -or ($item.Attributes -band [IO.FileAttributes]::ReparsePoint)) {
            throw "Unexpected bundle entry; left untouched: $($item.FullName)"
        }
    }
} else {
    New-Item -ItemType Directory -Path $output | Out-Null
}
foreach ($name in $runtime) {
    Copy-Item -LiteralPath (Join-Path $source $name) -Destination (Join-Path $output $name) -Force
}
Copy-Item -LiteralPath $readme -Destination (Join-Path $output 'README.txt') -Force
$manifest = foreach ($name in ($runtime + 'README.txt' | Sort-Object)) {
    $hash = (Get-FileHash -LiteralPath (Join-Path $output $name) -Algorithm SHA256).Hash.ToLowerInvariant()
    "$hash  $name"
}
[IO.File]::WriteAllLines((Join-Path $output 'MANIFEST.sha256'), [string[]]$manifest, [Text.UTF8Encoding]::new($false))
Write-Host "Server bundle refreshed: $output"
Write-Host 'Copy its CONTENTS into D:\TAEAttendance\service on the server. Keep data/secrets/backups separate.'
Write-Host 'No tests, credentials, databases, logs or addon PBOs were included. Nothing was installed or started.'
