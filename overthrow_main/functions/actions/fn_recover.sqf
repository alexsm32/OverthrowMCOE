params ["_user"];

private _range = 150;

private _veh = vehicle _user;
if(_veh == _user) exitWith {};
if((driver _veh) != _user) exitWith {"El looteo debe hacerlo el conductor del vehiculo" call OT_fnc_notifyMinor};
if((typeof _veh) != "OT_I_Truck_recovery") exitWith {"Esta orden solo funciona desde el recovery truck" call OT_fnc_notifyMinor};

if(isPlayer _user) then {
    disableUserInput true;
    [] spawn {
        sleep 20;
        disableUserInput false;
        //Fail safe for user input disabled.
    };
    format["Looteando los cuerpos en un radio de %1m",_range] call OT_fnc_notifyMinor;
    [15,false] call OT_fnc_progressBar;
}else {
    _user globalchat "Looteando cuerpos con un camion de recuperacion";
};

private _end = time + 15;
waitUntil {time > _end};

//Get the loose weapons
private _weapons = _veh nearentities ["WeaponHolderSimulated",_range];
{
    _weapon = _x;
    _s = (weaponsItems _weapon) select 0;
    if(!isNil {_s}) then {
        _cls = (_s select 0);
        _i = _s select 1;
        if(_i != "") then {_veh addItemCargoGlobal [_i,1]};
        _i = _s select 2;
        if(_i != "") then {_veh addItemCargoGlobal [_i,1]};
        _i = _s select 3;
        if(_i != "") then {_veh addItemCargoGlobal [_i,1]};

        _veh addWeaponCargoGlobal [_cls call BIS_fnc_baseWeapon,1];
        deleteVehicle _weapon;
    };
}foreach(_weapons);

//Get the bodies
private _count = 0;
{
    if !((_x distance _veh > _range) || (alive _x)) then {
        [_x,_veh] call OT_fnc_dumpStuff;
        _count = _count + 1;
        deleteVehicle _x;
    };
}foreach(entities "Man");

if(isPlayer _user) then {
    disableUserInput false;
    format["looteados %1 cuerpos en este camion",_count] call OT_fnc_notifyMinor;
}else {
    _user globalchat format["Terminado! Looteados %1 cuerpos",_count];
};
