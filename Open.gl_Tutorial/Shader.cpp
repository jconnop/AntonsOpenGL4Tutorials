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

}