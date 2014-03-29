#include "main.h"
#include "Game.h"
#include "Logger.h"

// FML it's a global. Fuck C style callbacks.
Fal::Game game;

int main()
{
	Fal::Logger::truncateLog(GL_LOG_FILE);

	if (game.Initialise())
	{
		game.MainLoop();
	}

	return 0;
}