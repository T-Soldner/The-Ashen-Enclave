"""Recolor installed Republic no-insignia PK-V5 paint without resizing."""
from pathlib import Path
import numpy as np
from PIL import Image

root = Path(__file__).resolve().parents[1]
source = root / 'docs/local-assets/pkv5-original-png'
target = root / 'Source Textures/TAEVehicles/pkv5'
target.mkdir(parents=True, exist_ok=True)
reference = np.asarray(Image.open(source / 'vwing-gold-reference.png').convert('RGB')).astype(np.float32)
r, g, b = reference[..., 0], reference[..., 1], reference[..., 2]
gold = np.median(reference[(r > g * 1.03) & (g > b * 1.3) & (r > 80) & (g > 60)], axis=0)
gold /= gold.max()
for name in ('chassis', 'turret_cannon', 'turret_multi', 'turret_mlrs', 'turret_mortar', 'turret_aa'):
    original = Image.open(source / f'{name}_co.png').convert('RGBA')
    pixels = np.asarray(original).copy()
    rgb = pixels[..., :3].astype(np.float32)
    r, g, b = rgb[..., 0], rgb[..., 1], rgb[..., 2]
    # Separate red painted areas from brown seams and hardware.
    red = (r > 50) & (r > g * 1.4) & (r > b * 1.4) & (np.abs(g - b) < r * 0.18)
    rgb[red] = r[red, None] * gold
    chroma = np.max(rgb, axis=2) - np.min(rgb, axis=2)
    light = rgb.mean(axis=2)
    neutral = np.clip((35 - chroma) / 15, 0, 1) * np.clip((light - 30) / 35, 0, 1)
    rgb *= (1 - 0.57 * neutral[..., None])
    pixels[..., :3] = np.rint(np.clip(rgb, 0, 255)).astype(np.uint8)
    result = Image.fromarray(pixels)
    assert result.size == original.size
    assert np.array_equal(pixels[..., 3], np.asarray(original)[..., 3])
    assert red.any()
    result.save(target / f'{name}_co.png')
    print(f'{name}: {original.size}, {red.sum()} gold pixels')
