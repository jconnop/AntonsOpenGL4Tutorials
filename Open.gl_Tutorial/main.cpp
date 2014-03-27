#include "main.h"
#include "Game.h"

int main()
{
	Fal::Game game;
	if (game.Initialise())
	{
		game.MainLoop();
	}

	return 0;
}