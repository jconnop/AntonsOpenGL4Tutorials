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
		Shader(const std::string& source, const GLenum type);

		~Shader();

		bool isCompiled();
		GLuint getHandle();
		std::string getInfoLog();
	private:
		GLuint mHandle;
		const GLenum mType;
		std::string mSource;

		bool Compile();

		// Disable some default constructors
		Shader();
		Shader(const Shader&);
	protected:

	};

}