closeDialog 0;
OT_inputHandler = {
	_val = parseNumber(ctrltext 1400);
	_cash = server getVariable ["money",0];
	if(_val > _cash) then {_val = _cash};
	if(_val > 0) then {
		[-_val] call OT_fnc_resistanceFunds;
        [_val] call OT_fnc_money;
	};
};

["Cuanto quieres coger de la caja de la resistencia?",1000] call OT_fnc_inputDialog;
