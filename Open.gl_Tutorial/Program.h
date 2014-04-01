/**
Wrapper for OpenGL shader program management
*/

#include "main.h"
#include "Shader.h"

#include <set>
#include <vector>

namespace Fal
{
	class Program
	{
	public:
		Program();

		// TODO: Copy constructor

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

		bool isLinked();

		GLint getAttribLocation(const std::string &name);

		// Info logs
		std::string getInfoLog();
		std::vector<std::string>& getShaderInfoLogs(std::vector<std::string> &shaderLogs);

		// Uniform setters
		Program& SetUniform1f(const std::string &name, float v1);
		Program& SetUniform2f(const std::string &name, float v1, float v2);
		Program& SetUniform3f(const std::string &name, float v1, float v2, float v3);
		Program& SetUniform4f(const std::string &name, float v1, float v2, float v3, float v4);

		Program& SetUniform1fv(const std::string &name, int num, const glm::vec1 &v);
		Program& SetUniform2fv(const std::string &name, int num, const glm::vec2 &v);
		Program& SetUniform3fv(const std::string &name, int num, const glm::vec3 &v);
		Program& SetUniform4fv(const std::string &name, int num, const glm::vec4 &v);

		Program& SetUniform1i(const std::string &name, int v1);
		Program& SetUniform2i(const std::string &name, int v1, int v2);
		Program& SetUniform3i(const std::string &name, int v1, int v2, int v3);
		Program& SetUniform4i(const std::string &name, int v1, int v2, int v3, int v4);

		Program& SetUniformMatrix2fv(const std::string &name, int count, glm::mat2 &v,
			bool transpose = false);
		Program& SetUniformMatrix3fv(const std::string &name, int count, glm::mat3 &v,
			bool transpose = false);
		Program& SetUniformMatrix4fv(const std::string &name, int count, glm::mat4 &v,
			bool transpose = false);

	private:
		GLuint mHandle;
		std::set<Shader *> mShaders;
		bool mInUse;

		void writeUniformError(const std::string &name, const char *file, const int line);
	protected:
	};
}