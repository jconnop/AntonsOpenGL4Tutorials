#include "Logger.h"

namespace Fal
{

	bool Logger::truncateLog(std::string file)
	{
		auto fileHandle = std::ofstream(file, std::ios::out | std::ios::trunc);
		if (!fileHandle.is_open() || !fileHandle.good())
		{
			fileHandle.close();
			return false;
		}

		std::time_t now = std::time(NULL);
		struct std::tm *ptm = std::localtime(&now);

		fileHandle << "Started logging at " 
			<< std::put_time(ptm, "%Y-%m-%d %H:%M:%S") 
			<< std::endl << std::endl;

		fileHandle.close();

		return true;
	}

	bool Logger::log(std::string file, std::string message, const char *filename, int line)
	{
		auto fileHandle = std::ofstream(file, std::ios::out | std::ios::app);
		if (!fileHandle.is_open() || !fileHandle.good())
		{
			fileHandle.close();
			return false;
		}

		std::time_t now = std::time(NULL);
		struct std::tm *ptm = std::localtime(&now);

		fileHandle << std::put_time(ptm, "%Y-%m-%d %H:%M:%S") << "\t"
			<< filename << ":" << line << "\t"
			<< message << std::endl;

		fileHandle.close();

		return true;
	}

}