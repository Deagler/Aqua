#pragma once
//Hooks
#include "cvmthook.h"
#include "universal\painttraverse.h"
#include "universal\cmcreatemove.h"
#include "universal\onscreensizechanged.h"

// Source Engine
#include "../source.h"
namespace hooks {
	inline void CheckHook(const char *pszName, void *pOriginalFunction)
	{
		if (pOriginalFunction)
			toolkit::debug::Log(GRAY, "Hooked %s.\n", pszName);
		else
			toolkit::debug::Log(RED, "Failed to hook %s.\n", pszName);
	}
	inline void DoHooks()
	{
		toolkit::debug::Log(TEAL, "\nHooking...\n");
		/*TODO: Code vfunc hooking class.*/
		pvmtPanel = new CVMTHook(source::interfaces::pPanel);
		PaintTraverseFn = (OriginalPaintTraverse)pvmtPanel->hookFunction(vfuncs::IPanel::PaintTraverse, hooked_PaintTraverse);
		CheckHook("PaintTraverse", PaintTraverseFn);

		pvmtClientMode = new CVMTHook(source::interfaces::pClientMode);
		ClientModeCreateMoveFn = (OriginalClientModeCreateMove)pvmtClientMode->hookFunction(vfuncs::IClientMode::CreateMove, hooked_CMCreateMove);
		CheckHook("CreateMove[CM]", ClientModeCreateMoveFn);
		
		pvmtSurface = new CVMTHook(source::interfaces::pSurface);
		OnScreenSizeChangedFn = (OriginalOnScreenSizeChanged)pvmtSurface->hookFunction(vfuncs::ISurface::OnScreenSizeChanged , hooked_OnScreenSizeChanged);
		CheckHook("OnScreenSizeChanged", OnScreenSizeChangedFn);

	}
}