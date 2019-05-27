class OT_dialog_start
{
	idd=-1;
	movingenable=false;

	class controlsBackground {
		class Background: RscOverthrowStructuredText
		{
			idc = 1100;
			x = 0.381406 * safezoneW + safezoneX;
			y = 0.137 * safezoneH + safezoneY;
			w = 0.252656 * safezoneW;
			h = 0.407 * safezoneH;
			colorBackground[] = {0.1,0.1,0.1,1};
			colorActive[] = {0.1,0.1,0.1,1};
		};
	};

	class controls
	{
		class RscButton_1600: RscOverthrowButton
		{
			idc = 1600;
			action = "closeDialog 0; createDialog""OT_dialog_load"";";
			text = "Cargar ultimo guardado"; //--- ToDo: Localize;
			x = 0.448438 * safezoneW + safezoneX;
			y = 0.313 * safezoneH + safezoneY;
			w = 0.118594 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Continuar desde ultimo guardado"; //--- ToDo: Localize;
		};
		class RscButton_1601: RscOverthrowButton
		{
			idc = 1601;
			action = "closeDialog 0;createDialog ""OT_dialog_newgame"";";

			text = "New Game"; //--- ToDo: Localize;
			x = 0.448438 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.118594 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Nuevo Juego (ESTA OPCION BORRA LOS SALVADOS ANTERIORES)"; //--- ToDo: Localize;
		};
		class background_picture: RscOverthrowPicture
		{
			idc = 1200;
			text = "\overthrow_main\ui\logo_overthrow.paa";
			x = 0.399969 * safezoneW + safezoneX;
			y = 0.038 * safezoneH + safezoneY;
			w = 0.216563 * safezoneW;
			h = 0.363 * safezoneH;
		};
	};
};

class OT_dialog_load
{
	idd=15150;
	movingenable=false;

	class controlsBackground {
		class background1: RscOverthrowStructuredText
		{
			idc = -1;
			x = 0.381406 * safezoneW + safezoneX;
			y = 0.137 * safezoneH + safezoneY;
			w = 0.252656 * safezoneW;
			h = 0.572 * safezoneH;
			colorBackground[] = {0.1,0.1,0.1,1};
		};
	};

	class controls
	{
		class EditBox: RscEditMulti
		{
			idc = 1400;
			text = "";
			x = 0.386562 * safezoneW + safezoneX;
			y = 0.291 * safezoneH + safezoneY;
			w = 0.242344 * safezoneW;
			h = 0.231 * safezoneH;
		};
		class LoadNormal: RscOverthrowButton
		{
			idc = -1;
			x = 0.448438 * safezoneW + safezoneX;
			y = 0.621 * safezoneH + safezoneY;
			w = 0.118594 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Continua el ultimo salvado"; //--- ToDo: Localize;
			action = "closeDialog 0;[] remoteExec ['OT_fnc_loadGame',2,false];";
			text = "Cargar Guardado (Original)"; //--- ToDo: Localize;
		};
		class LoadString: RscOverthrowButton
		{
			idc = -1;
			x = 0.448438 * safezoneW + safezoneX;
			y = 0.533 * safezoneH + safezoneY;
			w = 0.118594 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Cargar string como guardado"; //--- ToDo: Localize;
			action = "closeDialog 0; private _data = parseSimpleArray ctrlText ((findDisplay 15150) displayCtrl 1400);  [_data] remoteExec ['OT_fnc_loadGame',2,false];";
			text = "Import Save"; //--- ToDo: Localize;
		};
		class Logo_Picture: RscOverthrowPicture
		{
			idc = -1;
			text = "\overthrow_main\ui\logo_overthrow.paa";
			x = 0.399969 * safezoneW + safezoneX;
			y = 0.038 * safezoneH + safezoneY;
			w = 0.216563 * safezoneW;
			h = 0.363 * safezoneH;
		};
	};
};

class OT_dialog_vehicle
{
	idd=-1;
	movingenable=false;

	class controlsBackground {
		class RscStructuredText_1103: RscOverthrowStructuredText
		{
			idc = 1103;

			text = "";
			x = 0 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 0.159844 * safezoneW;
			h = 1 * safezoneH;
			colorBackground[] = {0.1,0.1,0.1,1};
		};
	};

	class controls
	{
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by ARMAzac, v1.063, #Xeqozy)
		////////////////////////////////////////////////////////
		class RscButton_1600: RscOverthrowButton
		{
			idc = 1600;
			action = "closeDialog 0;[] spawn OT_fnc_fastTravel;";
			tooltip = "Fast travels this vehicle and it's occupants"; //--- ToDo: Localize;

			text = "Viaje Rápido"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.126 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.066 * safezoneH;
		};
		class RscButton_1614: RscOverthrowButton
		{
			idc = 1614;
			action = "closeDialog 0;[player] spawn OT_fnc_recover;";
			tooltip = "desvalijar cuerpos en 150m. a la redonda"; //--- ToDo: Localize;

			text = "looteo"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.214 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.066 * safezoneH;
		};
		class RscButton_1613: RscOverthrowButton
		{
			idc = 1613;
			text = "Curro"; //--- ToDo: Localize;
			action = "call OT_fnc_jobsDialog";

			x = 0.005 * safezoneW + safezoneX;
			y = 0.302 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;

		};
		class RscButton_1601: RscOverthrowButton
		{
			idc = 1601;
			text = "Transferir desde"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.478 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "transfiere el contenido del contenedor más cercano a este vehículo"; //--- ToDo: Localize;
			action = "closeDialog 0;[] spawn OT_fnc_transferFrom;";
		};
		class RscButton_1602: RscOverthrowButton
		{
			idc = 1602;
			text = "Transferir hacia"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.390 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Transfiere el contenido de este vehículo al contenedor más cercano"; //--- ToDo: Localize;
			action = "closeDialog 0;[] spawn OT_fnc_transferTo;";
		};
		class RscButton_1603: RscOverthrowButton
		{
			idc = 1603;
			text = "Transferir objetos legales"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.566 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Transfiere los objetos legales (vendibles) del contenedor más cercano a este vehículo"; //--- ToDo: Localize;
			action = "closeDialog 0;[] spawn OT_fnc_transferLegit;";
		};
		class RscButton_1604: RscOverthrowButton
		{
			idc = 1604;
			text = "Coger objetos legales"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.654 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Coge los objetos legales (vendibles) de este vehículo a tu inventario"; //--- ToDo: Localize;
			action = "closeDialog 0;[] spawn OT_fnc_takeLegit;";
		};
		class RscButton_1605: RscOverthrowButton
		{
			idc = 1605;
			text = "Cerrar vehículo"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.742 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Cierra el vehículo para que solo tu puedas conducirlo o acceder al inventario"; //--- ToDo: Localize;
			action = "closeDialog 0;[] call OT_fnc_lockVehicle;";
		};
		class RscButton_1612: RscOverthrowButton
		{
			idc = 1612;
			action = "call OT_fnc_optionsDialog";

			text = "Opciones"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.885 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.066 * safezoneH;
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////

	};
};

class OT_dialog_vehiclewarehouse
{
	idd=-1;
	movingenable=false;

	class controlsBackground {
		class RscStructuredText_1103: RscOverthrowStructuredText
		{
			idc = 1103;

			text = "";
			x = 0 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 0.159844 * safezoneW;
			h = 1 * safezoneH;
			colorBackground[] = {0.1,0.1,0.1,1};
		};
	};

	class controls
	{
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by ARMAzac, v1.063, #Xeqozy)
		////////////////////////////////////////////////////////

		class RscButton_1600: RscOverthrowButton
		{
			idc = 1600;
			text = "Viaje rápido"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.39 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;
			action = "closeDialog 0;[] spawn OT_fnc_fastTravel;";
			tooltip = "Realiza un viaje rápido de este vehículo y sus ocupantes"; //--- ToDo: Localize;
		};
		class RscButton_1601: RscOverthrowButton
		{
			idc = 1601;
			text = "Coger desde"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.654 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Coger del almacén"; //--- ToDo: Localize;
			action = "closeDialog 0;createDialog ""OT_dialog_warehouse"";[] call OT_fnc_warehouseDialog;";
		};
		class RscButton_1602: RscOverthrowButton
		{
			idc = 1602;
			text = "Almacenar todo"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.478 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Almacena el contenido del vehículo en el almacén"; //--- ToDo: Localize;
			action = "closeDialog 0;[] spawn OT_fnc_transferTo;";
		};
		class RscButton_1603: RscOverthrowButton
		{
			idc = 1603;
			text = "Transferir objetos legales"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.566 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Coge los objetos legales del almacén"; //--- ToDo: Localize;
			action = "closeDialog 0;[] spawn OT_fnc_transferLegit;";
		};
		class RscButton_1612: RscOverthrowButton
		{
			idc = 1612;
			action = "call OT_fnc_optionsDialog";

			text = "Opciones"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.885 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.066 * safezoneH;
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////

	};
};

class OT_dialog_vehicleport
{
	idd=-1;
	movingenable=false;

	class controlsBackground {
		class RscStructuredText_1103: RscOverthrowStructuredText
		{
			idc = 1103;

			text = "";
			x = 0 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 0.159844 * safezoneW;
			h = 1 * safezoneH;
			colorBackground[] = {0.1,0.1,0.1,1};
		};
	};

	class controls
	{
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by ARMAzac, v1.063, #Xeqozy)
		////////////////////////////////////////////////////////

		class RscButton_1600: RscOverthrowButton
		{
			idc = 1600;
			text = "Viaje rápido"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.39 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;
			action = "closeDialog 0;[] spawn OT_fnc_fastTravel;";
			tooltip = "Realiza un viaje rápido de este vehículo y sus ocupantes"; //--- ToDo: Localize;
		};
		class RscButton_1601: RscOverthrowButton
		{
			idc = 1601;
			text = "Importacion"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.654 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Importa mercancia del mercado global"; //--- ToDo: Localize;
			action = "closeDialog 0;createDialog ""OT_dialog_import"";[] call OT_fnc_importDialog;";
		};
		class RscButton_1602: RscOverthrowButton
		{
			idc = 1602;
			text = "Exportar todo"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.566 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Exporta el contenido del vehículo"; //--- ToDo: Localize;
			action = "closeDialog 0;[] spawn OT_fnc_exportAll;";
		};
		class RscButton_1612: RscOverthrowButton
		{
			idc = 1612;
			action = "call OT_fnc_optionsDialog";

			text = "Opciones"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.885 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.066 * safezoneH;
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////

	};
};

class OT_dialog_vehiclehardware
{
	idd=-1;
	movingenable=false;

	class controlsBackground {
		class RscStructuredText_1103: RscOverthrowStructuredText
		{
			idc = 1103;

			text = "";
			x = 0 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 0.159844 * safezoneW;
			h = 1 * safezoneH;
			colorBackground[] = {0.1,0.1,0.1,1};
		};
	};

	class controls
	{
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by ARMAzac, v1.063, #Xeqozy)
		////////////////////////////////////////////////////////

		class RscButton_1600: RscOverthrowButton
		{
			idc = 1600;
			text = "Viaje rápido"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.39 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;
			action = "closeDialog 0;[] spawn OT_fnc_fastTravel;";
			tooltip = "Realiza un viaje rápido de este vehículo y sus ocupantes"; //--- ToDo: Localize;
		};
		class RscButton_1601: RscOverthrowButton
		{
			idc = 1601;
			text = "Comprar"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.654 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Compra de esta tienda de herramientas"; //--- ToDo: Localize;
			action = "closeDialog 0;[] call OT_fnc_buyHardwareDialog;";
		};
		class RscButton_1602: RscOverthrowButton
		{
			idc = 1602;
			text = "Vender"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.566 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Vende a esta tienda de herramientas"; //--- ToDo: Localize;
			action = "closeDialog 0;[] call OT_fnc_sellHardwareDialog;";
		};
		class RscButton_1612: RscOverthrowButton
		{
			idc = 1612;
			action = "call OT_fnc_optionsDialog";

			text = "Opciones"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.885 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.066 * safezoneH;
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////

	};
};

class OT_dialog_vehiclestore
{
	idd=-1;
	movingenable=false;

	class controlsBackground {
		class RscStructuredText_1103: RscOverthrowStructuredText
		{
			idc = 1103;

			text = "";
			x = 0 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 0.159844 * safezoneW;
			h = 1 * safezoneH;
			colorBackground[] = {0.1,0.1,0.1,1};
		};
	};

	class controls
	{
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by ARMAzac, v1.063, #Xeqozy)
		////////////////////////////////////////////////////////

		class RscButton_1600: RscOverthrowButton
		{
			idc = 1600;
			text = "Viaje Rápido "; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.39 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;
			action = "closeDialog 0;[] spawn OT_fnc_fastTravel;";
			tooltip = "Realiza un viaje rápido de este vehículo y sus ocupantes"; //--- ToDo: Localize;
		};
		class RscButton_1601: RscOverthrowButton
		{
			idc = 1601;
			text = "Comprar"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.654 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Compra de esta tienda"; //--- ToDo: Localize;
			action = "closeDialog 0;[] call OT_fnc_buyDialogVehicle;";
		};
		class RscButton_1602: RscOverthrowButton
		{
			idc = 1602;
			text = "Vender"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.566 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Vende a esta tienda"; //--- ToDo: Localize;
			action = "closeDialog 0;[] call OT_fnc_sellDialogVehicle;";
		};
		class RscButton_1612: RscOverthrowButton
		{
			idc = 1612;
			action = "call OT_fnc_optionsDialog";

			text = "Opciones"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.885 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.066 * safezoneH;
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////

	};
};

class OT_dialog_command
{
	idd=-1;
	movingenable=false;

	class controlsBackground {
		class RscStructuredText_1103: RscOverthrowStructuredText
		{
			idc = 1103;

			text = "";
			x = 0 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 0.159844 * safezoneW;
			h = 1 * safezoneH;
			colorBackground[] = {0.1,0.1,0.1,1};
		};
	};

	class controls
	{
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by ARMAzac, v1.063, #Xeqozy)
		////////////////////////////////////////////////////////

		class RscButton_1601: RscOverthrowButton
		{
			idc = 1601;
			text = "Desvalijar"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Manda a la IA seleccionada a lootear y meter el contenido en este vehículo"; //--- ToDo: Localize;
			action = "closeDialog 0;[] spawn OT_fnc_orderLoot;";
		};
		class RscButton_1602: RscOverthrowButton
		{
			idc = 1602;
			text = "Abrir inventario"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.324 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Manda a la IA sellecionada a abrir el inventario más cercano"; //--- ToDo: Localize;
			action = "closeDialog 0;[] spawn OT_fnc_orderOpenInventory;";
		};
		class RscButton_1603: RscOverthrowButton
		{
			idc = 1603;
			text = "Dividir escuadra"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Divide las unidades seleccionadas en una nueva escuadra"; //--- ToDo: Localize;
			action = "closeDialog 0;[] spawn OT_fnc_createSquad;";
		};
		class RscButton_1612: RscOverthrowButton
		{
			idc = 1612;
			action = "call OT_fnc_optionsDialog";

			text = "Opciones"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.885 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.066 * safezoneH;
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////

	};
};

class OT_dialog_squad
{
	idd=-1;
	movingenable=false;

	class controlsBackground {
		class RscStructuredText_1103: RscOverthrowStructuredText
		{
			idc = 1103;

			text = "";
			x = 0 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 0.159844 * safezoneW;
			h = 1 * safezoneH;
			colorBackground[] = {0.1,0.1,0.1,1};
		};
	};

	class controls
	{
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by ARMAzac, v1.063, #Xeqozy)
		////////////////////////////////////////////////////////

		class RscButton_1601: RscOverthrowButton
		{
			idc = 1601;
			text = "Asignar vehículo"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.324 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Assigna el vehículo al que estás mirando a una escuadra IA"; //--- ToDo: Localize;
			action = "closeDialog 0;[] call OT_fnc_squadAssignVehicle;";
		};
		class RscButton_1602: RscOverthrowButton
		{
			idc = 1602;
			text = "Embarcar"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Ordena a una escuadra IA entrar en un vehículo"; //--- ToDo: Localize;
			action = "closeDialog 0;[] call OT_fnc_squadGetIn;";
		};
		class RscButton_1603: RscOverthrowButton
		{
			idc = 1603;
			text = "Desembarcar"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "ordena a una escuadra IA desembarcar"; //--- ToDo: Localize;
			action = "closeDialog 0;[] call OT_fnc_squadGetOut;";
		};
		class RscButton_1604: RscOverthrowButton
		{
			idc = 1604;
			text = "Entra en mi vehículo"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.588 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Ordena a una escuadra entrar en tu vehículo"; //--- ToDo: Localize;
			action = "closeDialog 0;[] call OT_fnc_squadGetInMyVehicle;";
		};
		class RscButton_1612: RscOverthrowButton
		{
			idc = 1612;
			action = "call OT_fnc_optionsDialog";

			text = "Opciones"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.885 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.066 * safezoneH;
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////

	};
};

class OT_dialog_options
{
	idd=-1;
	movingenable=false;

	class controls
	{
		class RscButton_1600: RscOverthrowButton
		{
			idc = 1600;
			action = "closeDialog 0;[player] remoteExec ['OT_fnc_saveGame',2,false];";

			text = "GUARDADO PERSISTENTE (USAR ESTE)"; //--- ToDo: Localize;
			x = 0.386563 * safezoneW + safezoneX;
			y = 0.225 * safezoneH + safezoneY;
			w = 0.2475 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "SISTEMA DE GUARDADO SEGURO (incluso con actualizaciones de ARMA).Para cargarlo, reinicia la misión y elige CARGAR PERSISTENTE"; //--- ToDo: Localize;
		};
		class RscButton_1607: RscOverthrowButton
		{
			idc = 1607;
			action = "[] remoteExec [""OT_fnc_autoSaveToggle"",2];";
			text = "Tiempo de autoguardado"; //--- ToDo: Localize;
			x = 0.386562 * safezoneW + safezoneX;
			y = 0.313 * safezoneH + safezoneY;
			w = 0.118594 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Elige entre (0/5/10/15/30/45/60) minutos.\ el cero lo deshabilita!"; //--- ToDo: Localize;
		};
		class RscButton_1608: RscOverthrowButton
		{
			idc = 1608;
			action = "[] remoteExec [""OT_fnc_autoloadToggle"",2]";
			text = "Elegir autoloading"; //--- ToDo: Localize;
			x = 0.515469 * safezoneW + safezoneX;
			y = 0.313 * safezoneH + safezoneY;
			w = 0.118594 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Autoload de la misión en SERVIDORES DEDICADOS";
		};

		class RscButton_1601: RscOverthrowButton
		{
			idc = 1601;
			action = "OT_spawnCivPercentage = OT_spawnCivPercentage - 0.01; if(OT_spawnCivPercentage < 0) then {OT_spawnCivPercentage = 0};publicVariable 'OT_spawnCivPercentage';hint format['Civilian spawn now at %1%2',OT_spawnCivPercentage*100,'%'];";

			text = "Civ % --"; //--- ToDo: Localize;
			x = 0.386562 * safezoneW + safezoneX;
			y = 0.511 * safezoneH + safezoneY;
			w = 0.118594 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Disminuye la cantidad de civiles que spawnean en pueblos"; //--- ToDo: Localize;
		};
		class RscButton_1602: RscOverthrowButton
		{
			idc = 1602;
			action = "OT_spawnCivPercentage = OT_spawnCivPercentage + 0.01; if(OT_spawnCivPercentage < 0) then {OT_spawnCivPercentage = 0};publicVariable 'OT_spawnCivPercentage';hint format['Civilian spawn now at %1%2',OT_spawnCivPercentage*100,'%'];";

			text = "Civ % ++"; //--- ToDo: Localize;
			x = 0.515469 * safezoneW + safezoneX;
			y = 0.511 * safezoneH + safezoneY;
			w = 0.118594 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Aumenta la cantidad de civiles que spawnean en pueblos"; //--- ToDo: Localize;
		};
		class RscButton_1603: RscOverthrowButton
		{
			idc = 1603;
			action = "call OT_fnc_decreaseTax";

			text = "Impuestos % --"; //--- ToDo: Localize;
			x = 0.386562 * safezoneW + safezoneX;
			y = 0.61 * safezoneH + safezoneY;
			w = 0.118594 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Baja la tasa de impuestos de la resistencia"; //--- ToDo: Localize;
		};
		class RscButton_1604: RscOverthrowButton
		{
			idc = 1604;
			action = "call OT_fnc_increaseTax";

			text = "Impuestos % ++"; //--- ToDo: Localize;
			x = 0.515469 * safezoneW + safezoneX;
			y = 0.61 * safezoneH + safezoneY;
			w = 0.118594 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Sube la tasa de impuestos de la resistencia"; //--- ToDo: Localize;
		};
		class RscButton_1605: RscOverthrowButton
		{
			idc = 1605;
			action = "call OT_fnc_cleanDead;";
			text = "limpieza de cuerpos/restos"; //--- ToDo: Localize;
			x = 0.386562 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.118594 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Eliminar definitivamente los cadaveres, restos, vehículos inútiles, etc"; //--- ToDo: Localize;
		};
		class RscButton_1606: RscOverthrowButton
		{
			idc = 1606;
			action = "[[0,0],""setFog"",TRUE,FALSE] spawn BIS_fnc_MP";

			text = "Limpiar Niebla"; //--- ToDo: Localize;
			x = 0.515469 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.118594 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Limpia la niebla"; //--- ToDo: Localize;
		};
		class RscText_1009: RscOverthrowButton
		{
			idc = 1609;
			action = "call OT_fnc_toggleZeus;";
			text = "Activar/desactivar ZEUS"; //--- ToDo: Localize;
			x = 0.386562 * safezoneW + safezoneX;
			y = 0.709 * safezoneH + safezoneY;
			w = 0.2475 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Activar o desactivar ZEUS"; //--- ToDo: Localize;
		};
	};
};

class OT_dialog_upload
{
	idd=49558;
	movingenable=false;
	onLoad = "params [""_display""]; _display displayAddEventHandler [""KeyDown"", ""if ((_this select 1) == 1) then { true }""];";

	class controlsBackground
	{
		class background1: RscOverthrowText
		{
			idc = -1;
			text = "EXPORTAR MISION OVERTHROW"; //--- ToDo: Localize;
			x = 0.29375 * safezoneW + safezoneX;
			y = 0.225 * safezoneH + safezoneY;
			w = 0.4125 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
		};
		class background2: RscOverthrowText
		{
			idc = -1;
			x = 0.29375 * safezoneW + safezoneX;
			y = 0.247 * safezoneH + safezoneY;
			w = 0.4125 * safezoneW;
			h = 0.528 * safezoneH;
			colorBackground[] = {-1,-1,-1,0.7};
		};
		class background3: RscOverthrowText
		{
			idc = -1;
			x = 0.298905 * safezoneW + safezoneX;
			y = 0.577 * safezoneH + safezoneY;
			w = 0.402187 * safezoneW;
			h = 0.143 * safezoneH;
			colorBackground[] = {-1,-1,-1,0.5};
		};
	};
	class controls
	{
		class EditBox: RscEdit
		{
			idc = 1;
			style= 16;
			x = 0.298906 * safezoneW + safezoneX;
			y = 0.258 * safezoneH + safezoneY;
			w = 0.402187 * safezoneW;
			h = 0.308 * safezoneH;
			canModify = 0;
			font="EtelkaMonospacePro";
			colorBackground[] = {-1,-1,-1,0.75};
		};
		class LegalControlGroup: RscControlsGroup
		{
			idc = -1;
			x = 0.298905 * safezoneW + safezoneX;
			y = 0.577 * safezoneH + safezoneY;
			w = 0.402187 * safezoneW;
			h = 0.143 * safezoneH;
			class Controls
			{
				class LegalText: RscOverthrowStructuredText
				{
					idc = 5;
					x = 0 * safezoneW;
					y = 0 * safezoneH;
					w = 0.397031 * safezoneW;
					h = 0.143 * safezoneH;
					text = "";
					colorBackground[] = {-1,-1,-1,0};
				};
			};
		};
		class CancelButton: RscOverthrowStructuredText
		{
			idc = -1;
			text = "<t align='center' font='PuristaBold' color='#FFFFFF'>CERRAR MENÚ</t>"; //--- ToDo: Localize;
			onMouseButtonClick = "playSound ""click""; closeDialog 0;";
			x = 0.298906 * safezoneW + safezoneX;
			y = 0.731 * safezoneH + safezoneY;
			w = 0.402187 * safezoneW;
			h = 0.033 * safezoneH;
			onMouseEnter = "(_this select 0) ctrlSetStructuredText parseText ""<t align='center' font='PuristaBold' color='#00FF00'>CLOSE MENU</t>""; (_this select 0) ctrlCommit 0.5; ";
			onMouseExit = "(_this select 0) ctrlSetStructuredText parseText ""<t align='center' font='PuristaBold' color='#FFFFFF'>CLOSE MENU</t>""; (_this select 0) ctrlCommit 0.5; ";
			colorBackground[] = {-1,-1,-1,0.7};
		};
	};
};

class OT_dialog_main
{
	idd=8001;
	movingenable=false;

	class controlsBackground {
		class RscStructuredText_1103: RscOverthrowStructuredText
		{
			idc = 1103;

			text = "";
			x = 0 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 0.159844 * safezoneW;
			h = 1 * safezoneH;
			colorBackground[] = {0.1,0.1,0.1,1};
		};
		class RscStructuredText_1104: RscOverthrowStructuredText
		{
			idc = 1104;

			text = "";
			x = 0.876406 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 0.123759 * safezoneW;
			h = 1 * safezoneH;
			colorBackground[] = {0.1,0.1,0.1,1};
		};
	};

	class controls
	{
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by ARMAzac, v1.063, #Mucomo)
		////////////////////////////////////////////////////////
		class RscButton_1699: RscOverthrowButton
		{
			idc = 1699;
			action = "closeDialog 0;[] spawn OT_fnc_mapInfoDialog";

			text = "Situación del mapa (Inteligencia)"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.247 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Conseguir información sobre estabilidad y datos en el mapa"; //--- ToDo: Localize;
		};
		class RscStructuredText_1100: RscOverthrowStructuredText
		{
			idc = 1100;

			x = 0.005 * safezoneW + safezoneX;
			y = 0.302 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.1 * safezoneH;
			colorBackground[] = {0,0,0,0.4};
		};
		class RscStructuredText_1150: RscOverthrowStructuredText
		{
			idc = 1150;

			x = 0.16 * safezoneW + safezoneX;
			y = 0.302 * safezoneH + safezoneY;
			w = 0.3 * safezoneW;
			h = 0.3 * safezoneH;
			colorBackground[] = {0,0,0,0};
		};
		class RscButton_1600: RscOverthrowButton
		{
			idc = 1600;
			action = "closeDialog 0;[] spawn OT_fnc_fastTravel";

			text = "Viaje rápido"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.423 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Viaje instantaneo entre zonas controladas"; //--- ToDo: Localize;
		};
		class RscButton_1613: RscOverthrowButton
		{
			idc = 1613;
			action = "closeDialog 0;[] spawn OT_fnc_resistanceDialog";

			text = "La Resistencia"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.478 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Gestionar negocios y caja comun de la resistencia"; //--- ToDo: Localize;
		};
		class RscButton_1614: RscOverthrowButton
		{
			idc = 1614;
			action = "closeDialog 0;[] spawn OT_fnc_jobsDialog";

			text = "Curros activos"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.533 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Trabajos y tareas actualmente activadas"; //--- ToDo: Localize;
		};
		class RscButton_1601: RscOverthrowButton
		{
			idc = 1601;
			action = "closeDialog 0;createDialog 'OT_dialog_place'";

			text = "Colocar"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.588 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Colocar pequeños objetos en tu base y zonas amigas"; //--- ToDo: Localize;
		};
		class RscButton_1602: RscOverthrowButton
		{
			idc = 1602;
			action = "closeDialog 0;[] spawn OT_fnc_build";

			text = "Construir"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.643 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Construir eficicios en bases y pueblos"; //--- ToDo: Localize;
		};
		class RscButton_1603: RscOverthrowButton
		{
			idc = 1603;
			action = "[] spawn OT_fnc_manageRecruitsDialog;";

			text = "Gestionar Reclutamiento IA"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.698 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Gestiona tus reclutas IA"; //--- ToDo: Localize;
		};
		class RscButton_1611: RscOverthrowButton
		{
			idc = 1611;
			action = "[] spawn OT_fnc_characterSheetDialog;";

			text = "Ficha del personaje"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.753 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Mejora tu personaje"; //--- ToDo: Localize;
		};
		class RscButton_1612: RscOverthrowButton
		{
			idc = 1612;
			action = "call OT_fnc_optionsDialog";

			text = "Opciones"; //--- ToDo: Localize;
			x = 0.005 * safezoneW + safezoneX;
			y = 0.808 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Guardado persistente, limpieza de cadaveres, etc"; //--- ToDo: Localize;
		};

		class RscButton_1620: RscOverthrowButton
		{
			idc = 1620;
			action = "closeDialog 0;[] spawn OT_fnc_manageArea";

			text = "Adquisición"; //--- ToDo: Localize;
			x = 0.881562 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.044 * safezoneH;
		};
		class RscButton_1621: RscOverthrowButton
		{
			idc = 1621;
			action = "closeDialog 0;[] call OT_fnc_garrisonDialog";

			text = "Guarnición"; //--- ToDo: Localize;
			x = 0.943438 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.044 * safezoneH;
		};

		class RscPicture_1201: RscOverthrowPicture
		{
			idc = 1201;

			text = "#(argb,8,8,3)color(0,0,0,0)";
			x = 0.881562 * safezoneW + safezoneX;
			y = 0.479 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.1 * safezoneH;
		};
		class RscButton_1608: RscOverthrowButton
		{
			idc = 1608;
			action = "closeDialog 0;[] call OT_fnc_buyBuilding";

			text = "Comprar"; //--- ToDo: Localize;
			x = 0.881562 * safezoneW + safezoneX;
			y = 0.698 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Compra este edificio"; //--- ToDo: Localize;
		};
		class RscButton_1609: RscOverthrowButton
		{
			idc = 1609;
			action = "closeDialog 0;[] call OT_fnc_leaseBuilding";

			text = "Alquilar"; //--- ToDo: Localize;
			x = 0.881562 * safezoneW + safezoneX;
			y = 0.753 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Alquila este edificio"; //--- ToDo: Localize;
		};
		class RscButton_1610: RscOverthrowButton
		{
			idc = 1610;
			action = "closeDialog 0;[] call OT_fnc_setHome";

			text = "Establece como hogar"; //--- ToDo: Localize;
			x = 0.943438 * safezoneW + safezoneX;
			y = 0.753 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Haz este lugar tu hogar (spawn)"; //--- ToDo: Localize;
		};
		class RscStructuredText_1101: RscOverthrowStructuredText
		{
			idc = 1101;

			x = 0.881562 * safezoneW + safezoneX;
			y = 0.302 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.1 * safezoneH;
			colorBackground[] = {0,0,0,0.4};
		};
		class RscStructuredText_1102: RscOverthrowStructuredText
		{
			idc = 1102;

			x = 0.881562 * safezoneW + safezoneX;
			y = 0.588 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.1 * safezoneH;
			colorBackground[] = {0,0,0,0.4};
		};
		class RscPicture_1200: RscOverthrowPicture
		{
			idc = 1200;
			text = "\overthrow_main\ui\logo_overthrow.paa";
			x = 0.00499997 * safezoneW + safezoneX;
			y = 0.103 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.144 * safezoneW;
		};
		class RscStructuredText_1106: RscOverthrowStructuredText
		{
			idc = 1106;

			x = safezoneX + (0.8 * safezoneW);
			y = safezoneY + (0.15 * safezoneH);
			w = 0.19 * safezoneW;
			h = 0.1 * safezoneH;
			colorBackground[] = {0,0,0,0};
			colorActive[] = {0,0,0,0};
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////
	};
};

class OT_dialog_char
{
	idd=8003;
	movingenable=false;

	class controls
	{
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by ARMAzac, v1.063, #Pejity)
		////////////////////////////////////////////////////////

		class RscStructuredText_1100: RscOverthrowStructuredText
		{
			idc = 1100;
			text = ""; //--- ToDo: Localize;
			x = 0.273125 * safezoneW + safezoneX;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.143 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
			colorActive[] = {0,0,0,0.5};
		};
		class RscButton_1600: RscOverthrowButton
		{
			idc = 1600;
			text = "Increase Level (-10 Influence)"; //--- ToDo: Localize;
			x = 0.273125 * safezoneW + safezoneX;
			y = 0.423 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.044 * safezoneH;
			action="[""fitness""] call buyPerk;";
		};
		class RscStructuredText_1101: RscOverthrowStructuredText
		{
			idc = 1101;
			text = "Subir Nivel (-10 Influencia)"; //--- ToDo: Localize;
			x = 0.427812 * safezoneW + safezoneX;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.143 * safezoneH;
			colorBackground[] = {0,0,0,0.3};
			colorActive[] = {0,0,0,0.3};
		};
		class RscButton_1601: RscOverthrowButton
		{
			idc = 1601;
			text = "Subir Nivel (-10 Influencia)"; //--- ToDo: Localize;
			x = 0.427812 * safezoneW + safezoneX;
			y = 0.423 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.044 * safezoneH;
			action="[""trade""] call buyPerk;";
		};
		class RscStructuredText_1102: RscOverthrowStructuredText
		{
			idc = 1102;
			text = ""; //--- ToDo: Localize;
			x = 0.5825 * safezoneW + safezoneX;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.143 * safezoneH;
			colorBackground[] = {0,0,0,0.3};
			colorActive[] = {0,0,0,0.3};
		};
		class RscButton_1602: RscOverthrowButton
		{
			idc = 1602;
			text = "Subir Nivel (-10 Influencia)"; //--- ToDo: Localize;
			x = 0.5825 * safezoneW + safezoneX;
			y = 0.423 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.044 * safezoneH;
			action="[""stealth""] call buyPerk;";
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////
	};
};

class OT_dialog_tute
{
	idd=-1;
	movingenable=false;

	class controlsBackground {
		class RscStructuredText_1101: RscOverthrowStructuredText
		{
			idc = 1101;
			x = 0.324687 * safezoneW + safezoneX;
			y = 0.313 * safezoneH + safezoneY;
			w = 0.355781 * safezoneW;
			h = 0.198 * safezoneH;
			colorBackground[] = {0.1,0.1,0.1,1};
			colorActive[] = {0.1,0.1,0.1,1};
		};
	};

	class controls
	{
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by ARMAzac, v1.063, #Kizeru)
		////////////////////////////////////////////////////////

		class RscButton_1600: RscOverthrowButton
		{
			idc = 1600;
			action = "closeDialog 0;[] spawn OT_fnc_tutorial;";

			text = "Si"; //--- ToDo: Localize;
			x = 0.340156 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class RscButton_1601: RscOverthrowButton
		{
			idc = 1601;
			action = "closeDialog 0;";

			text = "No"; //--- ToDo: Localize;
			x = 0.592812 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class RscStructuredText_1100: RscOverthrowStructuredText
		{
			idc = 1100;

			text = "¿Quieres un titurial rápido? (te daremos cosas gratis)"; //--- ToDo: Localize;
			x = 0.340156 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.324844 * safezoneW;
			h = 0.033 * safezoneH;
			colorBackground[] = {0,0,0,0};
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////
	};
};

class OT_dialog_choose
{
	idd=8002;
	movingenable=false;

	class controls
	{
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by ARMAzac, v1.063, #Humesu)
		////////////////////////////////////////////////////////

		class RscStructuredText_1100: RscOverthrowStructuredText
		{
			idc = 1100;
			x = 0.29375 * safezoneW + safezoneX;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.4125 * safezoneW;
			h = 0.184 * safezoneH;
			colorBackground[] = {0.2,0.2,0.2,1};
		};

		class RscButton_1600: RscOverthrowButton
		{
			idc = 1600;
			text = "Lorem Ipsum dolor sit amet blah blah blah"; //--- ToDo: Localize;
			action = "closeDialog 0;0 call OT_fnc_choiceMade;";
			x = 0.298906 * safezoneW + safezoneX;
			y = 0.478 * safezoneH + safezoneY;
			w = 0.402187 * safezoneW;
			h = 0.055 * safezoneH;
			sizeEx = 0.017 * safezoneH;
		};
		class RscButton_1601: RscOverthrowButton
		{
			idc = 1601;
			text = "Lorem Ipsum dolor sit amet blah blah blah"; //--- ToDo: Localize;
			action = "closeDialog 0;1 call OT_fnc_choiceMade;";
			x = 0.298906 * safezoneW + safezoneX;
			y = 0.544 * safezoneH + safezoneY;
			w = 0.402187 * safezoneW;
			h = 0.055 * safezoneH;
			sizeEx = 0.017 * safezoneH;
		};
		class RscButton_1602: RscOverthrowButton
		{
			idc = 1602;
			text = "Lorem Ipsum dolor sit amet blah blah blah"; //--- ToDo: Localize;
			action = "closeDialog 0;2 call OT_fnc_choiceMade;";
			x = 0.298906 * safezoneW + safezoneX;
			y = 0.61 * safezoneH + safezoneY;
			w = 0.402187 * safezoneW;
			h = 0.055 * safezoneH;
			sizeEx = 0.017 * safezoneH;
		};
		class RscButton_1603: RscOverthrowButton
		{
			idc = 1603;
			text = "Lorem Ipsum dolor sit amet blah blah blah"; //--- ToDo: Localize;
			action = "closeDialog 0;3 call OT_fnc_choiceMade;";
			x = 0.298906 * safezoneW + safezoneX;
			y = 0.676 * safezoneH + safezoneY;
			w = 0.402187 * safezoneW;
			h = 0.055 * safezoneH;
			sizeEx = 0.017 * safezoneH;
		};
		class RscButton_1604: RscOverthrowButton
		{
			idc = 1604;
			text = "Lorem Ipsum dolor sit amet blah blah blah"; //--- ToDo: Localize;
			action = "closeDialog 0;4 call OT_fnc_choiceMade;";
			x = 0.298906 * safezoneW + safezoneX;
			y = 0.742 * safezoneH + safezoneY;
			w = 0.402187 * safezoneW;
			h = 0.055 * safezoneH;
			sizeEx = 0.017 * safezoneH;
		};
		class RscButton_1605: RscOverthrowButton
		{
			idc = 1605;
			text = "Lorem Ipsum dolor sit amet blah blah blah"; //--- ToDo: Localize;
			action = "closeDialog 0;5 call OT_fnc_choiceMade;";
			x = 0.298906 * safezoneW + safezoneX;
			y = 0.808 * safezoneH + safezoneY;
			w = 0.402187 * safezoneW;
			h = 0.055 * safezoneH;
			sizeEx = 0.017 * safezoneH;
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////
	};
};

class OT_dialog_newgame
{
	idd=8099;
	movingenable=false;

	class controlsBackground {
		class RscStructuredText_1100: RscOverthrowStructuredText
		{
			idc = 1100;
            x = 0.324687 * safezoneW + safezoneX;
            y = 0.269 * safezoneH + safezoneY;
            w = 0.345469 * safezoneW;
            h = 0.495 * safezoneH;
			colorBackground[] = {0.1,0.1,0.1,1};
			colorActive[] = {0.1,0.1,0.1,1};
		};
	};

	class controls
	{
        ////////////////////////////////////////////////////////
        // GUI EDITOR OUTPUT START (by ARMAzac, v1.063, #Zosiwi)
        ////////////////////////////////////////////////////////

        class RscButton_1600: RscOverthrowButton
        {
            idc = 1600;
            text = "Fácil"; //--- ToDo: Localize;
            x = 0.329844 * safezoneW + safezoneX;
            y = 0.313 * safezoneH + safezoneY;
            w = 0.0876563 * safezoneW;
            h = 0.077 * safezoneH;
			action = "server setvariable [""OT_difficulty"",0,true];call OT_fnc_newGameDialog;";
        };
        class RscButton_1601: RscOverthrowButton
        {
            idc = 1601;
            text = "Normal"; //--- ToDo: Localize;
            x = 0.453594 * safezoneW + safezoneX;
            y = 0.313 * safezoneH + safezoneY;
            w = 0.0876563 * safezoneW;
            h = 0.077 * safezoneH;
			action = "server setvariable [""OT_difficulty"",1,true];call OT_fnc_newGameDialog;";
            color[] = {0,0.8,0,1};
        };
        class RscButton_1602: RscOverthrowButton
        {
            idc = 1602;
            text = "Difícil"; //--- ToDo: Localize;
            x = 0.577344 * safezoneW + safezoneX;
            y = 0.313 * safezoneH + safezoneY;
            w = 0.0876563 * safezoneW;
            h = 0.077 * safezoneH;
			action = "server setvariable [""OT_difficulty"",2,true];call OT_fnc_newGameDialog;";
        };
        class RscStructuredText_1101: RscOverthrowStructuredText
        {
            idc = 1101;
            text = "<t size=""1.5"">Dificultad</t>"; //--- ToDo: Localize;
            x = 0.329844 * safezoneW + safezoneX;
            y = 0.269 * safezoneH + safezoneY;
            w = 0.159844 * safezoneW;
            h = 0.033 * safezoneH;
            colorBackground[] = {0,0,0,0};
        };
        class RscStructuredText_1102: RscOverthrowStructuredText
        {
            idc = 1102;
            text = "<t size=""1.5"">Viaje Rápido</t>"; //--- ToDo: Localize;
            x = 0.329844 * safezoneW + safezoneX;
            y = 0.423 * safezoneH + safezoneY;
            w = 0.159844 * safezoneW;
            h = 0.033 * safezoneH;
            colorBackground[] = {0,0,0,0};
        };
        class RscButton_1603: RscOverthrowButton
        {
            idc = 1603;
            text = "Gratis"; //--- ToDo: Localize;
            x = 0.329844 * safezoneW + safezoneX;
            y = 0.467 * safezoneH + safezoneY;
            w = 0.0876563 * safezoneW;
            h = 0.077 * safezoneH;
			action = "server setvariable [""OT_fastTravelType"",0,true];call OT_fnc_newGameDialog;";
        };
        class RscButton_1604: RscOverthrowButton
        {
            idc = 1604;
            text = "Coste"; //--- ToDo: Localize;
            x = 0.453594 * safezoneW + safezoneX;
            y = 0.467 * safezoneH + safezoneY;
            w = 0.0876563 * safezoneW;
            h = 0.077 * safezoneH;
			color[] = {0,0.8,0,1};
			action = "server setvariable [""OT_fastTravelType"",1,true];call OT_fnc_newGameDialog;";
        };
        class RscButton_1605: RscOverthrowButton
        {
            idc = 1605;
            text = "Desactivado"; //--- ToDo: Localize;
            x = 0.577344 * safezoneW + safezoneX;
            y = 0.467 * safezoneH + safezoneY;
            w = 0.0876563 * safezoneW;
            h = 0.077 * safezoneH;
			action = "server setvariable [""OT_fastTravelType"",2,true];call OT_fnc_newGameDialog;";
        };
        class RscButton_1606: RscOverthrowButton
        {
            idc = 1606;
            text = "Comenzar Juego"; //--- ToDo: Localize;
            x = 0.577344 * safezoneW + safezoneX;
            y = 0.676 * safezoneH + safezoneY;
            w = 0.0876563 * safezoneW;
            h = 0.077 * safezoneH;
			action = "closeDialog 0;[] remoteExec [""OT_fnc_newGame"",2,false]";
        };
        ////////////////////////////////////////////////////////
        // GUI EDITOR OUTPUT END
        ////////////////////////////////////////////////////////
    };
};
