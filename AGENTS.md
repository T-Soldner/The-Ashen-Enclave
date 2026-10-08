# Asset Author Credits

- Before adding new custom armor or helmets, require the user to identify the
  texture author. If omitted, ask before finalizing the asset. Do not infer the
  artist from the owner, filename, clan, Git committer, or uploader, and do not
  silently use a generic team credit as a substitute.
- Confirm separate armor and helmet authors when they differ. Preserve existing
  credits on texture updates unless the user identifies a different artist.
- The user confirmed that all current TAE jetpack work is theirs. The established
  credit name is Edonn (also known as Soldner). Keep the current jetpack credit
  "Kandosii Mod Devs and Edonn" and preserve upstream model/framework attribution.
- Existing generic or conflicting credits require user confirmation, not guesses.

# Weapon Ammunition Coverage

- When adding a new player weapon, add its usable ammunition to the restricted
  arsenal. Automatic crate additions apply only to GL and AT ammunition, not
  ordinary primary or secondary weapon magazines.
- Preserve the tins-only ammo crate design for ordinary weapon ammunition.
  The tins supply primary and secondary weapon ammunition; loose magazines are
  not needed in that crate.
  Add new arsenal-approved GL ammunition to the demolition crate and AT ammunition
  to the anti-tank crate. Preserve
  its existing approved explosives and backpack rockets; do not automatically
  expand other crate ammunition categories without a user request.
- Check arsenal ammunition coverage as part of completing each new weapon
  addition, including alternate ammunition and underbarrel launchers. Also check
  demolition/anti-tank crate coverage when the addition includes GL or AT ammunition.

# Patch and Release Notes

- Write straightforward, player-friendly notes that curious users can understand.
  Lead with what was added, changed or fixed and its effect in game.
- Use plain language and short bullets. Avoid internal jargon, implementation
  detail, classnames and file paths unless necessary to explain a user action.
- Keep technical validation and deployment instructions separate from the
  player-facing changelog, and distinguish source changes from actual deployment.
