#pragma once
#include "Window.h"

namespace Nade {
	class Input {
	public:
		static bool IsKeyPressed(Window* window, unsigned int keyCode) {
			return glfwGetKey(window->GetWindow(), keyCode);
		}
	};
}