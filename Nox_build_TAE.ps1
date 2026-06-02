# ================================
# The Ashen Enclave Addon Builder + Signer
# Nox's Version
# ================================

[CmdletBinding()]
param(
    [string]$SourceRoot = "C:\Users\chase\Documents\GitHub\The-Ashen-Enclave",
    [string]$ArmaRoot = "C:\Program Files (x86)\Steam\steamapps\common\Arma 3",
    [string]$ArmaToolsRoot = "C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools",
    [string]$ModFolderName = "@The Ashen Enclave",
    [string]$KeyName = "AshenEnclave",
    [switch]$NoPause
)

$ErrorActionPreference = "Stop"

$addonBuilder = Join-Path $ArmaToolsRoot "AddonBuilder\AddonBuilder.exe"
$dsSignFile = Join-Path $ArmaToolsRoot "DSSignFile\DSSignFile.exe"

$outputRoot = Join-Path $ArmaRoot "$ModFolderName\Addons"
$keysRoot = Join-Path $ArmaRoot "$ModFolderName\Keys"

$privateKey = Join-Path $ArmaToolsRoot "DSSignFile\$KeyName.biprivatekey"
$publicKey = Join-Path $ArmaToolsRoot "DSSignFile\$KeyName.bikey"

$addons = @(
    "TAECore",
    "TAEInsignias",
    "TAEWeapons",
    "TAEGear",
    "TAEUnits",
    "TAEObjects",
    "TAEVehicles"
)

$failures = New-Object System.Collections.Generic.List[string]

function Stop-Build {
    param(
        [Parameter(Mandatory = $true)]
        [string]$Message,

        [int]$ExitCode = 1
    )

    Write-Host "ERROR: $Message" -ForegroundColor Red
    if (-not $NoPause) {
        pause
    }
    exit $ExitCode
}

function Test-RequiredPath {
    param(
        [Parameter(Mandatory = $true)]
        [string]$Path,

        [Parameter(Mandatory = $true)]
        [string]$Description
    )

    if (-not (Test-Path -LiteralPath $Path)) {
        Stop-Build "$Description not found at: $Path"
    }
}

function Invoke-NativeTool {
    param(
        [Parameter(Mandatory = $true)]
        [string]$FilePath,

        [Parameter(Mandatory = $true)]
        [string[]]$Arguments
    )

    $previousErrorActionPreference = $ErrorActionPreference
    $ErrorActionPreference = "Continue"

    try {
        $output = & $FilePath @Arguments 2>&1
        $exitCode = $LASTEXITCODE
    } finally {
        $ErrorActionPreference = $previousErrorActionPreference
    }

    [PSCustomObject]@{
        ExitCode = $exitCode
        Output = $output
    }
}

try {
    $sourceRoot = (Resolve-Path -LiteralPath $SourceRoot).Path
} catch {
    Stop-Build "Source root not found at: $SourceRoot"
}

Write-Host "============================================================" -ForegroundColor DarkGray
Write-Host "The Ashen Enclave - Nox's Build" -ForegroundColor Cyan
Write-Host "Source: $sourceRoot" -ForegroundColor Gray
Write-Host "Output: $outputRoot" -ForegroundColor Gray
Write-Host "Key: $KeyName" -ForegroundColor Gray
Write-Host "============================================================" -ForegroundColor DarkGray
Write-Host ""

Test-RequiredPath -Path $addonBuilder -Description "AddonBuilder.exe"
Test-RequiredPath -Path $dsSignFile -Description "DSSignFile.exe"
Test-RequiredPath -Path $privateKey -Description "Private key"

New-Item -ItemType Directory -Path $outputRoot -Force | Out-Null
New-Item -ItemType Directory -Path $keysRoot -Force | Out-Null

if (Test-Path -LiteralPath $publicKey) {
    Copy-Item -LiteralPath $publicKey -Destination $keysRoot -Force
    Write-Host "Copied $KeyName.bikey to mod Keys folder." -ForegroundColor Green
} else {
    Write-Host "WARNING: $KeyName.bikey not found. Skipping public key copy." -ForegroundColor Yellow
    Write-Host $publicKey -ForegroundColor Yellow
}

Write-Host ""

foreach ($addon in $addons) {
    $sourcePath = Join-Path $sourceRoot $addon
    $pboPath = Join-Path $outputRoot "$addon.pbo"

    if (-not (Test-Path -LiteralPath $sourcePath)) {
        $message = "Source folder not found for $addon at $sourcePath"
        $failures.Add($message)
        Write-Host "ERROR: $message" -ForegroundColor Red
        Write-Host ""
        continue
    }

    Write-Host "Packing $addon..." -ForegroundColor Cyan

    # Clear stale output first so a failed build cannot look successful.
    if (Test-Path -LiteralPath $pboPath) {
        Remove-Item -LiteralPath $pboPath -Force
    }

    Get-ChildItem -LiteralPath $outputRoot -Filter "$addon.pbo.*.bisign" -ErrorAction SilentlyContinue |
        Remove-Item -Force

    $addonBuilderResult = Invoke-NativeTool -FilePath $addonBuilder -Arguments @(
        $sourcePath,
        $outputRoot,
        "-packonly",
        "-clear",
        "-prefix=$addon"
    )

    $addonBuilderOutput = $addonBuilderResult.Output
    $addonBuilderExitCode = $addonBuilderResult.ExitCode
    $addonBuilderOutput | ForEach-Object { Write-Host $_ }

    if (($addonBuilderExitCode -ne 0) -or (($addonBuilderOutput | Out-String) -match "(\[ERROR\]|Build failed)")) {
        $message = "Packing $addon failed. Exit code: $addonBuilderExitCode"
        $failures.Add($message)
        Write-Host "ERROR: $message" -ForegroundColor Red
        Write-Host ""
        continue
    }

    if (-not (Test-Path -LiteralPath $pboPath)) {
        $message = "Expected PBO for $addon was not found at $pboPath"
        $failures.Add($message)
        Write-Host "ERROR: $message" -ForegroundColor Red
        Write-Host ""
        continue
    }

    Write-Host "Finished packing $addon" -ForegroundColor Green
    Write-Host "Signing $addon.pbo with $KeyName.biprivatekey..." -ForegroundColor Cyan

    $signResult = Invoke-NativeTool -FilePath $dsSignFile -Arguments @($privateKey, $pboPath)
    $signExitCode = $signResult.ExitCode
    $signResult.Output | ForEach-Object { Write-Host $_ }

    if ($signExitCode -eq 0) {
        Write-Host "Signed $addon.pbo" -ForegroundColor Green
    } else {
        $message = "Signing $addon.pbo failed. Exit code: $signExitCode"
        $failures.Add($message)
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

    if (-not $NoPause) {
        pause
    }
    exit 1
}

Write-Host "Nox's build and signing complete. No errors detected." -ForegroundColor Green

if (-not $NoPause) {
    pause
}
exit 0
