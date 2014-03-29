#include "glfwCallbacks.h"
#include "Renderer.h"
#include "Game.h"

extern Fal::Game game;

void glfw_error_callback(int error, const char* description)
{
	fputs(description, stderr);
	Fal::Logger::log(GL_LOG_FILE, description, __FILE__, __LINE__);
}

void glfw_window_size_callback(GLFWwindow* window, int width, int height)
{
	game.getRenderer().setViewport(width, height);
}