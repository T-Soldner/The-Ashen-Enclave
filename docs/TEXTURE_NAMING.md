# Texture naming

Use ASCII letters, digits, and underscores, with a single dot before the extension. Keep the existing model identifier, part, and owner naming, then append the texture type:

- `MED_Armor_Galaxy_co.paa`: opaque diffuse/color.
- `Acklay_logo_ca.paa`: color with transparency.
- `_nohq`: high-quality normal map.
- `_as`: ambient shadow map.
- `_smdi`: optimized specular map.

Use the same suffix for PNG/TGA source exports and converted PAA files. Choose `_ca` when the image needs transparency, not merely because the source has an alpha channel. PSD working documents are not texture-converter inputs.

The suffix controls conversion behavior. Renaming a PAA does not reconvert it or change its compressed data. Update config, script, material, macro, and documentation references together when renaming files. Keep reference artwork outside packed addon folders.

Reference: https://community.bistudio.com/wiki/Arma:_Texture_Naming_Rules
