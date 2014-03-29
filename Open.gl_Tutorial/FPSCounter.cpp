#include "FPSCounter.h"
#include <cstdio>

namespace Fal
{
	double FPSCounter::mDISPLAY_INTERVAL = 0.25;

	FPSCounter::FPSCounter(GLFWwindow *window) : 
		mPreviousSeconds(glfwGetTime()),
		mFrameCount(0)
	{
		this->update();
	}

	void FPSCounter::update()
	{
		double currentSeconds = glfwGetTime();
		double elapsedSeconds = currentSeconds - mPreviousSeconds;
		if (elapsedSeconds > mDISPLAY_INTERVAL)
		{
			mPreviousSeconds = currentSeconds;
			mFPS = (double)mFrameCount / elapsedSeconds;
			char tmp[128];
			sprintf(tmp, "OpenGL @ FPS: %.f", mFPS);
			glfwSetWindowTitle(mWindow, tmp);
			mFrameCount = 0;
		}
		mFrameCount++;
	}
}