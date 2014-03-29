#include "main.h"
#include "Game.h"
#include "Logger.h"

int main()
{
	Fal::Game game;
	if (game.Initialise())
	{
		game.MainLoop();
	}

	return 0;
}

// C-style function callbacks
void glfw_error_callback(int error, const char* description) 
{
	fputs(description, stderr);
	Logger::log(GL_LOG_FILE, description, __FILE__, __LINE__);
}