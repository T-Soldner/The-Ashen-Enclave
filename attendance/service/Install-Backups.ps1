#Requires -Version 5.1
#Requires -RunAsAdministrator
[CmdletBinding()]
param([string]$Root = 'D:\TAEAttendance', [switch]$UpdateSchedule)
$ErrorActionPreference = 'Stop'
$Root = [IO.Path]::GetFullPath($Root).TrimEnd('\')
if ($Root.StartsWith('\\')) { throw 'Use local storage, not a network share.' }
$service = Join-Path $Root 'service'
$script = Join-Path $service 'backup_database.py'
$database = Join-Path $Root 'data\attendance.sqlite3'
foreach ($path in @($Root,$service,$script,$database)) {
    if (!(Test-Path -LiteralPath $path)) { throw "Missing required path: $path" }
    $cursor = $path
    while ($cursor) {
        if ((Get-Item -LiteralPath $cursor -Force).Attributes -band [IO.FileAttributes]::ReparsePoint) {
            throw 'Backup paths must not traverse links or junctions.'
        }
        $parent = [IO.Directory]::GetParent($cursor)
        if (!$parent) { break }
        $cursor = $parent.FullName
    }
}
$name = 'TAE Attendance Backup'
$weekly = New-ScheduledTaskTrigger -Weekly -WeeksInterval 1 -DaysOfWeek Saturday -At '03:00'
$description = 'Verified local attendance database backups Saturdays at 3 AM server time; keep latest 30 automatic backups.'
if ($UpdateSchedule) {
    $existing = Get-ScheduledTask -TaskName $name -ErrorAction Stop
    Set-ScheduledTask -TaskName $name -Trigger $weekly -Description $description | Out-Null
    Write-Host 'Backup schedule updated: Saturdays at 3 AM SERVER LOCAL TIME; no startup backup.'
    Write-Host 'Existing action, account, credentials and enabled/disabled state preserved.'
    return
}
if (Get-ScheduledTask -TaskName $name -ErrorAction SilentlyContinue) {
    throw 'Backup task already exists. Use -UpdateSchedule to change only its schedule.'
}
$watcher = Get-ScheduledTask -TaskName 'TAE Attendance Watcher' -ErrorAction Stop
$identity = [Security.Principal.WindowsIdentity]::GetCurrent()
$account = $identity.Name
$taskAccount = $watcher.Principal.UserId
try {
    if ($taskAccount -match '^S-1-') {
        $taskSid = [Security.Principal.SecurityIdentifier]::new($taskAccount)
    } else {
        $taskSid = ([Security.Principal.NTAccount]::new($taskAccount)).Translate([Security.Principal.SecurityIdentifier])
    }
} catch {
    throw "Could not resolve the existing task account to a Windows SID: $taskAccount. No tasks changed."
}
if ($taskSid.Value -ne $identity.User.Value) {
    throw "Run this as the existing task account: $($watcher.Principal.UserId)"
}
$python = $watcher.Actions[0].Execute
if (!(Test-Path -LiteralPath $python -PathType Leaf)) { throw 'Existing watcher Python executable not found.' }
# Verify a live snapshot before installing anything; existing workers stay running.
& $python $script --root $Root --keep 30
if ($LASTEXITCODE -ne 0) { throw 'Initial backup failed. No scheduled task installed.' }
$secret = Read-Host "Windows PASSWORD for $account (not the PIN)" -AsSecureString
if (!$secret.Length) { throw 'A nonblank Windows password is required.' }
$password = [Net.NetworkCredential]::new('', $secret).Password
try {
    $action = New-ScheduledTaskAction -Execute $python -Argument ('-u "' + $script + '" --root "' + $Root + '" --keep 30') -WorkingDirectory $service
    $settings = New-ScheduledTaskSettingsSet -StartWhenAvailable -RestartCount 3 -RestartInterval (New-TimeSpan -Minutes 5) -ExecutionTimeLimit (New-TimeSpan -Minutes 10) -MultipleInstances IgnoreNew -AllowStartIfOnBatteries -DontStopIfGoingOnBatteries
    $principal = New-ScheduledTaskPrincipal -UserId $account -LogonType Password -RunLevel Limited
    $task = New-ScheduledTask -Action $action -Trigger $weekly -Settings $settings -Principal $principal -Description $description
    Register-ScheduledTask -TaskName $name -InputObject $task -User $account -Password $password | Out-Null
} catch {
    Write-Host ('Windows Task Scheduler reported: ' + $_.Exception.Message.Replace($password,'[REDACTED]')) -ForegroundColor Yellow
    throw 'Backup task registration failed. Existing bot/watcher settings and credentials were not changed.'
} finally {
    $password = $null
    $secret.Dispose()
}
Write-Host 'Automatic backups installed: Saturdays at 3 AM SERVER LOCAL TIME; no startup backup.'
Write-Host "Initial backup verified. Backups: $Root\backups; log: $Root\logs\backup.log"
Write-Host 'Manual backups are not removed. No Discord token or Google key needed.'
