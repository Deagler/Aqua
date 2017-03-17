#pragma once

// Source Engine
#include "../source_engine/source.h"


#undef CreateFont

class CDrawingKit
{
public:
	void Init();
	bool WorldToScreen(Vector &vOrigin, Vector &vScreen);
	void DrawString(unsigned int Font, int x, int y, int r, int g, int b, int a, const char *pszText, ...);
	void DrawRectangle(int x, int y, int w, int h, int r, int g, int b, int a);
	void DrawRoundedRectangle(int x, int y, int w, int h, int r, int g, int b, int a);
	void DrawOutlinedRectangle(int x, int y, int w, int h, int r, int g, int b, int a);
	void DrawOutlinedRectangleRaw(int x, int y, int x1, int y1, int r, int g, int b, int a);
	void DrawLine(int x, int y, int x1, int y1, int r, int g, int b, int a);
	void Draw3DBox(Vector &mins, Vector &maxs, int r, int g, int b, int a);
	int GetTextWidth(unsigned int font, const char *pszText, ...);
	int GetTextHeight(unsigned int font, const char *pszText, ...);
	void GetTextSize(int &wide, int &tall, unsigned int font, const char *pszText, ...);


	inline int ScrW() { return (m_ScreenWidth); }
	inline int ScrH() { return (m_ScreenHeight); }
	unsigned long m_BaseFont;
	int m_BaseFontHeight;
	unsigned long m_ESPFont;
	int m_ESPFontHeight;
private:
	int m_ScreenWidth;
	int m_ScreenHeight;
};

extern CDrawingKit drawingManager;