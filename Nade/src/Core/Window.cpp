#include "Window.h"

namespace Nade {
	Window::Window(int width, int height, const char* title) {
		int success = glfwInit();
		if (!success)
		{
			std::cout << ND_WINDOW_NOT_INITIALIZED << std::endl;
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
		glfwSetWindowSizeCallback(mWindow, [](GLFWwindow* window, int width, int height) {
			WindowResizeEvent e(width, height);
			WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.width = width;
			data.height = height;
			data.callback(e);
		});
		glfwSetWindowPosCallback(mWindow, [](GLFWwindow* window, int xpos, int ypos) {
			WindowMoveEvent e(xpos, ypos);
			WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.callback(e);
		});
		glfwSetKeyCallback(mWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			switch (action) {
			case GLFW_PRESS: {
				KeyPressEvent e(key, 0);
				WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.callback(e);
				break;
			}
			case GLFW_REPEAT: {
				KeyPressEvent e(key, 1);
				WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.callback(e);
				break;
			}
			case(GLFW_RELEASE): {
				KeyReleaseEvent e(key);
				WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.callback(e);
				break;
			}
			}
		});
		glfwSetMouseButtonCallback(mWindow, [](GLFWwindow* window, int button, int action, int mods) {
			switch (action) {
			case GLFW_PRESS: {
				MouseButtonPressEvent e(button);
				WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.callback(e);
				break;
			}
			case GLFW_RELEASE: {
				MouseButtonReleaseEvent e(button);
				WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.callback(e);
				break;
			}
			}
		});
		glfwSetScrollCallback(mWindow, [](GLFWwindow* window, double xoffset, double yoffset) {
			MouseScrollEvent e(xoffset, yoffset);
			WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.callback(e);
		});
		glfwSetCursorPosCallback(mWindow, [](GLFWwindow* window, double xpos, double ypos) {
			MouseMoveEvent e(xpos, ypos);
			WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.callback(e);
		});
	}

	void Window::Update() {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.1f,0.1f,0.1f,1.0f);
		glfwPollEvents();
	}

	void Window::Render() {
		glfwSwapBuffers(mWindow);
	}
}