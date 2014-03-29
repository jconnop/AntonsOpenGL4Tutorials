#include "Logger.h"

bool Logger::truncateLog(std::string file)
{
	auto fileHandle = std::ofstream(file, std::ios::out | std::ios::trunc);

	time_t now = time(NULL);

	fileHandle << "Started logging at " << ctime(&now) << std::endl << std::endl;

	fileHandle.close();
}

bool Logger::log(std::string file, std::string message, const char *filename, int line)
{
	auto fileHandle = std::ofstream(file, std::ios::out | std::ios::app);

	time_t now = time(NULL);

	fileHandle << ctime(&now) << "\t" 
		<< filename << ":" << line << "\t"
		<< message << std::endl;

	fileHandle.close();
}