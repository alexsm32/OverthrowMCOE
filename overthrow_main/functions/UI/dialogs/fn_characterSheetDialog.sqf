closedialog 0;
createDialog "OT_dialog_char";
openMap false;

disableSerialization;

private _fitness = player getVariable ["OT_fitness",1];

private _ctrl = (findDisplay 8003) displayCtrl 1100;
_ctrl ctrlSetStructuredText parseText format["<t size=""2"">Forma fisica</t><br/><t size=""1.1"">Nivel %1</t><br/><t size=""0.7"">Aumenta tu distancia de sprint</t>",_fitness];

private _trade = player getVariable ["OT_trade",1];
_ctrl = (findDisplay 8003) displayCtrl 1101;
_ctrl ctrlSetStructuredText parseText format["<t size=""2"">Comercio</t><br/><t size=""1.1"">Nivel %1</t><br/><t size=""0.7"">Mejora tu habilidad de obtener mejores precios</t>",_trade];

private _stealth = player getVariable ["OT_stealth",1];
_ctrl = (findDisplay 8003) displayCtrl 1102;
_ctrl ctrlSetStructuredText parseText format["<t size=""2"">Sigilo</t><br/><t size=""1.1"">Nivel %1</t><br/><t size=""0.7"">Mejora tu habilidad de pasar material ilegal frente a la OTAN</t>",_stealth];

getPerkPrice = {
	private _perk = _this select 0;
	private _fitness = player getVariable [format["OT_%1",_perk],1];
	private _price = 10;
	if(_fitness isEqualTo 2) then {
		_price = 100;
	};
	if(_fitness isEqualTo 3) then {
		_price = 500;
	};
	if(_fitness isEqualTo 4) then {
		_price = 1000;
	};
	_price;
};

private _price = ["fitness"] call getPerkPrice;
ctrlSetText [1600,format["Aumentar nivel (-%1 Influencia)",_price]];

_price = ["trade"] call getPerkPrice;
ctrlSetText [1601,format["Aumentar nivel (-%1 Influencia)",_price]];

_price = ["stealth"] call getPerkPrice;
ctrlSetText [1602,format["Aumentar nivel (-%1 Influencia)",_price]];

if(_fitness isEqualTo 5) then {
	ctrlShow [1600,false];
};

if(_trade isEqualTo 5) then {
	ctrlShow [1601,false];
};

if(_stealth isEqualTo 5) then {
	ctrlShow [1602,false];
};

buyPerk = {
	_perk = _this select 0;
	disableSerialization;

	private _fitness = player getVariable [format["OT_%1",_perk],1];
	private _price = [_perk] call getPerkPrice;
	private _inf = player getVariable ["influence",0];

	if(_inf < _price) exitWith {"No tienes suficiente influencia" call OT_fnc_notifyMinor};

	_fitness = _fitness + 1;
	player setVariable [format["OT_%1",_perk],_fitness,true];
	_idc = 1600;
	_idcc = 1100;
	if(_perk isEqualTo "trade") then {_idc = 1601;_idcc = 1101};
	if(_perk isEqualTo "stealth") then {_idc = 1602;_idcc = 1102};

	if(_fitness isEqualTo 5) then {
		ctrlEnable [_idc,false];
	};
	player setVariable ["influence",_inf - _price,true];

	private _ctrl = (findDisplay 8003) displayCtrl _idcc;
	_txt = format["<t size=""2"">Forma fisica</t><br/><t size=""1.1"">Nivel %1</t><br/><t size=""0.7"">Increases the distance you can sprint</t>",_fitness];
	if(_perk isEqualTo "trade") then {
		_txt = format["<t size=""2"">Comercio</t><br/><t size=""1.1"">Nivel %1</t><br/><t size=""0.7"">Mejora tu habilidad de obtener mejores precios</t>",_fitness];
	};
	if(_perk isEqualTo "stealth") then {
		_txt = format["<t size=""2"">Sigilo</t><br/><t size=""1.1"">Nivel %1</t><br/><t size=""0.7"">Mejora tu habilidad de pasar material ilegal frente a la OTAN</t>",_fitness];
	};

	_ctrl ctrlSetStructuredText parseText _txt;
	_price = [_perk] call getPerkPrice;
	ctrlSetText [_idc,format["Aumentar Nivel (-%1 Influencia)",_price]];

	if(_fitness isEqualTo 5) then {
		ctrlShow [_idc,false];
	};
};
