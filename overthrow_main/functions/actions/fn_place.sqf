if !(captive player) exitWith {"No puedes colocar cosas cuando estes en busca y captura" call OT_fnc_notifyMinor};

private _typecls = _this;

([_typecls] call {
	params ["_typecls"];
	if(_typecls == "Camp") exitWith {
		[
			[0,3.5,1.1],
			[OT_item_Tent],
			40,
			"Crea un destino de viaje rapido para todos los jugadores. Solo uno por jugador, si construyes otro el anterior desaparecera"
		]
	};
	if(_typecls == "Base") exitWith {
		[
			[0,6,4],
			[OT_flag_IND],
			250,
			"Crea un destino de viaje rapido para todos los jugadores y permite la construccion de edificios militares"
		]
	};
	if(_typecls == "Ammobox") exitWith {
		[
			nil,
			[OT_item_Storage],
			60,
			"Una caja de municion vacia para llenarla con lo que te encuentres por ahi"
		]
	};
	if(_typecls == "Whiteboard") exitWith {
		[
			nil,
			[OT_item_Map],
			20,
			"Un mapa para planificar tu proximo ataque. NO USES LA OPCION DORMIR sin hablar con el resto de jugadores"
		]
	};
	{
		if((_x select 0) == _typecls) exitWith {
			[
				_x select 3,
				_x select 2,
				_x select 1,
				nil
			]
		};
	}foreach(OT_Placeables);
}) params [
	["_attachAt", [0,2,1]],
	["_modeValues", []],
	["_cost", 0],
	["_description", ""]
];
attachAt = _attachAt;
modeValues = _modeValues;

modeFinished = false;
modeCancelled = false;

//Price check (on aisle 3)
private _money = player getVariable "money";
if(_cost > _money) exitWith {format["No puedes pagar esto, necesitas $%1",_cost] call OT_fnc_notifyMinor};

if !([getpos player,_typecls] call OT_fnc_canPlace) exitWith {
	if(_typecls == "Camp") exitWith {
		"Los campamentos no pueden estar junto a otro edificio" call OT_fnc_notifyMinor;
	};
	if(_typecls == "Base") exitWith {
		"Las bases no pueden estar tan cerca de pueblos o bases de la OTAN" call OT_fnc_notifyMinor;
	};
	"Debes estar cerca de una base o edificio de tu propiedad" call OT_fnc_notifyMinor
};

if(isNil "modeValue") then {
	modeValue = 0;
};

modeTarget = objNULL;
modeRedo = false;
if(isNil "modeRotation") then {
	modeRotation = 180;
};

if(_cost > 0) then {
	[format [
		"<t size='1.1' color='#eeeeee'>%1</t><br/><t size='0.8' color='#bbbbbb'>$%2</t><br/><t size='0.4' color='#bbbbbb'>%3</t><br/><br/><t size='0.5' color='#bbbbbb'>Q,E = Rotar<br/>Spacio = Cambiar objeto<br/>Enter = hecho<br/>Shift = Rotar rapido/Colocar varios<br/>Esc = Cancelar</t>",
		_typecls,
		[_cost, 1, 0, true] call CBA_fnc_formatNumber,
		_description
	], [safeZoneX + (0.8 * safeZoneW), (0.2 * safeZoneW)], 0.5, 10, 0, 0, 2] call OT_fnc_dynamicText;


	_keyhandler = {
		params ["_ctrl", "_key", "_shift", "_ctrlKey", "_alt"];
    
		private _dir = modeRotation;
		if(_key isEqualTo 19) exitWith {
			//R
			false
		};
		if (_key isEqualTo 16) exitWith {
			//Q
			private _amt = 1;
			if(_shift) then {_amt = 45};
			private _newdir = _dir - _amt;
			if(_newdir < 0) then {_newdir = _newdir + 360};
			modeTarget setDir (_newdir);
			modeRotation = _newDir;
			true
		};
		if (_key isEqualTo 18) exitWith {
			//E
			private _amt = 1;
			if(_shift) then {_amt = 45};
			private _newdir = _dir + _amt;
			if(_newdir > 359) then {_newdir = _newdir - 360};
			modeTarget setDir (_newdir);
			modeRotation = _newDir;
			true
		};
		if(_key isEqualTo 57) exitWith {
			//Space
			detach modeTarget;
			deleteVehicle modeTarget;
			modeValue = modeValue + 1;
			if(modeValue > ((count modeValues)-1)) then {modeValue = 0};

			private _cls = modeValues select modeValue;

			modeTarget = createVehicle [_cls, [0,0,0], [], 0, "CAN_COLLIDE"];
			modeTarget enableDynamicSimulation true;
			if(_cls == "B_Boat_Transport_01_F") then {
				_dir = _dir + 90;
			};

			clearWeaponCargoGlobal modeTarget;
			clearMagazineCargoGlobal modeTarget;
			clearBackpackCargoGlobal modeTarget;
			clearItemCargoGlobal modeTarget;

			modeTarget attachTo [player,attachAt];
			modeTarget setDir _dir;
			true
		};
		if(_key isEqualTo 28) exitWith {
			//Enter
			modeFinished = true;
			if(_shift) then {
				modeRedo = true;
			};
			true
		};
		if(_key isEqualTo 1) exitWith {
			//ESC
			modeCancelled = true;
			true
		};
		false
	};

	private _cls = modeValues select modeValue;
	private _handlerId = (findDisplay 46) displayAddEventHandler ["KeyDown",_keyhandler];
	modeTarget = createVehicle [_cls, [0,0,0], [], 0, "CAN_COLLIDE"];

	clearWeaponCargoGlobal modeTarget;
	clearMagazineCargoGlobal modeTarget;
	clearBackpackCargoGlobal modeTarget;
	clearItemCargoGlobal modeTarget;

	modeTarget attachTo [player,attachAt];
	modeTarget setDir modeRotation;
	if(_cls == "B_Boat_Transport_01_F") then {
		private _p = getDir modeTarget;
		private _v = getDir player;
		private _c = 360;

		private _dir = _c-((_c-_p)-(_c-_v));
		if(_dir >= 360) then {_dir = _dir - 360};

		modeTarget setDir _dir + 90;
	};

	waitUntil {
		sleep 0.5; 
		modeFinished
		|| modeCancelled
		|| (count attachedObjects player == 0)
		|| (vehicle player != player)
		|| (!alive player)
		|| (!isPlayer player)
	};

	(findDisplay 46) displayRemoveEventHandler ["KeyDown",_handlerId];

	{detach _x} forEach attachedObjects player;

	if(
		modeCancelled
		|| (vehicle player != player)
		|| (!alive player)
		|| (!isPlayer player)
	) then {
		detach modeTarget;
		deleteVehicle modeTarget;
	}else{
		if ([getpos player,_typecls] call OT_fnc_canPlace) then {
			[-_cost] call OT_fnc_money;
			modeTarget setPosATL [getPosATL modeTarget select 0,getPosATL modeTarget select 1,getPosATL player select 2];
			[modeTarget,getPlayerUID player] call OT_fnc_setOwner;
			modeTarget remoteExec["OT_fnc_initObjectLocal",0,modeTarget];
			if(_typecls == "Base" || _typecls == "Camp") then {
				// @todo remove this when done
				createVehicle ["Land_ClutterCutter_large_F", (getpos modeTarget), [], 0, "CAN_COLLIDE"];
			};

			if(_typecls isEqualTo "Base") then {
				createDialog "OT_dialog_name";
				ctrlSetText [1400,"Base"];
			};
			if(_typecls == "Camp") then {
				private _mrkid = format["%1-camp",getplayeruid player];
				createMarker [_mrkid,getpos modeTarget];
				_mrkid setMarkerPos (getpos modeTarget);
				private _camp = player getVariable["camp",[]];
				if(count _camp > 0) then {
					{
						private _t = typeof _x;
						if((_x call OT_fnc_getOwner) == getplayeruid player) then {
							if(_t == OT_item_Tent || _t == "Land_ClutterCutter_large_F") then {
								deleteVehicle _x;
							};
						};
					}foreach(_camp nearObjects 10);
				};
				player setVariable ["camp",getpos modeTarget];
				_mrkid setMarkerShape "ICON";
				_mrkid setMarkerType "ot_Camp";
				_mrkid setMarkerColor "ColorWhite";
				_mrkid setMarkerAlpha 1;
				_mrkid setMarkerText format ["Camp %1",name player];
				_builder = name player;
				{
					_desc = (getpos modeTarget) call BIS_fnc_locationDescription;
					[_x,format["Nuevo campamento %1",_desc],format["%1 coloco un campamento %2",_builder,_desc]] call BIS_fnc_createLogRecord;
				}foreach([] call CBA_fnc_players);
			};
		}else{
			detach modeTarget;
			deleteVehicle modeTarget;
			_typecls call {
				if(_this == "Camp") exitWith {"No puedes poner un campamento junto a una de tus propiedades" call OT_fnc_notifyMinor;};
				if(_this == "Base") exitWith {"Las bases no pueden estar cerca de pueblos, instalaciones de la OTAN u otras bases" call OT_fnc_notifyMinor;};
				"Debes estar cerca de un edificio de tu propiedad" call OT_fnc_notifyMinor;
			};
		};
	};
}else{
	if(_typecls != "Camp" && _typecls != "Base") then {
		"para colocar este objeto debes estar cerca de una de tus propiedades" call OT_fnc_notifyMinor;
	}else{
		"No puedes colocar un campamento tan cerca de un pueblo o una base." call OT_fnc_notifyMinor;
	};
};

//Cleanup public vars
modeTarget = nil;
modeCancelled = nil;
modeFinished = nil;
if(modeRedo) then {
	_typecls spawn OT_fnc_place;
}else{
	modeValue = nil;
}
