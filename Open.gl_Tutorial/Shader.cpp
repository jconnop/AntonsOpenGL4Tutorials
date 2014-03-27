#include "Shader.h"

namespace Fal
{

	Shader::Shader(const std::string& relativePath, const GLenum type) :
		mRelativePath(relativePath),
		mType(type),
		mSource(""),
		mHandle(GL_FALSE)
	{
		this->LoadFromFile();

		this->Compile();
	}

	Shader::Shader(const std::string& source, const GLenum type, const bool direct) :
		mRelativePath(""),
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

	bool Shader::LoadFromFile()
	{
		// File input stream
		std::ifstream file(mRelativePath);

		// Use string constructor to read file into string
		std::string fileAsString((std::istreambuf_iterator<char>(file)),
			std::istreambuf_iterator<char>());

		this->mSource = fileAsString;

		return true;
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