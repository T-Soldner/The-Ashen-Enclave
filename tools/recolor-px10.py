"""Deterministic PX-10 paint adjustment and supplied rook decal placement."""
import argparse
from pathlib import Path
import numpy as np
from PIL import Image, ImageFilter

parser = argparse.ArgumentParser()
parser.add_argument('--crane', required=True, type=Path)
args = parser.parse_args()
root = Path(__file__).resolve().parents[1]
source = root / 'Reference Textures/PX-10 CAV/Imperial'
destination = root / 'TAEVehicles/data/px10'
destination.mkdir(parents=True, exist_ok=True)
crane = Image.open(args.crane).convert('RGBA')
# The supplied crest is flat neutral grey/black against a weathered panel.
box = (560, 1340, 825, 1520)
crest = crane.crop(box)
data = np.asarray(crest)
neutral = (data[:, :, 0] == data[:, :, 1]) & (data[:, :, 1] == data[:, :, 2]) & (data[:, :, 0] <= 77)
# Keep only the crest, not isolated neutral weathering elsewhere in the crop.
connected = np.zeros(neutral.shape, dtype=np.uint8)
pending = [(130, 90)]
while pending:
    x, y = pending.pop()
    if not (0 <= y < neutral.shape[0] and 0 <= x < neutral.shape[1]):
        continue
    if connected[y, x] or not neutral[y, x]:
        continue
    connected[y, x] = 255
    pending.extend(((x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)))
mask = Image.fromarray(connected).filter(ImageFilter.MaxFilter(3))
crest.putalpha(mask)
logo = crest.crop(crest.getbbox()).transpose(Image.Transpose.ROTATE_90)
logo.thumbnail((128, 176), Image.Resampling.LANCZOS)
# Rotate the complete original decal patch losslessly, including edge pixels.
# This avoids cutting antialiasing away or recompositing a degraded crest.
patch = crane.crop(box)
rotated = patch.transpose(Image.Transpose.ROTATE_180)
assert np.array_equal(np.asarray(rotated), np.asarray(patch)[::-1, ::-1])
original = Image.open(source / 'px10crane_co.png').convert('RGBA')
crane.paste(original.crop(box), box[:2], mask)
crane.paste(rotated, box[:2], mask.transpose(Image.Transpose.ROTATE_180))
crane.save(destination / 'px10crane_co.png')
for name in ('px10cav_imp_co', 'px10fuel_imp_co', 'px10cavintback_co', 'px10cavintfront_co'):
    image = Image.open(source / (name + '.png')).convert('RGBA')
    pixels = np.asarray(image).astype(np.float32)
    rgb = pixels[:, :, :3]
    light = rgb.mean(axis=2)
    chroma = rgb.max(axis=2) - rgb.min(axis=2)
    paint = (chroma < 25) & (light > 45) & (light < 210)
    baseline = float(np.median(light[paint]))
    # Bring the representative grey to #4D4D4D without flattening baked detail.
    factor = 77 / baseline
    weight = np.clip((35 - chroma) / 10, 0, 1)
    weight *= np.clip((light - 20) / 25, 0, 1)
    adjusted = rgb * (1 + (factor - 1) * weight[:, :, None])
    pixels[:, :, :3] = np.clip(adjusted, 0, 255)
    result = Image.fromarray(np.rint(pixels).astype(np.uint8))
    if name == 'px10cav_imp_co':
        result = result.resize((8192, 8192), Image.Resampling.LANCZOS)
        # Side-strip UV locations matched to the supplied screenshots (21/14
        # homography inliers). Opposite rotations keep the crests upright.
        for center_x, angle in ((725, 90), (110, -90)):
            decal = logo.rotate(angle, expand=True)
            result.alpha_composite(decal, (center_x * 4 - decal.width // 2, 4900 - decal.height // 2))
    result.save(destination / (name + '.png'))
    print(f'{name}: grey baseline {baseline:.1f} -> 77; {image.size}')
print('Dozer patch rotated losslessly; hull decals use supplied crest at 8K.')
