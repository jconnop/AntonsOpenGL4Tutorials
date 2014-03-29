/**
	Basic logging to file support
*/

#pragma once

#include "main.h"
#include <ctime>
#include <chrono>
#include <string>
#include <fstream>
#include <iomanip>

namespace Fal
{

	class Logger
	{
	public:
		static bool truncateLog(std::string file);
		static bool log(std::string file, std::string message, const char *filename, int line);
	private:
	protected:
	};

}