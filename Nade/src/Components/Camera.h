#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Input.h"
#include "Window.h"

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
		void UseDebugViewportMovement(Window* window) {
			if (Input::IsKeyPressed(window, GLFW_KEY_S)) {
				Translate(0, 0, 0.1);
			}
			else if (Input::IsKeyPressed(window, GLFW_KEY_W)) {
				Translate(0, 0, -0.1);
			}
			else if (Input::IsKeyPressed(window, GLFW_KEY_A)) {
				Translate(-0.1, 0, 0);
			}
			else if (Input::IsKeyPressed(window, GLFW_KEY_D)) {
				Translate(0.1, 0, 0);
			}
			else if (Input::IsKeyPressed(window, GLFW_KEY_UP)) {
				Rotate(1, 0, 0);
			}
			else if (Input::IsKeyPressed(window, GLFW_KEY_DOWN)) {
				Rotate(0, 1, 0);
			}
		}
	};
}