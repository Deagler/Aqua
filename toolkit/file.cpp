// Base Headers
#include <fstream>
#include <direct.h>

//Toolkit
#include "file.h"
#include "misc.h"

bool toolkit::file::Exists(const std::string &sPath)
{
	std::ifstream bCheckFile(sPath);

	return ((bool)bCheckFile);
}

std::string toolkit::file::Read(const std::string &sPath) // wtf broken
{
	std::string sReturnFile;
	std::string sTempLine;
	std::ifstream sReadFile(sPath);

	if (sReadFile.is_open())
	{

		while (!sReadFile.eof())
		{
			while (getline(sReadFile, sTempLine))
			{
				sReturnFile = sReturnFile + sTempLine + "\n";
			}

		}

		sReadFile.close();
	}
	return sReturnFile;
}

void toolkit::file::Write(const std::string &sPath, const std::string &sData)
{
	std::ofstream fWriteFile(sPath, std::ios::trunc | std::ios::binary);
	if (fWriteFile.is_open())
	{
		fWriteFile << sData;
		fWriteFile.close();
	}
}

void toolkit::file::CreateFolders(const std::string &sPath) // remake this aids.
{
	std::string sTempPath = "C:/"; // relative to C:/ drive, replace with SHGetFolderPath mayb???
	std::vector<std::string> vecPath = toolkit::misc::explode(sPath, '/');
	for (u_int i = 0; i < vecPath.size() - 1; i++)
	{
		std::string toCreate;
		if (i != vecPath.size() - 2)
		{
			toCreate = sTempPath + vecPath[i] + "/";
			sTempPath = sTempPath + vecPath[i] + "/";
		}
		else{
			toCreate = sTempPath + vecPath[i];
			sTempPath = sTempPath + vecPath[i];
		}

		_mkdir(toCreate.c_str());
		//CreateDirectory((LPCWSTR)toCreate.c_str(),NULL);
	}

}