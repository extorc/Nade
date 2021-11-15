#pragma once
#include "Nade.h"

namespace Nade {
	class Application {
	public:
		Application() {
			window = new Nade::Window(640, 360, "Nade Engine");

			std::string vSource = Nade::Shader::parseFile("../../res/shaders/Vertex.glsl");
			std::string fSource = Nade::Shader::parseFile("../../res/shaders/Fragment.glsl");

			shader = new Nade::Shader(vSource.c_str(), fSource.c_str());
		}

		Nade::Window* window;
		Nade::Shader* shader;
		Nade::Renderer renderer;
		Nade::Camera camera;

		virtual void Init() = 0;
		virtual void Update() = 0;
	};
}