private _handled = false;

if(!dialog) then {
	if(count (player nearObjects [OT_workshopBuilding,10]) > 0) then {
		[] call OT_fnc_workshopDialog;
	}else{
		if((vehicle player) != player && count (player nearObjects [OT_portBuilding,30]) > 0) then {
			createDialog "OT_dialog_vehicleport";
			private _ft = server getVariable ["OT_fastTravelType",1];
			if(!OT_adminMode && _ft > 1) then {
				ctrlEnable [1600,false];
			};
		}else{
			if (player getVariable ["OT_tute_trigger",false]) then {
				player setVariable ["OT_tute_trigger",false,true];
				[] spawn {
					hint format["Tomate tu tiempo para explorar el menu principal, Cuando acabes mira el mapa (%1 tecla)","ShowMap" call OT_fnc_getAssignedKey];

					private _acekey = "Left Windows (default)";
					private _acebind = ["ACE3 Common","ace_interact_menu_InteractKey"] call CBA_fnc_getKeybind;
					if(count _acebind > 0) then {
						_acekey = (cba_keybinding_keynames) getVariable [str ((_acebind select 5) select 0),_acekey];
					};

					sleep 3;
					[
						format [
							"<t align='center'><t size='0.6' color='#ffffff'>Main Menu</t><br/><br/>
							<t size='0.5' color='#ffffff'>Desde este menu puedes ejecutar acciones basicas como reclutar civiles o viajar a tus propiedes, bases y campamentos aliados. Como puedes ver abajo a la derecha, esta casa te pertenece,así que puedes viajar rapido hasta aqui,siempre que no estes en busca y captura, lleves drogas encima o armas a la vista.<br/><br/>
							Para continuar, sal de este menu (Esc) y abre el mapa (%1 tecla)</t>",
							"ShowMap" call OT_fnc_getAssignedKey
						], 0, 0.2, 120, 1, 0, 2] call OT_fnc_dynamicText;

					waitUntil {uisleep 1; visibleMap};

					hint format[
						"Manten el boton derecho del raton para moverte por el mapa, zoom con la rueda del raton. cuando termines sal del mapa pulsando ESC.",
						"Action" call OT_fnc_getAssignedKey
					];
					sleep 3;
					[format [
						"<t align='left'><t size='0.7' color='#000000'>Stability</t><br/>
						<t size='0.6' color='#000000'>Las zonas amarilals indican pueblos con estabilidad baja. Los iconos azules indican instalaciones conocidad de la OTAN.</t><br/><br/>
						<t size='0.5' color='#101010'>%3</t>",
						OT_tutorial_backstoryText
					], -0.5, 0.5, 240, 1, 0, 2] call OT_fnc_dynamicText;

					waitUntil {uisleep 1; !visibleMap};
					hint "";
					sleep 3;

					[format [
						"<t align='center'><t size='0.6' color='#ffffff'>Interaction</t><br/>
						<t size='0.5' color='#ffffff'>Algunos objetos,incluyendo los que hay en tu casa,disponen de acciones que puedes hacer con ellos.Prueba moviendote al ammobox e interactua manteniendo la tecla (%1). mueve el ratón a 'Abrir' y suelta la tecla de interaccion.</t><br/><br/>",
						_acekey
					], 0, 0.2, 20, 1, 0, 2] call OT_fnc_dynamicText;

					sleep 20;
					_gundealer = spawner getVariable format["gundealer%1",(getpos player) call OT_fnc_nearestTown];
					[player,getpos _gundealer,"Gun Dealer"] call OT_fnc_givePlayerWaypoint;
					sleep 3;
					hint "Vete y habla con tu traficante de armas local. Vete a la marca del mapa. No te preocupes ya que no llevas nada ilegal (no uses la vision nocturna).";

					waitUntil {uisleep 1; (player distance2d getPosASL _gundealer) < 5};


					_lines = [
						"Hola? Te conozco?",
						format ["No. Me llamo %1 y he oido que tal vez puedas ayudarme",name player],
						"Ah, si? Depende. En que puedo ayudarte?"
					];

					_gundealer = spawner getVariable format["gundealer%1",(getpos player) call OT_fnc_nearestTown];
					_done = {
						_options = [
							[
								"Estoy harto de la OTAN. que podemos hacer?",
								{
									_gundealer = spawner getVariable format["gundealer%1",(getpos player) call OT_fnc_nearestTown];
									[
										player,
										_gundealer,
										[
											(_this select 0),
											"Ya veo. Seguro que no te gusto que disparasen a los manifestantes, tengo por aqui una pistola vieja.",
											"Que cojones quieres que haga con esto?",
											"Ni idea. Pero todos los tipos que han venido pro aqui quejandose de la OTAN querian una pistola y yo no hago preguntas.",
											"Um.. gracias...supongo",
											"Tranqui, cualquier cosa que hagas a mi me viene bien. Te pagare si te ocupas de ellos."
										],
										{
											hint format[
												"La pistola esta en tu bolsillo, puedes equiparla desde el inventario (%1 tecla) arrastrandola a tus manos. Pero.... ten cuidado, Si la OTAN te ve con un arma disparara, sin avisar, asi que mantenla escondida hata que....mmm... la necesites",
												"Gear" call OT_fnc_getAssignedKey
											];
											[{
												playSound "3DEN_notificationDefault";
												[] call (OT_tutorialMissions select 0);
												hint "Has terminado el tutorial. Suerte!";
												player setVariable ["OT_tute_inProgress", false];
											},0,10] call CBA_fnc_waitAndExecute;
										}
									] call OT_fnc_doConversation;
									player addItemToUniform OT_item_BasicGun;
									player addItemToUniform OT_item_BasicAmmo;
									player addItemToUniform OT_item_BasicAmmo;
									player addItemToUniform OT_item_BasicAmmo;
								}
							],
							[
								format ["Hay mucho crimen en %1, y la OTAN y la Policia no hacen nada",OT_nation],
								{
									_gundealer = spawner getVariable format["gundealer%1",(getpos player) call OT_fnc_nearestTown];
									[
										player,
										_gundealer,
										[
											(_this select 0),
											"Tienes razon. ya que nos disparan por lo menos que nos protejan de las bandas",
											"Pues si",
											"Sabes?, tengo una pistola vieja por aqui.",
											"Y que quieres que haga yo con esto?",
											format[
												"Los comerciantes locales pagan por hacer...desaparecer a miembros de bandas en %1, Vete y caza a algunos!",
												OT_nation
											],
											"Vale... gracias",
											"A mandar, ven si necesitas municion o cosas que no te ventan en tiendas..digamos....convencionales."
										],
										{
											hint format[
												"La pistola esta en tu bolsillo, puedes equiparla desde el inventario (%1 tecla) arrastrandola a tus manos. Pero.... ten cuidado, Si la OTAN o una banda te ve con un arma,disparara sin avisar, asi que mantenla escondida hata que....mmm... la necesites",
												"Gear" call OT_fnc_getAssignedKey
											];
											[{
												playSound "3DEN_notificationDefault";
												[] call (OT_tutorialMissions select 1);
												hint "Has completado el tutorial. Suerte!";
												player setVariable ["OT_tute_inProgress", false];
											},1,10] call CBA_fnc_waitAndExecute;
										}
									] call OT_fnc_doConversation;
									player addItemToUniform OT_item_BasicGun;
									player addItemToUniform OT_item_BasicAmmo;
									player addItemToUniform OT_item_BasicAmmo;
									player addItemToUniform OT_item_BasicAmmo;
								}
							],
							[
								"Necesito pasta y no me importa infringir la ley",
								{
									_gundealer = spawner getVariable format["gundealer%1",(getpos player) call OT_fnc_nearestTown];
									[
										player,
										_gundealer,
										[
											(_this select 0),
											"Con todo lo que esta pasando...no se... toma esto",
											"Hierba?,que hago yo con esto?",
											"Vendesela a los civiles. Igual asi se calman",
											"Um.. Gracias",
											"Sin problema. Ven cuando quieras mas"
										],
										{
											hint format[
												"Las drogras estan en tu bolsillo, puedes verlo en el inventario (%1 tecla). tambien puedes fumartelo tu mismo para relajarte usando la interaccion ACE",
												"Gear" call OT_fnc_getAssignedKey
											];
											[{
												playSound "3DEN_notificationDefault";
												[] call (OT_tutorialMissions select 2);
												hint "Has terminado el tutorial, suerte!";
												player setVariable ["OT_tute_inProgress", false];
											},2,10] call CBA_fnc_waitAndExecute;
										}
									] call OT_fnc_doConversation;
									player addItemToUniform "OT_Ganja";
								}
							],
							[
								"Quiero hacer dinero legalmente",
								{
									_gundealer = spawner getVariable format["gundealer%1",(getpos player) call OT_fnc_nearestTown];
									[
										player,
										_gundealer,
										[
											(_this select 0),
											"En serio?.. esto es Tanoa muchacho... tal vez puedas desguazar algun vehiculo roto que te encuentres... pero no lo veo... busca un trabajo honrado como el mio",
											"OK, Gracias",
											"De nada hombre... nos vemos"
										],
										{
											hint format["Los vehiculos destrozados pueden ser desguazados con las herramientas,Deberias tener unas en tu casa. Las tiendas estan marcadas en el mapa con un icono que indica lo que compran/venden. Los pueblos mas pequeños y con menor estabilidad pagan mas por lo que vendas.",
												"Gear" call OT_fnc_getAssignedKey
											];
											[{
												playSound "3DEN_notificationDefault";
												[] call (OT_tutorialMissions select 3);
												hint "Has acabado el turorial, suerte!";
												player setVariable ["OT_tute_inProgress", false];
											},3,10] call CBA_fnc_waitAndExecute;
										}
									] call OT_fnc_doConversation;

								}
							]
						];

						_options call OT_fnc_playerDecision;
					};
					[_gundealer,player,_lines,_done] call OT_fnc_doConversation;
				};
			};
			if(hcShownBar && count (hcSelected player) > 0) exitWith {
				createDialog "OT_dialog_squad";
			};
			if(!hcShownBar && ({!isplayer _x} count (groupSelectedUnits player) > 0)) exitWith {
				{
					if(isPlayer _x) then {
						player groupSelectUnit [_x,false];
					};
				}foreach(groupSelectedUnits player);
				createDialog "OT_dialog_command";
			};
			if(vehicle player != player) exitWith {
				private _ferry = player getVariable ["OT_ferryDestination",[]];
				if(count _ferry isEqualTo 3) exitWith {
					_veh = vehicle player;

					disableUserInput true;
					_town = _ferry call OT_fnc_nearestTown;

					private _cost = player getVariable ["OT_ferryCost",0];
					if((player getVariable ["money",0]) < _cost) exitWith {
						"No puedes pagarte el viaje!" call OT_fnc_notifyMinor;
						disableUserInput false;
					};
					[-_cost] call OT_fnc_money;
					cutText [format["acelerando el viaje a %1",_town],"BLACK",2];
					player setVariable ["OT_ferryDestination",[],false];
					[_ferry,_veh] spawn {
						params ["_pos","_veh"];
						sleep 2;
						private _driver = driver _veh;
						private _e = [];
						{
							private _p = [_pos,[0,50]] call SHK_pos_fnc_pos;
							moveOut _x;
							_x allowDamage false;
							_x setPos _p;
							_e pushback _x;
						} foreach(crew vehicle player);
						sleep 2;
						disableUserInput false;
						cutText ["","BLACK IN",3];
						deleteVehicle _driver;
						deleteVehicle _veh;
						{
							_x allowDamage true;
						}foreach(_e);
					};
				};
				call {
					if(driver vehicle player != player) exitWith {
						[] spawn OT_fnc_mainMenu;
					};
					if(call OT_fnc_playerIsAtWarehouse) exitWith {
						createDialog "OT_dialog_vehiclewarehouse";
					};
					if(call OT_fnc_playerIsAtHardwareStore) exitWith {
						createDialog "OT_dialog_vehiclehardware";
					};
					if(call OT_fnc_playerIsAtStore) exitWith {
						createDialog "OT_dialog_vehiclestore";
					};
					createDialog "OT_dialog_vehicle";
					[] spawn OT_fnc_vehicleDialog;
				};
			};

			private _cTarget = cursorTarget;
			if((_cTarget isKindOf "CAManBase") && (alive _cTarget) && (!isplayer _cTarget) && !(side _cTarget isEqualTo west) && (_cTarget distance player) < 10) exitWith {
				_cTarget call OT_fnc_talkToCiv;
			};
			[] spawn OT_fnc_mainMenu;
		};
	};
}else{
	closeDialog 0;
};
_handled = true;

_handled
