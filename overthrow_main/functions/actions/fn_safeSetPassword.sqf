OT_context = _this select 0;
OT_inputHandler = {
	_val = ctrltext 1400;
	OT_context setVariable ["password",_val,true];
};

["Establece PIN (deja en blanco para quitarlo)",""] call OT_fnc_inputDialog;