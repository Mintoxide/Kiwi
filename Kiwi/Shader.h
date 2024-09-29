#pragma once

#include "Common.h"
#include <fstream>
#include <sstream>
#include <iostream>

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
		void Activate();
		ShaderProgram(std::initializer_list<Shader> shaders);
	};
}