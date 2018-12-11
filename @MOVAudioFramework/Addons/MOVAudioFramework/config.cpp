// #include "BIS_AddonInfo.hpp"
class CfgPatches
{
	class MOVAudioScripts
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={
			"RPC_Scripts",
			"DZ_Data"
		};
	};
};
class CfgMods
{
	class MOVAudioFramework
	{
	    dir = "MOVAudioFramework";
	    picture = "";
	    action = "";
	    hideName = 1;
	    hidePicture = 1;
	    name = "Audio Framework";
	    credits = "mov3ax";
	    author = "mov3ax";
	    authorID = "0";
	    version = "1.0";
	    extra = 0;
	    type = "mod";

	    dependencies[] = { "World", "Mission" };

	    class defs
	    {
			class worldScriptModule
            {
                value = "";
                files[] = {"mov/audio/4_World"};
            };
			class missionScriptModule
            {
                value = "";
                files[] = {"mov/audio/5_Mission"};
            };
        };
    };
};
class CfgSounds
{
	class default
	{
		name="";
		titles[]={};
	};
	class TestSound: default
	{
		sound[]=
		{
			"\mov\audio\sounds\test",
			1,
			1,
			2000
		};
	};
};