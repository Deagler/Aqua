#pragma once
// Base Headers
#include <Windows.h>

// Source Engine
#include "../../source.h"
#include "../../../sdk/usercmd.h"

// Hooks
#include "../cvmthook.h"




using namespace source::interfaces;

typedef bool(__fastcall *OriginalClientModeCreateMove)(void *thisptr, int edx, float fInputSampleTime, CSGOUserCmd *cmd);
OriginalClientModeCreateMove ClientModeCreateMoveFn;

CVMTHook *pvmtClientMode;

bool  __fastcall hooked_CMCreateMove(void *thisptr, DWORD edx, float fInputSampleTime, CSGOUserCmd *cmd) {

	ClientModeCreateMoveFn(thisptr, edx, fInputSampleTime, cmd);
	/*
	TODO: Figure out the best way to use different structs
		  CSGO Usercmd is different to other games.
	*/

	if (pEngineClient->IsInGame())
	{
	
	}
	return false;
}