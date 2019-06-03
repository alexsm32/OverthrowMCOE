class CfgWeapons {
	class ItemCore;
	class OT_ItemCore: ItemCore {
        type = 4096;//4;
        detectRange = -1;
        simulation = "ItemMineDetector";
    };
	class InventoryItem_Base_F;
    class OT_Ganja: OT_ItemCore {
        scope = 2;
        picture = "\overthrow_main\ui\items\ganja_x_ca.paa";
        displayName = "Ganja";
        descriptionShort = "150g. de la mejor hierba de tanoa";
        descriptionUse = "";
        class ItemInfo: InventoryItem_Base_F {
            mass = 2;
        };
    };
	class OT_Blow: OT_ItemCore {
        scope = 2;
        picture = "\overthrow_main\ui\items\blow_x_ca.paa";
        displayName = "Blow";
        descriptionShort = "Un polvo blanco que convierte a lideres mundiales en chusma y a chusma el lideres mundiales";
        descriptionUse = "";
        class ItemInfo: InventoryItem_Base_F {
            mass = 2;
        };
    };
	class OT_Wood: OT_ItemCore {
        scope = 2;
        picture = "\overthrow_main\ui\items\wood_x_ca.paa";
        displayName = "Wood";
        descriptionShort = "Madera en tablones apta para la venta";
        descriptionUse = "";
        class ItemInfo: InventoryItem_Base_F {
            mass = 250;
        };
    };
	class OT_Steel: OT_ItemCore {
        scope = 2;
        picture = "\overthrow_main\ui\items\steel_x_ca.paa";
        displayName = "Steel";
        descriptionShort = "Una aleacion de hierro y carbono";
        descriptionUse = "";
        class ItemInfo: InventoryItem_Base_F {
            mass = 400;
        };
    };
	class OT_Plastic: OT_ItemCore {
        scope = 2;
        picture = "\overthrow_main\ui\items\plastic_x_ca.paa";
        displayName = "Plastic";
        descriptionShort = "Material polimerico procedente del petroleo";
        descriptionUse = "";
        class ItemInfo: InventoryItem_Base_F {
            mass = 150;
        };
    };
	class OT_Sugarcane: OT_ItemCore {
        scope = 2;
        picture = "\overthrow_main\ui\items\cane_x_ca.paa";
        displayName = "Sugarcane";
        descriptionShort = "La planta de la que sale el azucar";
        descriptionUse = "";
        class ItemInfo: InventoryItem_Base_F {
            mass = 50;
        };
    };
	class OT_Sugar: OT_ItemCore {
        scope = 2;
        picture = "\overthrow_main\ui\items\sugar_x_ca.paa";
        displayName = "Sugar";
        descriptionShort = "Polvo dulce usado en reposteria, para el cafe y otros usos culinarios";
        descriptionUse = "";
        class ItemInfo: InventoryItem_Base_F {
            mass = 30;
        };
    };
	class OT_Grapes: OT_ItemCore {
        scope = 2;
        picture = "\overthrow_main\ui\items\cane_x_ca.paa";
        displayName = "Grapes";
        descriptionShort = "Una fruta, empleada para comer con queso, en nochevieja o para hacer vino";
        descriptionUse = "";
        class ItemInfo: InventoryItem_Base_F {
            mass = 50;
        };
    };
	class OT_Wine: OT_ItemCore {
        scope = 2;
        picture = "\overthrow_main\ui\items\cane_x_ca.paa";
        displayName = "Wine";
        descriptionShort = "Una bebida alcoholica de gran calidad en Europa. En tanoa es un brevaje infecto";
        descriptionUse = "";
        class ItemInfo: InventoryItem_Base_F {
            mass = 50;
        };
    };
	class OT_Olives: OT_ItemCore {
        scope = 2;
        picture = "\overthrow_main\ui\items\cane_x_ca.paa";
        displayName = "Olives";
        descriptionShort = "Un pequeño arbol mediterraneo que se encuentra en Espana, Italia y Altis, de el se sacan las aceitunas para hacer aceite de oliva.";
        descriptionUse = "";
        class ItemInfo: InventoryItem_Base_F {
            mass = 50;
        };
    };
	class OT_Fertilizer: OT_ItemCore {
        scope = 2;
        picture = "\overthrow_main\ui\items\fertilizer_x_ca.paa";
        displayName = "Fertilizer";
        descriptionShort = "Un material sintetico o natural (mierda de animales), empleado para mejorar el rendimiento del los cultivos";
        descriptionUse = "";
        class ItemInfo: InventoryItem_Base_F {
            mass = 80;
        };
    };
	class OT_ammo50cal: OT_ItemCore {
        scope = 2;
        picture = "\overthrow_main\ui\items\ammo50cal_x_ca.paa";
        displayName = "100 x 50 Cal BMG";
        descriptionShort = "100 Rounds of .50 Calibre 660 grain FMJ xM33 ammunition para armas estaticas";
        descriptionUse = "";
        class ItemInfo: InventoryItem_Base_F {
            mass = 25;
        };
    };


	//Craftable items
	class ACE_ItemCore;
	class ACE_fieldDressing : ACE_ItemCore {
		ot_craftable = 1;
		ot_craftQuantity = 5;
		ot_craftRecipe = "[[""Uniform_Base"",1]]";
	};

	class ACE_CableTie : ACE_ItemCore {
		ot_craftable = 1;
		ot_craftQuantity = 10;
		ot_craftRecipe = "[[""OT_Plastic"",1]]";
	};

	class ACE_Clacker : ACE_ItemCore {
		ot_craftable = 1;
		ot_craftQuantity = 5;
		ot_craftRecipe = "[[""OT_Steel"",1]]";
	};

	class ACE_DeadManSwitch : ACE_ItemCore {
		ot_craftable = 1;
		ot_craftQuantity = 7;
		ot_craftRecipe = "[[""OT_Steel"",1]]";
	};

	class ACE_EarPlugs : ACE_ItemCore {
		ot_craftable = 1;
		ot_craftQuantity = 2;
		ot_craftRecipe = "[[""OT_Plastic"",1]]";
	};
};
