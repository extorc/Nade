#include "Window.h"

namespace Nade {
	Window::Window(int width, int height, const char* title) {
		int success = glfwInit();
		if (!success)
		{
			std::cout << ND_GLFW_NOT_INITIALIZED << std::endl;
		}

		mWindow = glfwCreateWindow(width, height, title, 0, 0);

		if (!mWindow) {
			std::cout << ND_WINDOW_NOT_CREATED_ERROR << std::endl;
		}

		glfwMakeContextCurrent(mWindow);
	}

	void Window::Update() {
		glfwPollEvents();
	}

	void Window::Render() {
		glfwSwapBuffers(mWindow);
	}

	bool Window::ShouldClose() {
		return glfwWindowShouldClose(mWindow);
	}
}