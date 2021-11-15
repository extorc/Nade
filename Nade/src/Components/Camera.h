#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Nade {
	class Camera {
	public:
		glm::mat4 projection = glm::perspective(45.0f, 16.0f / 9.0f, 0.1f, 100.0f);
		glm::mat4 view = glm::mat4(1.0f);

		void Translate(double x, double y, double z) {
			view = glm::translate(view, glm::vec3(-(float)x,-(float)y,-(float)z));
		}
		void Rotate(double x, double y, double z) {
			view = glm::rotate(view, glm::radians((float)x), glm::vec3(1, 0, 0));
			view = glm::rotate(view, glm::radians((float)y), glm::vec3(0, 1, 0));
			view = glm::rotate(view, glm::radians((float)z), glm::vec3(0, 0, 1));
		}
	};
}