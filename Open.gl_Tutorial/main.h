#pragma once

//We are linking statically with GLEW
#define GLEW_STATIC

// GLEW header
#include <GL/glew.h>

// Other library headers
#include <GLFW/glfw3.h>

// Project wide defines
#define GL_LOG_FILE "gl.log"

namespace Fal
{

	int main();
	void glfw_error_callback(int error, const char* description);

}