#pragma once

#include "Common.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm.hpp>

namespace Kiwi {

	enum class ShaderType {
		Fragment = GL_FRAGMENT_SHADER,
		Vertex = GL_VERTEX_SHADER,
		Compute = GL_COMPUTE_SHADER,
		Geometry = GL_GEOMETRY_SHADER
	};

	class Shader {

	private:
		uint32 Handle;
		const char* Source;

	public:
		static std::string FromFile(std::string filename) {
			std::string content;
			std::ifstream fileStream(filename, std::ios::in);

			if (!fileStream.is_open()) {
				throw std::runtime_error("Could not read shader file");
			}

			std::string line = "";
			while (!fileStream.eof()) {
				std::getline(fileStream, line);
				content.append(line + "\n");
			}

			fileStream.close();
			return content;
		}

		ShaderType Type;

		MProperty(uint32, Handle);
		void Compile();

		Shader(ShaderType type, const char* source);
		~Shader();
	};

	class ShaderProgram {
		uint32 Handle;

	public:
		void SetUniform(const std::string& name, const glm::vec4 v) const;
		void SetUniform(const std::string& name, const glm::vec3 v) const;
		void SetUniform(const std::string& name, const glm::vec2 v) const;
		void SetUniform(const std::string& name, float v) const;

		void Use() const;
		ShaderProgram(std::initializer_list<Shader> shaders);
	};
}