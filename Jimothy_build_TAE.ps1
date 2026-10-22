# The Ashen Enclave Local Test Builder - Jimothy (unsigned only)
[CmdletBinding()]
param(
    [string]$SourceRoot = "C:\Users\mrjim\Documents\GitHub\The-Ashen-Enclave",
    [string]$OutputRoot = "D:\SteamLibrary\steamapps\common\Arma 3@MyTestPatch\addons",
    [string]$ArmaToolsRoot = "D:\SteamLibrary\steamapps\common\Arma 3 Tools",
    [switch]$NoPause
)

$ErrorActionPreference = "Stop"
$addons = @(
    "TAECore", "TAEInsignias", "TAEMarkers", "TAEWeapons", "TAEGear",
    "TAEHUD", "TAEDrones", "adv_aceCPR", "TAEASTRS", "TAEJLTSCompat",
    "TAEUnits", "TAEObjects", "TAEVehicles"
)
$failures = New-Object System.Collections.Generic.List[string]

try {
    $SourceRoot = (Resolve-Path -LiteralPath $SourceRoot).ProviderPath
    $OutputRoot = $ExecutionContext.SessionState.Path.GetUnresolvedProviderPathFromPSPath($OutputRoot)
    $modRoot = Split-Path -Path $OutputRoot -Parent
    if ([string]::IsNullOrWhiteSpace($modRoot) -or
        (Split-Path -Path $OutputRoot -Leaf) -ine "addons" -or
        $OutputRoot.Equals($SourceRoot, [StringComparison]::OrdinalIgnoreCase) -or
        $OutputRoot.StartsWith($SourceRoot.TrimEnd('\') + '\', [StringComparison]::OrdinalIgnoreCase)) {
        throw "Use a separate addons output directory outside the source tree."
    }
    $addonBuilder = Join-Path $ArmaToolsRoot "AddonBuilder\AddonBuilder.exe"
    $runtimeIncludeList = Join-Path $SourceRoot "TAE_build_include.lst"
    $modStuffRoot = Join-Path $SourceRoot "Mod Stuff"
    $requiredFiles = @($addonBuilder, $runtimeIncludeList)
    foreach ($path in $requiredFiles) {
        if (-not (Test-Path -LiteralPath $path -PathType Leaf)) { throw "Required file not found: $path" }
    }
    foreach ($path in (@($SourceRoot, $modStuffRoot) + ($addons | ForEach-Object { Join-Path $SourceRoot $_ }))) {
        if (-not (Test-Path -LiteralPath $path -PathType Container)) { throw "Required source folder not found: $path" }
    }

    New-Item -ItemType Directory -Path $OutputRoot -Force | Out-Null
    Get-ChildItem -LiteralPath $modStuffRoot -File | ForEach-Object {
        Copy-Item -LiteralPath $_.FullName -Destination $modRoot -Force
    }
    Write-Host "Local testing only: building unsigned PBOs. No signing key required." -ForegroundColor Yellow

    foreach ($addon in $addons) {
        try {
            $sourcePath = Join-Path $SourceRoot $addon
            $pboPath = Join-Path $OutputRoot "$addon.pbo"
            Write-Host "Packing $addon..." -ForegroundColor Cyan
            # Only remove this addon's stale output in the validated output directory.
            if (Test-Path -LiteralPath $pboPath) { Remove-Item -LiteralPath $pboPath -Force }
            Get-ChildItem -LiteralPath $OutputRoot -Filter "$addon.pbo.*.bisign" -File |
                ForEach-Object { Remove-Item -LiteralPath $_.FullName -Force }
            $buildOutput = & $addonBuilder $sourcePath $OutputRoot -clear "-include=$runtimeIncludeList" "-prefix=$addon" 2>&1
            $buildExitCode = $LASTEXITCODE
            $buildOutput | ForEach-Object { Write-Host $_ }
            if ($buildExitCode -ne 0 -or (($buildOutput | Out-String) -match '(\[ERROR\]|Build failed)')) {
                throw "Packing $addon failed (exit $buildExitCode)."
            }
            if (-not (Test-Path -LiteralPath $pboPath -PathType Leaf) -or (Get-Item -LiteralPath $pboPath).Length -eq 0) {
                throw "Expected nonempty PBO not found: $pboPath"
            }
            if ($addon -eq "TAEUnits") {
                Get-ChildItem -LiteralPath $OutputRoot -File |
                    Where-Object { $_.Name -eq "TAEMiningGuild.pbo" -or $_.Name -like "TAEMiningGuild.pbo.*.bisign" } |
                    ForEach-Object { Remove-Item -LiteralPath $_.FullName -Force }
            }
            Write-Host "Finished $addon" -ForegroundColor Green
        } catch {
            $failures.Add($_.Exception.Message)
            Write-Host "ERROR: $($_.Exception.Message)" -ForegroundColor Red
        }
    }
} catch {
    $failures.Add($_.Exception.Message)
    Write-Host "ERROR: $($_.Exception.Message)" -ForegroundColor Red
}

if ($failures.Count -gt 0) {
    Write-Host "BUILD FAILED: $($failures.Count) error(s)." -ForegroundColor Red
    $failures | ForEach-Object { Write-Host " - $_" -ForegroundColor Red }
    if (-not $NoPause) { pause }
    exit 1
}
Write-Host "Jimothy build complete. Output: $OutputRoot" -ForegroundColor Green
if (-not $NoPause) { pause }
exit 0
