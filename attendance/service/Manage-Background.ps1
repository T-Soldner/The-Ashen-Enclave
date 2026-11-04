#Requires -Version 5.1
[CmdletBinding()]
param([ValidateSet('Status','Start','Stop')][string]$Action = 'Status')
$ErrorActionPreference = 'Stop'
foreach ($component in @('Bot','Watcher')) {
    $name = "TAE Attendance $component"
    $task = Get-ScheduledTask -TaskName $name -ErrorAction Stop
    if ($Action -eq 'Start') {
        Enable-ScheduledTask -TaskName $name | Out-Null
        Start-ScheduledTask -TaskName $name
    } elseif ($Action -eq 'Stop') {
        Disable-ScheduledTask -TaskName $name | Out-Null
        Stop-ScheduledTask -TaskName $name
    }
    $task = Get-ScheduledTask -TaskName $name
    $info = Get-ScheduledTaskInfo -TaskName $name
    [pscustomobject]@{Task=$name; State=$task.State; LastStart=$info.LastRunTime; LastResult=$info.LastTaskResult}
}
