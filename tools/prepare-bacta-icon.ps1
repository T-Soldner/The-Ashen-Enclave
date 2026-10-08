param([Parameter(Mandatory=$true)][string]$Source)
Add-Type -AssemblyName System.Drawing
$root = Split-Path $PSScriptRoot -Parent
$sourceDir = Join-Path $root 'Source Textures\Medical'
$targetDir = Join-Path $root 'TAEObjects\data\medical'
New-Item -ItemType Directory -Force $sourceDir, $targetDir | Out-Null
$image = [Drawing.Image]::FromFile($Source)
$bitmap = New-Object Drawing.Bitmap 512,512
$graphics = [Drawing.Graphics]::FromImage($bitmap)
try {
    $graphics.InterpolationMode = [Drawing.Drawing2D.InterpolationMode]::HighQualityBicubic
    $graphics.DrawImage($image, 0, 0, 512, 512)
    $png = Join-Path $sourceDir 'bacta_spray_box_icon_co.png'
    $bitmap.Save($png, [Drawing.Imaging.ImageFormat]::Png)
} finally {
    $graphics.Dispose()
    $bitmap.Dispose()
    $image.Dispose()
}
& 'D:\SteamLibrary\steamapps\common\Arma 3 Tools\TexView2\Pal2PacE.exe' $png (Join-Path $targetDir 'bacta_spray_box_icon_co.paa')
if ($LASTEXITCODE -ne 0) {throw 'Icon conversion failed'}
