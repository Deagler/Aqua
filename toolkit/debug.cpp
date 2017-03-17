#include <Windows.h>
#include "debug.h"

HANDLE toolkit::debug::Console;
void toolkit::debug::CreateConsole() {
	AllocConsole();
	Console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitle("Aqua - Log");
}