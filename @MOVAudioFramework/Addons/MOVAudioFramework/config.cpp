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
class CfgSoundShaders
{
	class baseCharacter_SoundShader;
	class Test_SoundShader: baseCharacter_SoundShader
	{
		samples[] = {{"mov\audio\sounds\test",1}};
		volume = 0.5011872;
	};
};
class CfgSoundSets
{
	class baseCharacter_SoundSet;
	class Test_SoundSet: baseCharacter_SoundSet
	{
		soundShaders[] = {"Test_SoundShader"};
		loop = 1;
		frequencyRandomizer = 1;
		volumeRandomizer = 1;
	};
};