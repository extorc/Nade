#include "Application.h"

namespace Nade {

	Application::Application() {
		window = new Nade::Window(640, 360, "Nade Engine");

		std::string vSource = Nade::Shader::parseFile("../../res/shaders/Vertex.glsl");
		std::string fSource = Nade::Shader::parseFile("../../res/shaders/Fragment.glsl");

		shader = new Nade::Shader(vSource.c_str(), fSource.c_str());

		window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}

	void Application::OnEvent(Event& e)
	{
		if (e.GetEventType() == EventType::WindowClose) {
			OnWindowCloseEvent(e);
		}
		if (e.GetEventType() == EventType::WindowResize) {
			OnWindowResizeEvent(e);
		}
		if (e.GetEventType() == EventType::WindowMove) {
			OnWindowMoveEvent(e);
		}
		if (e.GetEventType() == EventType::KeyPress) {
			OnKeyPressedEvent(e);
		}
		if (e.GetEventType() == EventType::KeyRelease) {
			OnKeyReleasedEvent(e);
		}
		if (e.GetEventType() == EventType::MouseButtonPress) {
			OnMousePressedEvent(e);
		}
		if (e.GetEventType() == EventType::MouseButtonRelease) {
			OnMouseReleasedEvent(e);
		}
		if (e.GetEventType() == EventType::MouseScroll) {
			OnMouseScrollEvent(e);
		}
	}
	void Application::OnWindowCloseEvent(Event& e)
	{
		window->mRunningState = false;
		std::cout << e.GetEventName() << std::endl;
	}
	void Application::OnWindowResizeEvent(Event& e)
	{
		std::cout << e.ToString() << std::endl;
	}
	void Nade::Application::OnWindowMoveEvent(Event& e)
	{
		std::cout << e.ToString() << std::endl;
	}
	void Application::OnKeyPressedEvent(Event& e)
	{
		std::cout << e.ToString() << std::endl;
	}
	void Application::OnKeyReleasedEvent(Event& e)
	{
		std::cout << e.ToString() << std::endl;
	}
	void Application::OnMousePressedEvent(Event& e) 
	{
		std::cout << e.ToString() << std::endl;
	}
	void Application::OnMouseReleasedEvent(Event& e) 
	{
		std::cout << e.ToString() << std::endl;
	}
	void Application::OnMouseScrollEvent(Event& e)
	{
		std::cout << e.ToString() << std::endl;
	}
}