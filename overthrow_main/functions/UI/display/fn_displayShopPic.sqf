disableSerialization;
params ["_ctrl","_index"];

private _cls = _ctrl lbData _index;
private _price = _ctrl lbValue _index;

private _pic = "";
private _txt = "";
private _desc = "";
if(_price > -1) then {
    ctrlEnable [1600,true];
    private _res = [_cls] call {
		params ["_cls"];
        if(_cls == "Set_HMG") exitWith {
			[
				getText(configFile >> "cfgVehicles" >> "C_Quadbike_01_F" >> "editorPreview"),
            	"A Quad-bike containing the backpacks required to set up a Static HMG",
            	"Quad Bike w/ HMG Backpacks"
			]
        };
    	if(_cls isKindOf ["Default",configFile >> "CfgMagazines"]) exitWith {
    		[
				_cls call OT_fnc_magazineGetPic,
    			_cls call OT_fnc_magazineGetName,
    			_cls call OT_fnc_magazineGetDescription
			]
    	};
    	if(isClass (configFile >> "CfgGlasses" >> _cls)) exitWith {
    		[
				gettext(configFile >> "CfgGlasses" >> _cls >> "picture"),
				nil,
    			gettext(configFile >> "CfgGlasses" >> _cls >> "displayName")
			]
    	};
        if(_cls isKindOf "Man") exitWith {
            private _soldier = _cls call OT_fnc_getSoldier;
            private _bought = _soldier select 5;
    		private _price = _soldier select 0;

            _text = "";
            {
                _x params ["_cls","_qty"];
                private _name = _cls call OT_fnc_anythingGetName;
                private _cost = (([OT_nation,_cls,30] call OT_fnc_getPrice) * _qty);
                _text = format["%1%2 x %3 = $%4<br/>",_text,_qty,_name,[_cost, 1, 0, true] call CBA_fnc_formatNumber];
            }foreach(_bought);

            if(_text isEqualTo "") then {
                _text = "Todo lo necesario para este vehiculo esta en el almacen";
            }else{
                _text = format["Estos objetos no estan en el almacen por lo que debes obtenerlos de otra forma:<br/>%1",_text];
            };

    		[
				nil,
    			_text,
				_cls call OT_fnc_vehicleGetName,
				_price
			]
    	};
    	if(isClass (configFile >> "CfgVehicles" >> _cls)) exitWith {
    		[
				getText(configFile >> "cfgVehicles" >> _cls >> "editorPreview"),
				[
					getText(configFile >> "cfgVehicles" >> _cls >> "Library" >> "libTextDesc"),
					"Te lleva de A a B con cierto riesgo de volcar"
				] select (_cls == "C_Quadbike_01_F"),
				_cls call OT_fnc_vehicleGetName
			]
    	};
    	if(_cls isKindOf "Bag_Base") exitWith {
    		[
				_cls call OT_fnc_vehicleGetPic,
				_cls call OT_fnc_vehicleGetDescription,
				_cls call OT_fnc_vehicleGetName
			]
    	};
    	if(_cls isKindOf ["Default",configFile >> "CfgWeapons"]) exitWith {
    		[
				_cls call OT_fnc_weaponGetPic,
    			format["%1<br/>%2",getText(configFile >> "CfgWeapons" >> _cls >> "descriptionShort"),_cls call OT_fnc_magazineGetDescription],
    			_cls call OT_fnc_weaponGetName
			]
    	};
    	if(_cls in OT_allSquads) exitWith {
            private _squad = _cls call OT_fnc_getSquad;
            _price = _squad param [0,0];
            ctrlEnable [1601,false];

			[
				nil,
    			"Recluta a esta escuadra, accesible en tu barra de alto mando CTRL+Espacio.",
				_cls,
				_price
			]
    	};
    };
	_pic = _res param [0, ""];
	_desc = _res param [1, ""];
	_txt = _res param [2, ""];
	_price = _res param [3, _price];
}else{
    ctrlEnable [1600,false];
    _desc = _cls;
    _txt = "No Disponible";
    _price = "";
};
if(!isNil "_pic" && { !(_pic isEqualTo "") }) then {
	ctrlSetText [1200,_pic];
};

if(_cls in OT_allExplosives) then {
    _cost = cost getVariable _cls;
    _chems = server getVariable ["reschems",0];
    _desc = format["Requerido: %1 x quimicos (%2 disponible)<br/>%3",_cost select 3,_chems,_desc];
};

_textctrl = (findDisplay 8000) displayCtrl 1100;

if(_price isEqualType 0) then {
    _price = "$" + ([_price, 1, 0, true] call CBA_fnc_formatNumber);
}else{
    _price = "";
};

_textctrl ctrlSetStructuredText parseText format["
	<t align='center' size='1.5'>%1</t><br/>
	<t align='center' size='1.2'>%3</t><br/><br/>
	<t align='center' size='0.8'>%2</t>
",_txt,_desc,_price];
