#pragma once
// Base
#include <Windows.h>
#include <string>
#include <vector>
#include <fstream>
#include <direct.h>

namespace toolkit {
	namespace file {
		bool Exists(const std::string &sPath);
		std::string Read(const std::string &sPath);
		void Write(const std::string &sPath, const std::string &sData);
		void CreateFolders(const std::string &sPath);
	}
}
