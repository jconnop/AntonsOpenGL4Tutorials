/**
	Keeps track of FPS, and displays in GLFW window title
*/

#pragma once

#include "main.h"

namespace Fal
{
	class FPSCounter
	{
	public:
		FPSCounter();
		FPSCounter(GLFWwindow *window);

		void update();
		void setWindow(GLFWwindow *window);
	private:
		FPSCounter(const FPSCounter&); // Disable copy constructor

		GLFWwindow *mWindow;
		double mPreviousSeconds;
		int mFrameCount;
		double mFPS;
		static double mDISPLAY_INTERVAL;
	protected:
	};
}