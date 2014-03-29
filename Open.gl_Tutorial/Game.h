/**
High level game logic. Main loop, etc.
*/
#pragma once

#include "main.h"
#include "Renderer.h"

namespace Fal
{

	class Game
	{
	public:
		Game();
		~Game();

		bool Initialise();
		void MainLoop();

		Renderer& getRenderer();
	private:
		Renderer mRenderer;
	protected:
	};

}