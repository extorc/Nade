#pragma once
#include "pch.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Event.h"

#define ND_GLFW_NOT_INITIALIZED "Failed to initialize GLFW"
#define ND_WINDOW_NOT_CREATED_ERROR "Failed to create a Window"
#define ND_OPENGL_NOT_INITIALIZED "Failed to initialize Glad"

namespace Nade {
	class Window {
	public:
		Window(int width, int height, const char* title);

		void Update();
		void Render();
		GLFWwindow* GetWindow() const { return mWindow; }

		using EventCallback = std::function<void(Event&)>;
		void SetEventCallback(const EventCallback callback) { mData.callback = callback; }

		bool mRunningState = true;
	private:
		struct WindowData {
			int width;
			int height;
			const char* title;
			EventCallback callback;
		};
		WindowData mData;
		GLFWwindow* mWindow;
	};
}