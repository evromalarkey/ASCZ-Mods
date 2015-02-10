////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 4.91
//Tue Feb 10 09:54:27 2015 : Source 'file' date Tue Feb 10 09:54:27 2015
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//ndefs=4
enum {
	StabilizedInAxesNone = 0,
	StabilizedInAxisX = 1,
	StabilizedInAxisY = 2,
	StabilizedInAxesBoth = 3
};

//Class P:\cdf_a3\cdf_a3_vehicles\brdm2\config.bin{
class CfgPatches
{
	class CAWheeled_E_BRDM2
	{
		units[] = {"BRDM2_TK_EP1","BRDM2_ATGM_TK_EP1","BRDM2_TK_GUE_EP1","BRDM2_HQ_TK_GUE_EP1"};
		weapons[] = {};
		requiredVersion = 1.02;
		requiredAddons[] = {"CAWheeled","CAWheeled_E"};
	};
};
class CfgVehicles
{
	class Land;
	class LandVehicle: Land
	{
		class NewTurret;
	};
	class Car: LandVehicle
	{
		class Turrets
		{
			class MainTurret;
		};
	};
	class Wheeled_APC: Car{};
	class BRDM2_Base: Wheeled_APC
	{
		model = "\cdf_a3\cdf_a3_vehicles\brdm2\BRDM2.p3d";
		htMin = 60;
		htMax = 1800;
		afMax = 200;
		mfMax = 100;
		mFact = 1;
		tBody = 250;
		crewVulnerable = 0;
		hideProxyInCombat = 0;
		viewDriverInExternal = 1;
		viewGunnerInExternal = 1;
		viewCargoInExternal = 1;
		radarType = 4;
		commanderCanSee = 31;
		gunnerCanSee = 31;
		driverCanSee = 31;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = "+30";
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = "+100";
					initFov = 0.2;
					minFov = 0.05;
					maxFov = 0.2;
					gunnerOpticsEffect[] = {"TankGunnerOptics1","OpticsBlur2","OpticsCHAbera2"};
					visionMode[] = {"Normal","NVG"};
				};
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"cdf_a3\cdf_a3_vehicles\brdm2\data\BRDM2_01.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\BRDM2_01.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_01_destruct.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_02.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_02.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_02_destruct.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\default.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\default.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\default_destruct.rvmat"};
		};
	};
	class BRDM2_ATGM_Base: BRDM2_Base
	{
		model = "\cdf_a3\cdf_a3_vehicles\brdm2\BRDM2_ATGM.p3d";
	};
	class BRDM2_HQ_Base: BRDM2_Base
	{
		model = "\cdf_a3\cdf_a3_vehicles\brdm2\BRDM2_HQ.p3d";
	};
	class BRDM2_TK_EP1: BRDM2_Base
	{
		expansion = 1;
		scope = 2;
		side = 0;
		accuracy = 0.3;
		faction = "BIS_TK";
		crew = "TK_Soldier_EP1";
		typicalCargo[] = {"TK_Soldier_EP1"};
		hiddenSelectionsTextures[] = {"\cdf_a3\cdf_a3_vehicles\brdm2\data\BRDM2_01_TKA_CO.paa"};
		hiddenSelections[] = {"Camo1"};
		class TransportMagazines
		{
			class _xx_20Rnd_762x51_FNFAL
			{
				magazine = "20Rnd_762x51_FNFAL";
				count = 30;
			};
			class _xx_HandGrenade_East
			{
				magazine = "HandGrenade_East";
				count = 10;
			};
			class _xx_100Rnd_762x54_PK
			{
				magazine = "100Rnd_762x54_PK";
				count = 5;
			};
			class _xx_SmokeShellOrange
			{
				magazine = "SmokeShellOrange";
				count = 2;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
		};
		class TransportWeapons
		{
			class _xx_FN_FAL
			{
				weapon = "FN_FAL";
				count = 2;
			};
		};
	};
	class BRDM2_ATGM_TK_EP1: BRDM2_ATGM_Base
	{
		expansion = 1;
		scope = 2;
		side = 0;
		accuracy = 0.3;
		faction = "BIS_TK";
		crew = "TK_Soldier_EP1";
		typicalCargo[] = {"TK_Soldier_EP1"};
		class Damage
		{
			tex[] = {};
			mat[] = {"cdf_a3\cdf_a3_vehicles\brdm2\data\BRDM2_01.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\BRDM2_01.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_01_destruct.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_02.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_02.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_02_destruct.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_ATGM_01.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_ATGM_01.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_atgm_01_destruct.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\default.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\default.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\default_destruct.rvmat"};
		};
		hiddenSelectionsTextures[] = {"\cdf_a3\cdf_a3_vehicles\brdm2\data\BRDM2_ATGM_01_TKA_CO.paa"};
		hiddenSelections[] = {"Camo1"};
		class TransportMagazines
		{
			class _xx_20Rnd_762x51_FNFAL
			{
				magazine = "20Rnd_762x51_FNFAL";
				count = 30;
			};
			class _xx_HandGrenade_East
			{
				magazine = "HandGrenade_East";
				count = 10;
			};
			class _xx_100Rnd_762x54_PK
			{
				magazine = "100Rnd_762x54_PK";
				count = 5;
			};
			class _xx_SmokeShellOrange
			{
				magazine = "SmokeShellOrange";
				count = 2;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
		};
		class TransportWeapons
		{
			class _xx_FN_FAL
			{
				weapon = "FN_FAL";
				count = 2;
			};
		};
	};
	class BRDM2_TK_GUE_EP1: BRDM2_Base
	{
		expansion = 1;
		scope = 2;
		side = 2;
		accuracy = 0.3;
		faction = "BIS_TK_GUE";
		crew = "TK_GUE_Soldier_EP1";
		typicalCargo[] = {"TK_GUE_Soldier_EP1"};
		hiddenSelectionsTextures[] = {"\cdf_a3\cdf_a3_vehicles\brdm2\data\BDRM2_KHK_01_CO.paa"};
		hiddenSelections[] = {"Camo1"};
		class Damage
		{
			tex[] = {};
			mat[] = {"cdf_a3\cdf_a3_vehicles\brdm2\data\BRDM2_01.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\BRDM2_01.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_01_destruct.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_02.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_02.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_02_destruct.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\default.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\default.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\default_destruct.rvmat"};
		};
		class TransportMagazines
		{
			class _xx_30Rnd_545x39_AK
			{
				magazine = "30Rnd_545x39_AK";
				count = 30;
			};
			class _xx_HandGrenade_East
			{
				magazine = "HandGrenade_East";
				count = 10;
			};
			class _xx_100Rnd_762x54_PK
			{
				magazine = "100Rnd_762x54_PK";
				count = 5;
			};
			class _xx_SmokeShellOrange
			{
				magazine = "SmokeShellOrange";
				count = 2;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
		};
		class TransportWeapons
		{
			class _xx_AK_74
			{
				weapon = "AK_74";
				count = 2;
			};
		};
	};
	class BRDM2_HQ_TK_GUE_EP1: BRDM2_HQ_Base
	{
		expansion = 1;
		scope = 2;
		side = 2;
		accuracy = 0.3;
		faction = "BIS_TK_GUE";
		crew = "TK_GUE_Soldier_EP1";
		typicalCargo[] = {"TK_GUE_Soldier_EP1"};
		hiddenSelectionsTextures[] = {"\cdf_a3\cdf_a3_vehicles\brdm2\data\BDRM2_KHK_01_CO.paa"};
		hiddenSelections[] = {"Camo1"};
		class Damage
		{
			tex[] = {};
			mat[] = {"cdf_a3\cdf_a3_vehicles\brdm2\data\BRDM2_01.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\BRDM2_01.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_01_destruct.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_02.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_02.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_02_destruct.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\default.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\default.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\default_destruct.rvmat"};
		};
		class TransportMagazines
		{
			class _xx_30Rnd_545x39_AK
			{
				magazine = "30Rnd_545x39_AK";
				count = 30;
			};
			class _xx_HandGrenade_East
			{
				magazine = "HandGrenade_East";
				count = 10;
			};
			class _xx_100Rnd_762x54_PK
			{
				magazine = "100Rnd_762x54_PK";
				count = 5;
			};
			class _xx_SmokeShellOrange
			{
				magazine = "SmokeShellOrange";
				count = 2;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
		};
		class TransportWeapons
		{
			class _xx_Binocular
			{
				weapon = "Binocular";
				count = 2;
			};
			class _xx_NVGoggles
			{
				weapon = "NVGoggles";
				count = 2;
			};
		};
	};
};
//};
