params ["_id","_jobdef","_params"];

_jobdef params ["_name","_target","_condition","_code","_repeat"];

_active = spawner getVariable ["OT_activeJobs",[]];
_job = [_id,_params] call _code;
_j = [_id,_job,_repeat];
_active pushback _j;

spawner setVariable ["OT_activeJobs",_active,true];

_j spawn {
	params ["_id","_job","_repeat"];
	_job params ["_info","_markerPos","_setup","_fail","_success","_end","_jobparams"];
	_jobparams spawn _setup;
	[{
		params ["_id","_job","_repeat","_info","_markerPos","_setup","_fail","_success","_end","_jobparams"];

		private _done = false;
		[{
			(_this select 0) params ["_done","_id","_job","_repeat","_info","_markerPos","_setup","_fail","_success","_end","_jobparams"];
			private _handle = _this select 1;
			if (!_done) then {
				if(call {
					if(_jobparams call _success) exitWith {
						_jobparams pushback true;
						true
					};
					if(_jobparams call _fail) exitWith {
						_jobparams pushback false;
						true
					};
					false
				}) then {
					_jobparams call _end;
					_active = spawner getVariable ["OT_activeJobs",[]];
					private _idx = -1;
					{
					    _x params ["_cid"];
						if(_cid == _id) exitWith {_idx = _forEachIndex};
					} forEach _active;
					if(_idx > -1) then {
						_active deleteAt _idx;
						spawner setVariable ["OT_activeJobs",_active,true];
					};

					_active = server getVariable ["OT_activeJobIds",[]];
					_active deleteAt (_active find _id);

					format["Job completed: %1",(_job select 0) select 0] remoteExec ["OT_fnc_notifyGood",0,false];

					if(_repeat < 1) then {
						_completed = server getVariable ["OT_completedJobIds",[]];
						_completed pushback _id;
					};
					[_handle] call CBA_fnc_removePerFrameHandler;
				};
			};
		}, 1, [_done,_id,_job,_repeat,_info,_markerPos,_setup,_fail,_success,_end,_jobparams]] call CBA_fnc_addPerFrameHandler;
	}, [_id,_job,_repeat,_info,_markerPos,_setup,_fail,_success,_end,_jobparams], 5] call CBA_fnc_waitAndExecute;

};
