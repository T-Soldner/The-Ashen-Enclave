#Requires -Version 5.1
#Requires -RunAsAdministrator
[CmdletBinding()]
param(
    [string]$Root = 'D:\TAEAttendance',
    [string]$RptDirectory = 'D:\ArmA3\A3Master',
    [string]$GoogleCredentials = 'D:\TAEAttendance\secrets\google-service-account.json',
    [string]$PythonExe,
    [switch]$EnableAutoOnboarding,
    [switch]$ResumeSetup
)
$ErrorActionPreference = 'Stop'
$identity = [Security.Principal.WindowsIdentity]::GetCurrent()
$account = $identity.Name
$Root = [IO.Path]::GetFullPath($Root).TrimEnd('\')
$service = Join-Path $Root 'service'
$secrets = Join-Path $Root 'secrets'
$configPath = Join-Path $secrets 'background.json'
$tokenPath = Join-Path $secrets 'discord-token.xml'
foreach ($path in @($Root,$service,$secrets,$RptDirectory,(Join-Path $Root 'data\attendance.sqlite3'),$GoogleCredentials,(Join-Path $service 'background_worker.py'))) {
    if (!(Test-Path -LiteralPath $path)) { throw "Missing required path: $path" }
    $cursor = [IO.Path]::GetFullPath($path)
    while ($cursor) {
        if ((Get-Item -LiteralPath $cursor).Attributes -band [IO.FileAttributes]::ReparsePoint) { throw 'Background paths must be local and not links/junctions.' }
        $parent = [IO.Directory]::GetParent($cursor)
        if (!$parent) { break }
        $cursor = $parent.FullName
    }
}
if ($Root.StartsWith('\\')) { throw 'Use a local drive, not a network share.' }
foreach ($component in @('Bot','Watcher')) {
    if (Get-ScheduledTask -TaskName "TAE Attendance $component" -ErrorAction SilentlyContinue) {
        throw 'Tasks already exist. Stop them with Manage-Background.ps1 before updating settings; do not overwrite running tasks.'
    }
}
$running = Get-CimInstance Win32_Process | Where-Object {
    $_.Name -match '^python(w)?\.exe$' -and $_.CommandLine -match '(discord_bot\.py|collector\.py.*\bwatch\b|background_worker\.py)'
}
if ($running) { throw 'Stop the existing bot and RPT watcher with Ctrl+C before setup.' }
if (!$PythonExe) {
    $PythonExe = (& python -c 'import sys; print(sys.executable)')
    if ($LASTEXITCODE -ne 0) { throw 'Python not found. Supply -PythonExe with its full path.' }
}
$PythonExe = (Resolve-Path -LiteralPath $PythonExe).ProviderPath
& $PythonExe -c 'import sqlite3, discord, google.auth, requests'
if ($LASTEXITCODE -ne 0) { throw 'Required Python packages missing. Nothing was installed.' }
& $PythonExe (Join-Path $service 'discord_bot.py') --db (Join-Path $Root 'data\attendance.sqlite3') --guild-id 1477486339984199932 --check
if ($LASTEXITCODE -ne 0) { throw 'Bot command check failed. No tasks installed.' }
if ($ResumeSetup) {
    if (!(Test-Path -LiteralPath $configPath) -or !(Test-Path -LiteralPath $tokenPath)) {
        throw 'Resume requires both saved background.json and discord-token.xml. No files changed.'
    }
    $config = Get-Content -LiteralPath $configPath -Raw | ConvertFrom-Json
    if ($config.account -ine $account -or $config.root -ine $Root -or $config.token_file -ine $tokenPath) {
        throw 'Saved setup belongs to a different account or path. No files changed.'
    }
    if ($EnableAutoOnboarding) { throw 'Resume preserves the existing flags. Do not supply -EnableAutoOnboarding again.' }
    $token = Import-Clixml -LiteralPath $tokenPath
    if ($token -isnot [Security.SecureString] -or $token.Length -eq 0) {
        throw 'Saved token could not be decrypted for this account/server. No files changed.'
    }
    Write-Host 'Reusing saved encrypted token and configuration; no files replaced.'
} elseif ((Test-Path -LiteralPath $configPath) -or (Test-Path -LiteralPath $tokenPath)) {
    throw 'Background configuration/token already exist. Preserve them and review before rerunning setup.'
}
Write-Host "Tasks will run as $account, even when signed out."
Write-Host 'Enter that Windows account PASSWORD (not its PIN). It is passed to Windows Task Scheduler, not saved in our files.'
$windowsSecret = Read-Host 'Windows password' -AsSecureString
if ($windowsSecret.Length -eq 0) { throw 'A nonblank Windows password is required for unattended tasks.' }
if (!$ResumeSetup) {
    $token = Read-Host 'Paste Discord BOT TOKEN using right-click, then Enter (hidden)' -AsSecureString
$plainToken = [Net.NetworkCredential]::new('', $token).Password
if ($plainToken -notmatch '^[A-Za-z0-9_.-]+$') { throw 'Token contains invalid characters. No task installed.' }
$plainToken = $null
# Restrict the secret directory to this account, SYSTEM and local administrators.
$acl = New-Object Security.AccessControl.DirectorySecurity
$acl.SetAccessRuleProtection($true,$false)
foreach ($sid in @($identity.User.Value,'S-1-5-18','S-1-5-32-544')) {
    $principal = [Security.Principal.SecurityIdentifier]::new($sid)
    $rule = [Security.AccessControl.FileSystemAccessRule]::new($principal,'FullControl','ContainerInherit,ObjectInherit','None','Allow')
    $acl.AddAccessRule($rule)
}
Set-Acl -LiteralPath $secrets -AclObject $acl
$token | Export-Clixml -LiteralPath $tokenPath
$botArgs = @('--db',(Join-Path $Root 'data\attendance.sqlite3'),'--guild-id','1477486339984199932',
    '--loa-channel-id','1477486341469241549','--bot-spam-channel-id','1477486342169432118',
    '--sheets-credentials',$GoogleCredentials,'--applications-review-channel-id','1477486342471680236',
    '--enable-sheet-writes','--enable-roster-scan','--enable-application-roles')
if ($EnableAutoOnboarding) { $botArgs += '--enable-auto-onboarding' }
$config = @{root=$Root; rpt_dir=$RptDirectory; token_file=$tokenPath; bot_args=$botArgs; account=$account}
[IO.File]::WriteAllText($configPath,($config | ConvertTo-Json -Depth 4),[Text.UTF8Encoding]::new($false))
}
$logs = Join-Path $Root 'logs'
if (!(Test-Path -LiteralPath $logs)) { New-Item -ItemType Directory -Path $logs | Out-Null }
$startup = New-ScheduledTaskTrigger -AtStartup
$retry = New-ScheduledTaskTrigger -Once -At (Get-Date).AddMinutes(1) -RepetitionInterval (New-TimeSpan -Minutes 5)
$settings = New-ScheduledTaskSettingsSet -StartWhenAvailable -RestartCount 10 -RestartInterval (New-TimeSpan -Minutes 1) -ExecutionTimeLimit ([TimeSpan]::Zero) -MultipleInstances IgnoreNew -AllowStartIfOnBatteries -DontStopIfGoingOnBatteries
$principal = New-ScheduledTaskPrincipal -UserId $account -LogonType Password -RunLevel Limited
$registered = @()
$password = [Net.NetworkCredential]::new('', $windowsSecret).Password
try {
    foreach ($component in @('Bot','Watcher')) {
        $arguments = '-u "' + (Join-Path $service 'background_worker.py') + '" --config "' + $configPath + '" --component ' + $component
        $action = New-ScheduledTaskAction -Execute $PythonExe -Argument $arguments -WorkingDirectory $service
        $task = New-ScheduledTask -Action $action -Trigger @($startup,$retry) -Settings $settings -Principal $principal -Description 'TAE attendance background worker; no live operation finalization.'
        $task.Settings.Enabled = $false
        Register-ScheduledTask -TaskName "TAE Attendance $component" -InputObject $task -User $account -Password $password | Out-Null
        $registered += "TAE Attendance $component"
    }
} catch {
    $detail = $_.Exception.Message.Replace($password,'[REDACTED]')
    $cleanupFailed = $false
    foreach ($name in $registered) {
        try { Unregister-ScheduledTask -TaskName $name -Confirm:$false }
        catch { $cleanupFailed = $true }
    }
    Write-Host "Windows Task Scheduler reported: $detail" -ForegroundColor Yellow
    if ($cleanupFailed) { Write-Host 'Some disabled tasks could not be rolled back. Inspect Task Scheduler before retrying.' -ForegroundColor Yellow }
    throw 'Task registration failed; see the Windows error above. Encrypted token/config preserved. Retry with -ResumeSetup after resolving the cause.'
} finally {
    $password = $null
    $windowsSecret.Dispose()
    $token.Dispose()
}
Write-Host 'Two tasks installed DISABLED. No bot or watcher started.'
Write-Host 'Start them with: .\Manage-Background.ps1 -Action Start'
Write-Host 'Operation finalization/promotions remain OFF. Logs: D:\TAEAttendance\logs'
