# ================================
# The Ashen Enclave Addon Builder + Signer
# Hondo Version
# ================================

$addonBuilder = "C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\AddonBuilder\AddonBuilder.exe"
$dsSignFile   = "C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\DSSignFile\DSSignFile.exe"

$sourceRoot = "C:\Users\Shmavoc\OneDrive\Documents\Github\The-Ashen-Enclave"
$outputRoot = "C:\Program Files (x86)\Steam\steamapps\common\Arma 3\@The Ashen Enclave\Addons"
$keysRoot   = "C:\Program Files (x86)\Steam\steamapps\common\Arma 3\@The Ashen Enclave\Keys"

$privateKey = "C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\DSSignFile\TAEAUX.biprivatekey"
$publicKey  = "C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\DSSignFile\TAEAUX.bikey"

$addons = @(
    "TAECore",
    "TAEWeapons",
    "TAEGear",
    "TAEUnits",
    "TAEObjects",
    "TAEVehicles"
)

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
    exit
}

if (!(Test-Path $dsSignFile)) {
    Write-Host "ERROR: DSSignFile.exe not found at:" -ForegroundColor Red
    Write-Host $dsSignFile -ForegroundColor Red
    pause
    exit
}

# Check private key
if (!(Test-Path $privateKey)) {
    Write-Host "ERROR: Private key not found at:" -ForegroundColor Red
    Write-Host $privateKey -ForegroundColor Red
    pause
    exit
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
        Write-Host "SKIPPING: $addon folder not found at $sourcePath" -ForegroundColor Yellow
        continue
    }

    Write-Host "Packing $addon..." -ForegroundColor Cyan

    & $addonBuilder `
        "$sourcePath" `
        "$outputRoot" `
        -packonly `
        -clear `
        -prefix="$addon"

    if ($LASTEXITCODE -ne 0) {
        Write-Host "ERROR packing $addon. Exit code: $LASTEXITCODE" -ForegroundColor Red
        Write-Host ""
        continue
    }

    if (!(Test-Path $pboPath)) {
        Write-Host "ERROR: Expected PBO was not found:" -ForegroundColor Red
        Write-Host $pboPath -ForegroundColor Red
        Write-Host ""
        continue
    }

    Write-Host "Finished packing $addon" -ForegroundColor Green

    # Remove old bisign files for this PBO
    Get-ChildItem -Path $outputRoot -Filter "$addon.pbo.*.bisign" -ErrorAction SilentlyContinue | Remove-Item -Force

    Write-Host "Signing $addon.pbo with TAEAUX.biprivatekey..." -ForegroundColor Cyan

    & $dsSignFile `
        "$privateKey" `
        "$pboPath"

    if ($LASTEXITCODE -eq 0) {
        Write-Host "Signed $addon.pbo" -ForegroundColor Green
    } else {
        Write-Host "ERROR signing $addon.pbo. Exit code: $LASTEXITCODE" -ForegroundColor Red
    }

    Write-Host ""
}

Write-Host "Hondo build and signing complete." -ForegroundColor Green
pause