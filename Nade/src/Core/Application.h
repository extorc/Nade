#pragma once
#include "Nade.h"

namespace Nade {
	class Application {
	public:
		Application() {
			window = new Nade::Window(640, 360, "Nade Engine");

			std::string vSource = Nade::Shader::parseFile("C:/dev/Nade/Nade/res/shaders/Vertex.glsl");
			std::string fSource = Nade::Shader::parseFile("C:/dev/Nade/Nade/res/shaders/Fragment.glsl");

			shader = new Nade::Shader(vSource.c_str(), fSource.c_str());
		}

		Nade::Window* window;
		Nade::Shader* shader;
		Nade::Renderer renderer;

		glm::mat4 projection = glm::ortho(-1.0, 1.0, -9.0/16.0, 9.0/16.0, -10.0, 10.0);

		virtual void Init() = 0;
		virtual void Update() = 0;
	};
}