#include "main.h"

Game::Game()
{
	this->renderer.InitWindow(4, 0, false, 1024, 768, std::string("OpenGL Stuff"));
}

Game::~Game()
{

}

bool Game::Initialise()
{
	if (this->renderer.LoadShaders() && this->renderer.LoadScene())
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
	GLFWwindow *window = this->renderer.getWindow();

	while (!glfwWindowShouldClose(window))
	{
		this->renderer.RenderScene();

		glfwSwapBuffers(window);

		glfwPollEvents();

		//Messy, move me
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, GL_TRUE);
		}
	}

}