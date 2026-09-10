# Sniper Capacity, Optics and Follow-Up Planning

Status: discussion only; no numerical changes approved. Recorded 2026-09-09.

## Player test evidence

The user reports comparable practical results across the tested sniper weapons at
400 m: head and torso hits killed in one shot; arm and leg hits took several
rounds. Exact target/armor, weapon subset, optics, ACE settings and trial counts
were not recorded. Treat this as useful player evidence, not a controlled proof
that all sniper ammunition is equivalent against all targets.

Current direction: leave damage alone while comparing capacity, optics and firing
cadence. No capacity, optic or firing-rate change is authorized by this discussion.

## Current source comparison

| QM weapon | Allowed primary cell capacity | Seconds between shots | Nominal cyclic ceiling | Approximate default/dedicated optic magnification |
|---|---:|---:|---:|---|
| 3AS DLT-19X | 10 (both red and blue) | 1.00 | 60 RPM | 4-12x, linked 3AS DLT-19X optic |
| IDA 773 Firepuncher | 10 | 0.17142 | 350 RPM | 2x or 8.8x, built-in optic |
| TAE IQA-12 | 5 | 0.60 | 100 RPM | 5/10/15/20/25/30x, linked FP-2 |
| IDA Galaar-90 | 5 | 0.60 | 100 RPM | 2x or approximately 6x, linked IDA Targeting Scope |
| IDA DC-15X | 5 | 0.60 | 100 RPM | 2x or approximately 6x, built-in optic |
| MTI NT-242 | 15 (precision cell) | 2.00 | 30 RPM | 8-24x with the dedicated NT scope fitted |
| LFP LW-7 | 12 | 0.70 | 85.7 RPM | Intended 3/6/9/12/15/20x steps; conflicting min/max, verify live |
| LFP Westar Sniper | 14 | 0.70 | 85.7 RPM | Intended 3/6/9/12/15/20x steps; conflicting min/max, verify live |

All known modes above are single-shot/semi-auto, not full auto. RPM is 60 divided
by config reloadTime: a theoretical cycle ceiling, not measured aimed fire or
magazine reload speed. Animations, scripts and recoil recovery can limit cadence.

Zoom uses approximately 0.25 / optics FOV for comparison, not monitor-measured
magnification. Only the built-in or named dedicated optic is compared, not every
compatible attachment. In particular the NT scope is available separately in the
arsenal; this does not assert that it is preinstalled on a bare NT-242.

Raw zoom values (minimum field of view first):

- DLT-19X scope: 0.0208 to 0.0625.
- 773 built-in: discreteFov 0.125, 0.0285.
- FP-2: discreteFov 0.05, 0.025, 0.0167, 0.0125, 0.01, 0.0083.
- IDA Targeting Scope and DC-15X: discreteFov 0.125, 0.042.
- NT scope: 0.010416667 to 0.03125 (magnified mode).

## Interpretation to discuss

- 773 is the obvious rapid-follow-up candidate; test whether recoil/animation
  permits its nominal cadence while maintaining hits.
- NT's fifteen-round capacity offsets its slow cycle. At equivalent one-shot
  torso outcomes it is not automatically the fastest rifle despite high raw hit.
- IQA and Galaar/DC-15X share a five-round/0.6-second baseline, but their default
  optics differ substantially. FP-2 gives IQA much more magnification; compare
  target acquisition and field of view as well as maximum zoom.
- DLT-19X occupies a middle position: ten rounds, slower follow-up than IDA's
  five-round rifles, with more magnification than the stock Galaar/DC-15X optics.
- Higher magnification is not always better, especially for acquisition at shorter
  ranges. Do not force all snipers to the same optic or capacity by default.

Next evidence: actual aimed follow-up times, magazine-change times, full-magazine
engagements and live LFP values. If results support it, discuss identities before
choosing numbers: rapid follow-up, versatile precision, or deliberate anti-materiel.

## References

Local snapshot: 2026-09-09-review.md and 2026-09-09-static-audit.json in this folder.
Live TAE FP-2 source: ../../TAEWeapons/config.cpp.
Installed source configs inspected: 3AS_Weapons/Imperial; Indecisive Armoury
Weapons_REPUBLIC and Weapons_INDEP; mti_armoury_weapons/nt.

[Bohemia config reference](https://community.bistudio.com/wiki/CfgWeapons_Config_Reference)
describes optics field of view and weapon cycle settings. These are source-level
figures, not a new complete engine-merged export.

Update: [PBO Manager follow-up](lfp-extraction-followup.md) recovered readable LFP
include targets. Capacity and cadence above are now verified against those files;
scope behavior still requires a live check because its configuration conflicts.
