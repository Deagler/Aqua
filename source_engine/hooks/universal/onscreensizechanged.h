#pragma once
// Base Headers
#include <Windows.h>

// Source Engine
#include "../../source.h"

// Hooks
#include "../cvmthook.h"



typedef void (__fastcall *OriginalOnScreenSizeChanged)(void *thisptr, int edx, int OldWidth, int OldHeight);
OriginalOnScreenSizeChanged OnScreenSizeChangedFn;

CVMTHook *pvmtSurface;


void __fastcall hooked_OnScreenSizeChanged(void *thisptr, int edx, int OldWidth, int OldHeight)
{
	OnScreenSizeChangedFn(thisptr, edx, OldWidth, OldHeight);
}