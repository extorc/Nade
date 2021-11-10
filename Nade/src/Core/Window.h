#pragma once
#include "GLFW/glfw3.h"
#include <iostream>

#define ND_GLFW_NOT_INITIALIZED "Failed to initialize GLFW"
#define ND_WINDOW_NOT_CREATED_ERROR "Failed to create a Window"

namespace Nade {
	class Window {
	public:
		Window(int width, int height, const char* title);

		void Update();
		void Render();
		bool ShouldClose();
	private:
		GLFWwindow* mWindow;
	};
}