#pragma once
// Base Headers
#include <Windows.h>

// Source Engine
#include "../../source.h"

// Hooks
#include "../cvmthook.h"

// Toolkit
#include "../../../toolkit/debug.h"

// Aqua
#include "../../../aqua/drawingkit.h"
#include "../../../aqua/entityhelper.h"

// DUI
#include "../../../dui/backend/drawing.h"
#include "../../../dui/utilities/fontmanager.h"
#include "../../../dui/backend/controlcreator.h"


typedef void * (__fastcall *OriginalPaintTraverse)(void *thisptr, int edx, unsigned int vguiPanel, bool forceRepaint, bool allowForce);
OriginalPaintTraverse PaintTraverseFn;

CVMTHook *pvmtPanel;


void * __fastcall hooked_PaintTraverse(void *thisptr, int edx, unsigned int vguiPanel, bool forceRepaint, bool allowForce) {
	using namespace source::interfaces;
	void * oReturn = PaintTraverseFn(thisptr, edx, vguiPanel, forceRepaint, allowForce);
	static unsigned int vPanelToDraw;

	if (!vPanelToDraw)
	{
		const char* vPanelName = pPanel->GetName(vguiPanel);
		bool bFound = false;

		if (source::IsGMod())
		{
			if (vPanelName[0] == 'O' && vPanelName[7] == 'P')
				bFound = true;
		}
		else if (vPanelName[0] == 'M' && vPanelName[2] == 't')
			bFound = true;


		
		


		if (bFound)
		{
		

			vPanelToDraw = vguiPanel;
			toolkit::debug::Log(TEAL, "\nFound %s!\n", vPanelName);
		}
	}

	if (vPanelToDraw == vguiPanel)
	{
	


	}

	return (oReturn);
}