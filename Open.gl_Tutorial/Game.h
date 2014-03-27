/**
High level game logic. Main loop, etc.
*/

#include "main.h"

class Game
{
public:
	Game();
	~Game();
	bool Initialise();
	void MainLoop();
private:
	Renderer renderer;
protected:
};