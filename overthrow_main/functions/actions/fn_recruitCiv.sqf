private _town = (getpos player) call OT_fnc_nearestTown;
private _standing = [_town] call OT_fnc_support;

if(_standing < 10 && count (player nearObjects [OT_refugeeCamp,50]) isEqualTo 0) exitWith {
	"necesitas un apoyo a la resistencia mayor de 10 o estar en un campo de refugiados para reclutar civiles" call OT_fnc_notifyMinor
};

if(({side _x isEqualTo west || side _x isEqualTo east} count (player nearEntities 50)) > 0) exitWith {"No puedes reclutar con enemigos cerca" call OT_fnc_notifyMinor};

private _price = [_town,"CIV",_standing] call OT_fnc_getPrice;
private _money = player getVariable ["money",0];

if(_money < _price) exitWith {"No puedes permitirte esto" call OT_fnc_notifyMinor};
playSound "3DEN_notificationDefault";
player setVariable ["money",_money-_price,true];

[_town,1] call OT_fnc_support;

private _civ = OT_interactingWith;
[_civ,getPlayerUID player] call OT_fnc_setOwner;
_civ removeAllEventHandlers "FiredNear";
[_civ] joinSilent nil;
[_civ] joinSilent (group player);
_civ setCaptive true;
_civ setSkill 0.2 + (random 0.3);
[_civ] call OT_fnc_initRecruit;
_civ setVariable ["OT_spawntrack",true,true];

[player,format["New Recruit: %1",name _civ],format["Reclutado: %1 por $%2",name _civ,_price]] call BIS_fnc_createLogRecord;
format["%1 ha sido reclutado",name _civ] call OT_fnc_notifyMinor;

_civ setBehaviour "SAFE";
[[_civ,""],"switchMove",TRUE,FALSE] call BIS_fnc_MP; // @todo replace with remote exec
