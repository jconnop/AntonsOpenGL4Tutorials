#pragma once

//We are linking statically with GLEW
#define GLEW_STATIC

// GLEW header
#include <GL/glew.h>

// Other library headers
#include <GLFW/glfw3.h>

// Project wide defines
#define GL_LOG_FILE "gl.log"

int main();