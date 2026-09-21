# Aircraft Requisition

## Module choices

- **TAE Aircraft Requisition** (`TAE_Module_AircraftRequisition`): aircraft spawning and servicing in one module. Do not add a service module to the same pad.
- **TAE Aircraft Service Pad** (`TAE_Module_AircraftRepair`): standalone service station with identical requirements, but no aircraft list or spawn actions. The classname is unchanged.

Both use shared repair/service functions. Pad and aircraft locks prevent simultaneous jobs, including requests from overlapping stations.

## Eden setup

1. Place a terminal or other interaction object. Set its variable name to `TAE_AircraftTerminal`.
2. Place an invisible helipad named `TAE_AircraftPad`. Its position, elevation and heading define the aircraft spawn transform. Keep it level and test with the largest aircraft.
3. Place **TAE Aircraft Requisition** (`TAE_Module_AircraftRequisition`) from Modules. Set the terminal and pad variable-name fields to match. No synchronization lines or mission scripts are needed.
4. Leave Aircraft classnames as `[]` for all five TAE aircraft: V-wing, Delta-7, Kom'rk, Skycat and Z-98. A custom array replaces this list, for example:

```sqf
["TAE_VWing", "TAE_Z98_Headhunter"]
```

Only existing, public `Air` classes are accepted. Rejected entries are logged to the RPT. Dependencies supplying custom aircraft must be loaded by every machine.

For multiple terminals, use separate modules, uniquely named objects and non-overlapping pads. Place terminals outside the clearance radius so the requesting player does not block the pad. Default clearance radius is 30 metres; increase it for larger aircraft. The check covers people, vehicles and wrecks within 15 metres vertically of the pad, not arbitrary buildings, ceilings or terrain geometry. Test elevated pads in-game; the module does not supply a collision floor or deploy landing gear for you.

## Access and actions

Pilot qualification uses `ls_common_pilot = 1` in the player's unit config, not clothing, group leadership or the HUD Clan Leader option. TAE Pilot and Shyyyo qualify. Players must be alive, on foot and within four metres of the terminal to see its scroll actions. The server checks qualification and distance again.

Each authorized aircraft has a **Request** scroll action. Aircraft spawn empty. An occupied pad rejects spawning. Requests are serialized on the server; there is no aircraft deletion, return, resource cost or additional cooldown in this version.

All service actions accept exactly one living aircraft, including aircraft not in the spawn list. It must be empty, engine off and stationary.

- **Repair aircraft on pad:** restores hull and individual hitpoints in one-second ticks. Default full repair duration is 60 seconds, configurable in the module. Lesser damage finishes sooner.
- **Refuel aircraft on pad:** adds 1/30 of tank capacity every second, stopping at full. An empty tank takes 30 seconds.
- **Rearm aircraft on pad:** restores integral gun/countermeasure magazine groups and mounted pylon racks in stages over 60 seconds. Restores expended default reserve magazines, keeps current pylon choices and leaves empty pylons empty. Each magazine group or rack completes as one stage, not individual rounds.
- **Change aircraft pylons:** opens pylon/store dropdowns from the scroll action. Only compatible stores and Empty pylon are offered. One selected pylon takes 30 seconds; changes apply only when installation completes. Aircraft without pylons show an informational message instead.

Servicing stops if the aircraft is occupied, starts its engine, moves off the pad, is destroyed, loses server locality, or the module/pad is deleted. Completed stages remain; interrupted pylon installation leaves the old store untouched. The pad is unavailable for new requests while servicing. The requestor may leave the terminal after starting work. Status messages go to the requestor.

## Verification checklist

- Pilot and Shyyyo see actions; unqualified units do not.
- Custom classname array replaces defaults; unavailable classes are logged.
- Spawn heading/elevation and clearance are correct for every allowed aircraft.
- Two simultaneous requests produce only one aircraft.
- Occupants, nearby players and wrecks block a new spawn.
- Damaged empty aircraft repairs progressively; boarding interrupts it and releases the pad.
- Repair a previously client-owned aircraft on a dedicated server.
- Verify partial refueling, interruption, and stopping at full.
- Expend all cannon/countermeasure magazines and pylon ammunition, then verify staged rearming and unchanged pylon choices.
- Check compatible/empty pylon installation, interruption, stale aircraft selection, and removal of unused pylon weapons.
- Joining in progress and respawning preserve correct access.
- Deleting the module removes terminal actions.

Config compilation was checked locally. Runtime, dedicated-server and JIP tests remain required.
