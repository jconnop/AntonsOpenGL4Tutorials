#include "main.h"

int main()
{
	Game game;
	if (game.Initialise())
	{
		game.MainLoop();
	}

	return 0;
}