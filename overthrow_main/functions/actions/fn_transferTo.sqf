private _target = vehicle player;
private _notvehicle = false;
if(_target isEqualTo player) then {
	_target = OT_warehouseTarget;
	_notvehicle = true;
};

if(isNull _target || isNil "_target") exitWith {};

private _objects = [];
private _b = player call OT_fnc_nearestRealEstate;
private _iswarehouse = false;

if(!_notvehicle) then {
	{
		if!(_x isEqualTo _target) then {_objects pushback _x};
	}foreach(player nearEntities [["Car","ReammoBox_F","Air","Ship"],20]);
};


if(!_notvehicle  && _objects isEqualTo []) exitWith {
	"No hay vehiculos o contenedores a menos de 20m. " call OT_fnc_notifyMinor;
};

if(count _objects isEqualTo 1) then {
	[vehicle player, (_objects select 0)] call OT_fnc_transferHelper;
}else{
	private _options = [];
	{
		_options pushback [
			format[
				"%1 (%2m)",
				(typeof _x) call OT_fnc_vehicleGetName,
				round (_x distance player)
			],
			OT_fnc_transferHelper,
			[vehicle player, _x]
		];
	}foreach(_objects);
	"A donde quieres transferir la carga?" call OT_fnc_notifyBig;
	_options call OT_fnc_playerDecision;
};
