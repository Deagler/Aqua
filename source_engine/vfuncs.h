#pragma once;

namespace vfuncs {
	namespace CHLClient {
		extern unsigned int GetAllClasses;
		extern unsigned int IN_ActivateMouse;
		extern unsigned int CreateMove;
		extern unsigned int WriteUserCmdDeltaToBuffer;
	}

	namespace IClientMode {
		extern unsigned int ShouldDrawFog;
		extern unsigned int CreateMove;
	}

	namespace IClientEntity {
		extern unsigned int GetAbsOrigin;
		extern unsigned int SetupBones;
		extern unsigned int IsDormant;
	}

	namespace IClientEntityList {
		extern unsigned int GetClientEntity;
		extern unsigned int GetClientEntityFromHandle;
		extern unsigned int NumberOfEntities;
		extern unsigned int GetHighestEntityIndex;
	}

	namespace IPanel {
		extern unsigned int GetName;
		extern unsigned int PaintTraverse;
	}

	namespace ISurface {
		extern unsigned int DrawSetColor;
		extern unsigned int DrawFilledRect;
		extern unsigned int DrawOutlinedRect;
		extern unsigned int DrawLine;
		extern unsigned int DrawSetTextFont;
		extern unsigned int DrawSetTextColor;
		extern unsigned int DrawSetTextPos;
		extern unsigned int DrawPrintText;
		extern unsigned int CreateFontW;
		extern unsigned int SetFontGlyphSet;
		extern unsigned int GetTextSize;
		extern unsigned int OnScreenSizeChanged;
	}

	namespace IVEngineClient {
		extern unsigned int GetScreenSize;
		extern unsigned int GetPlayerInfo;
		extern unsigned int Con_IsVisible;
		extern unsigned int GetLocalPlayer;
		extern unsigned int GetLastTimeStamp;
		extern unsigned int GetViewAngles;
		extern unsigned int SetViewAngles;
		extern unsigned int GetMaxClients;
		extern unsigned int IsInGame;
		extern unsigned int IsDrawingLoadingImage;
		extern unsigned int WorldToScreenMatrix;
		extern unsigned int IsTakingScreenshot;
		extern unsigned int GetNetChannelInfo;
		extern unsigned int ClientCmd_Unrestricted;
	}

	namespace IVModelInfo {
		extern unsigned int GetModel;
		extern unsigned int GetModelName; // mayb we parse name and shit, we'll see.
		extern unsigned int GetStudiomodel;
	}

	void SetupVFuncs();

}