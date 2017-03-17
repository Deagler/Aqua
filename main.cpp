/*
Aqua - Source Engine Base

Credits:
Nanocat
Leystryku


Created by Deagler and Infernus

*/

// Base Headers
#include <Windows.h>


// Toolkit Headers
#include "toolkit\file.h"
#include "toolkit\debug.h"

// Source Engine Headers
#include "source_engine\source.h"

// Hook Headers
#include "source_engine\hooks\hooks.h"

// DUI
#include "dui\backend\controlhandler.h"



DWORD WINAPI EntryThread(LPVOID lpParam)
{
	while (!GetModuleHandle("client.dll"))
		Sleep(200);

	toolkit::debug::CreateConsole();
	source::GrabCurrentGame();

	toolkit::file::CreateFolders("aqua/"+std::string(source::pszAbbGame)+"/netvars/misc.txt");
	toolkit::file::CreateFolders("aqua/"+std::string(source::pszAbbGame)+"/logs/misc.txt");

	
	toolkit::debug::Log(COLORS::TEAL, "\nAqua for %s(%i) loaded!\n\n", source::pszCurrentGame, source::appID);

	source::interfaces::GrabInterfaces();
	source::netvars::offsets::GrabOffsets();
	drawingManager.Init();
	hooks::DoHooks();
	DUI::Init();
	source::netvars::DumpNetvars();
	
	
	return (NULL);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)EntryThread, NULL, NULL, NULL);
	}


	return TRUE;
}