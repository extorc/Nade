#pragma once
#include <string>

namespace Nade {
	class Texture{
	private:
		unsigned int texture;
		std::string filePath;
		unsigned char* localBuffer;
		int width, height, BBP;
	public:
		Texture();
		void Bind(unsigned int slot = 0);
		void Unbind();
		int getWidth() { return width; }
		int getHeight() { return height; }
		void CreateTexture(const std::string& filePath);
	};
}