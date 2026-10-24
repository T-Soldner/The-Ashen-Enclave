param([Parameter(Mandatory=$true)][string]$Source, [Parameter(Mandatory=$true)][string]$Destination)
Add-Type -AssemblyName System.Drawing
Add-Type -ReferencedAssemblies System.Drawing -TypeDefinition @'
using System;
using System.Drawing;
public static class EliteAwingPaint {
    public static void Recolor(string source, string destination) {
        using (var image = new Bitmap(source)) {
            for (int y = 0; y < image.Height; y++) {
                for (int x = 0; x < image.Width; x++) {
                    Color c = image.GetPixel(x, y);
                    double r = c.R, g = c.G, b = c.B;
                    if (b > r * 1.2 && b > g * 1.02) {
                        image.SetPixel(x, y, Color.FromArgb(c.A, c.B, c.R, c.R));
                    } else {
                        double high = Math.Max(r, Math.Max(g, b));
                        double low = Math.Min(r, Math.Min(g, b));
                        // Keep gold emblems, dark hardware and saturated markings intact.
                        double weight = Math.Min(1, Math.Max(0, (high - 75) / 40));
                        weight *= Math.Min(1, Math.Max(0, (0.28 - (high - low) / Math.Max(high, 1)) / 0.12));
                        double scale = 1 - 0.8 * weight;
                        image.SetPixel(x, y, Color.FromArgb(c.A, (int)(r * scale), (int)(g * scale), (int)(b * scale)));
                    }
                }
            }
            System.IO.Directory.CreateDirectory(System.IO.Path.GetDirectoryName(destination));
            image.Save(destination, System.Drawing.Imaging.ImageFormat.Png);
        }
    }
}
'@
[EliteAwingPaint]::Recolor($Source, $Destination)
