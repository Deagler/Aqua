#pragma once
// Base
#include <Windows.h>

// Toolkit
#include "misc.h"

enum COLORS {
	DARKBLUE = 1,
	DARKGREEN,
	DARKTEAL,
	DARKRED,
	DARKPINK,
	DARKYELLOW,
	GRAY,
	DARKGRAY,
	BLUE,
	GREEN,
	TEAL,
	RED,
	PINK,
	YELLOW,
	WHITE
};

namespace toolkit {
	namespace debug {
		extern HANDLE Console;
		void CreateConsole();

		template <typename ...Args>
		void Log(WORD col, const char *pszMessage, Args... args)
		{
			if (col != NULL)
				SetConsoleTextAttribute(Console, col);

			char szString[1024] = { '\0' };

			sprintf_s(szString, pszMessage, args...);

			WriteConsole(Console, szString, strlen(szString), NULL, NULL);
		}
	}
}