#include "Shader.h"

namespace Kiwi {

	Shader::Shader(ShaderType type, const char* source) 
		: Source(source), Type(type) {
		Compile();
	}

	void Shader::Compile() {
		if (Type == ShaderType::Vertex) {
			Handle = glCreateShader(GL_VERTEX_SHADER);
		}
		else if (Type == ShaderType::Fragment) {
			Handle = glCreateShader(GL_FRAGMENT_SHADER);
		}

		glShaderSource(Handle, 1, &Source, nullptr);
		glCompileShader(Handle);

		int success;
		std::string log;
		glGetShaderiv(Handle, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(Handle, 512, nullptr, log.data());
			throw std::runtime_error("shader compilation error: " + log);
		}
	}

	Shader::~Shader() {
		glDeleteShader(Handle);
	}

	ShaderProgram::ShaderProgram(std::initializer_list<Shader> shaders) {

		int success;
		std::string log;
		Handle = glCreateProgram();

		for (auto& shader : shaders)
		{
			glAttachShader(Handle, shader.GetHandle());
		}

		glLinkProgram(Handle);

		glGetProgramiv(Handle, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(Handle, 512, nullptr, log.data());
			throw std::runtime_error("shader linking error: " + log);
		}


	}

	void ShaderProgram::Use() const {
		glUseProgram(Handle);
	}

	void ShaderProgram::SetUniform(const std::string& name, const glm::vec4 v) const {
		
		glUniform4f(
			glGetUniformLocation(Handle, name.data()),
			v.x, v.y, v.z, v.w);
	}

	void ShaderProgram::SetUniform(const std::string& name, const glm::vec3 v) const {

		glUniform3f(
			glGetUniformLocation(Handle, name.data()),
			v.x, v.y, v.z);
	}

	void ShaderProgram::SetUniform(const std::string& name, const glm::vec2 v) const {

		glUniform2f(
			glGetUniformLocation(Handle, name.data()),
			v.x, v.y);
	}

	void ShaderProgram::SetUniform(const std::string& name, float v) const {

		glUniform1f(
			glGetUniformLocation(Handle, name.data()),
			v);
	}
}