class CfgPatches {
	class ascz_headgear {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Characters_F_BLUFOR"};
	};
};

class cfgWeapons
{
	class H_Cap_oli_hs;
	class ItemInfo;
	class H_Bandana_khaki: H_Cap_oli_hs
	{
		author = "ASCZ";
		displayName = "Bandana [Khaki]";
		picture = "\ascz_headgear\data\UI\icon_bandana_khaki.paa";

		model = "\ascz_headgear\bandana.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\ascz_headgear\data\bandana_khaki_co.paa"};
        class ItemInfo: ItemInfo{
			uniformModel = "\ascz_headgear\bandana.p3d";
		};
	};
	class H_bandana_black: H_bandana_khaki
	{
	author = "ASCZ";
	displayName = "Bandana [Black]";
	picture = "\ascz_headgear\data\UI\icon_bandana_black.paa";
	
	    hiddenSelectionsTextures[] = {"\ascz_headgear\data\bandana_black_co.paa"};
	    class ItemInfo: ItemInfo{};
	};
	class H_bandana_brown: H_bandana_black
	{
	author = "ASCZ";
	displayName = "Bandana [Brown]";
	picture = "\ascz_headgear\data\UI\icon_bandana_brown.paa";
	
	    hiddenSelectionsTextures[] = {"\ascz_headgear\data\bandana_brown_co.paa"};
	    class ItemInfo: ItemInfo{};
	};
	class H_bandana_red: H_bandana_brown
	{
	author = "ASCZ";
	displayName = "Bandana [Red]";
	picture = "\ascz_headgear\data\UI\icon_bandana_red.paa";
	
	    hiddenSelectionsTextures[] = {"\ascz_headgear\data\bandana_red_co.paa"};
	    class ItemInfo: ItemInfo{};
	};
};