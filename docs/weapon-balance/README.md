# Arsenal and Quartermaster Balance Planning

Status: Balance review closed; current balance accepted by the user. Future reviews
are driven by player feedback. Approved functionality/availability changes remain
subject to in-game verification. Last updated: 2026-09-10.

## Authority and guardrails

The user requested that this research be retained for future planning. No balance,
arsenal, QM, dependency, or gameplay changes are authorized by this plan alone. Do not
implement a recommendation without explicit approval. Custom TAE weapon variants
are a possible future direction, not an approved project. Work one decision at a
time. Do not commit, push, merge, or release these notes unless requested.

Scope means weapons available in the TAE arsenal, grouped by the QM, including
third-party weapons. It does not mean only classes defined in TAEWeapons.
Sidearms are intentionally outside the current QM point tracking.

## Retained evidence

- [Original review and tables](2026-09-09-review.md).
- [Static extracted data](2026-09-09-static-audit.json).
- [Sniper testing and capacity/optics planning](sniper-planning.md).
- [LFP PBO Manager extraction follow-up](lfp-extraction-followup.md): capacity and
  cadence now recovered; supersedes the original audit's LFP extraction limitation.
- `snapshots/`: copies of the TAE arsenal, QM and weapon override sources used
  to identify the current selection. These are reference copies, not runtime code.

The JSON is a preliminary file-based extraction, NOT an engine-merged config
export. Null means unresolved, not zero. It includes auxiliary entries and parent
fire modes that may not be active. Magazine wells, addon load order, scripted
ammo changes and runtime modifiers were not comprehensively resolved. Consult the
review's manual findings before using a raw value. Never generate balance patches
automatically from this JSON.

The review/JSON retain original local paths to temporary decoded third-party
configs. Those links may expire and are provenance hints, not durable evidence
archives. Only the derived report/data and TAE snapshots are retained here; vendor
models, textures and full extracted addons are not redistributed. Workshop files
may update in place. This snapshot used installed LS Stable, not Public Testing,
before the anticipated September 14 weapon rebalance. Revalidate before decisions.

This directory is outside all addon source directories and Mod Stuff. The current
three build scripts enumerate addon folders explicitly, so these documents are
not packed into the mod or copied to its distribution folder.

## Phased plan

### 1. Agree on roles and allowed capabilities

Deliverable: an approved role matrix, before changing any stats.

- Preserve the current nine-point maximum and specialization costs unless the
  user chooses otherwise. Do not assume every paid role must beat Rifleman in DPS.
- Describe each role's intended advantage and disadvantage: precision, armor
  penetration, close-range burst, suppression, sustained fire, or explosive utility.
- Decide explicitly whether Rifleman may use EE-2 high-power explosives and
  Westar-35S underbarrel scatter ammunition. Availability is not proof of intent.
- Clarify overlapping weapon families, both DLT-19 providers, FWMB variants and
  LFP Westar carbine assignments. Keep sidearm omissions separate from real gaps.
- Decide whether adjustments should primarily address role overlap, extreme
  outliers, underperformers, or all three. Proposed default: outliers first.

Gate: user approves role boundaries. No numerical targets yet.

### 2. Establish the actual loaded baseline

Deliverable: dated in-game config export and compatibility map.

- Record Arma build, full loaded preset/addon versions, ACE medical/ballistics
  settings, stamina modifiers and relevant KND feature settings.
- Export resolved weapon -> active muzzle -> player fire mode -> compatible
  magazine (including wells) -> ammo -> submunition chains from configFile.
- Intersect compatibility with actual arsenal entries; separately include scripted
  substitutions and CBA disposable-launcher handling.
- Capture hit, caliber, explosive/indirect damage, penetration submunitions,
  projectile counts/spread, speed overrides, typicalSpeed, drag, recoil, dispersion,
  weapon/magazine mass, reload time, capacity and script-driven firing behavior.
- Resolve protected LFP weapons through the running game's config rather than
  assuming they are weak, strong, missing, or identical to another provider.
- Recheck after LS's planned update; keep before/after snapshots separately.

Gate: evidence supports the shortlisted comparisons; unresolved entries remain
explicitly unranked. Do not treat nominal hit * RPM as actual DPS.

### 3. Run controlled comparison tests

Deliverable: repeatable test results with conditions attached to every result.

- Use identical shooter skill, stance, attachments, target class, armor and ACE
  settings. Compare the same hit location and reset the target between trials.
- Suggested infantry ranges: 25, 100, 300 and 600 m where appropriate to the role.
  Include unarmored and the armored enemies actually used in operations.
- Begin with ten controlled trials per shortlisted weapon/condition; expand where
  results vary. Record failed shots and spread, not only successful hits.
- Separate single-hit effect, incapacitation, death, practical engagement time,
  recoil recovery, reload downtime, ammunition expenditure and sustained accuracy.
- For shotguns, measure pattern and hit reliability at multiple short ranges.
- For explosives, measure splash and friendly-fire risk as well as direct impact.
- For AT/AA and CSW, use representative vehicles, hit aspects, locking conditions,
  deployment time, crew requirements and carried-ammo burden. Separate test pass.
- Include human handling tests with the group's real stamina settings; weight may
  be a much weaker drawback for players than it is for AI.

Gate: a repeatable gameplay problem, not just an impressive config number.

### 4. Approve one small proposal

Deliverable: one proposed change with alternatives, expected effect and rollback.

Options, from least invasive: clarify QM policy; restrict a particular ammo type;
adjust a specific TAE-owned variant; introduce a new TAE-derived variant if approved.
Avoid global changes to another mod's shared ammo or base weapon classes.

If custom variants are chosen later, prefer inheriting the vendor model/animations
and overriding only necessary properties. Check licensing/dependencies, all muzzles,
magazine wells, scripts that require exact classnames, UI names, arsenal entries,
QM wording and saved loadout migration. Do not copy vendor assets by default.
Existing TAEWeapons may suffice; a new PBO is not presumed necessary.

Gate: explicit approval of the precise implementation and scope.

### 5. Prototype, compare and release only when approved

- Keep original and candidate available in a private test configuration.
- Repeat the same tests, plus multiplayer/JIP, AI, resupply, saved loadouts and
  script compatibility checks. Verify no unintended changes to hostile weapons.
- Accept only if the intended role improves without removing its meaningful cost
  or creating a new dominant choice. Agree on acceptance criteria before coding.
- Keep a reversible commit and document measured before/after behavior.
- Release only on request, following the existing dev/main and version workflow.

## Priority queue (not approved changes)

The historical queue below is closed by the user's acceptance of overall balance
on 2026-09-10. Unfinished balance tests are no longer required. Reopen a specific
item only in response to new feedback; retain the table as review history.

| Priority | Question | Evidence still needed |
|---|---|---|
| 1 | EE-2 moved to Grenadier; Westar scatter cell removed from restricted arsenal | Approved and implemented locally; in-game verification pending |
| 2 | Sniper review, including NT-242 | Closed: user satisfied with practical testing; leave snipers unchanged |
| 3 | Bowcaster normal and heavy cells | Accepted for now: user reports no issues; leave unchanged |
| 4 | Rancor fast-fire mode | Accepted: user prefers current behavior; leave unchanged |
| 5 | SX-21 CQC review | Accepted after user testing; leave unchanged |
| 6 | HPB-14 visibility and practical testing | Inheritance fix implemented; repack/restart and test. DW-32S and DC-15LE accepted unchanged |
| 7 | Are free rifles undermining paid role identity? | A295/EE-3/E-22/DC-15A comparisons under identical conditions |
| 8 | What about LFP, launchers, CSW and drones? | Complete runtime data and separate role-appropriate trials |

## Decision log

Latest decision (2026-09-10): accept all current weapon balance and wait for player
reports of underpowered options. Remove the TAE HPB-14 secondary muzzle and remove
its scatter cell from the restricted arsenal. Retain legacy scatter classes for
existing loadout references; do not modify MokTech's original weapon or ammunition.

| Date | Decision | State |
|---|---|---|
| 2026-09-09 | Preserve audit and plan; make no gameplay changes | Approved |
| 2026-09-09 | Possible future custom TAE weapons | Discussed only; deferred |
| 2026-09-09 | Proposed test priorities and phased process above | Draft; not gameplay authorization |
| 2026-09-09 | Remove only ls_magazine_westar35s_scatter from restricted arsenal; keep normal Westar ammunition and weapons | Approved; implemented locally |
| 2026-09-09 | Move the whole EE-2 from Rifleman to Grenadier (3 points) in QM; retain weapon/ammo in arsenal | Approved; implemented locally |
| 2026-09-09 | Accept current sniper balance after user testing; leave all snipers unchanged | Review closed; no sniper changes |
| 2026-09-10 | Accept Bowcaster as-is for now; user reports no issues | No weapon or ammunition changes |
| 2026-09-10 | Accept Rancor, including fast-fire mode, as-is | No weapon or ammunition changes |
| 2026-09-10 | Accept SX-21 after user testing; user reports no issues | No weapon or ammunition changes |
| 2026-09-10 | Accept DW-32S accuracy niche and DC-15LE player preference | Leave both unchanged; user's DW-23 reference interpreted as DW-32S |
| 2026-09-10 | Preserve MokTech HPB parent inheritance to address missing arsenal weapon | Approved; source fix implemented, CfgConvert passed; live verification pending |

The dated audit and snapshots remain unchanged as the pre-decision baseline.
The Westar change does not delete its class or strip existing inventories, and
does not globally disable the scatter muzzle or other compatible ammunition.
The EE-2 change is QM policy, not automatic per-player arsenal enforcement.

Sniper review is closed: the user is satisfied after practical testing and wants
the snipers left unchanged. Earlier sniper concerns in the dated audit are not
active change proposals. Bowcaster is also accepted as-is for now, including its
current ammunition availability. Rancor is accepted unchanged, including fast-fire
mode. SX-21 is accepted unchanged after user testing. DW-32S and DC-15LE are
accepted unchanged based on user feedback.

## Next test sequence

Superseded by overall balance acceptance on 2026-09-10. Only HPB functionality
checks and approved availability/QM release checks remain relevant: after repacking
and restarting, verify arsenal visibility, standard-cell loading/firing/reloading,
absence of the secondary mode and scatter cell from the restricted arsenal, and
absence of the previous parent-class removal warning. No full balance pass is pending.

1. Repack and restart Arma; confirm tae_HPB14 appears in the restricted arsenal
   as HPB-14 Heavy Blaster Rifle (Reduced Power). Check the new RPT for the old
   HPB parent-class removal warning. Verify both reduced-power cells, loading,
   firing both muzzles and reloading. Damage settings were not changed by the fix.
2. Test HPB-14 effectiveness against the group's usual infantry alongside an
   accepted heavy weapon such as DC-15LE or Rancor. Keep range, target armor and
   hit location comparable; assess accuracy, ammo consumption and handling as
   well as shots to incapacitate. No automatic damage adjustment is planned.
3. Review Rifleman standouts A295, EE-3, E-22 and DC-15A against one another, then
   consider whether any makes paid roles redundant. Do not reopen accepted weapons
   merely because raw config values differ.
4. Separately review launchers, CSW and drones using relevant targets and practical
   deployment tests. Resolve remaining LFP data only where needed for those reviews.
5. Before release, verify EE-2's Grenadier QM placement and the Westar scatter-cell
   removal in game. Commit, push and merge only when explicitly requested.

No numerical balance changes are authorized.
Update this file when a decision is made so later work can resume from the same
record. Do not assume chat memory alone retains this plan.
