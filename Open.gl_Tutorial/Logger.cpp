#include "Logger.h"

namespace Fal
{

	bool Logger::truncateLog(std::string file)
	{
		auto fileHandle = std::ofstream(file, std::ios::out | std::ios::trunc);
		if (!fileHandle.good())
		{
			fileHandle.close();
			return false;
		}

		time_t now = time(NULL);

		fileHandle << "Started logging at " << ctime(&now) << std::endl << std::endl;

		fileHandle.close();

		return true;
	}

	bool Logger::log(std::string file, std::string message, const char *filename, int line)
	{
		auto fileHandle = std::ofstream(file, std::ios::out | std::ios::app);
		if (!fileHandle.good())
		{
			fileHandle.close();
			return false;
		}

		time_t now = time(NULL);

		fileHandle << ctime(&now) << "\t"
			<< filename << ":" << line << "\t"
			<< message << std::endl;

		fileHandle.close();

		return true;
	}

}