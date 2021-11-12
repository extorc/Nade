#pragma once
#include "Application.h"

class Main : public Nade::Application {
public:
	Nade::GameObject object;

	void Init() override {
		object.SetModel(Nade::ModelLoader::Load(Cubeposition, Cubeindex, Cubecoords, 72, 36, 48));
		object.SetTexture(Nade::TextureLoader::Load("res/textures/Blackhole.jpg"));
	}

	void Update() override {
		if (glfwGetKey(window->GetWindow(), GLFW_KEY_S)) {
			camera.Translate(0, 0, 0.05);
		}else if (glfwGetKey(window->GetWindow(), GLFW_KEY_W)) {
			camera.Translate(0, 0, -0.05);
		}else if (glfwGetKey(window->GetWindow(), GLFW_KEY_A)) {
			camera.Translate(-0.05, 0, 0);
		}else if (glfwGetKey(window->GetWindow(), GLFW_KEY_D)) {
			camera.Translate(0.05, 0, 0);
		}
		object.Rotate(-0.5f,-1,0);
		renderer.Draw(object, shader);
	}
};