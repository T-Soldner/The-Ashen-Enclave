# Changelog

## 1.3.4.2 - November 4, 2026

### Mod
- Added Samantha's Nite Owl helmet, Clan Rook Nite Owl armor and Keira's custom
  armor to the arsenal, with wearable options and Keira's texture credits.
- Updated Keira's helmet textures and corrected capitalization in her gear menus.
- Updated Galaxy's armor, bracers and helmet textures.
- Fixed terminal spawning height: most vehicles spawn one metre above the
  terminal's level; Kom'rk variants spawn two metres above it.
- Fixed Kom'rk cargo-bay access and crate handling. Fit the optional cargo bay,
  open it, then load crates using the terminal; crates no longer spawn outside
  the vehicle by default.

### Separate Attendance Service
- Added server attendance collection, Discord applications, clan applications,
  training records, promotions and Google Sheets synchronization.
- Added staff-reviewed Steam account detection and manual clan transfers.
- Simplified commands into member, staff and maintenance groups, with private help.
- Added opt-in bot-spam alerts after four consecutive unexcused missed operations.
  Alerts never automatically remove roles or clan membership.
- Added background task management and verified weekly database backups.

### Deployment Notes
These are source changes, not confirmation of a Workshop upload or server update.
The attendance service and its server-only addon deploy separately from the main
mod. Existing data and credentials must be preserved. Backup task installation
requires the Windows account password; it remains pending on the live server.
