//Vamos a disparar a algunos bandidos

private _done = player getVariable ["OT_tutesDone",[]];
_done pushBackUnique "CRIM";
player setVariable ["OT_tutesDone",_done,true];

private _targets = [];
private _destination = [];
private _thistown = (getposATL player) call OT_fnc_nearestTown;

//Ha spawneado alguien cerca?
{
    if(side _x isEqualTo east) then {
        _targets pushback _x;
    };
}foreach(player nearEntities ["CAManBase", OT_spawnDistance]);

//No? Veamos donde hay un pueblo con una banda activa
if(count _targets isEqualTo 0) exitWith {
    private _towns = [OT_townData,[],{(_x select 0) distance player},"ASCEND"] call BIS_fnc_SortBy;
    private _town = "";
    private _done = false;
    {
        _x params ["_pos","_t"];
        _gangshere = OT_civilians getVariable [format["gangs%1",_t],[]];
        if !(_t isEqualTo _thistown) then {
            if(count _gangshere > 0) then {
                _gang = OT_civilians getVariable [format["gang%1",_gangshere select 0],[]];
                if(count _gang > 0) then {
                    if(count(_gang select 0) > 0) then {
                        _destination = _pos;
                        _town = _t;
                        _done = true;
                    };
                };
            };
        };
        if(_done) exitWith {};
    }foreach(_towns);

    if(count _destination > 0) then {
        //give waypoint
        [player,_destination,_town] call OT_fnc_givePlayerWaypoint;

        format[
            "Parece que no hay bandas cerca. Dirigete a %1, Deberias encontrar alguna por alli. Esta marcada en el mapa",
            _town
        ] call OT_fnc_notifyMinor;

        [
            {
                player distance _this < 200
            },
            {
                //If the player fast travelled, give time to spawn
                [{
                    //espero encontrar un objetivo
                    [] call (OT_tutorialMissions select 1);
                },0,10] call CBA_fnc_waitAndExecute;
            },
            _destination
        ] call CBA_fnc_waitUntilAndExecute;

    }else{
        //Me temo que la resistencia controla todo el mapa,XD
    };
};

"Hay una banda por aqui cerca,puede que los lugareños te den algo de pasta si les invitas a irse" call OT_fnc_notifyMinor;

//pick the first group and reveal
private _sorted = [_targets,[],{_x distance player},"ASCEND"] call BIS_fnc_SortBy;
private _group = group (_sorted select 0);
player reveal [leader _group,4];

//give waypoint
private _wp = [player,position leader _group,"Gang"] call OT_fnc_givePlayerWaypoint;
private _total = count units _group;

private _loopCode = {
    params ["_loopCode","_wp","_reached","_group","_total","_done"];
    if(!isNil "_wp") then {
        //update waypoint
        OT_missionMarker = getPosATL leader _group;
        _wp setWaypointPosition [OT_missionMarker, 0];
    };
    if(!_reached) then {
        _reached = player distance (leader _group) < 30;
    }else{
        private _num = _total - ({alive _x} count units _group);
        _done = _num >= _total;
        hintSilent format["Kills: %1/%2",_num,_total];
    };

    if !(_done) then {
        [
            _loopCode,
            [_loopCode,_wp,_reached,_group,_total,false],
            0.5
        ] call CBA_fnc_waitAndExecute;
    } else {
        call OT_fnc_clearPlayerWaypoint;
    };
};

[_loopCode,_wp,false,_group,_total,false] call _loopCode;
