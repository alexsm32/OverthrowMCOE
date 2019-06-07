OT_context = _this select 0;

private _password = OT_context getVariable ["password",""];

if(_password isEqualTo "") exitWith {
	private _in = OT_context getVariable ["money",0];

	OT_inputHandler = {
		_val = parseNumber(ctrltext 1400);
		_cash = player getVariable ["money",0];
		_in = OT_context getVariable ["money",0];
		if(_val > _in) then {_val = _in};
		if(_val > 0) then {
			[_val] call OT_fnc_money;
			OT_context setVariable ["money",_in - _val,true];
		};
	};

	[format["cuanto quieres coger (Total $%1 )",[_in, 1, 0, true] call CBA_fnc_formatNumber],100] call OT_fnc_inputDialog;
};

OT_inputHandler = {
	private _password = OT_context getVariable ["password",""];
	private _pw = ctrlText 1400;
	if(_pw != _password) exitWith {"PIN INCORRECTO" call OT_fnc_notifyMinor};
	private _in = OT_context getVariable ["money",0];

	OT_inputHandler = {
		_val = parseNumber(ctrltext 1400);
		_cash = player getVariable ["money",0];
		_in = OT_context getVariable ["money",0];
		if(_val > _in) then {_val = _in};
		if(_val > 0) then {
			[_val] call OT_fnc_money;
			OT_context setVariable ["money",_in - _val,true];
		};
	};

	[format["Cuanto quieres coger? (Total $%1 )",[_in, 1, 0, true] call CBA_fnc_formatNumber],100] call OT_fnc_inputDialog;
};

["Introduce tu PIN",""] call OT_fnc_inputDialog;