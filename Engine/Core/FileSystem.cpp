#include "FileSystem.h"
#include <filesystem>
#include <fstream>
#include <sstream>

namespace nc
{
	bool ReadFileToString(const std::string& filename, std::string& filestring)
	{
		std::ifstream fileStream(filename, std::ios::in);
		if (!fileStream.is_open())
		{
			SDL_Log("Error: Failed to open file: %s", filename.c_str());
			return false;
		}

		std::stringstream stream;
		stream << fileStream.rdbuf();
		filestring = stream.str();

		fileStream.close();

		return true;

	}
	void nc::SetFilePath(const std::string& pathname)
	{
		std::filesystem::current_path(pathname);
	}

	std::string nc::GetFilePath()
	{
		return std::filesystem::current_path().string();
	}

}
