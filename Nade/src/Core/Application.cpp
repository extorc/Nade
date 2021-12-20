#include "Application.h"

#define BIND_FUNC(x) std::bind(&Application::x, this, std::placeholders::_1)

namespace Nade {

Application::Application()
{
    window = new Nade::Window(640, 360, "Nade Engine");

    std::string vSource = Nade::Shader::parseFile("../../res/shaders/Vertex.glsl");
    std::string fSource = Nade::Shader::parseFile("../../res/shaders/Fragment.glsl");

    shader = new Nade::Shader(vSource.c_str(), fSource.c_str());

    window->SetEventCallback(BIND_FUNC(OnEvent));
}

void Application::OnEvent(Event& e)
{
    EventDispatcher dispatcher;
    dispatcher.Dispatch(e, BIND_FUNC(OnWindowCloseEvent),EventType::WindowClose);
    dispatcher.Dispatch(e, BIND_FUNC(OnWindowResizeEvent), EventType::WindowResize);
    dispatcher.Dispatch(e, BIND_FUNC(OnWindowMoveEvent), EventType::WindowMove);
    dispatcher.Dispatch(e, BIND_FUNC(OnKeyReleasedEvent), EventType::KeyRelease);
    dispatcher.Dispatch(e, BIND_FUNC(OnMouseMoveEvent), EventType::MouseMove);
    dispatcher.Dispatch(e, BIND_FUNC(OnMouseScrollEvent), EventType::MouseScroll);

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
void Application::OnMouseMoveEvent(Event& e)
{
    if (Input::IsMouseButtonPressed(window, GLFW_MOUSE_BUTTON_LEFT)) {
        double x, y;
        glfwGetCursorPos(window->GetWindow(), &x, &y);
        double xOffset = x - old_x;
        double yOffset = y - old_y;
        camera.Rotate(yOffset / 2, xOffset / 2, 0);
    }
    glfwGetCursorPos(window->GetWindow(), &old_x, &old_y);
}
}