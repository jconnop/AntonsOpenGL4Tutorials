/**
Wrapper for OpenGL shader program management
*/

#include "main.h"
#include "Shader.h"

namespace Fal
{
	class Program
	{
	public:
		~Program();

		// Returns reference to self for call chaining
		Program& attachShader(Shader *shader);
		Program& attachShader(Shader &shader);
		Program& detachShader(Shader *shader);
		Program& detachShader(Shader &shader);
		Program& addShaderFromSource(const std::string &source, GLenum type);
		Program& link();
		Program& startUsing();
		Program& stopUsing();

		bool isGood();

		Program& bindAttribLocation(const std::string &name, int index);
		Program& getAttribLocation(const std::string &name);


		// Uniform setters
		bool SetUniform1f(const std::string &name, float v1);
		bool SetUniform2f(const std::string &name, float v1, float v2);
		bool SetUniform3f(const std::string &name, float v1, float v2, float v3);
		bool SetUniform4f(const std::string &name, float v1, float v2, float v3, float v4);

		bool SetUniform1fv(const std::string &name, int num, const float *v);
		bool SetUniform2fv(const std::string &name, int num, const float *v);
		bool SetUniform3fv(const std::string &name, int num, const float *v);
		bool SetUniform4fv(const std::string &name, int num, const float *v);

		bool SetUniform1i(const std::string &name, int v1);
		bool SetUniform2i(const std::string &name, int v1, int v2);
		bool SetUniform3i(const std::string &name, int v1, int v2, int v3);
		bool SetUniform4i(const std::string &name, int v1, int v2, int v3, int v4);

		bool SetUniformMatrix2fv(const std::string &name, int count, float *v,
			bool transpose = false);
		bool SetUniformMatrix3fv(const std::string &name, int count, float *v,
			bool transpose = false);
		bool SetUniformMatrix4fv(const std::string &name, int count, float *v,
			bool transpose = false);

	private:
	protected:
	};
}