/**
High level game logic. Main loop, etc.
*/
#pragma once

#include "main.h"

class Game
{
public:
	Game();
	~Game();
	bool Initialise();
	void MainLoop();
private:
	Renderer mRenderer;
protected:
};