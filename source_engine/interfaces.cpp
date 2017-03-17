// Base Headers
#include <Windows.h>
#include <stdio.h>

// Source Engine
#include "source.h"

// Toolkit
#include "../toolkit/sigscan.h"

using namespace source;
IVEngineClient		*interfaces::pEngineClient;
IClientEntityList	*interfaces::pEntityList;
CHLClient			*interfaces::pClient;
IPanel				*interfaces::pPanel;
ISurface			*interfaces::pSurface;
IVModelInfo			*interfaces::pModelInfo;
IClientMode			*interfaces::pClientMode;
void				*interfaces::pIInput;

void interfaces::GrabInterfaces() {
	toolkit::debug::Log(TEAL, "Grabbing Interfaces...\n");

	pEngineClient = backend::GetInterface<IVEngineClient *>("engine.dll", "VEngineClient", "IVEngineClient");
	pEntityList = backend::GetInterface<IClientEntityList *>("client.dll", "VClientEntityList", "IClientEntityList");
	pClient = backend::GetInterface<CHLClient *>("client.dll", "VClient", "CHLClient");

	DWORD dwClientMode = toolkit::sigscan::FindPattern("client.dll", sigs::clientMode_pattern, sigs::clientMode_mask);
	pClientMode = **(IClientMode ***)(dwClientMode + 0x2);
	backend::CheckInterface("IClientMode", "Signature", pClientMode);

	pPanel = backend::GetInterface<IPanel *>("vgui2.dll", "VGUI_Panel", "IPanel");
	pSurface = backend::GetInterface<ISurface *>("vguimatsurface.dll", "VGUI_Surface", "ISurface");
	pModelInfo = backend::GetInterface<IVModelInfo *>("engine.dll", "VModelInfoClient", "IVModelInfo");

	//if (source::IsGMod())
	//	pIInput = backend::GetInterface<void *>("vgui2.dll", "VGUI_Input", "IInput");



}

template <class CInterface>
CInterface interfaces::backend::GetInterface(const char *pszModule, const char *pszInterface, const char *pszPrintName)
{
	char szTempInterface[128]; 
	CreateInterfaceFn interfaceFactory = getFactory(pszModule);
	CInterface pInterface;

	for (int i = 100; i > 0; i--)
	{
		if (i <= 9)
			sprintf_s(szTempInterface, "%s00%i", pszInterface, i);

		if (i >= 10)
			sprintf_s(szTempInterface, "%s0%i", pszInterface, i);

		pInterface = (CInterface)interfaceFactory(szTempInterface, NULL);

		if (pInterface)
			break;
	}

	backend::CheckInterface(pszPrintName, szTempInterface, pInterface);
	return (pInterface);
}



