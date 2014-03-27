#include "Renderer.h"

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

		// Set high level GL options
		glEnable(GL_DEPTH_TEST); // enable depth-testing
		glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"

		this->window = window;
		return window;
	}

	GLFWwindow *Renderer::getWindow()
	{
		return this->window;
	}

	bool Renderer::LoadShaders()
	{
		this->vertex_shaders["basic"] =
			new Shader("Shaders/Vertex/basic_vs.glsl", GL_VERTEX_SHADER);

		this->fragment_shaders["basic"] =
			new Shader("Shaders/Fragment/basic_fs.glsl", GL_FRAGMENT_SHADER);


		return true;
	}

	bool Renderer::LoadScene()
	{
		// Triangle vertex position data
		float points[] = {
			0.0f, 0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f
		};


		// Create VBO for triangle vertex positions
		GLuint vbo = GL_FALSE;
		glGenBuffers(1, &vbo);
		this->vbos["trianglePosition"] = vbo;

		// Bind triangle position VBO
		glBindBuffer(GL_ARRAY_BUFFER, this->vbos["trianglePosition"]);

		// Shunt triangle position data to gpu memory
		glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);


		// Create VAO for triangle mesh
		GLuint vao = GL_FALSE;
		glGenVertexArrays(1, &vao);
		this->vaos["triangle"] = vao;

		// Bind triangle mesh VAO
		glBindVertexArray(this->vaos["triangle"]);

		// Enable vertex shader attribute #0
		glEnableVertexAttribArray(0);

		// Bind triangle position VBO
		glBindBuffer(GL_ARRAY_BUFFER, this->vbos["trianglePosition"]);

		// Define layout of vertex shader attribute #0
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);


		// Create shader program: basic
		GLuint shader_programme = glCreateProgram();
		glAttachShader(shader_programme, this->fragment_shaders["basic"]->getHandle());
		glAttachShader(shader_programme, this->vertex_shaders["basic"]->getHandle());
		glLinkProgram(shader_programme);
		this->shader_programs["basic"] = shader_programme;

		return true;
	}

	bool Renderer::RenderScene()
	{
		return true;
	}

}