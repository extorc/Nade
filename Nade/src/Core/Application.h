#pragma once
#include "Nade.h"

namespace Nade {
	class Application {
	public:
		Application();

		Nade::Window* window;
		Nade::Shader* shader;
		Nade::Renderer renderer;
		Nade::Camera camera;

		virtual void Init() = 0;
		virtual void Update() = 0;

		void OnEvent(Event& e);
		void OnWindowCloseEvent(Event& e);
		void OnWindowResizeEvent(Event& e);
		void OnWindowMoveEvent(Event& e);
	};
}