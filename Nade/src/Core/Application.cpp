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
	}
	void Application::OnWindowCloseEvent(Event& e)
	{
		window->mRunningState = false;
		std::cout << e.GetEventName() << std::endl;
	}
}