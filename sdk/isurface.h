#pragma once
//SDK
#include "getvfunc.h"
#undef CreateFont

enum FontDrawType_t
{
	// Use the "additive" value from the scheme file
	FONT_DRAW_DEFAULT = 0,

	// Overrides
	FONT_DRAW_NONADDITIVE,
	FONT_DRAW_ADDITIVE,

	FONT_DRAW_TYPE_COUNT = 2,
};

class ISurface
{
public:													
	void DrawSetColor(int r, int g, int b, int a)
	{
		typedef void(__thiscall* vfunc)(void *, int, int, int, int);
		getvfunc<vfunc>(this, vfuncs::ISurface::DrawSetColor)(this, r, g, b, a);
	}

	void DrawFilledRect(int x0, int y0, int x1, int y1)
	{
		typedef void(__thiscall* vfunc)(void *, int, int, int, int);
		getvfunc<vfunc>(this, vfuncs::ISurface::DrawFilledRect)(this, x0, y0, x1, y1);
	}

	void DrawOutlinedRect(int x0, int y0, int x1, int y1)
	{
		typedef void(__thiscall* vfunc)(void *, int, int, int, int);
		getvfunc<vfunc>(this, vfuncs::ISurface::DrawOutlinedRect)(this, x0, y0, x1, y1);
	}

	void DrawLine(int x0, int y0, int x1, int y1)
	{
		typedef void(__thiscall* vfunc)(void *, int, int, int, int);
		getvfunc<vfunc>(this, vfuncs::ISurface::DrawLine)(this, x0, y0, x1, y1);
	}

	void DrawSetTextFont(unsigned long font)
	{
		typedef void(__thiscall* vfunc)(void *, unsigned long);
		getvfunc<vfunc>(this, vfuncs::ISurface::DrawSetTextFont)(this, font);
	}

	void DrawSetTextColor(int r, int g, int b, int a)
	{
		typedef void(__thiscall* vfunc)(void *, int, int, int, int);
		getvfunc<vfunc>(this, vfuncs::ISurface::DrawSetTextColor)(this, r, g, b, a);
	}

	void DrawSetTextPos(int x, int y)
	{
		typedef void(__thiscall* vfunc)(void *, int, int);
		getvfunc<vfunc>(this, vfuncs::ISurface::DrawSetTextPos)(this, x, y);
	}

	void DrawPrintText(const wchar_t *text, int textLen)
	{
		typedef void(__thiscall* vfunc)(void *, const wchar_t *, int, int);
		return getvfunc<vfunc>(this, vfuncs::ISurface::DrawPrintText)(this, text, textLen, 0);
	}

	unsigned long CreateFont()
	{
		typedef unsigned int(__thiscall* vfunc)(void *);
		return getvfunc<vfunc>(this, vfuncs::ISurface::CreateFontW)(this);
	}

	void SetFontGlyphSet(unsigned long font, const char *windowsFontName, int tall, int weight, int blur, int scanlines, int flags)
	{
		typedef void(__thiscall* vfunc)(void *, unsigned long, const char*, int, int, int, int, int, int, int);
		getvfunc<vfunc>(this, vfuncs::ISurface::SetFontGlyphSet)(this, font, windowsFontName, tall, weight, blur, scanlines, flags, 0, 9);
	}

	void GetTextSize(unsigned long font, const wchar_t *text, int &wide, int &tall)
	{
		typedef void(__thiscall* vfunc)(void *, unsigned long, const wchar_t *, int&, int&);
		getvfunc<vfunc>(this, vfuncs::ISurface::GetTextSize)(this, font, text, wide, tall);
	}
};