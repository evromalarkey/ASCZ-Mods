class CfgPatches
{
	class tka_a3_vehicles_uaz
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"tka_a3_vehicles"};
		magazines[] = {};
		ammo[] = {};
	};
};

class WeaponFireGun;
class WeaponCloudsGun;
class WeaponFireMGun;
class WeaponCloudsMGun;
class RCWSOptics;
class CfgVehicles
{
	class LandVehicle;
	class Car: LandVehicle
	{
		class HitPoints;
		class NewTurret;
	};
	class Car_F: Car
	{
		class Turrets
		{
			class MainTurret: NewTurret{};
		};
		class HitPoints
		{
			class HitLFWheel;
			class HitLF2Wheel;
			class HitRFWheel;
			class HitRF2Wheel;
			class HitBody;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
			class HitGlass5;
			class HitGlass6;
		};
		class EventHandlers;
		class AnimationSources;
	};
	class Offroad_01_base_F: Car_F{};
	class RHS_UAZ_Base: Offroad_01_base_F{};
	class TKA_A3_UAZ_Base: RHS_UAZ_Base
	{
		class Turrets
		{
			class MainTurret: NewTurret{};
		};
		class UserActions{};
		class RenderTargets{};
		accuracy = 0.25;
		attenuationEffectType = "OpenCarAttenuation";
		transportSoldier = 0;
		memoryPointsGetInCargo[] = {"pos cargo"};
		memoryPointsGetInCargoDir[] = {"pos cargo dir"};
	};
	class TKA_A3_UAZ_MG_Base: TKA_A3_UAZ_Base
	{
		model = "\tka_a3\tka_a3_vehicles\uaz\uaz_mg.p3d";
		picture = "\tka_a3\tka_a3_vehicles\uaz\data\uaz_mg_ca.paa";
		Icon = "\tka_a3\tka_a3_vehicles\uaz\data\icomap_uaz_mg_ca.paa";
		displayName = "UAZ (DShKM)";
		gunnerOpticsShowCursor = 1;
		class CargoTurret;
		class Turrets: Turrets
		{
			class CargoTurret_01: CargoTurret
			{
				gunnerAction = "passenger_inside_2";
				memoryPointsGetInCargo[] = {"pos cargo"};
				memoryPointsGetInCargoDir[] = {"pos cargo dir"};
				gunnerName = "Passenger (Front Right Seat)";
				gunnerCompartments = "Compartment2";
				memoryPointGunnerOptics = "eye";
				LODTurnedIn = 1200;
				LODTurnedOut = 1200;
				proxyIndex = 1;
				gunnerDoor = "Door_RF";
				maxElev = 45;
				minElev = -35;
				maxTurn = 41;
				minTurn = -95;
				isPersonTurret = 1;
				gunnerUsesPilotView = 0;
				class dynamicViewLimits
				{
					CargoTurret_02[] = {-105,40};
				};
			};
			class MainTurret: MainTurret
			{
				body = "mainTurret";
				gun = "mainGun";
				animationSourceBody = "mainTurret";
				animationSourceGun = "mainGun";
				discreteDistance[] = {100,200,300,400,500,600,800,1000,1200,1500};
				discreteDistanceInitIndex = 2;
				outGunnerMayFire = 1;
				forceHideGunner = 0;
				castGunnerShadow = 1;
				viewGunnerInExternal = 1;
				gunnerForceOptics = 0;
				weapons[] = {"RDS_DSHKM"};
				soundServo[] = {"A3\sounds_f\dummysound",0.01,1.0,10};
				magazines[] = {"RDS_150Rnd_127x107_DSHKM","RDS_150Rnd_127x107_DSHKM","RDS_150Rnd_127x107_DSHKM","RDS_150Rnd_127x107_DSHKM"};
				gunnerAction = "TKA_A3_UAZ_Gunner01";
				gunnerInAction = "TKA_A3_UAZ_Gunner01";
				ejectDeadGunner = 1;
				minElev = -25;
				maxElev = "+60";
				stabilizedInAxes = 0;
				startEngine = 0;
				gunBeg = "usti hlavne";
				gunEnd = "konec hlavne";
				memoryPointGunnerOptics = "gunnerview";
				optics = 0;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"tka_a3\tka_a3_vehicles\uaz\data\uaz_main_metal.rvmat","tka_a3\tka_a3_vehicles\uaz\data\uaz_main_metal_damage.rvmat","tka_a3\tka_a3_vehicles\uaz\data\uaz_main_metal_destruct.rvmat","tka_a3\tka_a3_vehicles\uaz\data\uaz_other_metal.rvmat","tka_a3\tka_a3_vehicles\uaz\data\uaz_other_metal_damage.rvmat","tka_a3\tka_a3_vehicles\uaz\data\uaz_other_metal_destruct.rvmat","tka_a3\tka_a3_vehicles\uaz\data\uaz_skla.rvmat","a3\data_f\glass_veh_armored_damage.rvmat","a3\data_f\glass_veh_armored_damage.rvmat","tka_a3\tka_a3_vehicles\uaz\data\dshk.rvmat","tka_a3\tka_a3_vehicles\uaz\data\dshk_damage.rvmat","tka_a3\tka_a3_vehicles\uaz\data\dshk_destruct.rvmat"};
		};
		class AnimationSources: AnimationSources
		{
			class ReloadAnim
			{
				source = "reload";
				weapon = "RDS_DSHKM";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "RDS_DSHKM";
			};
			class Revolving
			{
				source = "revolving";
				weapon = "RDS_DSHKM";
			};
		};
	};
	class TKA_A3_UAZ_AGS30_Base: TKA_A3_UAZ_Base
	{
		model = "\tka_a3\tka_a3_vehicles\uaz\uaz_granade.p3d";
		picture = "\tka_a3\tka_a3_vehicles\uaz\data\uaz_granade_CA.paa";
		Icon = "\tka_a3\tka_a3_vehicles\uaz\data\icomap_Uaz_gl_CA.paa";
		displayName = "UAZ (AGS-30)";
		gunnerHasFlares = 1;
		gunnerOpticsShowCursor = 1;
		class CargoTurret;
		class Turrets: Turrets
		{
			class CargoTurret_01: CargoTurret
			{
				gunnerAction = "passenger_inside_2";
				memoryPointsGetInGunner = "pos cargo";
				memoryPointsGetInGunnerDir = "pos cargo dir";
				gunnerName = "Passenger (Front Right Seat)";
				gunnerCompartments = "Compartment2";
				memoryPointGunnerOptics = "eye";
				LODTurnedIn = 1200;
				LODTurnedOut = 1200;
				proxyIndex = 1;
				gunnerDoor = "Door_RF";
				maxElev = 45;
				minElev = -35;
				maxTurn = 41;
				minTurn = -95;
				isPersonTurret = 1;
				gunnerUsesPilotView = 0;
				class dynamicViewLimits
				{
					CargoTurret_02[] = {-105,40};
				};
			};
			class MainTurret: MainTurret
			{
				body = "mainTurret";
				gun = "mainGun";
				outGunnerMayFire = 1;
				forceHideGunner = 0;
				castGunnerShadow = 1;
				viewGunnerInExternal = 1;
				gunnerForceOptics = 0;
				gunnerOutOpticsShowCursor = 0;
				weapons[] = {"RDS_AGS30"};
				soundServo[] = {"A3\sounds_f\dummysound",0.01,1.0,10};
				magazines[] = {"RDS_29Rnd_30mm_AGS30","RDS_29Rnd_30mm_AGS30","RDS_29Rnd_30mm_AGS30","RDS_29Rnd_30mm_AGS30"};
				gunnerAction = "TKA_A3_UAZ_Gunner02";
				gunnerInAction = "TKA_A3_UAZ_Gunner02";
				ejectDeadGunner = 1;
				minElev = -25;
				maxElev = "+60";
				gunnerOpticsModel = "\tka_a3\tka_a3_vehicles\uaz\optika_AGS30.p3d";
				stabilizedInAxes = 0;
				startEngine = 0;
				class GunFire: WeaponCloudsMGun
				{
					interval = 0.01;
				};
			};
		};
		class AnimationSources: AnimationSources
		{
			class belt_rotation
			{
				source = "reload";
				weapon = "RDS_AGS30";
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"tka_a3\tka_a3_vehicles\uaz\data\ags30.rvmat","tka_a3\tka_a3_vehicles\uaz\data\ags30.rvmat","tka_a3\tka_a3_vehicles\uaz\data\ags30_destruct.rvmat","tka_a3\tka_a3_vehicles\uaz\data\tripod_ags.rvmat","tka_a3\tka_a3_vehicles\uaz\data\tripod_ags.rvmat","tka_a3\tka_a3_vehicles\uaz\data\tripod_ags_destruct.rvmat","tka_a3\tka_a3_vehicles\uaz\data\uaz_main_metal.rvmat","tka_a3\tka_a3_vehicles\uaz\data\uaz_main_metal_damage.rvmat","tka_a3\tka_a3_vehicles\uaz\data\uaz_main_metal_destruct.rvmat","tka_a3\tka_a3_vehicles\uaz\data\uaz_other_metal.rvmat","tka_a3\tka_a3_vehicles\uaz\data\uaz_other_metal_damage.rvmat","tka_a3\tka_a3_vehicles\uaz\data\uaz_other_metal_destruct.rvmat","tka_a3\tka_a3_vehicles\uaz\data\uaz_skla.rvmat","a3\data_f\glass_veh_armored_damage.rvmat","a3\data_f\glass_veh_armored_damage.rvmat"};
		};
		hiddenSelections[] = {"Camo1","Camo2"};
		hiddenSelectionsTextures[] = {"\tka_a3\tka_a3_vehicles\uaz\data\Uaz_main_CO.paa","\tka_a3\tka_a3_vehicles\uaz\data\uaz_mount_co.paa"};
	};
	class TKA_A3_UAZ_SPG9_Base: TKA_A3_UAZ_Base
	{
		model = "\tka_a3\tka_a3_vehicles\uaz\uaz_spg9.p3d";
		picture = "\tka_a3\tka_a3_vehicles\uaz\data\uaz_spg9_CA.paa";
		Icon = "\tka_a3\tka_a3_vehicles\uaz\data\icomap_Uaz_spg9_CA.paa";
		displayName = "UAZ (SPG-9)";
		gunnerOpticsShowCursor = 0;
		class CargoTurret;
		class Turrets: Turrets
		{
			class CargoTurret_01: CargoTurret
			{
				gunnerAction = "passenger_inside_2";
				memoryPointsGetInCargo[] = {"pos cargo"};
				memoryPointsGetInCargoDir[] = {"pos cargo dir"};
				gunnerName = "Passenger (Front Right Seat)";
				gunnerCompartments = "Compartment2";
				memoryPointGunnerOptics = "eye";
				LODTurnedIn = 1200;
				LODTurnedOut = 1200;
				proxyIndex = 1;
				gunnerDoor = "Door_RF";
				maxElev = 45;
				minElev = -35;
				maxTurn = 41;
				minTurn = -95;
				isPersonTurret = 1;
				gunnerUsesPilotView = 0;
				class dynamicViewLimits
				{
					CargoTurret_02[] = {-105,40};
				};
			};
			class MainTurret: MainTurret
			{
				body = "mainTurret";
				gun = "mainGun";
				outGunnerMayFire = 1;
				forceHideGunner = 0;
				castGunnerShadow = 1;
				viewGunnerInExternal = 1;
				gunnerForceOptics = 0;
				gunnerOutOpticsShowCursor = 0;
				weapons[] = {"RDS_SPG9"};
				soundServo[] = {"A3\sounds_f\dummysound",0.01,1.0,10};
				magazines[] = {"RDS_PG9_AT","RDS_OG9_HE","RDS_PG9_AT","RDS_OG9_HE","RDS_PG9_AT","RDS_OG9_HE"};
				gunnerAction = "TKA_A3_SPG_Car_Gunner";
				gunnerInAction = "TKA_A3_SPG_Car_Gunner";
				ejectDeadGunner = 1;
				minElev = -25;
				maxElev = "+60";
				stabilizedInAxes = 0;
				gunnerOpticsModel = "\tka_a3\tka_a3_vehicles\uaz\2Dscope_SPG_4.p3d";
				startEngine = 0;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"tka_a3\tka_a3_vehicles\uaz\data\uaz_main_metal.rvmat","tka_a3\tka_a3_vehicles\uaz\data\uaz_main_metal_damage.rvmat","tka_a3\tka_a3_vehicles\uaz\data\uaz_main_metal_destruct.rvmat","tka_a3\tka_a3_vehicles\uaz\data\uaz_other_metal.rvmat","tka_a3\tka_a3_vehicles\uaz\data\uaz_other_metal_damage.rvmat","tka_a3\tka_a3_vehicles\uaz\data\uaz_other_metal_destruct.rvmat","tka_a3\tka_a3_vehicles\uaz\data\uaz_skla.rvmat","a3\data_f\glass_veh_armored_damage.rvmat","a3\data_f\glass_veh_armored_damage.rvmat","tka_a3\tka_a3_vehicles\uaz\data\dshk.rvmat","tka_a3\tka_a3_vehicles\uaz\data\dshk_damage.rvmat","tka_a3\tka_a3_vehicles\uaz\data\dshk_destruct.rvmat"};
		};
		class AnimationSources: AnimationSources
		{
			class ReloadAnim
			{
				source = "reload";
				weapon = "RDS_SPG9";
			};
		};
		hiddenSelections[] = {"Camo1","Camo2"};
		hiddenSelectionsTextures[] = {"\tka_a3\tka_a3_vehicles\uaz\data\Uaz_main_CO.paa","\tka_a3\tka_a3_vehicles\uaz\data\uaz_mount_co.paa"};
	};
};
//};
