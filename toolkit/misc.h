#pragma once
// Base
#include <string>
#include <vector>
#include <sstream>
#include <ctime>

namespace toolkit {
	namespace misc {
		bool inRange(int mx, int my, int x, int y, int w, int h);
		template <typename ...Args>
		std::string format(const char *pszString, Args... args)
		{
			char szString[1024] = { '\0' };

			sprintf_s(szString, pszString, args...);

			return (szString);
		}
		std::vector<std::string> explode(std::string const & s, char delim);


		std::string GetTime(bool bForFileName);
		std::string MakeHeading(std::vector<std::string> sLines);
	}
}

