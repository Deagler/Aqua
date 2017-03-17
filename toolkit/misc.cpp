// Base
#include <sstream>
#include <ctime>
#include <stdarg.h>
// Toolkit
#include "misc.h"



bool toolkit::misc::inRange(int mx, int my, int x, int y, int w, int h)
{
	if ((mx >= x && my >= y) && (mx <= (x + w) && my <= (y + h)))
		return true;
	else
		return false;
}

std::vector<std::string> toolkit::misc::explode(std::string const & s, char delim) // TODO: redo.
{
	std::vector<std::string> result;
	std::istringstream iss(s);

	for (std::string token; std::getline(iss, token, delim);)
	{
		result.push_back(std::move(token));
	}

	return result;
}

std::string toolkit::misc::GetTime(bool bForFileName) /*TODO: prolly redo this*/
{
	time_t time_temp = time(0);
	tm* ourtime = localtime(&time_temp);
	char cu_time[300];
	if (bForFileName)
	{
		sprintf(cu_time, "%02i-%02i-%02i(%02i.%02i.%02i)", ourtime->tm_hour, ourtime->tm_min, ourtime->tm_sec, ourtime->tm_mday, ourtime->tm_mon + 1, ourtime->tm_year + 1900);
	}
	else {
		sprintf(cu_time, "%02i:%02i:%02i (%02i/%02i/%02i)", ourtime->tm_hour, ourtime->tm_min, ourtime->tm_sec, ourtime->tm_mday, ourtime->tm_mon + 1, ourtime->tm_year + 1900);
	}

	return (std::string(cu_time));

}

std::string toolkit::misc::MakeHeading(std::vector<std::string> sLines) {

	unsigned int maxLength = 0;


	for (std::vector<std::string>::iterator it = sLines.begin(); it != sLines.end(); it++)
	{
		maxLength = maxLength < (*it).length() ? (*it).length() : maxLength;
	}

	std::string szReturn(maxLength + 11, '*');
	szReturn.insert(szReturn.begin(), '/');
	szReturn += '\n';

	for (std::vector<std::string>::iterator it = sLines.begin(); it != sLines.end(); it++)
	{
		if ((*it).find("#baseline#") != std::string::npos)
		{
			szReturn.insert(szReturn.end(), maxLength + 12, '*');
		}
		else
		{
			int length = ((maxLength + 12) - (*it).length()) / 2;
			szReturn += '*';
			if ((*it).length() % 2 == 1)
				szReturn.insert(szReturn.end(), length, ' ');
			else
				szReturn.insert(szReturn.end(), length - 1, ' ');
			szReturn += (*it);
			szReturn.insert(szReturn.end(), length - 1, ' ');
			szReturn += '*';
		}
		szReturn += '\n';
	}

	szReturn.insert(szReturn.end(), maxLength + 11, '*');
	szReturn += '/';
	return szReturn;
}