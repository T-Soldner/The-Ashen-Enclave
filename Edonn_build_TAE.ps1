# ================================
# The Ashen Enclave Addon Builder + Signer
# Edonn Version
# ================================

$addonBuilder = "C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\AddonBuilder\AddonBuilder.exe"
$dsSignFile   = "C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\DSSignFile\DSSignFile.exe"

$sourceRoot = "C:\Users\tomso\Github\The-Ashen-Enclave"
$outputRoot = "C:\Program Files (x86)\Steam\steamapps\common\Arma 3\@The Ashen Enclave\Addons"
$keysRoot   = "C:\Program Files (x86)\Steam\steamapps\common\Arma 3\@The Ashen Enclave\Keys"

$privateKey = "C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\DSSignFile\Soldner.biprivatekey"
$publicKey  = "C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\DSSignFile\Soldner.bikey"

$addons = @(
    "TAECore",
    "TAEInsignias",
    "TAEWeapons",
    "TAEGear",
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

# Copy public .bikey into mod Keys folder if available
if (Test-Path $publicKey) {
    Copy-Item -Path $publicKey -Destination $keysRoot -Force
    Write-Host "Copied Soldner.bikey to mod Keys folder." -ForegroundColor Green
} else {
    Write-Host "WARNING: Soldner.bikey not found. Skipping public key copy." -ForegroundColor Yellow
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
        -packonly `
        -clear `
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

    Write-Host "Signing $addon.pbo with Soldner.biprivatekey..." -ForegroundColor Cyan

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

Write-Host "Edonn build and signing complete. No errors detected." -ForegroundColor Green
pause
exit 0
