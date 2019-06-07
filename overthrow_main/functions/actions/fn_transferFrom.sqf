private _veh = vehicle player;

if(_veh isEqualTo player) exitWith {};

private _objects = [];
{
	if!(_x isEqualTo _veh) then {_objects pushback _x};
}foreach(player nearEntities [["Car","ReammoBox_F","Air","Ship"],20]);

if(_objects isEqualTo []) exitWith {
	"No hay otros vehiculos o contenedores a menos de 20m de este vehiculo" call OT_fnc_notifyMinor;
};
private _sorted = [_objects,[],{_x distance player},"ASCEND"] call BIS_fnc_SortBy;
private _target = _sorted select 0;

if(_veh call OT_fnc_unitSeen) then {
	if((_target getVariable ["stockof",""]) isEqualType 0) then {
		{
			_x setCaptive false;
		}foreach(crew _veh);
		[_veh] call OT_fnc_revealToNATO;
		hint "Te han pillao robando! correeeeee!";
	};
};

if(count _objects isEqualTo 1) then {
	[(_objects select 0), vehicle player] call OT_fnc_transferHelper;
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
			[_x, vehicle player]
		];
	}foreach(_objects);
	"De que contenedor quieres transferir?" call OT_fnc_notifyBig;
	_options call OT_fnc_playerDecision;
};
