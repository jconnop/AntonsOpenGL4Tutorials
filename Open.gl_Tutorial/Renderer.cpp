#include "main.h"

Renderer::Renderer()
{

}

Renderer::~Renderer()
{
	this->window = 0;
	glfwTerminate();
}

GLFWwindow * Renderer::InitWindow(int glMajor, int glMinor, bool fullscreen, int x, int y, std::string title)
{
	// Init GLFW Library
	glfwInit();

	// Set up window options
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, glMajor);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, glMinor);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Create Window object
	GLFWwindow* window = 0;
	if (fullscreen)
	{
		window = glfwCreateWindow(x, y, title.c_str(), glfwGetPrimaryMonitor(), nullptr); // Fullscreen
	}
	else
	{
		window = glfwCreateWindow(x, y, title.c_str(), nullptr, nullptr); // Windowed
	}

	// Activate window
	glfwMakeContextCurrent(window);

	// Init GLEW library
	glewExperimental = GL_TRUE;
	glewInit();

	this->window = window;
	return window;
}

GLFWwindow *Renderer::getWindow()
{
	return this->window;
}

bool Renderer::LoadShaders()
{

	return true;
}

bool Renderer::LoadScene()
{

	return true;
}

bool Renderer::RenderScene()
{
	return true;
}