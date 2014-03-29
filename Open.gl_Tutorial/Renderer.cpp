#include "Renderer.h"
#include "Logger.h"
#include <assert.h>

namespace Fal
{
	Renderer::Renderer()
	{

	}

	Renderer::~Renderer()
	{
		for (auto shader : this->vertex_shaders)
		{
			delete shader.second;
		}

		for (auto shader : this->fragment_shaders)
		{
			delete shader.second;
		}

		this->vertex_shaders.clear();
		this->fragment_shaders.clear();

		this->window = 0;
		glfwTerminate();
	}

	GLFWwindow * Renderer::InitWindow(int glMajor, int glMinor, bool fullscreen, int x, int y, std::string title)
	{
		// Log GL version
		assert(Logger::log(GL_LOG_FILE,
			std::string("Starting GLFW version ").append(glfwGetVersionString()),
			__FILE__, __LINE__));

		// Register GLFW error callback
		glfwSetErrorCallback(glfw_error_callback);

		// Init GLFW Library
		if (!glfwInit()) {
			Logger::log(GL_LOG_FILE, "ERROR: could not start GLFW3", __FILE__, __LINE__);
			return NULL;
		}

		// Set up window options
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, glMajor);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, glMinor);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
		glfwWindowHint(GLFW_SAMPLES, 8);


		// Create Window object
		GLFWwindow* window = NULL;
		GLFWmonitor *mon = glfwGetPrimaryMonitor();
		const GLFWvidmode *vmode = glfwGetVideoMode(mon);
		if (fullscreen)
		{
			// Make sure to have valid window size
			if (x == 0 || y == 0)
			{
				x = vmode->width;
				y = vmode->height;
			}
			window = glfwCreateWindow(x, y, title.c_str(), mon, nullptr); // Fullscreen
		}
		else
		{
			// Make sure to have valid window size
			if (x == 0 || y == 0)
			{
				x = vmode->width / 2;
				y = vmode->height / 2;
			}
			window = glfwCreateWindow(x, y, title.c_str(), nullptr, nullptr); // Windowed
		}

		// Register GLFW window resize callback
		glfwSetWindowSizeCallback(window, glfw_window_size_callback);

		// Activate window
		glfwMakeContextCurrent(window);

		// Init GLEW library
		glewExperimental = GL_TRUE;
		glewInit();

		// Set high level GL options
		glEnable(GL_DEPTH_TEST); // enable depth-testing
		glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"

		// Set viewport sizes
		mViewportX = x;
		mViewportY = y;

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
		// Wipe the drawing surface clear
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Update viewport
		glViewport(0, 0, mViewportX, mViewportY);

		return true;
	}

	void Renderer::setViewport(int x, int y)
	{
		mViewportX = x;
		mViewportY = y;
	}

}