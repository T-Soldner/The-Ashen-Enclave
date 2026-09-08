# Motion tracker

Select **Motion Tracker Range** in **Addon Options > The Ashen Enclave > Helmet HUD**:
50 m (default) or 100 m. This is a personal setting and changes the detection radius immediately.
Select **Motion tracker** under **Auxiliary Display** in the same Addon Options section. The selector offers Hidden, Map, Camera, and Motion tracker; there is no display-cycle keybind.

The tracker follows the installed TCP reference's default detection rules, using original TAE code and vanilla icons:

- Living, visible infantry and air/ground vehicles within the selected radius.
- Movement above 4.5 km/h, or an unsuppressed shot within the last 0.5 seconds.
- Slow/stationary contacts disappear unless firing, except living squad members, who remain visible within range.
- Suppression uses muzzle attachment audibleFire coefficients below 1, or ammunition audibleFire below 5.5 for integral suppression.
- Knowledge above 0.1 enables side identification: green friendly, red hostile; otherwise amber unknown. Squad members use compass colors: light blue, or red for medics.
- No line-of-sight requirement. Hidden/dead objects and the player's vehicle are excluded.
- Camera-relative bearings and a rotating cardinal cross. Rings mark 25/50 m in 50 m mode and 25/50/75/100 m in 100 m mode, with matching cross and ring thickness.
- A square drawing area holds the circular outline without the rectangular auxiliary backdrop. Resolution-scaled dots and touching chevrons show horizontal movement; stationary contacts remain dots. Vehicles use larger dots.
- Candidate scans run at 10 Hz; rendering uses the cached candidates for smooth rotation. Local firing handlers are removed when contacts leave range or radar closes. No new network messages are sent.

Remote gunfire events are subject to Arma's camera-range event delivery. Movement detection does not depend on gunfire events. A shot in the brief interval before a newly arrived contact's first scan will not be captured.

## In-game verification

1. Switch through all auxiliary modes in Addon Options repeatedly. Verify only one panel is visible and radar returns without stale contacts. The camera-target shortcut should work only with Camera selected.
2. Test 50 m and 100 m with contacts just inside/outside each boundary; change range while radar is open.
3. Walk slowly, run, stop, fire unsuppressed, and fire suppressed weapons on a second client and AI. Check 0.5-second shot decay, muzzle brakes, and integral suppression.
4. Check unknown contacts before identification and friendly/hostile colors afterward. Check a moving vehicle and exclusion of the player's own vehicle.
5. Rotate and use freelook; verify ahead/right/behind/left placement and circular rings at 16:9, ultrawide, and different UI scales.
6. Remove the helmet, die/respawn, and enter/exit Arsenal. Confirm radar and its firing handlers clean up and restart normally.

Config parsing and static checks do not replace these runtime/multiplayer checks.
