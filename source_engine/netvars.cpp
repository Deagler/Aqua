#pragma once
//Windows
#include <string>
#include <fstream>

// Source Engine
#include "../sdk/clientclass.h"
#include "source.h"

// Toolkit
#include "../toolkit/file.h"

typedef unsigned long DWORD;
using namespace source;
#undef GetProp

DWORD netvars::backend::CrawlTableForOffset(RecvTable *pTable, const char *name, DWORD offset)
{

	for (int i = 0; i < pTable->numprops; i++)
	{
		RecvProp *pProp = pTable->GetProp(i);

		if (pProp->datatable && pProp->datatable->numprops > 0)
		{
			int iResult = CrawlTableForOffset(pProp->datatable, name, offset + pProp->offset);
			if (iResult != 0x0)
				return iResult;

		}

		std::string propName(pProp->name);
		if (propName.find("[0]") != propName.npos)
			propName.replace(propName.find("[0]"), 3, "\0\0\0");
		if (_stricmp(name, propName.c_str()))
			continue;

		return offset += pProp->offset;
	}

	return 0x0;
}

DWORD netvars::backend::FindNetvar(const char *table, const char *name) {
	ClientClass *pClass = interfaces::pClient->GetAllClasses();

	for (ClientClass *pClass = interfaces::pClient->GetAllClasses(); pClass; pClass = pClass->next)
	{
		RecvTable *pTable = pClass->datatable;

		if (pTable->numprops <= 1)
			continue;

		if (_stricmp(table, pTable->name))
			continue;

	}

	for (; pClass; pClass = pClass->next)
	{
		RecvTable *pTable = pClass->datatable;

		if (pTable->numprops <= 1)
			continue;

		if (_stricmp(table, pTable->name))
			continue;

		int iResult = CrawlTableForOffset(pTable, name);

		toolkit::debug::Log(GRAY, "%s: %s - > 0x%X\n", table, name, iResult);
		return iResult;
	}
	return NULL;

}

std::string toAppend = "";

static void DumpTable(RecvTable *p_Table, int nRecursionLevel) 
{
	std::string tabs = "\t"; // autismo code, wait 4 it.
	for (int j = 0; j != nRecursionLevel; j++)
	{
		tabs = tabs + "\t-";// lmfao
	}
	int numprops = p_Table->numprops;
	if (numprops > 30 && p_Table->GetProp(1)->offset == 0x4)
	{
		numprops = 30;
	}

	for (int i = 0; i < numprops; i++)
	{
		RecvProp *p_Prop = p_Table->GetProp(i);
		const char * name = p_Prop->name;

		if (p_Prop->offset)
		{
			//Msg(std::string(tabs+"%s - > 0x%X\n").c_str(),name,p_Prop->offset);
			if (p_Prop->datatable && p_Prop->datatable->numprops > 3)
			{
				toAppend = toAppend + tabs + toolkit::misc::format("%s - > 0x%X [ %i Members ]\n", name, p_Prop->offset, p_Prop->datatable->numprops);
			}
			else {
				toAppend = toAppend + tabs + toolkit::misc::format("%s - > 0x%X\n", name, p_Prop->offset);
			}

		}

		if (p_Prop->datatable)
		{
			//if(p_Prop->datatable->GetPropR(1)->offset != 0x01 && p_Prop->datatable->GetPropR(1)->offset != 0x04 &&  p_Prop->datatable->GetPropR(1)->offset != 0x14)
			//{
			if (p_Prop->offset == 0x0)
				nRecursionLevel--;
			DumpTable(p_Prop->datatable, ++nRecursionLevel);
			//}
		}
	}


}
void netvars::DumpNetvars()
{
	toolkit::debug::Log(GRAY, "\nAttempting to Dump Netvars\n");
	std::string sPath = "C:/aqua/"+std::string(source::pszAbbGame)+"/netvars/" + toolkit::misc::GetTime(true) + ".lua";
	std::vector<std::string> sLines = { "Aqua", "A revolution that unbelievably became a multi-hack", "", "Net Variable Dump for " + std::string(source::pszCurrentGame), "Dumped at " + toolkit::misc::GetTime(false), "", "#baseline#", "Created by Deagler" };

	toolkit::file::Write(sPath,toolkit::misc::MakeHeading(sLines) + "\n\n");

	std::ofstream fAppendFile(sPath, std::ios::app | std::ios::binary);
	if (fAppendFile.is_open())
	{

		for (ClientClass *pClass = (ClientClass *)source::interfaces::pClient->GetAllClasses(); pClass != NULL; pClass = pClass->next)
		{
			RecvTable *p_rTable = pClass->datatable;
			toAppend = toAppend + toolkit::misc::format("\n\n<  %s  >\n", p_rTable->name);
			DumpTable(p_rTable, 0);

		}


		fAppendFile << toAppend;
		fAppendFile.close();
		toolkit::debug::Log(TEAL, "\nNetvar Dump Stored at [ %s ]\n", sPath.c_str());
	} else {
		toolkit::debug::Log(RED, "\nUnable to open file [ %s ]\n", sPath.c_str());
	}

	
}

DWORD netvars::offsets::m_iHealth;
DWORD netvars::offsets::m_vecOrigin;
DWORD netvars::offsets::m_iTeamNum;
DWORD netvars::offsets::m_iObserverMode;
DWORD netvars::offsets::m_hObserverTarget;
DWORD netvars::offsets::m_Collision;
DWORD netvars::offsets::m_vecMins;
DWORD netvars::offsets::m_vecMaxs;
DWORD netvars::offsets::m_hActiveWeapon;
DWORD netvars::offsets::m_fFlags;
DWORD netvars::offsets::m_nTickBase;
DWORD netvars::offsets::m_nModelIndex;
DWORD netvars::offsets::m_nHitboxSet;
DWORD netvars::offsets::m_bSpottedBy;
void netvars::offsets::GrabOffsets()
{
	toolkit::debug::Log(TEAL, "\nGrabbing Netvar Offsets...\n");

	m_vecOrigin = backend::FindNetvar("DT_BaseEntity", "m_vecOrigin");
	m_iTeamNum = backend::FindNetvar("DT_BaseEntity", "m_iTeamNum");
	m_Collision = backend::FindNetvar("DT_BaseEntity", "m_Collision");
	m_vecMins = backend::FindNetvar("DT_BaseEntity", "m_vecMins");
	m_vecMaxs = backend::FindNetvar("DT_BaseEntity", "m_vecMaxs");
	m_nModelIndex = backend::FindNetvar("DT_BaseEntity", "m_nModelIndex");
	m_bSpottedBy = backend::FindNetvar("DT_BaseEntity", "m_bSpottedBy");

	m_iObserverMode = backend::FindNetvar("DT_BasePlayer", "m_iObserverMode");
	m_hObserverTarget = backend::FindNetvar("DT_BasePlayer", "m_hObserverTarget");
	m_fFlags = backend::FindNetvar("DT_BasePlayer", "m_fFlags");
	m_iHealth = backend::FindNetvar("DT_BasePlayer", "m_iHealth");
	m_nTickBase = backend::FindNetvar("DT_BasePlayer", "m_nTickBase");

	m_hActiveWeapon = backend::FindNetvar("DT_BaseCombatCharacter", "m_hActiveWeapon");
	m_nHitboxSet = backend::FindNetvar("DT_BaseCombatCharacter", "m_nHitboxSet");
}

