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

		mData.width = width;
		mData.height = height;
		mData.title = title;

		glfwMakeContextCurrent(mWindow);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cout << ND_OPENGL_NOT_INITIALIZED << std::endl;
		}

		glfwSwapInterval(2);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);

		glfwSetWindowUserPointer(mWindow, &mData);

		glfwSetWindowCloseCallback(mWindow, [](GLFWwindow* window) {
			WindowCloseEvent e;
			WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.callback(e);
		});
	}

	void Window::Update() {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.1,0.1,0.1,1.0);
		glfwPollEvents();
	}

	void Window::Render() {
		glfwSwapBuffers(mWindow);
	}
}