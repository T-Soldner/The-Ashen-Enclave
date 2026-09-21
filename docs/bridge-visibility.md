# Bridge Visibility Module

Place `TAE Bridge Visibility` in Eden's Modules list (category: other/no category).
Save it with the ship and bridge layer in the composition. No separate trigger, mission
SQF files or object init calls are required for visibility.

Default references:

- Exterior object variable: `TAE_Acclamator_Exterior`
- Interior Eden layer: `TAE_Bridge_Interior` (includes sublayers)
- Zone half-width and half-length: 30 metres each (60 by 60 metres total)
- Vertical half-height: 8 metres above and below the module centre
- Excluded variables: `BridgeShield,Bridge_Close_Ray,Bridge_Open_Ray`

Adjust names and all three half-dimensions in the module attributes. Place the
module at the centre of the usable bridge volume, including its elevation, and
rotate its heading to align the rectangular zone. Pitch and roll are not used.
The old `TAE_Bridge_Zone` trigger is no longer read and can be removed. Existing
modules must be repositioned from any former placeholder location into the bridge.
Use unique names/layers for each bridge. Do not overlap modules' object sets.

Dedicated server and headless clients never hide objects. Player clients hide the
ship inside the zone and hide interior scenery outside. Zeus display shows the
original visibility. Joining clients receive the server's references. Respawning
players are checked automatically. Removing the module restores the
client's original visibility states.

## Limitations

- Single-player/listen-server hosts switch visibility too. Their rendering and
  server simulation share a world, so hiding scenery also affects server-side
  collision. Dedicated servers and headless clients remain unchanged.
- Local hiding also affects collision. Use independent collision-only support
  geometry that is not in the interior layer, especially for client-local AI.
- AI and players are never hidden. Outside observers might see bridge occupants.
- Logic objects, including scripted light emitters, are not toggled. Existing
  light init scripts may need separate integration to avoid light leaking outside.
- The ray shield remains controlled by its independent global actions.
- The whole ship is hidden inside, including hull visible through bridge windows.
- This is a stationary composition feature, not moving-ship support.
- Avoid other visibility scripts controlling these same scenery objects.

## Multiplayer Acceptance Checks

1. Rebuild TAEObjects and restart server and clients with the updated addon.
2. One player inside and one outside: confirm opposite scenery visibility.
3. Walk across the entrance and verify floors, stairs and zone height.
4. Join in progress, respawn, and enter/exit Zeus; check visibility refreshes.
5. Test server AI and player-group AI for support-floor collision.
6. Activate/deactivate the ray shield from both sides; verify independence.
7. Delete the module and confirm original scenery visibility returns.

Config conversion passed during development. These runtime checks still require
Arma multiplayer testing; compilation does not verify SQF behavior or collision.
