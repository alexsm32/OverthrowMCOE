params ["_jobid","_jobparams"];
_jobparams params ["_missiondef"];

private _params = [_missiondef];
_missiondef params ["_missionid","_missiontype","_p1","_p2","_hour"];

//Build a mission description and title
private _description = "";
private _title = "";

if(_missiontype == "CONVOY") then {
    _description = format["Hemos recibido informacion de un convoy de la OTAN de %1 a %2 aproximadamente a las %3:00 de hoy.",_p1 select 1,_p2 select 1,_hour];
    _title = format["NATO Convoy de %1 a %2",_p1 select 1,_p2 select 1];
    //notify the players
    _description remoteExec ["OT_fnc_notifyMinor",0,false];
};

private _markerPos = _p2 select 0;

//The data below is what is returned to the gun dealer/faction rep, _markerPos is where to put the mission marker, the code in {} brackets is the actual mission code, only run if the player accepts
[
    [_title,_description],
    _markerPos,
    {
        //No setup required
    },
    {
        //Fail check...
        //something is alive and made it to destination
        params ["_missiondef"];
        _missiondef params ["_id","_ty","_p1","_p2","_hour"];
        _group = spawner getVariable [format["spawn%1",_id],nil];
        _topos = _p2 select 0;
        _failed = false;
        if(!isNil "_group" && (count units _group) > 0) then {
            _pos = getpos(leader _group);
            if((_pos distance2D _topos) < 50) exitWith {_failed = true};
        };

        _failed
    },
    {
        //Succeed check...
        //everyone is dead
        params ["_missiondef"];
        _missiondef params ["_id","_ty","_p1","_p2","_hour"];
        _group = spawner getVariable [format["spawn%1",_id],nil];
        (count units _group) isEqualTo 0
    },
    {
        //we dont need to do anything
    },
    _params
];
