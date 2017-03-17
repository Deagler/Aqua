// Source Engine
#include "source.h"
#include "vfuncs.h"

// Toolkit
#include "../toolkit/file.h"


const char* source::pszCurrentGame = "Unknown";
const char* source::pszAbbGame = "UNKWN";
int source::appID = 0;
char *source::sigs::clientMode_pattern;
char *source::sigs::clientMode_mask;

void source::GrabCurrentGame()
{
	if (toolkit::file::Exists(".//steam_appid.txt"))
	{
		source::appID = std::stoi(toolkit::file::Read(".//steam_appid.txt"));
		switch (appID)
		{
		case 4000:
			source::pszCurrentGame = "Garry's Mod";
			source::pszAbbGame = "GMod";
			break;
		case 730:
			source::pszCurrentGame = "Counter-Strike: Global Offensive";
			source::pszAbbGame = "CSGO";
			break;
		case 620:
			source::pszCurrentGame = "Portal 2";
			source::pszAbbGame = "Portal"; // bcuz who even plays first one
			break;
		case 240:
			source::pszCurrentGame = "Counter-Strike: Source";
			source::pszAbbGame = "CSS";
			break;
		case 440:
			source::pszCurrentGame = "Team Fortress 2";
			source::pszAbbGame = "TF2";
			break;
		case 265630:
			source::pszCurrentGame = "Fistful of Frags";
			source::pszAbbGame = "FOF";
			break;
		case 550:
			source::pszCurrentGame = "Left 4 Dead 2";
			source::pszAbbGame = "L4D2";
			break;
		case 300:
			source::pszCurrentGame = "Day of Defeat: Source";
			source::pszAbbGame = "DODS";
			break;
		}

		if (source::IsGMod())
		{
			source::sigs::clientMode_pattern = "\x8B\x0D\x00\x00\x00\x00\x50\x8B\x01\x8B\x50\x24\xFF\xD2";
			source::sigs::clientMode_mask = "xx????xxxxxxxx";
		}
		else if (source::IsCSGO())
		{
			source::sigs::clientMode_pattern = "\x8B\x0D\x00\x00\x00\x00\x8B\xB6\x00\x00\x00\x00\x57";
			source::sigs::clientMode_mask = "xx????xx????x";
		}
		else
		{ // Seems to be the same for TF2/CSS/Fistful of Frags 
			source::sigs::clientMode_pattern = "\x8B\x0D\x00\x00\x00\x00\xFF\xB0\x00\x00\x00\x00\x8B\x01";
			source::sigs::clientMode_mask = "xx????xx????xx";
		}
		/*TODO: Find L4D2 and Portal 2 ClientMode*/
		vfuncs::SetupVFuncs();
	}

}
