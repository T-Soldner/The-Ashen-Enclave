param(
    [Parameter(Mandatory = $true)][string]$Source,
    [string]$Pal2Pac = 'D:\SteamLibrary\steamapps\common\Arma 3 Tools\TexView2\Pal2PacE.exe'
)
$ErrorActionPreference = 'Stop'
Add-Type -AssemblyName System.Drawing
$output = Join-Path $PSScriptRoot '..\TAEObjects\data\posters'
[IO.Directory]::CreateDirectory($output) | Out-Null
$inputImage = [Drawing.Image]::FromFile((Resolve-Path -LiteralPath $Source))
$canvas = New-Object Drawing.Bitmap 2048, 2048
$graphics = [Drawing.Graphics]::FromImage($canvas)
try {
    $graphics.Clear([Drawing.Color]::Transparent)
    $graphics.InterpolationMode = [Drawing.Drawing2D.InterpolationMode]::HighQualityBicubic
    $scale = [Math]::Min(2048 / $inputImage.Width, 2048 / $inputImage.Height)
    $width = [int][Math]::Round($inputImage.Width * $scale)
    $height = [int][Math]::Round($inputImage.Height * $scale)
    $graphics.DrawImage($inputImage, [int]((2048-$width)/2), [int]((2048-$height)/2), $width, $height)
    $png = Join-Path $output 'hang_in_there_ca.png'
    $canvas.Save($png, [Drawing.Imaging.ImageFormat]::Png)
} finally {
    $graphics.Dispose()
    $canvas.Dispose()
    $inputImage.Dispose()
}
& $Pal2Pac $png (Join-Path $output 'hang_in_there_ca.paa')
if ($LASTEXITCODE -ne 0) { throw 'Poster PAA conversion failed.' }
