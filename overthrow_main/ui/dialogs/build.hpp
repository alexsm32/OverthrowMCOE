class OT_dialog_buildbase
{
	idd=-1;
	movingenable=false;
	onMouseMoving = "_this call buildOnMouseMove";
	onMouseButtonDown = "_this call buildOnMouseDown";
	onMouseButtonUp = "_this call buildOnMouseUp";
	onMouseZChanged = "_this call buildOnMouseWheel";
	onKeyDown = "_this call buildOnKeyDown";
	onKeyUp = "_this call buildOnKeyUp";
	class controls
	{
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by ARMAzac, v1.063, #Qytyja)
		////////////////////////////////////////////////////////

		class RscButton_1600: RscOverthrowButton
		{
			idc = 1600;
			action = "closeDialog 0;[] call cancelBuild;";

			text = "Cerrar"; //--- ToDo: Localize;
			x = 0.0204687 * safezoneW + safezoneX;
			y = 0.324 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.077 * safezoneH;
		};
		class RscButton_1601: RscOverthrowButton
		{
			idc = 1601;
			action = "'Walls' call build";

			text = "Muros"; //--- ToDo: Localize;
			x = 0.0204687 * safezoneW + safezoneX;
			y = 0.588 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Evitan la entrada de personas (o tanques)"; //--- ToDo: Localize;
		};
		class RscButton_1602: RscOverthrowButton
		{
			idc = 1602;
			action = "'Observation Post' call build";

			text = "Puesto de Observacion"; //--- ToDo: Localize;
			x = 0.0204687 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Poporciona inteligencia de la zona"; //--- ToDo: Localize;
		};
		class RscButton_1603: RscOverthrowButton
		{
			idc = 1603;
			action = "'Bunkers' call build";

			text = "Bunkers"; //--- ToDo: Localize;
			x = 0.0204687 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Pequeñas estructuras defensivas"; //--- ToDo: Localize;
		};
		class RscButton_1604: RscOverthrowButton
		{
			idc = 1604;
			action = "'Workshop' call build";

			text = "Taller"; //--- ToDo: Localize;
			x = 0.891875 * safezoneW + safezoneX;
			y = 0.324 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Modifica vehículos"; //--- ToDo: Localize;
		};
		class RscButton_1605: RscOverthrowButton
		{
			idc = 1605;
			action = "'Helipad' call build";

			text = "Helipuerto"; //--- ToDo: Localize;
			x = 0.891875 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Los helicopteros necesitan un lugar para aterrizar"; //--- ToDo: Localize;
		};
		class RscButton_1606: RscOverthrowButton
		{
			idc = 1606;
			action = "'Refugee Camp' call build";

			text = "Campo de refugiados"; //--- ToDo: Localize;
			x = 0.891875 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Ayuda a reclutar civiles para nuestra causa"; //--- ToDo: Localize;
		};
		class RscButton_1607: RscOverthrowButton
		{
			idc = 1607;
			action = "'Training Camp' call build";

			text = "Campo de entrenamiento"; //--- ToDo: Localize;
			x = 0.891875 * safezoneW + safezoneX;
			y = 0.588 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Recluta soldados equipados y entrenados"; //--- ToDo: Localize;
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////

	};
};

class OT_dialog_buildobjective
{
	idd=-1;
	movingenable=false;
	onMouseMoving = "_this call buildOnMouseMove";
	onMouseButtonDown = "_this call buildOnMouseDown";
	onMouseButtonUp = "_this call buildOnMouseUp";
	onMouseZChanged = "_this call buildOnMouseWheel";
	onKeyDown = "_this call buildOnKeyDown";
	onKeyUp = "_this call buildOnKeyUp";
	class controls
	{
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by ARMAzac, v1.063, #Jatizu)
		////////////////////////////////////////////////////////

		class RscButton_1600: RscOverthrowButton
		{
			idc = 1600;
			action = "closeDialog 0;[] call cancelBuild;";

			text = "Cerrar"; //--- ToDo: Localize;
			x = 0.0204687 * safezoneW + safezoneX;
			y = 0.324 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.077 * safezoneH;
		};
		class RscButton_1601: RscOverthrowButton
		{
			idc = 1601;
			action = "'Walls' call build";

			text = "Muros"; //--- ToDo: Localize;
			x = 0.0204687 * safezoneW + safezoneX;
			y = 0.588 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Evitan la entrada de personas (o tanques)"; //--- ToDo: Localize;
		};
		class RscButton_1602: RscOverthrowButton
		{
			idc = 1602;
			action = "'Observation Post' call build";

			text = "Puesto de observación"; //--- ToDo: Localize;
			x = 0.0204687 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Una torre pequeña para armas estáticas"; //--- ToDo: Localize;
		};
		class RscButton_1603: RscOverthrowButton
		{
			idc = 1603;
			action = "'Bunkers' call build";

			text = "Bunkers"; //--- ToDo: Localize;
			x = 0.0204687 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Pequeñas estructuras defensivas"; //--- ToDo: Localize;
		};
		class RscButton_1604: RscOverthrowButton
		{
			idc = 1604;
			action = "'Warehouse' call build";

			text = "Almacén"; //--- ToDo: Localize;
			x = 0.0204687 * safezoneW + safezoneX;
			y = 0.676 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Almacena y recupera objetos de todos los almacenes"; //--- ToDo: Localize;
		};
		class RscButton_1605: RscOverthrowButton
		{
			idc = 1605;
			action = "'Barracks' call build";

			text = "Cuartel"; //--- ToDo: Localize;
			x = 0.891875 * safezoneW + safezoneX;
			y = 0.324 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.077 * safezoneH;
		};
		class RscButton_1606: RscOverthrowButton
		{
			idc = 1606;
			action = "'Workshop' call build";

			text = "Taller"; //--- ToDo: Localize;
			x = 0.891875 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Modifica vehículos"; //--- ToDo: Localize;
		};
		class RscButton_1607: RscOverthrowButton
		{
			idc = 1607;
			action = "'Helipad' call build";

			text = "helipuerto"; //--- ToDo: Localize;
			x = 0.891875 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Los helicopteros necesitan un sitio para aterrizar"; //--- ToDo: Localize;
		};
		class RscButton_1608: RscOverthrowButton
		{
			idc = 1608;
			action = "'Guard Tower' call build";

			text = "Torre de guardia"; //--- ToDo: Localize;
			x = 0.891875 * safezoneW + safezoneX;
			y = 0.588 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Una gran torre de vigilancia"; //--- ToDo: Localize;
		};
		class RscButton_1609: RscOverthrowButton
		{
			idc = 1609;
			action = "'Radar' call build";

			text = "Radar"; //--- ToDo: Localize;
			x = 0.891875 * safezoneW + safezoneX;
			y = 0.676 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Detecta drones y aeronaves con un radio de 2500 m"; //--- ToDo: Localize;
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////

	};
};

class OT_dialog_buildtown
{
	idd=-1;
	movingenable=false;
	onMouseMoving = "_this call buildOnMouseMove";
	onMouseButtonDown = "_this call buildOnMouseDown";
	onMouseButtonUp = "_this call buildOnMouseUp";
	onMouseZChanged = "_this call buildOnMouseWheel";
	onKeyDown = "_this call buildOnKeyDown";
	onKeyUp = "_this call buildOnKeyUp";
	class controls
	{
				////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by ARMAzac, v1.063, #Satudy)
		////////////////////////////////////////////////////////

		class RscButton_1600: RscOverthrowButton
		{
			idc = 1600;
			action = "closeDialog 0;[] call cancelBuild;";

			text = "Cerrar"; //--- ToDo: Localize;
			x = 0.0204687 * safezoneW + safezoneX;
			y = 0.324 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.077 * safezoneH;
		};
		class RscButton_1601: RscOverthrowButton
		{
			idc = 1601;
			action = "'Workshop' call build";

			text = "Taller"; //--- ToDo: Localize;
			x = 0.0204687 * safezoneW + safezoneX;
			y = 0.588 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Modifica vehículos"; //--- ToDo: Localize;
		};
		class RscButton_1602: RscOverthrowButton
		{
			idc = 1602;
			action = "'House' call build";

			text = "Casa"; //--- ToDo: Localize;
			x = 0.0204687 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "4 paredes, un techo y una puerta si tienes suerte"; //--- ToDo: Localize;
		};
		class RscButton_1603: RscOverthrowButton
		{
			idc = 1603;
			action = "'Warehouse' call build";

			text = "Almacén"; //--- ToDo: Localize;
			x = 0.0204687 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Almacena objetos"; //--- ToDo: Localize;
		};
		class RscButton_1604: RscOverthrowButton
		{
			idc = 1601;
			action = "'Police Station' call build";

			text = "Comisaría"; //--- ToDo: Localize;
			x = 0.0204687 * safezoneW + safezoneX;
			y = 0.676 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.077 * safezoneH;
			tooltip = "Aumenta la estabilidad y mantiene la paz"; //--- ToDo: Localize;
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////

	};
};

class OT_dialog_police
{
	idd=9000;
	movingenable=false;
	class controlsBackground
	{
		class RscStructuredText_1100: RscOverthrowStructuredText
		{
			idc = 1100;

			text = "<t size=""2"" align=""center"">Blah Comisaría</t>"; //--- ToDo: Localize;
			x = 0.288594 * safezoneW + safezoneX;
			y = 0.214 * safezoneH + safezoneY;
			w = 0.422812 * safezoneW;
			h = 0.572 * safezoneH;
			colorBackground[] = {0.1,0.1,0.1,1};
			colorActive[] = {0.1,0.1,0.1,1};
		};
	};
	class controls
	{
				////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by ARMAzac, v1.063, #Pikulu)
		////////////////////////////////////////////////////////

		class RscStructuredText_1101: RscOverthrowStructuredText
		{
			idc = 1101;

			text = "<t size=""1.5"" align=""center"">Policia: 2</t>"; //--- ToDo: Localize;
			x = 0.29375 * safezoneW + safezoneX;
			y = 0.28 * safezoneH + safezoneY;
			w = 0.4125 * safezoneW;
			h = 0.033 * safezoneH;
			colorBackground[] = {0,0,0,0.1};
			colorActive[] = {0,0,0,1};
		};
		/*
		class RscButton_1600: RscOverthrowButton
		{
			idc = 1600;

			text = "Transfiere 1"; //--- ToDo: Localize;
			x = 0.29375 * safezoneW + safezoneX;
			y = 0.368 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.077 * safezoneH;
		};
		class RscStructuredText_1102: RscOverthrowStructuredText
		{
			idc = 1102;

			text = "<t align=""center"">Transferir a otra estación</t>"; //--- ToDo: Localize;
			x = 0.288594 * safezoneW + safezoneX;
			y = 0.335 * safezoneH + safezoneY;
			w = 0.422812 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {0,0,0,0};
			colorActive[] = {0,0,0,0};
		};*/
		class RscStructuredText_1103: RscOverthrowStructuredText
		{
			idc = 1103;

			text = "<t align=""center"">Contratar policía</t>"; //--- ToDo: Localize;
			x = 0.288594 * safezoneW + safezoneX;
			y = 0.467 * safezoneH + safezoneY;
			w = 0.422812 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {0,0,0,0};
			colorActive[] = {0,0,0,0};
		};
		class RscStructuredText_1104: RscOverthrowStructuredText
		{
			idc = 1104;

			text = "<t size=""1.2"" align=""center"">Efectos</t><br/><br/><t size=""0.8"" align=""center"">+1 Estabilidad/hr</t>"; //--- ToDo: Localize;
			x = 0.4175 * safezoneW + safezoneX;
			y = 0.632 * safezoneH + safezoneY;
			w = 0.170156 * safezoneW;
			h = 0.088 * safezoneH;
			colorBackground[] = {0,0,0,0.1};
			colorActive[] = {0,0,0,1};
		};
		class RscButton_1608: RscOverthrowButton
		{
			idc = 1608;

			text = "Edit Loadout"; //--- ToDo: Localize;
			x = 0.4175 * safezoneW + safezoneX;
			y = 0.73 * safezoneH + safezoneY;
			w = 0.170156 * safezoneW;
			h = 0.033 * safezoneH;
			action = "[] call OT_fnc_editPoliceLoadout";
		};
		/*
		class RscButton_1601: RscOverthrowButton
		{
			idc = 1601;

			text = "Transfiere 2"; //--- ToDo: Localize;
			x = 0.407187 * safezoneW + safezoneX;
			y = 0.368 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.077 * safezoneH;
		};
		class RscButton_1602: RscOverthrowButton
		{
			idc = 1602;

			text = "Transfiere 4"; //--- ToDo: Localize;
			x = 0.520625 * safezoneW + safezoneX;
			y = 0.368 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.077 * safezoneH;
		};
		class RscButton_1603: RscOverthrowButton
		{
			idc = 1603;

			text = "Transfiere todos"; //--- ToDo: Localize;
			x = 0.634062 * safezoneW + safezoneX;
			y = 0.368 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.077 * safezoneH;
		};
		*/
		class RscButton_1604: RscOverthrowButton
		{
			idc = 1604;

			text = "+1"; //--- ToDo: Localize;
			x = 0.29375 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.077 * safezoneH;
			action = "1 call OT_fnc_addPolice;";
		};
		class RscButton_1605: RscOverthrowButton
		{
			idc = 1605;

			text = "+2"; //--- ToDo: Localize;
			x = 0.407187 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.077 * safezoneH;
			action = "2 call OT_fnc_addPolice;";
		};
		class RscButton_1606: RscOverthrowButton
		{
			idc = 1606;

			text = "+4"; //--- ToDo: Localize;
			x = 0.520625 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.077 * safezoneH;
			action = "4 call OT_fnc_addPolice;";
		};
		class RscButton_1607: RscOverthrowButton
		{
			idc = 1607;

			text = "+8"; //--- ToDo: Localize;
			x = 0.634062 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.077 * safezoneH;
			action = "8 call OT_fnc_addPolice;";
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////



	};
};
