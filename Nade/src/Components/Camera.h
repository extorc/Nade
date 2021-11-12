#pragma once
#include "Nade.h"

namespace Nade {
	class Camera {
	public:
		glm::mat4 projection = glm::perspective(45.0f, 16.0f / 9.0f, 0.1f, 100.0f);
		glm::mat4 view = glm::mat4(1.0f);

		void Translate(double x, double y, double z) {
			view = glm::translate(view, glm::vec3(-(float)x,-(float)y,-(float)z));
		}
	};
}