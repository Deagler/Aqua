// Source Engine
#include "vfuncs.h"
#include "source.h"

unsigned int vfuncs::CHLClient::GetAllClasses;
unsigned int vfuncs::CHLClient::IN_ActivateMouse;
unsigned int vfuncs::CHLClient::CreateMove;
unsigned int vfuncs::CHLClient::WriteUserCmdDeltaToBuffer;

unsigned int vfuncs::IClientMode::ShouldDrawFog;
unsigned int vfuncs::IClientMode::CreateMove;

unsigned int vfuncs::IClientEntity::GetAbsOrigin;
unsigned int vfuncs::IClientEntity::SetupBones; // IClientRenderable
unsigned int vfuncs::IClientEntity::IsDormant; // IClientNetworkable

unsigned int vfuncs::IClientEntityList::GetClientEntity;
unsigned int vfuncs::IClientEntityList::GetClientEntityFromHandle;
unsigned int vfuncs::IClientEntityList::NumberOfEntities;
unsigned int vfuncs::IClientEntityList::GetHighestEntityIndex;

unsigned int vfuncs::IPanel::GetName;
unsigned int vfuncs::IPanel::PaintTraverse;

unsigned int vfuncs::ISurface::DrawSetColor;
unsigned int vfuncs::ISurface::DrawFilledRect;
unsigned int vfuncs::ISurface::DrawOutlinedRect;
unsigned int vfuncs::ISurface::DrawLine;
unsigned int vfuncs::ISurface::DrawSetTextFont;
unsigned int vfuncs::ISurface::DrawSetTextColor;
unsigned int vfuncs::ISurface::DrawSetTextPos;
unsigned int vfuncs::ISurface::DrawPrintText;
unsigned int vfuncs::ISurface::CreateFontW;
unsigned int vfuncs::ISurface::SetFontGlyphSet;
unsigned int vfuncs::ISurface::GetTextSize;
unsigned int vfuncs::ISurface::OnScreenSizeChanged;

unsigned int vfuncs::IVEngineClient::GetScreenSize;
unsigned int vfuncs::IVEngineClient::GetPlayerInfo;
unsigned int vfuncs::IVEngineClient::Con_IsVisible;
unsigned int vfuncs::IVEngineClient::GetLocalPlayer;
unsigned int vfuncs::IVEngineClient::GetLastTimeStamp;
unsigned int vfuncs::IVEngineClient::GetViewAngles;
unsigned int vfuncs::IVEngineClient::SetViewAngles;
unsigned int vfuncs::IVEngineClient::GetMaxClients;
unsigned int vfuncs::IVEngineClient::IsInGame;
unsigned int vfuncs::IVEngineClient::IsDrawingLoadingImage;
unsigned int vfuncs::IVEngineClient::WorldToScreenMatrix;
unsigned int vfuncs::IVEngineClient::GetNetChannelInfo;
unsigned int vfuncs::IVEngineClient::IsTakingScreenshot;
unsigned int vfuncs::IVEngineClient::ClientCmd_Unrestricted;

unsigned int vfuncs::IVModelInfo::GetModel;
unsigned int vfuncs::IVModelInfo::GetModelName;
unsigned int vfuncs::IVModelInfo::GetStudiomodel;

void vfuncs::SetupVFuncs()
{

	vfuncs::CHLClient::GetAllClasses = 8; 
	vfuncs::CHLClient::IN_ActivateMouse = 14;
	vfuncs::CHLClient::CreateMove = 21;
	vfuncs::CHLClient::WriteUserCmdDeltaToBuffer = 23;

	if (source::IsL4D2())
		vfuncs::CHLClient::GetAllClasses = 7;
	

	vfuncs::IClientMode::ShouldDrawFog = 15;
	vfuncs::IClientMode::CreateMove = 21;

	if (source::IsCSGO())
		vfuncs::IClientMode::CreateMove = 24;
	

	vfuncs::IClientEntity::GetAbsOrigin = 9;
	vfuncs::IClientEntity::SetupBones = 16;
	vfuncs::IClientEntity::IsDormant = 9; // CSGO Index, TODO: Find index for other games.

	if (source::IsCSGO())
	{
		vfuncs::IClientEntity::GetAbsOrigin = 10;
		vfuncs::IClientEntity::SetupBones = 13;
	}

	vfuncs::IClientEntityList::GetClientEntity = 3;
	vfuncs::IClientEntityList::GetClientEntityFromHandle = 4;
	vfuncs::IClientEntityList::NumberOfEntities = 5;
	vfuncs::IClientEntityList::GetHighestEntityIndex = 6;

	vfuncs::IPanel::GetName = 36;
	vfuncs::IPanel::PaintTraverse = 41;

	vfuncs::ISurface::DrawSetColor = 11;
	vfuncs::ISurface::DrawFilledRect = 12;
	vfuncs::ISurface::DrawOutlinedRect = 14;
	vfuncs::ISurface::DrawLine = 15;
	vfuncs::ISurface::DrawSetTextFont = 17;
	vfuncs::ISurface::DrawSetTextColor = 19;
	vfuncs::ISurface::DrawSetTextPos = 20;
	vfuncs::ISurface::DrawPrintText = 22;
	vfuncs::ISurface::CreateFontW = 66;
	vfuncs::ISurface::SetFontGlyphSet = 67;
	vfuncs::ISurface::GetTextSize = 75;
	
	if (source::IsCSGO())
	{
		vfuncs::ISurface::DrawSetColor = 15;
		vfuncs::ISurface::DrawFilledRect = 16;
		vfuncs::ISurface::DrawOutlinedRect = 18;
		vfuncs::ISurface::DrawLine = 19;
		vfuncs::ISurface::DrawSetTextFont = 23;
		vfuncs::ISurface::DrawSetTextColor = 25;
		vfuncs::ISurface::DrawSetTextPos = 26;
		vfuncs::ISurface::DrawPrintText = 28;
		vfuncs::ISurface::CreateFontW = 71;
		vfuncs::ISurface::SetFontGlyphSet = 72;
		vfuncs::ISurface::GetTextSize = 79;
		vfuncs::ISurface::OnScreenSizeChanged = 116;
	}

	vfuncs::IVEngineClient::GetScreenSize = 5;
	vfuncs::IVEngineClient::GetPlayerInfo = 8;
	vfuncs::IVEngineClient::Con_IsVisible = 11;
	vfuncs::IVEngineClient::GetLocalPlayer = 12;
	vfuncs::IVEngineClient::GetLastTimeStamp = 14;
	vfuncs::IVEngineClient::GetViewAngles = 19;
	vfuncs::IVEngineClient::SetViewAngles = 20;
	vfuncs::IVEngineClient::GetMaxClients = 21;
	vfuncs::IVEngineClient::IsInGame = 26;
	vfuncs::IVEngineClient::IsDrawingLoadingImage = 28;
	vfuncs::IVEngineClient::WorldToScreenMatrix = 36;
	vfuncs::IVEngineClient::GetNetChannelInfo = 72;
	vfuncs::IVEngineClient::IsTakingScreenshot = 85;
	vfuncs::IVEngineClient::ClientCmd_Unrestricted = 106;

	if (source::IsCSGO())
	{
		vfuncs::IVEngineClient::GetMaxClients = 20;
		vfuncs::IVEngineClient::WorldToScreenMatrix = 37;
	}

	vfuncs::IVModelInfo::GetModel = 1;
	vfuncs::IVModelInfo::GetModelName = 3;
	vfuncs::IVModelInfo::GetStudiomodel = 27;

	if (source::IsCSGO())
		vfuncs::IVModelInfo::GetStudiomodel = 30;

	


}