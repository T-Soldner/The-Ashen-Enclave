# ================================
# The Ashen Enclave Addon Builder + Signer
# Interactive Version (based on Hondo's build)
# ================================

$addonBuilder = "C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\AddonBuilder\AddonBuilder.exe"
$dsSignFile   = "C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\DSSignFile\DSSignFile.exe"

Write-Host "Enter the mod source folder containing TAEGear and Mod Stuff."
$sourceInput = (Read-Host "Mod source folder").Trim().Trim('"')
Write-Host "Enter the Addons folder where the PBOs should go."
Write-Host "Mod Stuff will be copied to its parent folder; Keys will be created there too."
$outputInput = (Read-Host "PBO output folder").Trim().Trim('"')
if ([string]::IsNullOrWhiteSpace($sourceInput) -or [string]::IsNullOrWhiteSpace($outputInput)) {
    Write-Host "ERROR: Both folders are required." -ForegroundColor Red
    pause
    exit 1
}
try {
    $sourceRoot = (Resolve-Path -LiteralPath $sourceInput -ErrorAction Stop).ProviderPath
    $outputRoot = $ExecutionContext.SessionState.Path.GetUnresolvedProviderPathFromPSPath($outputInput)
    $modRoot = Split-Path -Path $outputRoot -Parent
    if (!(Test-Path -LiteralPath $sourceRoot -PathType Container) -or
        [string]::IsNullOrWhiteSpace($modRoot) -or
        $outputRoot.Equals($sourceRoot, [StringComparison]::OrdinalIgnoreCase) -or
        $outputRoot.StartsWith($sourceRoot.TrimEnd('\') + '\', [StringComparison]::OrdinalIgnoreCase)) {
        throw "Use a valid source directory and a separate PBO output directory outside the source tree."
    }
    if ((Test-Path -LiteralPath $outputRoot) -and !(Test-Path -LiteralPath $outputRoot -PathType Container)) {
        throw "The PBO output path must be a directory."
    }
} catch {
    Write-Host "ERROR: $($_.Exception.Message)" -ForegroundColor Red
    pause
    exit 1
}
$keysRoot = Join-Path $modRoot "Keys"
$runtimeIncludeList = Join-Path $sourceRoot "TAE_build_include.lst"
$modStuffRoot = Join-Path $sourceRoot "Mod Stuff"

$privateKey = "C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\DSSignFile\TAEAUX.biprivatekey"
$publicKey  = "C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\DSSignFile\TAEAUX.bikey"

$addons = @(
    "TAECore",
    "TAEInsignias",
    "TAEMarkers",
    "TAEWeapons",
    "TAEGear",
    "TAEHUD",
    "TAEDrones",
    "adv_aceCPR",
    "TAEASTRS",
    "TAEJLTSCompat",
    "TAEUnits",
    "TAEObjects",
    "TAEVehicles"
)

$failures = @()

# Make sure output folders exist
if (!(Test-Path $outputRoot)) {
    New-Item -ItemType Directory -Path $outputRoot -Force | Out-Null
}

if (!(Test-Path $keysRoot)) {
    New-Item -ItemType Directory -Path $keysRoot -Force | Out-Null
}

if (!(Test-Path $modStuffRoot)) {
    Write-Host "ERROR: Mod Stuff folder not found at:" -ForegroundColor Red
    Write-Host $modStuffRoot -ForegroundColor Red
    pause
    exit 1
}

New-Item -ItemType Directory -Path $modRoot -Force | Out-Null
Get-ChildItem -LiteralPath $modStuffRoot -File | ForEach-Object {
    Copy-Item -LiteralPath $_.FullName -Destination $modRoot -Force
    Write-Host "Copied Mod Stuff\$($_.Name) to $modRoot" -ForegroundColor Green
}

# Check required tools
if (!(Test-Path $addonBuilder)) {
    Write-Host "ERROR: AddonBuilder.exe not found at:" -ForegroundColor Red
    Write-Host $addonBuilder -ForegroundColor Red
    pause
    exit 1
}

if (!(Test-Path $dsSignFile)) {
    Write-Host "ERROR: DSSignFile.exe not found at:" -ForegroundColor Red
    Write-Host $dsSignFile -ForegroundColor Red
    pause
    exit 1
}

# Check private key
if (!(Test-Path $privateKey)) {
    Write-Host "ERROR: Private key not found at:" -ForegroundColor Red
    Write-Host $privateKey -ForegroundColor Red
    pause
    exit 1
}

if (!(Test-Path $runtimeIncludeList)) {
    Write-Host "ERROR: TAE runtime asset include list not found at:" -ForegroundColor Red
    Write-Host $runtimeIncludeList -ForegroundColor Red
    pause
    exit 1
}

# Copy public .bikey into mod Keys folder if available
if (Test-Path $publicKey) {
    Copy-Item -Path $publicKey -Destination $keysRoot -Force
    Write-Host "Copied TAEAUX.bikey to mod Keys folder." -ForegroundColor Green
} else {
    Write-Host "WARNING: TAEAUX.bikey not found. Skipping public key copy." -ForegroundColor Yellow
    Write-Host $publicKey -ForegroundColor Yellow
}

Write-Host ""

foreach ($addon in $addons) {
    $sourcePath = Join-Path $sourceRoot $addon
    $pboPath    = Join-Path $outputRoot "$addon.pbo"

    if (!(Test-Path $sourcePath)) {
        $message = "Source folder not found for $addon at $sourcePath"
        $failures += $message
        Write-Host "ERROR: $message" -ForegroundColor Red
        continue
    }

    Write-Host "Packing $addon..." -ForegroundColor Cyan

    # Clear stale output first so a failed build cannot look successful.
    if (Test-Path $pboPath) {
        Remove-Item -Path $pboPath -Force
    }

    Get-ChildItem -Path $outputRoot -Filter "$addon.pbo.*.bisign" -ErrorAction SilentlyContinue | Remove-Item -Force

    $addonBuilderOutput = & $addonBuilder `
        "$sourcePath" `
        "$outputRoot" `
        -clear `
        -include="$runtimeIncludeList" `
        -prefix="$addon" 2>&1
    $addonBuilderExitCode = $LASTEXITCODE
    $addonBuilderOutput | ForEach-Object { Write-Host $_ }

    if (($addonBuilderExitCode -ne 0) -or (($addonBuilderOutput | Out-String) -match "(\[ERROR\]|Build failed)")) {
        $message = "Packing $addon failed. Exit code: $addonBuilderExitCode"
        $failures += $message
        Write-Host "ERROR: $message" -ForegroundColor Red
        Write-Host ""
        continue
    }

    if (!(Test-Path $pboPath)) {
        $message = "Expected PBO for $addon was not found at $pboPath"
        $failures += $message
        Write-Host "ERROR: $message" -ForegroundColor Red
        Write-Host $pboPath -ForegroundColor Red
        Write-Host ""
        continue
    }

    Write-Host "Finished packing $addon" -ForegroundColor Green

    Write-Host "Signing $addon.pbo with TAEAUX.biprivatekey..." -ForegroundColor Cyan

    & $dsSignFile `
        "$privateKey" `
        "$pboPath"

    if ($LASTEXITCODE -eq 0) {
        Write-Host "Signed $addon.pbo" -ForegroundColor Green
    } else {
        $message = "Signing $addon.pbo failed. Exit code: $LASTEXITCODE"
        $failures += $message
        Write-Host "ERROR: $message" -ForegroundColor Red
    }

    Write-Host ""
}

if ($failures.Count -gt 0) {
    Write-Host ""
    Write-Host "============================================================" -ForegroundColor Red
    Write-Host "BUILD FAILED: $($failures.Count) error(s) occurred." -ForegroundColor Red
    Write-Host "============================================================" -ForegroundColor Red
    foreach ($failure in $failures) {
        Write-Host " - $failure" -ForegroundColor Red
    }
    Write-Host "============================================================" -ForegroundColor Red
    pause
    exit 1
}

Write-Host "Interactive build and signing complete. No errors detected." -ForegroundColor Green
pause
exit 0
