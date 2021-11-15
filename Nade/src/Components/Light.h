#pragma once
#include "glm.hpp"
#include "Graphics/Components/Shader.h"

namespace Nade {
	class Light {
	public:
		Light(){}
		Light(glm::vec3 position, glm::vec3 color):position(position), color(color){}

		void SetPosition(float x, float y, float z) {
			position = glm::vec3(x, y, z);
		}
		void SetColor(float r, float g, float b) {
			color = glm::vec3(r, g, b);
		}
		void Bind(unsigned int program) {
			Nade::Shader::SetVec3(program, "light_color", color);
			Nade::Shader::SetVec3(program, "light_position", position);
		}
		glm::vec3 position;
		glm::vec3 color;
	};
}