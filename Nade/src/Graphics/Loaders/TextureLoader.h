#pragma once
#include "pch.h"

namespace Nade {
	class TextureLoader{
	private:
		unsigned int texture;
		std::string filePath;
		unsigned char* localBuffer;
		int width, height, BBP;
	public:
		static void Bind(unsigned int texture);
		static void Unbind();
		static unsigned int Load(const std::string& filePath);
	};
}
