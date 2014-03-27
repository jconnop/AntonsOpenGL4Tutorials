/**
	Wrapper for OpenGL shader management
*/
#pragma once

#include "main.h"
#include <fstream>
#include <string>

namespace Fal
{

	class Shader
	{
	public:
		Shader(const std::string& relativePath, const GLenum type);
		Shader(const std::string& source, const GLenum type, const bool direct);

		~Shader();

		inline GLuint getHandle();
	private:
		GLuint mHandle;
		const GLenum mType;
		const std::string mRelativePath;
		std::string mSource;

		bool LoadFromFile();
		bool Compile();
	protected:

	};

}