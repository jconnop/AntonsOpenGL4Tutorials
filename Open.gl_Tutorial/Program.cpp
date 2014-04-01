#include "Program.h"
#include "Logger.h"

namespace Fal
{
	Program::Program()
	{
		mHandle = glCreateProgram();
	}

	Program::~Program()
	{
		// If program in use, stop using
		if (mInUse)
		{
			stopUsing();
		}

		// Detach and delete shaders
		for (auto shader : mShaders)
		{
			detachShader(*shader);
			delete shader;
		}
		mShaders.clear();

		// Delete program
		glDeleteProgram(mHandle);
	}

	Program& Program::attachShader(Shader *shader)
	{
		if (shader != nullptr)
		{
			// Dereference and call other version
			attachShader(*shader);
		}
	}
	
	Program& Program::attachShader(Shader &shader)
	{
		glAttachShader(mHandle, shader.getHandle());
		mShaders.insert(&shader);
	}

	Program& Program::detachShader(Shader *shader)
	{
		if (shader != nullptr)
		{
			// Dereference and call other version
			detachShader(*shader);
		}
	}

	Program& Program::detachShader(Shader &shader)
	{
		glDetachShader(mHandle, shader.getHandle());
		mShaders.erase(&shader);
	}

	Program& Program::addShaderFromSource(const std::string &source, GLenum type)
	{
		Shader *shader = new Shader(source, type);
		if (shader == nullptr || !shader->isCompiled())
		{
			Logger::log(GL_LOG_FILE,
				"ERROR: Failed to add shader to program from source", __FILE__, __LINE__);
		}

		attachShader(*shader);

		return *this;
	}

	Program& Program::link()
	{
		glLinkProgram(mHandle);

		if (!isLinked())
		{
			Logger::log(GL_LOG_FILE,
				"ERROR: Failed to link shader program", __FILE__, __LINE__);
		}

		return *this;
	}

	Program& Program::startUsing()
	{
		// Start using the program in the GL state machine
		if (!mInUse)
		{
			glUseProgram(mHandle);
			mInUse = true;
		}

		return *this;
	}

	Program& Program::stopUsing()
	{
		// Stop using the program in the GL state machine
		if (mInUse)
		{
			glUseProgram(GL_FALSE);
			mInUse = false;
		}

		return *this;
	}

	bool Program::isLinked()
	{
		GLint linked = GL_FALSE;
		glGetProgramiv(mHandle, GL_LINK_STATUS, &linked);

		return (linked == GL_TRUE);
	}

	GLint Program::getAttribLocation(const std::string &attribName)
	{
		return glGetAttribLocation(mHandle, attribName.c_str());
	}

	std::string Program::getInfoLog()
	{
		int logLength = 0;

		// Get the length of the log
		glGetProgramiv(mHandle, GL_INFO_LOG_LENGTH, &logLength);

		if (logLength > 0)
		{
			// Allocate a buffer and get the log
			int dummy;
			char *buffer = new char[logLength];
			glGetProgramInfoLog(mHandle, logLength, &dummy, buffer);

			std::string infoLog(buffer);
			delete[] buffer;

			return infoLog;
		}
		else
		{
			return std::string("");
		}

	}

	std::vector<std::string>& Program::getShaderInfoLogs(std::vector<std::string> &shaderLogs)
	{
		// Get shader logs
		for (auto shader : mShaders)
		{
			shaderLogs.push_back(shader->getInfoLog());
		}

		return shaderLogs;
	}

	Program& Program::SetUniform1f(const std::string &name, float v1)
	{
		GLint loc = glGetUniformLocation(mHandle, name.c_str());

		if (loc == -1)
		{
			writeUniformError(name, __FILE__, __LINE__);
			return *this;
		}

		glUniform1f(loc, v1);
	}

	Program& Program::SetUniform2f(const std::string &name, float v1, float v2)
	{
		GLint loc = glGetUniformLocation(mHandle, name.c_str());

		if (loc == -1)
		{
			writeUniformError(name, __FILE__, __LINE__);
			return *this;
		}

		glUniform2f(loc, v1, v2);
	}

	Program& Program::SetUniform3f(const std::string &name, float v1, float v2, float v3)
	{
		GLint loc = glGetUniformLocation(mHandle, name.c_str());

		if (loc == -1)
		{
			writeUniformError(name, __FILE__, __LINE__);
			return *this;
		}

		glUniform3f(loc, v1, v2, v3);
	}

	Program& Program::SetUniform4f(const std::string &name, float v1, float v2, float v3, float v4)
	{
		GLint loc = glGetUniformLocation(mHandle, name.c_str());

		if (loc == -1)
		{
			writeUniformError(name, __FILE__, __LINE__);
			return *this;
		}

		glUniform4f(loc, v1, v2, v3, v4);
	}

	Program& Program::SetUniform1fv(const std::string &name, int num, const glm::vec1 &v)
	{
		GLint loc = glGetUniformLocation(mHandle, name.c_str());

		if (loc == -1)
		{
			writeUniformError(name, __FILE__, __LINE__);
			return *this;
		}

		// glm::value_ptr extension doesn't play nicely with glm::vec1 extension
		float temp = v.x;
		glUniform1fv(loc, num, &temp);
	}

	Program& Program::SetUniform2fv(const std::string &name, int num, const glm::vec2 &v)
	{
		GLint loc = glGetUniformLocation(mHandle, name.c_str());

		if (loc == -1)
		{
			writeUniformError(name, __FILE__, __LINE__);
			return *this;
		}

		glUniform2fv(loc, num, glm::value_ptr(v));
	}

	Program& Program::SetUniform3fv(const std::string &name, int num, const glm::vec3 &v)
	{
		GLint loc = glGetUniformLocation(mHandle, name.c_str());

		if (loc == -1)
		{
			writeUniformError(name, __FILE__, __LINE__);
			return *this;
		}

		glUniform3fv(loc, num, glm::value_ptr(v));
	}

	Program& Program::SetUniform4fv(const std::string &name, int num, const glm::vec4 &v)
	{
		GLint loc = glGetUniformLocation(mHandle, name.c_str());

		if (loc == -1)
		{
			writeUniformError(name, __FILE__, __LINE__);
			return *this;
		}

		glUniform4fv(loc, num, glm::value_ptr(v));
	}

	Program& Program::SetUniform1i(const std::string &name, int v1)
	{
		GLint loc = glGetUniformLocation(mHandle, name.c_str());

		if (loc == -1)
		{
			writeUniformError(name, __FILE__, __LINE__);
			return *this;
		}

		glUniform1i(loc, v1);
	}

	Program& Program::SetUniform2i(const std::string &name, int v1, int v2)
	{
		GLint loc = glGetUniformLocation(mHandle, name.c_str());

		if (loc == -1)
		{
			writeUniformError(name, __FILE__, __LINE__);
			return *this;
		}

		glUniform2i(loc, v1, v2);
	}

	Program& Program::SetUniform3i(const std::string &name, int v1, int v2, int v3)
	{
		GLint loc = glGetUniformLocation(mHandle, name.c_str());

		if (loc == -1)
		{
			writeUniformError(name, __FILE__, __LINE__);
			return *this;
		}

		glUniform3i(loc, v1, v2, v3);
	}

	Program& Program::SetUniform4i(const std::string &name, int v1, int v2, int v3, int v4)
	{
		GLint loc = glGetUniformLocation(mHandle, name.c_str());

		if (loc == -1)
		{
			writeUniformError(name, __FILE__, __LINE__);
			return *this;
		}

		glUniform4i(loc, v1, v2, v3, v4);
	}

	Program& Program::SetUniformMatrix2fv(const std::string &name, int count, glm::mat2 &v,
		bool transpose)
	{
		GLint loc = glGetUniformLocation(mHandle, name.c_str());

		if (loc == -1)
		{
			writeUniformError(name, __FILE__, __LINE__);
			return *this;
		}

		glUniformMatrix2fv(loc, count, (transpose ? 1 : 0), glm::value_ptr(v));
	}

	Program& Program::SetUniformMatrix3fv(const std::string &name, int count, glm::mat3 &v,
		bool transpose)
	{
		GLint loc = glGetUniformLocation(mHandle, name.c_str());

		if (loc == -1)
		{
			writeUniformError(name, __FILE__, __LINE__);
			return *this;
		}

		glUniformMatrix3fv(loc, count, (transpose ? 1 : 0), glm::value_ptr(v));
	}

	Program& Program::SetUniformMatrix4fv(const std::string &name, int count, glm::mat4 &v,
		bool transpose)
	{
		GLint loc = glGetUniformLocation(mHandle, name.c_str());

		if (loc == -1)
		{
			writeUniformError(name, __FILE__, __LINE__);
			return *this;
		}

		glUniformMatrix4fv(loc, count, (transpose ? 1 : 0), glm::value_ptr(v));
	}

	void Program::writeUniformError(const std::string &name, const char *file, int line)
	{
		std::string errorMsg("ERROR: Faied to set uniform: ");
		errorMsg.append(name);
		Logger::log(GL_LOG_FILE, errorMsg, file, line);
	}
}