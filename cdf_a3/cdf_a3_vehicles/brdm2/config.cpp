class CfgPatches
{
	class cdf_a3_vehicles_brdm2
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.02;
		requiredAddons[] = {"CAWheeled","CAWheeled_E"};
	};
};
class WeaponFireGun;
class WeaponCloudsGun;
class WeaponFireMGun;
class WeaponCloudsMGun;
class RCWSOptics;
class CfgAmmo {
	class MissileBase;
    class M_Titan_AT: MissileBase {};
    class CDF_A3_M_AT5_AT: M_Titan_AT //AT-5 Spandrel /Konkurs 9M113
	{
		hit=520;indirectHit=12;indirectHitRange=1.2; // 600mm vs RHA
		irLock=true;
		rhs_ce_penetration="ACR_A3_M_AT5_penetrator";

		manualControl=true;
		maxControlRange=4000;
		trackOversteer = 0.95;
		trackLead = 0.9;
		maneuvrability = 8;
		explosive=1;

		timeToLive = 25;
		simulationStep = 0.005000;
		sideAirFriction = 0.050000;
		maxSpeed = 200;
		initTime = 0.25;
		thrustTime = 1.500000;
		thrust = 210;
		deflecting = 0;
		fuseDistance = 5;
		whistleDist = 2;
	};
};
class CfgMagazines {
    class VehicleMagazine;
	class CDF_A3_5Rnd_AT5: VehicleMagazine
	{
		scope = 2;
		displayName = "AT5";
		displayNameShort = "9M113";
		ammo=CDF_A3_M_AT5_AT;
		initSpeed = 55.1688;
		count=5;
		maxLeadSpeed=10;
		nameSound="missiles";
	};
};
class CfgWeapons {

	class missiles_titan;
	class CDF_A3_AT5_Launcher: missiles_titan
	{
        autoReload = 0;
        scope=1;
        canLock=1;
        cursor="rocket";
		minRange=75;minRangeProbab=0.6;
		midRange=1400;midRangeProbab=0.7;
		maxRange=4000;maxRangeProbab=0.001;
        sounds[] = {StandardSound};
        class StandardSound
        {
            weaponSoundEffect = "DefaultRifle";
            begin1[] ={"\acr_a3\acr_a3_vehicles\bmp2\Javelin1",1.6228,1,1000};
            soundBegin[] = {"begin1",1};
        };
        reloadTime=1;
        magazineReloadTime=30;
        aiRateOfFire=5;
        aiRateOfFireDistance=1400;
		displayName="$STR_DN_AT5LAUNCHER";
		magazines[]=
		{
			"CDF_A3_5Rnd_AT5"
		};

	};
};
class CfgVehicles
{
    class LandVehicle;
    class Car: LandVehicle
    {
        class NewTurret;
    };
    class Car_F: Car
    {
        class AnimationSources;
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
            class HitGlass1;
            class HitGlass2;
            class HitGlass3;
            class HitGlass4;
            class HitGlass5;
            class HitGlass6;
        };
    };
	class CDF_A3_BRDM2_Base: Car_F
	{
		displayName= $STR_DN_BRDM2;
		vehicleClass = "Armored";
		picture="\cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_CA.paa";
		Icon="\cdf_a3\cdf_a3_vehicles\brdm2\data\icomap_brdm_CA.paa";
		model = "\cdf_a3\cdf_a3_vehicles\brdm2\BRDM2.p3d";
		scope = 0;
		mapSize = 6;
		crewVulnerable = 0;
		transportSoldier = 3;
		transportAmmo = 0;
		driverLeftHandAnimName = "drivewheel";
		driverRightHandAnimName = "drivewheel";

		transportMaxMagazines = 100;
		transportMaxWeapons = 10;

		viewDriverInExternal = 1;
		viewGunnerInExternal = 1;
		viewCargoInExternal = 1;

		radarType = 8;
		commanderCanSee = "4+8+2+32+16";
		driverCanSee = "4+8+2+32+16";
		gunnerCanSee = "4+2+8+32+16";

		armor = 120;
		armorStructural = 8.0;
		cost = 100000;
		threat[]={0.5, 0.5, 0.1};
		weapons[] = {"TruckHorn"};
		magazines[] = {};
		damageResistance = 0.02409;

		canFloat = 1;
		waterAngularDampingCoef = 10.0;
		waterResistanceCoef = 0.5;
		waterLeakiness = 1.5;
		engineShiftY = 1.2;
		driverAction = "Driver_MRAP_03";
		cargoAction[] = {"passenger_generic01_foldhands","passenger_generic01_foldhands"};
		getInAction = "GetInHigh";
		getOutAction = "GetOutHigh";
		cargoGetInAction[] = {"GetOutHigh"};
		cargoGetOutAction[] = {"GetOutHigh"};
		hideWeaponsDriver = 1;
		hideWeaponsCargo = 1;

		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				memoryPointsGetInGunner = "pos gunner";
				memoryPointsGetInGunnerDir = "pos gunner dir";
				body = "mainTurret";
				gun = "mainGun";
                // Coaxial gun
                memoryPointGun = "machinegun";
                selectionFireAnim = "zasleh";

                // Main gun
                gunBeg = "usti hlavne";
                gunEnd = "konec hlavne";
				weapons[] = {"HMG_127_APC","LMG_coax"};
				magazines[] = {"500Rnd_127x99_mag_Tracer_Yellow","2000Rnd_762x51_Belt_T_Yellow"};
				soundServo[] = {"A3\sounds_f\dummysound",0.01,1.0,10};
				gunnerAction = "gunner_MRAP_03";
				viewGunnerInExternal = 1;
				gunnerForceOptics = 1;
				castGunnerShadow = 0;
				stabilizedInAxes = StabilizedInAxesNone;
				memoryPointGunnerOptics = "gunnerview";
				gunnerOpticsModel = "\cdf_a3\cdf_a3_vehicles\brdm2\2Dscope_BMPgun";
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				discreteDistanceInitIndex = 2;
				minElev = -5;
				maxElev = 20;
				class ViewOptics: RCWSOptics{};
				class ViewGunner: ViewOptics
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
				class HitPoints: HitPoints
				{
					class HitTurret
					{
						armor = 0.8;
						material = -1;
						name = "vez";
						visual = "vez";
						passThrough = 1;
						minimalHit = 0.1;
						explosionShielding = 0.4;
						radius = 0.25;
					};
					class HitGun
					{
						armor = 0.2;
						material = -1;
						name = "zbran";
						visual = "zbran";
						passThrough = 0;
						minimalHit = 0.1;
						explosionShielding = 0.2;
						radius = 0.25;
					};
				};
			};
		};

		class AnimationSources: AnimationSources
        {
            class recoil_source
            {
                source="reload";
                weapon="HMG_127_APC";
            };
        };
		class Damage
		{
			tex[] = {};
			mat[] =
			{
                "cdf_a3\cdf_a3_vehicles\brdm2\data\BRDM2_01.rvmat",
                "cdf_a3\cdf_a3_vehicles\brdm2\data\BRDM2_01.rvmat",
                "cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_01_destruct.rvmat",

                "cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_02.rvmat",
                "cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_02.rvmat",
                "cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_02_destruct.rvmat",

                "a3\data_f\default.rvmat",
                "a3\data_f\default.rvmat",
                "a3\data_f\default_destruct.rvmat"
			};
		};
		class Exhausts
		{
			class Exhaust
			{
				position = "vyfuk start";
				direction = "vyfuk konec";
				effect = "ExhaustEffectMRAP_03";
			};
			class Exhaust2
			{
				position = "vyfuk start 2";
				direction = "vyfuk konec 2";
				effect = "ExhaustEffectMRAP_03";
			};
		};

        dustFrontLeftPos = "stopa PLL";
        dustFrontRightPos = "stopa PPP";
        dustBackLeftPos = "stopa ZLL";
        dustBackRightPos = "stopa ZPP";

        class Reflectors
        {
            class Left
            {
                color[] = {1900,1800,1700};
                ambient[] = {5,5,5};
                position = "L svetlo";
                direction = "Konec L svetla";
                hitpoint = "L svetlo";
                selection = "L svetlo";
                size = 1;
                innerAngle = 100;
                outerAngle = 179;
                coneFadeCoef = 10;
                intensity = 1;
                useFlare = 0;
                dayLight = 0;
                flareSize = 1.0;
                class Attenuation
                {
                    start = 1.0;
                    constant = 0;
                    linear = 0;
                    quadratic = 0.25;
                    hardLimitStart = 30;
                    hardLimitEnd = 60;
                };
            };
            class Right: Left
            {
                position = "P svetlo";
                direction = "Konec P svetla";
                hitpoint = "P svetlo";
                selection = "P svetlo";
            };
            class Right2: Right
            {
                position = "P svetlo";
                useFlare = 1;
            };
            class Left2: Left
            {
                position = "L svetlo";
                useFlare = 1;
            };
        };
        aggregateReflectors[] = {{ "Left","Right","Left2","Right2" }};

		//PhysX
        #include "physx.hpp"

        //SOUNDS
		soundGetIn[] = {"A3\Sounds_F\vehicles\soft\MRAP_03\getin",0.56234133,1};
		soundGetOut[] = {"A3\Sounds_F\vehicles\soft\MRAP_03\getout",0.56234133,1,40};
		soundDammage[] = {"",1.0,1};
		soundEngineOnInt[] = {"A3\Sounds_F\vehicles\soft\MRAP_03\MRAP_03_start_int",0.31622776,1.0};
		soundEngineOnExt[] = {"A3\Sounds_F\vehicles\soft\MRAP_03\MRAP_03_start_ext",0.56234133,1.0,200};
		soundEngineOffInt[] = {"A3\Sounds_F\vehicles\soft\MRAP_03\MRAP_03_stop_int",0.31622776,1.0};
		soundEngineOffExt[] = {"A3\Sounds_F\vehicles\soft\MRAP_03\MRAP_03_stop_ext",0.56234133,1.0,200};
		buildCrash0[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1",1.0,1,200};
		buildCrash1[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2",1.0,1,200};
		buildCrash2[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3",1.0,1,200};
		buildCrash3[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4",1.0,1,200};
		soundBuildingCrash[] = {"buildCrash0",0.25,"buildCrash1",0.25,"buildCrash2",0.25,"buildCrash3",0.25};
		WoodCrash0[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_1",1.0,1,200};
		WoodCrash1[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_1",1.0,1,200};
		WoodCrash2[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_1",1.0,1,200};
		WoodCrash3[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_1",1.0,1,200};
		soundWoodCrash[] = {"woodCrash0",0.25,"woodCrash1",0.25,"woodCrash2",0.25,"woodCrash3",0.25};
		armorCrash0[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1",1.0,1,200};
		armorCrash1[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2",1.0,1,200};
		armorCrash2[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3",1.0,1,200};
		armorCrash3[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4",1.0,1,200};
		soundArmorCrash[] = {"ArmorCrash0",0.25,"ArmorCrash1",0.25,"ArmorCrash2",0.25,"ArmorCrash3",0.25};
		Crash0[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1",1.0,1,200};
		Crash1[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2",1.0,1,200};
		Crash2[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3",1.0,1,200};
		Crash3[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4",1.0,1,200};
		soundCrashes[] = {"Crash0",0.25,"Crash1",0.25,"Crash2",0.25,"Crash3",0.25};
		class Sounds
		{
			class Idle_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_03\MRAP_03_500rpm_ext",0.31622776,1,100};
				frequency = "0.95	+	((rpm/	3000) factor[(0/	3000),(900/	3000)])*0.15";
				volume = "engineOn*camPos*(((rpm/	3000) factor[(200/	3000),(300/	3000)])	*	((rpm/	3000) factor[(900/	3000),(600/	3000)]))";
			};
			class Engine
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_03\MRAP_03_1000rpm_ext",0.39810717,1,200};
				frequency = "0.9	+	((rpm/	3000) factor[(900/	3000),(1500/	3000)])*0.2";
				volume = "engineOn*camPos*(((rpm/	3000) factor[(800/	3000),(1000/	3000)])	*	((rpm/	3000) factor[(2000/	3000),(1400/	3000)]))";
			};
			class Engine1_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_03\MRAP_03_1200rpm_ext",0.5011872,1,250};
				frequency = "0.9	+	((rpm/	3000) factor[(1500/	3000),(2100/	3000)])*0.2";
				volume = "engineOn*camPos*(((rpm/	3000) factor[(1600/	3000),(1950/	3000)])	*	((rpm/	3000) factor[(2800/	3000),(2300/	3000)]))";
			};
			class Engine2_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_03\MRAP_03_1500rpm_ext",0.63095737,1,250};
				frequency = "0.95	+	((rpm/	3000) factor[(2100/	3000),(3100/	3000)])*0.1";
				volume = "engineOn*camPos*((rpm/	3000) factor[(2400/	3000),(3200/	3000)])";
			};
			class IdleThrust
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_03\MRAP_03_500rpm_ext_exhaust",0.56234133,1,150};
				frequency = "0.95	+	((rpm/	3000) factor[(0/	3000),(900/	3000)])*0.15";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3000) factor[(200/	3000),(300/	3000)])	*	((rpm/	3000) factor[(900/	3000),(600/	3000)]))";
			};
			class EngineThrust
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_03\MRAP_03_1000rpm_ext_exhaust",0.63095737,1,200};
				frequency = "0.9	+	((rpm/	3000) factor[(900/	3000),(1500/	3000)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3000) factor[(800/	3000),(1000/	3000)])	*	((rpm/	3000) factor[(2000/	3000),(1400/	3000)]))";
			};
			class Engine1_Thrust_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_03\MRAP_03_1200rpm_ext_exhaust",0.70794576,1,250};
				frequency = "0.9	+	((rpm/	3000) factor[(1500/	3000),(2100/	3000)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3000) factor[(1600/	3000),(1950/	3000)])	*	((rpm/	3000) factor[(2800/	3000),(2300/	3000)]))";
			};
			class Engine2_Thrust_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_03\MRAP_03_1500rpm_ext_exhaust",1.1220185,1,300};
				frequency = "0.95	+	((rpm/	3000) factor[(2100/	3000),(3100/	3000)])*0.1";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/	3000) factor[(2400/	3000),(3200/	3000)])";
			};
			class Idle_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_03\MRAP_03_500rpm_int",0.2238721,1};
				frequency = "0.95	+	((rpm/	3000) factor[(0/	3000),(900/	3000)])*0.15";
				volume = "engineOn*(1-camPos)*(((rpm/	3000) factor[(200/	3000),(300/	3000)])	*	((rpm/	3000) factor[(900/	3000),(600/	3000)]))";
			};
			class Engine_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_03\MRAP_03_1000rpm_int",0.25118864,1};
				frequency = "0.9	+	((rpm/	3000) factor[(900/	3000),(1500/	3000)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/	3000) factor[(800/	3000),(1000/	3000)])	*	((rpm/	3000) factor[(2000/	3000),(1400/	3000)]))";
			};
			class Engine1_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_03\MRAP_03_1200rpm_int",0.31622776,1};
				frequency = "0.9	+	((rpm/	3000) factor[(1500/	3000),(2100/	3000)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/	3000) factor[(1600/	3000),(1950/	3000)])	*	((rpm/	3000) factor[(2800/	3000),(2300/	3000)]))";
			};
			class Engine2_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_03\MRAP_03_1500rpm_int",0.4466836,1};
				frequency = "0.95	+	((rpm/	3000) factor[(2100/	3000),(3100/	3000)])*0.1";
				volume = "engineOn*(1-camPos)*((rpm/	3000) factor[(2400/	3000),(3200/	3000)])";
			};
			class IdleThrust_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_03\MRAP_03_500rpm_int_exhaust",0.39810717,1};
				frequency = "0.95	+	((rpm/	3000) factor[(0/	3000),(900/	3000)])*0.15";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3000) factor[(200/	3000),(300/	3000)])	*	((rpm/	3000) factor[(900/	3000),(600/	3000)]))";
			};
			class EngineThrust_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_03\MRAP_03_1000rpm_int_exhaust",0.5011872,1};
				frequency = "0.9	+	((rpm/	3000) factor[(900/	3000),(1500/	3000)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3000) factor[(800/	3000),(1000/	3000)])	*	((rpm/	3000) factor[(2000/	3000),(1400/	3000)]))";
			};
			class Engine1_Thrust_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_03\MRAP_03_1200rpm_int_exhaust",0.63095737,1};
				frequency = "0.9	+	((rpm/	3000) factor[(1500/	3000),(2100/	3000)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3000) factor[(1600/	3000),(1950/	3000)])	*	((rpm/	3000) factor[(2800/	3000),(2300/	3000)]))";
			};
			class Engine2_Thrust_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_03\MRAP_03_1500rpm_int_exhaust",0.8912509,1};
				frequency = "0.95	+	((rpm/	3000) factor[(2100/	3000),(3100/	3000)])*0.1";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/	3000) factor[(2400/	3000),(3200/	3000)])";
			};
			class Movement
			{
				sound = "soundEnviron";
				frequency = "1";
				volume = "0";
			};
			class TiresRockOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_1",1.4125376,1.0,60};
				frequency = "1";
				volume = "camPos*rock*(speed factor[2, 20])";
			};
			class TiresSandOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-sand1",1.0,1.0,60};
				frequency = "1";
				volume = "camPos*sand*(speed factor[2, 20])";
			};
			class TiresGrassOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_2",1.0,1.0,60};
				frequency = "1";
				volume = "camPos*grass*(speed factor[2, 20])";
			};
			class TiresMudOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-mud2",1.0,1.0,60};
				frequency = "1";
				volume = "camPos*mud*(speed factor[2, 20])";
			};
			class TiresGravelOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_gravel_1",1.5848932,1.0,60};
				frequency = "1";
				volume = "camPos*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_asfalt_2",1.0,1.0,60};
				frequency = "1";
				volume = "camPos*asphalt*(speed factor[2, 20])";
			};
			class NoiseOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\noise_ext_car_3",1.2589254,1.0,90};
				frequency = "1";
				volume = "camPos*(damper0 max 0.02)*(speed factor[0, 8])";
			};
			class TiresRockIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_1",0.70794576,1.0};
				frequency = "1";
				volume = "(1-camPos)*rock*(speed factor[2, 20])";
			};
			class TiresSandIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int-tires-sand2",0.70794576,1.0};
				frequency = "1";
				volume = "(1-camPos)*sand*(speed factor[2, 20])";
			};
			class TiresGrassIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_2",0.70794576,1.0};
				frequency = "1";
				volume = "(1-camPos)*grass*(speed factor[2, 20])";
			};
			class TiresMudIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int-tires-mud2",0.70794576,1.0};
				frequency = "1";
				volume = "(1-camPos)*mud*(speed factor[2, 20])";
			};
			class TiresGravelIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_gravel_1",0.70794576,1.0};
				frequency = "1";
				volume = "(1-camPos)*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_asfalt_2",0.70794576,1.0};
				frequency = "1";
				volume = "(1-camPos)*asphalt*(speed factor[2, 20])";
			};
			class NoiseIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\noise_int_car_3",0.5011872,1.0};
				frequency = "1";
				volume = "(damper0 max 0.1)*(speed factor[0, 8])*(1-camPos)";
			};
			class breaking_ext_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04",0.56234133,1,100};
				frequency = 1;
				volume = "engineOn*camPos*(LongSlipDrive Factor[-0.15, -0.3])*(Speed Factor[2, 10])";
			};
			class acceleration_ext_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",0.56234133,1,100};
				frequency = 1;
				volume = "engineOn*camPos*(LongSlipDrive Factor[0.15, 0.3])*(Speed Factor[10, 1])";
			};
			class turn_left_ext_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",0.56234133,1,100};
				frequency = 1;
				volume = "engineOn*camPos*(latSlipDrive Factor[0.15, 0.3])*(Speed Factor[0, 10])";
			};
			class turn_right_ext_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",0.56234133,1,100};
				frequency = 1;
				volume = "engineOn*camPos*(latSlipDrive Factor[-0.15, -0.3])*(Speed Factor[0, 10])";
			};
			class breaking_ext_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04",0.56234133,1,100};
				frequency = 1;
				volume = "engineOn*camPos*(LongSlipDrive Factor[-0.15, -0.3])*(Speed Factor[2, 10])";
			};
			class acceleration_ext_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",0.56234133,1,100};
				frequency = 1;
				volume = "engineOn*camPos*(LongSlipDrive Factor[0.15, 0.3])*(Speed Factor[10, 0])";
			};
			class turn_left_ext_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",0.56234133,1,100};
				frequency = 1;
				volume = "engineOn*camPos*(latSlipDrive Factor[0.15, 0.3])*(Speed Factor[0, 10])";
			};
			class turn_right_ext_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",0.56234133,1,100};
				frequency = 1;
				volume = "engineOn*camPos*(latSlipDrive Factor[-0.15, -0.3])*(Speed Factor[0, 10])";
			};
			class breaking_int_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04_int",0.56234133,1};
				frequency = 1;
				volume = "engineOn*(1-camPos)*(LongSlipDrive Factor[-0.15, -0.3])*(Speed Factor[2, 6])";
			};
			class acceleration_int_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",0.56234133,1};
				frequency = 1;
				volume = "engineOn*(1-camPos)*(LongSlipDrive Factor[0.15, 0.3])*(Speed Factor[10, 0])";
			};
			class turn_left_int_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",0.56234133,1};
				frequency = 1;
				volume = "engineOn*(1-camPos)*(latSlipDrive Factor[0.15, 0.3])*(Speed Factor[0, 10])";
			};
			class turn_right_int_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",0.56234133,1};
				frequency = 1;
				volume = "engineOn*(1-camPos)*(latSlipDrive Factor[-0.15, -0.3])*(Speed Factor[0, 10])";
			};
			class breaking_int_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04_int",0.56234133,1};
				frequency = 1;
				volume = "engineOn*(1-camPos)*(LongSlipDrive Factor[-0.15, -0.3])*(Speed Factor[2, 6])";
			};
			class acceleration_int_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",0.56234133,1};
				frequency = 1;
				volume = "engineOn*(1-camPos)*(LongSlipDrive Factor[0.15, 0.3])*(Speed Factor[10, 0])";
			};
			class turn_left_int_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",0.56234133,1};
				frequency = 1;
				volume = "engineOn*(1-camPos)*(latSlipDrive Factor[0.15, 0.3])*(Speed Factor[0, 10])";
			};
			class turn_right_int_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",0.56234133,1};
				frequency = 1;
				volume = "engineOn*(1-camPos)*(latSlipDrive Factor[-0.15, -0.3])*(Speed Factor[0, 10])";
			};
		};

		class ViewPilot
		{
            initAngleX=10; minAngleX=-65; maxAngleX=+85; //Rg 30;
            initAngleY=0; minAngleY=-150; maxAngleY=+150; //Rg 100;
			initFov=0.7; minFov=0.42; maxFov=0.85;
		};

		//HITPOINTS
		class HitPoints: HitPoints
		{
			class HitLFWheel: HitLFWheel
			{
				armor = 0.4;
				explosionShielding = 1;
			};
			class HitLF2Wheel: HitLF2Wheel
			{
				armor = 0.4;
				explosionShielding = 1;
			};
			class HitRFWheel: HitRFWheel
			{
				armor = 0.4;
				explosionShielding = 1;
			};
			class HitRF2Wheel: HitRF2Wheel
			{
				armor = 0.4;
				explosionShielding = 1;
			};
			class HitFuel
			{
				armor = 0.5;
				material = -1;
				name = "palivo";
				visual = "";
				passThrough = 0.2;
				minimalHit = 0.25;
				explosionShielding = 0.6;
				radius = 0.25;
			};
			class HitEngine
			{
				armor = 0.5;
				material = -1;
				name = "motor";
				visual = "";
				passThrough = 0.2
				minimalHit = 0.25;
				explosionShielding = 0.4;
				radius = 0.25;
			};
			class HitBody
			{
				armor = 1.0;
				material = -1;
				name = "karoserie";
				visual = "";
				passThrough = 1;
				minimalHit = 0.25;
				explosionShielding = 0.2;
				radius = 0.33;
			};
		};
		armorGlass=0.5;
		armorWheels=0.15;
		armorBody=0.4;
        armorFuel=1.4;
        armorLights=0.4;

		wheelDamageThreshold = 0.7;
		wheelDestroyThreshold = 0.99;
		wheelDamageRadiusCoef = 0.95;
		wheelDestroyRadiusCoef = 0.45;
	};

	class CDF_A3_BRDM2_ATGM_Base: CDF_A3_BRDM2_Base
	{
	    displayName= $STR_DN_BRDM2_ATGM;
    	vehicleClass = "Armored";
		model = "\cdf_a3\cdf_a3_vehicles\brdm2\BRDM2_ATGM.p3d";
		picture="\cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_atgm_CA.paa";
		Icon="\cdf_a3\cdf_a3_vehicles\brdm2\data\icomap_brdm_atgm_CA.paa";
		mapSize = 6;
		transportSoldier = 0;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"CDF_A3_AT5_Launcher"};
				soundServo[] = {"A3\sounds_f\dummysound",0.01,1.0,10};
				magazines[] = {"CDF_A3_5Rnd_AT5","CDF_A3_5Rnd_AT5"};
				gunBeg = "spice rakety";
				gunEnd = "konec rakety";
				gunnerOpticsModel = "\cdf_a3\cdf_a3_vehicles\brdm2\2Dscope_ATGM";
				gunnerAction = "gunner_MRAP_03";
				class ViewOptics
				{
					initAngleX=5; minAngleX=-30; maxAngleX=+30;
					initAngleY=0; minAngleY=0; maxAngleY=0;
					initFov=0.200; minFov=0.058; maxFov=0.200;  //(initFov=0.047; minFov=0.047; maxFov=0.047;)
				};
			};
		};
	};
	class CDF_A3_BRDM2_HQ_Base: CDF_A3_BRDM2_Base
	{
		displayName= $STR_DN_BRDM2_HQ;
		vehicleClass = "Armored";
		model = "\cdf_a3\cdf_a3_vehicles\brdm2\BRDM2_HQ.p3d";
		Icon="\cdf_a3\cdf_a3_vehicles\brdm2\data\icomap_brdm_hq_CA.paa";
		mapSize = 6;
        transportSoldier = 0;
        class AnimationSources: AnimationSources
        {
            class ReloadAnim
            {
                source="reload";
                weapon="LMG_coax";
            };
            class ReloadMagazine
            {
                source="reloadmagazine";
                weapon="LMG_coax";
            };
            class Revolving
            {
                source="revolving";
                weapon="LMG_coax";
            };
        };
        class Turrets: Turrets
        {
            class MainTurret: NewTurret
            {
                weapons[]={"LMG_coax"};
                magazines[]={200Rnd_762x51_Belt_T_Yellow,200Rnd_762x51_Belt_T_Yellow,200Rnd_762x51_Belt_T_Yellow,200Rnd_762x51_Belt_T_Yellow,200Rnd_762x51_Belt_T_Yellow};
                class Turrets{};

                startEngine = 0;
                gunnerOpticsModel = "\A3\weapons_f\reticle\optics_empty";
                gunnerAction = "gunner_MRAP_03"; // GAZ_Gunner
                gunnerInAction = "gunner_MRAP_03";
                memoryPointGun = "usti hlavne";
                gunBeg = "usti hlavne";
                gunEnd = "konec hlavne";
                memoryPointGunnerOptics= "eye";
                selectionFireAnim = "zasleh";


                #define VIEW_GUNNER 1000
                #define VIEW_PILOT 1100
                #define VIEW_CARGO 1200

                LODTurnedIn = VIEW_GUNNER;
                LODTurnedOut = VIEW_GUNNER;

                viewGunnerInExternal=1;
                gunnerForceOptics = 0;
                outGunnerMayFire = 1;

                stabilizedInAxes = StabilizedInAxesNone;

                castGunnerShadow = 0;
                forceHideGunner = 1;
                class ViewOptics
                {
                    initAngleX=0; minAngleX=-30; maxAngleX=+30;
                    initAngleY=0; minAngleY=-100; maxAngleY=+100;
                    initFov=0.7; minFov=0.25; maxFov=1.1;
                };

                minTurn=-90; maxTurn=90;
                minElev = __EVAL(-0.6*180/3.1415926);
                maxElev = __EVAL(0.46*180/3.1415926);
                commanding = 1;
                primaryGunner = 0;
                primaryObserver = 1;
            };
        };
        threat[]={0.3, 0.0, 0.1};
	};

    class CDF_A3_BRDM: CDF_A3_BRDM2_Base
    {
        author = "CDF_A3";
        scope=2;
        scopeCurator=2;
        side = 1;
        faction = "CDF_A3";
        crew = "B_CDF_A3_Soldier_Crew";
        typicalCargo[] = {"B_CDF_A3_Soldier_Crew"};
    };
    class CDF_A3_BRDM_ATGM: CDF_A3_BRDM2_ATGM_Base
    {
        author = "CDF_A3";
        scope=2;
        scopeCurator=2;
        side = 1;
        faction = "CDF_A3";
        crew = "B_CDF_A3_Soldier_Crew";
        typicalCargo[] = {"B_CDF_A3_Soldier_Crew"};
    };
    class CDF_A3_BRDM_HQ: CDF_A3_BRDM2_HQ_Base
    {
        author = "CDF_A3";
        scope=2;
        scopeCurator=2;
        side = 1;
        faction = "CDF_A3";
        crew = "B_CDF_A3_Soldier_Crew";
        typicalCargo[] = {"B_CDF_A3_Soldier_Crew"};
    };

//	class CDF_A3_BRDM2_TK_EP1: CDF_A3_BRDM2_Base
//	{
//		expansion = 1;
//		scope = 2;
//		side = 0;
//		accuracy = 0.3;
//		faction = "BIS_TK";
//		crew = "TK_Soldier_EP1";
//		typicalCargo[] = {"TK_Soldier_EP1"};
//		hiddenSelectionsTextures[] = {"\cdf_a3\cdf_a3_vehicles\brdm2\data\BRDM2_01_TKA_CO.paa"};
//		hiddenSelections[] = {"Camo1"};
//		class TransportMagazines
//		{
//			class _xx_20Rnd_762x51_FNFAL
//			{
//				magazine = "20Rnd_762x51_FNFAL";
//				count = 30;
//			};
//			class _xx_HandGrenade_East
//			{
//				magazine = "HandGrenade_East";
//				count = 10;
//			};
//			class _xx_100Rnd_762x54_PK
//			{
//				magazine = "100Rnd_762x54_PK";
//				count = 5;
//			};
//			class _xx_SmokeShellOrange
//			{
//				magazine = "SmokeShellOrange";
//				count = 2;
//			};
//			class _xx_SmokeShell
//			{
//				magazine = "SmokeShell";
//				count = 2;
//			};
//		};
//		class TransportWeapons
//		{
//			class _xx_FN_FAL
//			{
//				weapon = "FN_FAL";
//				count = 2;
//			};
//		};
//	};
//	class CDF_A3_BRDM2_ATGM_TK_EP1: CDF_A3_BRDM2_Base
//	{
//		expansion = 1;
//		scope = 2;
//		side = 0;
//		accuracy = 0.3;
//		faction = "BIS_TK";
//		crew = "TK_Soldier_EP1";
//		typicalCargo[] = {"TK_Soldier_EP1"};
//		class Damage
//		{
//			tex[] = {};
//			mat[] = {"cdf_a3\cdf_a3_vehicles\brdm2\data\BRDM2_01.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\BRDM2_01.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_01_destruct.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_02.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_02.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_02_destruct.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_ATGM_01.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_ATGM_01.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_atgm_01_destruct.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\default.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\default.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\default_destruct.rvmat"};
//		};
//		hiddenSelectionsTextures[] = {"\cdf_a3\cdf_a3_vehicles\brdm2\data\BRDM2_ATGM_01_TKA_CO.paa"};
//		hiddenSelections[] = {"Camo1"};
//		class TransportMagazines
//		{
//			class _xx_20Rnd_762x51_FNFAL
//			{
//				magazine = "20Rnd_762x51_FNFAL";
//				count = 30;
//			};
//			class _xx_HandGrenade_East
//			{
//				magazine = "HandGrenade_East";
//				count = 10;
//			};
//			class _xx_100Rnd_762x54_PK
//			{
//				magazine = "100Rnd_762x54_PK";
//				count = 5;
//			};
//			class _xx_SmokeShellOrange
//			{
//				magazine = "SmokeShellOrange";
//				count = 2;
//			};
//			class _xx_SmokeShell
//			{
//				magazine = "SmokeShell";
//				count = 2;
//			};
//		};
//		class TransportWeapons
//		{
//			class _xx_FN_FAL
//			{
//				weapon = "FN_FAL";
//				count = 2;
//			};
//		};
//	};
//	class CDF_A3_BRDM2_TK_GUE_EP1: CDF_A3_BRDM2_Base
//	{
//		expansion = 1;
//		scope = 2;
//		side = 2;
//		accuracy = 0.3;
//		faction = "BIS_TK_GUE";
//		crew = "TK_GUE_Soldier_EP1";
//		typicalCargo[] = {"TK_GUE_Soldier_EP1"};
//		hiddenSelectionsTextures[] = {"\cdf_a3\cdf_a3_vehicles\brdm2\data\BDRM2_KHK_01_CO.paa"};
//		hiddenSelections[] = {"Camo1"};
//		class Damage
//		{
//			tex[] = {};
//			mat[] = {"cdf_a3\cdf_a3_vehicles\brdm2\data\BRDM2_01.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\BRDM2_01.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_01_destruct.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_02.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_02.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_02_destruct.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\default.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\default.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\default_destruct.rvmat"};
//		};
//		class TransportMagazines
//		{
//			class _xx_30Rnd_545x39_AK
//			{
//				magazine = "30Rnd_545x39_AK";
//				count = 30;
//			};
//			class _xx_HandGrenade_East
//			{
//				magazine = "HandGrenade_East";
//				count = 10;
//			};
//			class _xx_100Rnd_762x54_PK
//			{
//				magazine = "100Rnd_762x54_PK";
//				count = 5;
//			};
//			class _xx_SmokeShellOrange
//			{
//				magazine = "SmokeShellOrange";
//				count = 2;
//			};
//			class _xx_SmokeShell
//			{
//				magazine = "SmokeShell";
//				count = 2;
//			};
//		};
//		class TransportWeapons
//		{
//			class _xx_AK_74
//			{
//				weapon = "AK_74";
//				count = 2;
//			};
//		};
//	};
//	class CDF_A3_BRDM2_HQ_TK_GUE_EP1: CDF_A3_BRDM2_HQ_Base
//	{
//		expansion = 1;
//		scope = 2;
//		side = 2;
//		accuracy = 0.3;
//		faction = "BIS_TK_GUE";
//		crew = "TK_GUE_Soldier_EP1";
//		typicalCargo[] = {"TK_GUE_Soldier_EP1"};
//		hiddenSelectionsTextures[] = {"\cdf_a3\cdf_a3_vehicles\brdm2\data\BDRM2_KHK_01_CO.paa"};
//		hiddenSelections[] = {"Camo1"};
//		class Damage
//		{
//			tex[] = {};
//			mat[] = {"cdf_a3\cdf_a3_vehicles\brdm2\data\BRDM2_01.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\BRDM2_01.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_01_destruct.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_02.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_02.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\brdm2_02_destruct.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\default.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\default.rvmat","cdf_a3\cdf_a3_vehicles\brdm2\data\default_destruct.rvmat"};
//		};
//		class TransportMagazines
//		{
//			class _xx_30Rnd_545x39_AK
//			{
//				magazine = "30Rnd_545x39_AK";
//				count = 30;
//			};
//			class _xx_HandGrenade_East
//			{
//				magazine = "HandGrenade_East";
//				count = 10;
//			};
//			class _xx_100Rnd_762x54_PK
//			{
//				magazine = "100Rnd_762x54_PK";
//				count = 5;
//			};
//			class _xx_SmokeShellOrange
//			{
//				magazine = "SmokeShellOrange";
//				count = 2;
//			};
//			class _xx_SmokeShell
//			{
//				magazine = "SmokeShell";
//				count = 2;
//			};
//		};
//		class TransportWeapons
//		{
//			class _xx_Binocular
//			{
//				weapon = "Binocular";
//				count = 2;
//			};
//			class _xx_NVGoggles
//			{
//				weapon = "NVGoggles";
//				count = 2;
//			};
//		};
//	};
};
