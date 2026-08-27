params [["_unit", player, [objNull]]];

if (!hasInterface || {isNull _unit} || {!local _unit}) exitWith {};
if (_unit getVariable ["TAE_quartermasterDiaryAdded", false]) exitWith {};

_unit setVariable ["TAE_quartermasterDiaryAdded", true];
_unit createDiarySubject ["TAE_Quartermaster", "TAE Quartermaster"];

private _content =
	"<font size='18' color='#D6B85A'>Quartermaster and Specializations</font><br/><br/>" +
	"The Quartermaster manages specialization equipment. Choose specializations totaling no more than <font color='#E24A4A'>9 points</font>.<br/><br/>" +
	"<font color='#D6B85A'>Rising Phoenix - 4 points</font><br/>JT-12 Jet Pack<br/><br/>" +
	"<font color='#D6B85A'>Lancer - 8 points</font><br/>Z-6 and Z-12 Jet Packs<br/><br/>" +
	"<font color='#D6B85A'>Marksman - 3 points</font><br/>DW-32S, A310, MK Blaster, BR-77<br/><br/>" +
	"<font color='#D6B85A'>AT/AA - 6 points</font><br/>HH-12 Launcher, PLX-1, RPS-6 variants<br/><br/>" +
	"<font color='#D6B85A'>Grenadier - 3 points</font><br/>A280 UGL, DP-23 UGL, E-11 UGL, E-10 UGL, DC-15S UGL, MPL-57, Bowcaster<br/><br/>" +
	"<font color='#D6B85A'>CQC - 3 points</font><br/>DP-23, Scattergun, EE-4, DC-23, SX-21, T-14 Blaster Repeater<br/><br/>" +
	"<font color='#D6B85A'>Demolitions - 5 points</font><br/>Explosives and in-game engineer permissions<br/><br/>" +
	"<font color='#D6B85A'>Communications - 2 points</font><br/>LR backpack variants<br/><br/>" +
	"<font color='#D6B85A'>Heavy Weapons - 5 points</font><br/>DLT-19, FWMB-10, RT-97C, M-41, Z-6, DC-15LE, HPB-14, JD-70 Rancor<br/><br/>" +
	"<font color='#D6B85A'>Sniper - 5 points</font><br/>DLT-19X, 773, IQA, Galaar-90, DC-15X, NT-242, LW-7, Westar Sniper, T-21, T-21 (Legacy), T-21B<br/><br/>" +
	"<font color='#D6B85A'>Rifleman - 0 points</font><br/>A180, A180 Stock, A180 Rifle, A280, A280C, A295, A300, A300C, E-11 variants, E-5, A475, DH-17 Rifle, DH-17, E-10, E-22, EE-3, F-78, Galaar-15, SB-B3, Westar-35C, Westar-35S, ZH-73, DC-15S, DC-15A, EE-2, EE-3B<br/><br/>" +
	"<font color='#D6B85A'>CSW - 9 points</font><br/>Crew-Served Weapons (turrets, mortars, and similar emplacements)<br/><br/>" +
	"<font color='#D6B85A'>SUAS - 3 points</font><br/>Small Unmanned Aircraft Systems (aerial drones)<br/><br/>" +
	"<font color='#D6B85A'>Medic - 5 points</font><br/>In-game medical permissions";

_unit createDiaryRecord [
	"TAE_Quartermaster",
	["Specializations - 9 Point Maximum", _content]
];
