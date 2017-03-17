#include "drawingkit.h"
#include <stdio.h>
using namespace source::interfaces;
CDrawingKit drawingManager;
void CDrawingKit::Init()
{
	pEngineClient->GetScreenSize(m_ScreenWidth, m_ScreenHeight);
	toolkit::debug::Log(WHITE, "Screen Res: %i x %i\n", m_ScreenWidth, m_ScreenHeight);

	this->m_BaseFontHeight = 13;
	this->m_ESPFontHeight = 13;

	this->m_BaseFont = pSurface->CreateFont();
	this->m_ESPFont = pSurface->CreateFont();

	pSurface->SetFontGlyphSet(this->m_BaseFont, "Arial", this->m_BaseFontHeight, 500, 0, 0, 0);
	pSurface->SetFontGlyphSet(this->m_ESPFont, "Arial", this->m_ESPFontHeight, 300, 0, 0, 0x200);
}

bool CDrawingKit::WorldToScreen(Vector &vOrigin, Vector &vScreen)
{
	const VMatrix & worldToScreen = pEngineClient->WorldToScreenMatrix();
	if (!worldToScreen[3][0])
		return false;
	float w = worldToScreen[3][0] * vOrigin[0] + worldToScreen[3][1] * vOrigin[1] + worldToScreen[3][2] * vOrigin[2] + worldToScreen[3][3];
	vScreen.z = 0; //Screen doesn't have a 3rd dimension.

	if (w > 0.001f) //If the object is within view.
	{
		float fl1DBw = 1 / w; //Divide 1 by the angle.
		vScreen.x = (m_ScreenWidth / 2) + (0.5f * ((worldToScreen[0][0] * vOrigin[0] + worldToScreen[0][1] * vOrigin[1] + worldToScreen[0][2] * vOrigin[2] + worldToScreen[0][3]) * fl1DBw) * m_ScreenWidth + 0.5f); //Get the X dimension and push it in to the Vector.
		vScreen.y = (m_ScreenHeight / 2) - (0.5f * ((worldToScreen[1][0] * vOrigin[0] + worldToScreen[1][1] * vOrigin[1] + worldToScreen[1][2] * vOrigin[2] + worldToScreen[1][3]) * fl1DBw) * m_ScreenHeight + 0.5f); //Get the Y dimension and push it in to the Vector.
		return true;
	}

	return false;
}

void CDrawingKit::DrawString(unsigned int Font, int x, int y, int r, int g, int b, int a, const char *pszText, ...)
{
	if (pszText == NULL)
		return;

	va_list va_alist;
	char szBuffer[1024] = { '\0' };
	wchar_t szString[1024] = { '\0' };

	va_start(va_alist, pszText);
	vsprintf_s(szBuffer, pszText, va_alist);
	va_end(va_alist);

	wsprintfW(szString, L"%S", szBuffer);

	pSurface->DrawSetTextPos(x, y);
	pSurface->DrawSetTextFont(Font);
	pSurface->DrawSetTextColor(r, g, b, a);
	pSurface->DrawPrintText(szString, wcslen(szString));
}


void CDrawingKit::DrawRectangle(int x, int y, int w, int h, int r, int g, int b, int a)
{
	pSurface->DrawSetColor(r, g, b, a);
	pSurface->DrawFilledRect(x, y, x + w, y + h);
}

void CDrawingKit::DrawOutlinedRectangle(int x, int y, int w, int h, int r, int g, int b, int a)
{
	pSurface->DrawSetColor(r, g, b, a);
	pSurface->DrawOutlinedRect(x, y, x + w, y + h);
}

void CDrawingKit::DrawOutlinedRectangleRaw(int x, int y, int x1, int y1, int r, int g, int b, int a)
{
	pSurface->DrawSetColor(r, g, b, a);
	pSurface->DrawOutlinedRect(x, y, x1, y1);
}


void CDrawingKit::DrawLine(int x, int y, int x1, int y1, int r, int g, int b, int a)
{
	pSurface->DrawSetColor(r, g, b, a);
	pSurface->DrawLine(x, y, x1, y1);
}

void CDrawingKit::Draw3DBox(Vector &mins, Vector &maxs, int r, int g, int b, int a)
{
	Vector diff = maxs - mins;
	Vector pointsToDraw[24] = {
		// Bottom Horizontal lines
		mins, mins + Vector(diff.x, 0, 0), // 1 - 2
		mins + Vector(diff.x, 0, 0), mins + Vector(diff.x, diff.y, 0), // 2 - 3
		mins + Vector(diff.x, diff.y, 0), mins + Vector(0, diff.y, 0), // 3 - 4
		mins + Vector(0, diff.y, 0), mins, // 4 - 1

		// Vertical Lines

		mins, mins + Vector(0, 0, diff.z), // 1 - 6
		mins + Vector(diff.x, 0, 0), mins + Vector(diff.x, 0, diff.z), // 2 - 7
		mins + Vector(diff.x, diff.y, 0), mins + Vector(diff.x, diff.y, diff.z), // 3 - 8
		mins + Vector(0, diff.y, 0), mins + Vector(0, diff.y, diff.z), // 4 - 5

		// Top Horizontal lines.
		maxs, maxs - Vector(diff.x, 0, 0), // 8 - 5
		maxs - Vector(diff.x, 0, 0), maxs - Vector(diff.x, diff.y, 0), // 5 - 6
		maxs - Vector(diff.x, diff.y, 0), maxs - Vector(0, diff.y, 0), // 6 - 7
		maxs - Vector(0, diff.y, 0), maxs // 7 - 8
	};
	Vector startPos, endPos;
	for (int i = 0; i < 24; i += 2)
	{
		if (WorldToScreen(pointsToDraw[i], startPos))
		{
			if (WorldToScreen(pointsToDraw[i + 1], endPos))
				DrawLine((int)startPos.x, (int)startPos.y, (int)endPos.x, (int)endPos.y, r, g, b, a);
		}
	}


}

int CDrawingKit::GetTextWidth(unsigned int font, const char *pszText, ...)
{

	va_list va_alist;
	char szBuffer[1024] = { '\0' };
	wchar_t szString[1024] = { '\0' };

	va_start(va_alist, pszText);
	vsprintf_s(szBuffer, pszText, va_alist);
	va_end(va_alist);

	wsprintfW(szString, L"%S", szBuffer);

	int wide = 0;
	int nullvariable;

	pSurface->GetTextSize(font, szString, wide, nullvariable);

	return wide;
}

int CDrawingKit::GetTextHeight(unsigned int font, const char *pszText, ...)
{

	va_list va_alist;
	char szBuffer[1024] = { '\0' };
	wchar_t szString[1024] = { '\0' };

	va_start(va_alist, pszText);
	vsprintf_s(szBuffer, pszText, va_alist);
	va_end(va_alist);

	wsprintfW(szString, L"%S", szBuffer);

	int height = 0;
	int nullvariable;

	pSurface->GetTextSize(font, szString, nullvariable, height);

	return height;
}

void CDrawingKit::GetTextSize(int &wide, int &tall, unsigned int font, const char *pszText, ...)
{

	va_list va_alist;
	char szBuffer[1024] = { '\0' };
	wchar_t szString[1024] = { '\0' };

	va_start(va_alist, pszText);
	vsprintf_s(szBuffer, pszText, va_alist);
	va_end(va_alist);

	wsprintfW(szString, L"%S", szBuffer);


	pSurface->GetTextSize(font, szString, wide, tall);
}