//Let's find some wrecks to salvage

private _done = player getVariable ["OT_tutesDone",[]];
_done pushBackUnique "Economy";
player setVariable ["OT_tutesDone",_done,true];

private _actualMission = {
    private _targets = [];
    private _destination = [];
    private _thistown = (getposATL player) call OT_fnc_nearestTown;

    //Is there some already spawned within spawn distance?
    {
        if(damage _x > 0.9) then {
            _targets pushback _x;
        };
    }foreach(player nearObjects ["Car", OT_spawnDistance]);


    //No? well where is the closest town?
    if(count _targets isEqualTo 0) exitWith {
        private _towns = [OT_townData,[],{(_x select 0) distance player},"ASCEND"] call BIS_fnc_SortBy;
        private _town = _towns select 1;
        private _destination = _town select 0;
        _town = _town select 1;

        if(count _destination > 0) then {
            //give waypoint
            [player,_destination,_town] call OT_fnc_givePlayerWaypoint;

            format["Parece que no hay chatarra cerca. Vete a %1, deber�as encontrar algo por all�. est� marcado en tu mapa",_town] call OT_fnc_notifyMinor;

            [
                {
                    player distance _this < 200
                },
                {
                    //If the player fast travelled, give time to spawn
                    [{
                        //loop and hope we find a target
                        [] call (OT_tutorialMissions select 3);
                    },0,10] call CBA_fnc_waitAndExecute;
                },
                _destination
            ] call CBA_fnc_waitUntilAndExecute;
        }else{
            //I guess resistance controls the entire map, gg
        };
    };

    "Hay chatarra por aqu�. usa las herramientas para desguazarla" call OT_fnc_notifyMinor;

    private _sorted = [_targets,[],{_x distance player},"ASCEND"] call BIS_fnc_SortBy;
    private _veh = _sorted select 0;
    player reveal [_veh,4];

    //give waypoint
    private _wp = [player,position _veh,"Wreck"] call OT_fnc_givePlayerWaypoint;

    private _loopCode = {
        params["_loopCode","_veh"];
        if(player distance _veh < 10 && "ToolKit" in items player) then {
            _reached = true;
            "Usa la tecla de interacci�n sobre la chatarra.
            Lo que saques puede ser vendido en las tiendas de herramientas,
            solo conduce hasta all� y pulsa 'Y'" call OT_fnc_notifyMinor;
            call OT_fnc_clearPlayerWaypoint;
        } else {
            [_loopCode,_this,0.5] call CBA_fnc_waitAndExecute;
        };
    };
    [_loopCode,_veh] call _loopCode;
};


//First do we have a toolkit?
if !("ToolKit" in items player) then {
    "Coge las herramientas de la caja de munici�n de tu casa,
    necesitar�s una mochila" call OT_fnc_notifyMinor;
    private _home = player getVariable "home";
    private _wp = [player,_home,"Grab Toolkit"] call OT_fnc_givePlayerWaypoint;
    private _loop = {
        params["_loop","_actualMission"];
        if("ToolKit" in items player) then {
            call _actualMission;
        } else {
            [_loop,_this,5] call CBA_fnc_waitAndExecute;
        };
    };
    [_loop,_actualMission] call _loop;
} else {
    call _actualMission;
};
