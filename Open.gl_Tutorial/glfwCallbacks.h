/**
	C-style GLFW library callback functions
*/

#pragma once

#include "main.h"
#include "Logger.h"

void glfw_error_callback(int error, const char* description);
void glfw_window_size_callback(GLFWwindow* window, int width, int height);