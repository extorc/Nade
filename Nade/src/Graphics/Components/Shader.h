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
	private:
		unsigned int program;
	};
}