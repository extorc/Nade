#pragma once
#include "glad/glad.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

namespace Nade {
	class Shader {
	public:
		Shader(const char* vSource, const char* fSource);
		unsigned int CreateShader(const char* source, unsigned int type);
		static std::string parseFile(std::string path);

		static void Set4F(unsigned int program, char* variable, float v0, float v1, float v2, float v3) {
			glUniform4f(glGetUniformLocation(program, variable), v0, v1, v2, v3);
		}
		static void Set1i(unsigned int program, char* variable, int v0) {
			glUniform1i(glGetUniformLocation(program, variable), v0);
		}
		unsigned int GetProgram() const { return program; }
	private:
		unsigned int program;
	};
}