#include "Game.h"

namespace Fal
{

	Game::Game()
	{
		this->mRenderer.InitWindow(4, 0, false, 1024, 768, std::string("OpenGL Stuff"));
	}

	Game::~Game()
	{

	}

	bool Game::Initialise()
	{
		if (this->mRenderer.LoadShaders() && this->mRenderer.LoadScene())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Game::MainLoop()
	{
		GLFWwindow *window = this->mRenderer.getWindow();

		while (!glfwWindowShouldClose(window))
		{
			this->mRenderer.RenderScene();

			glfwSwapBuffers(window);

			glfwPollEvents();

			//Messy, move me
			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			{
				glfwSetWindowShouldClose(window, GL_TRUE);
			}
		}

	}

	Renderer& Game::getRenderer()
	{
		return this->mRenderer;
	}

}