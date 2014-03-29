/**
Renderer is a class that wraps all the OpenGL functionality
*/
#pragma once

#include "main.h"
#include <map>
#include "Shader.h"
#include "glfwCallbacks.h"

namespace Fal
{
	class Renderer
	{
	public:
		Renderer();
		~Renderer();
		GLFWwindow * InitWindow(int glMajor, int glMinor, bool fullscreen, int x, int y, std::string title);
		GLFWwindow *getWindow();
		bool LoadScene();
		bool LoadShaders();
		bool RenderScene();
		void setViewport(int x, int y);
	private:
		bool loadAndCompileShader(const std::string relativePath, const GLenum type, GLuint *shader);
		int mViewportX;
		int mViewportY;
	protected:
		GLFWwindow *window;
		std::map <std::string, GLuint> vaos;
		std::map <std::string, GLuint> vbos;
		std::map <std::string, GLuint> shader_programs;
		std::map <std::string, Fal::Shader *> vertex_shaders;
		std::map <std::string, Fal::Shader *> fragment_shaders;
	};

}