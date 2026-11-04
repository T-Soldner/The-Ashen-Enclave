[CmdletBinding()]
param(
    [Parameter(Mandatory=$true)][string]$OutputMod,
    [string]$ArmaToolsRoot = 'D:\SteamLibrary\steamapps\common\Arma 3 Tools'
)
$ErrorActionPreference = 'Stop'
$builder = Join-Path $ArmaToolsRoot 'AddonBuilder\AddonBuilder.exe'
if (!(Test-Path -LiteralPath $builder)) { throw "AddonBuilder not found: $builder" }
$source = Join-Path $PSScriptRoot 'addon\TAEAttendance'
$output = $ExecutionContext.SessionState.Path.GetUnresolvedProviderPathFromPSPath($OutputMod)
$repo = Split-Path $PSScriptRoot -Parent
if ($output.StartsWith($repo.TrimEnd('\') + '\', [StringComparison]::OrdinalIgnoreCase) -or $output -eq $repo) {
    throw 'Use a separate output mod folder outside the repository.'
}
$addons = Join-Path $output 'addons'
New-Item -ItemType Directory -Path $addons -Force | Out-Null
$pbo = Join-Path $addons 'TAEAttendance.pbo'
if (Test-Path -LiteralPath $pbo) { throw "Choose a fresh output folder; existing PBO found: $pbo" }
$ErrorActionPreference = 'Continue'
& $builder $source $addons '-clear' '-packonly' '-prefix=TAEAttendance' "-toolsDirectory=$ArmaToolsRoot"
$exitCode = $LASTEXITCODE
$ErrorActionPreference = 'Stop'
if ($exitCode -ne 0 -or !(Test-Path -LiteralPath $pbo) -or (Get-Item -LiteralPath $pbo).Length -eq 0) {
    throw "Attendance build failed (exit $exitCode)."
}
Write-Host "Unsigned server-only test PBO ready: $pbo"
