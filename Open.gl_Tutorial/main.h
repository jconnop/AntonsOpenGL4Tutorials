#pragma once

//We are linking statically with GLEW
#define GLEW_STATIC

// GLEW header
#include <GL/glew.h>

// GLFW header
#include <GLFW/glfw3.h>

// GLM header / defines
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

// Project wide defines
#define GL_LOG_FILE "gl.log"

int main();
void glfw_error_callback(int error, const char* description);