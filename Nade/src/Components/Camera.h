#pragma once
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

namespace Nade {
	class Camera {
	public:
		glm::mat4 projection = glm::perspective(45.0f, 16.0f / 9.0f, 0.1f, 100.0f);
		glm::mat4 view = glm::mat4(1.0f);
	};
}