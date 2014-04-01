#include "Shader.h"

namespace Fal
{

	Shader::Shader(const std::string& source, const GLenum type) :
		mType(type),
		mSource(source),
		mHandle(GL_FALSE)
	{
		this->Compile();
	}

	Shader::~Shader()
	{
		if (mHandle != GL_FALSE)
		{
			glDeleteShader(mHandle);
		}
	}

	GLuint Shader::getHandle()
	{
		return mHandle;
	}

	bool Shader::Compile()
	{
		mHandle = glCreateShader(mType);
		const char * source = mSource.c_str();
		glShaderSource(mHandle, 1, &source, NULL);
		glCompileShader(mHandle);

		return true;
	}

	std::string Shader::getInfoLog()
	{
		int logLength = 0;

		// Get length of log
		glGetShaderiv(mHandle, GL_INFO_LOG_LENGTH, &logLength);

		if (logLength > 0)
		{
			int dummy;
			char *buffer = new char[logLength];
			glGetShaderInfoLog(mHandle, logLength, &dummy, buffer);

			std::string infoLog(buffer);
			delete[] buffer;

			return infoLog;
		}
		else
		{
			// No log
			return std::string("");
		}
	}
}