/**
Renderer is a class that wraps all the OpenGL functionality
*/

#include "main.h"
#include <map>

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
private:
	bool loadAndCompileShader(const std::string relativePath, const GLenum type, GLuint *shader);
protected:
	GLFWwindow *window;
	std::map <std::string, GLuint> vaos;
	std::map <std::string, GLuint> vertex_shaders;
	std::map <std::string, GLuint> fragment_shaders;
};