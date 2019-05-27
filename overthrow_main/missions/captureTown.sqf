params ["_jobid","_jobparams"];
_jobparams params ["_faction"];

private _factionPos = server getVariable [format["factionrep%1",_faction],[]];
private _destinationName = _factionPos call OT_fnc_nearestTown;
private _params = [_destinationName,_faction];
private _markerPos = server getVariable [_destinationName,[]];
private _factionName = server getvariable format["factionname%1",_faction];

private _effect = format["El pueblo dará impulso a la estabilidad %1 ayundando a calmar a la población.<br/><t size='0.9'>Recompensa: $2,500 fondos para la resistencia, +10 (%1)</t>",_factionName];

//Build a mission description and title
private _description = format["%1 preferiría que %2 fuese controlado por la resistencia. Baja la estabilidad haciendo trabajos o matando gendarmes hasta 0%. <br/><br/>%3",_factionName,_destinationName,_effect];
private _title = format["Capture %1 for %2",_destinationName,_factionName];

//The data below is what is returned to the gun dealer/faction rep, _markerPos is where to put the mission marker, the code in {} brackets is the actual mission code, only run if the player accepts
[
    [_title,_description],
    _markerPos,
    {
        //No setup required for this mission
    },
    {
        //Fail check...
        false
    },
    {
        //Success Check
        params ["_destinationName"];

        _destinationName in (server getVariable ["NATOabandoned",[]])
    },
    {
        params ["_destinationName","_faction","_wassuccess"];

        //If mission was a success
        if(_wassuccess) then {
            [
                {
                    params ["_faction","_destinationName"];

                    [_destinationName,10] call OT_fnc_stability;
                    [2500] call OT_fnc_resistanceFunds;
                    server setVariable [format["standing%1",_faction],(server getVariable [format["standing%1",_faction],0]) + 10,true];

                    private _factionName = server getvariable format["factionname%1",_faction];
                    format ["Mensaje de %1: %2 captured. Donados $2500 a la resistencia ayudará a los esfuerzos de la bloblación civil. (+10 stabilidad, +10 %1)",_factionName,_destinationName] remoteExec ["OT_fnc_notifyMinor",0,false];
                },
                [_faction,_destinationName],
                2
            ] call CBA_fnc_waitAndExecute;

        };
    },
    _params
];
