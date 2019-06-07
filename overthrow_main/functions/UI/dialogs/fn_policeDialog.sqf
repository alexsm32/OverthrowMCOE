disableSerialization;

_town = (getpos player) call OT_fnc_nearestTown;
if !(_town in (server getvariable ["NATOabandoned",[]])) exitWith {"Esta comisaria esta bajo control de la OTAN" call OT_fnc_notifyMinor};

_garrison = server getVariable [format['police%1',_town],0];
createDialog "OT_dialog_police";

private _soldier = "Police" call OT_fnc_getSoldier;
_price =_soldier param [0,500];

_effect = floor(_garrison / 2);
if(_effect isEqualTo 0) then {_effect = "None"} else {_effect = format["+%1 Estabilidad/10 mins",_effect]};

if !(call OT_fnc_playerIsGeneral) then {
    ctrlEnable [1608,false];
};

((findDisplay 9000) displayCtrl 1100) ctrlSetStructuredText parseText format["<t size=""2"" align=""center"">%1 Comisaria</t>",_town];
((findDisplay 9000) displayCtrl 1103) ctrlSetStructuredText parseText format["<t align=""center"">Contratar Policia ($-%1)</t>",_price];
((findDisplay 9000) displayCtrl 1101) ctrlSetStructuredText parseText format["<t size=""1.5"" align=""center"">Policia: %1</t>",_garrison];
((findDisplay 9000) displayCtrl 1104) ctrlSetStructuredText parseText format["<t size=""1.2"" align=""center"">Efectos</t><br/><br/><t size=""0.8"" align=""center"">%1</t>",_effect];
