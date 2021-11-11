#pragma once
#include "Application.h"

class Main : public Nade::Application {
public:
	Nade::GameObject object;

	void Init() override {
		object.SetModel(Nade::ModelLoader::Load(Quadposition, Quadindex, Quadcoords, 12, 6, 8));
		object.SetTexture(Nade::TextureLoader::Load("res/textures/Blackhole.jpg"));
	}

	void Update() override {
		//object.Translate(0, 0, -0.01);
		object.Rotate(-0.5f,-1,0);
		camera.view = glm::translate(camera.view, glm::vec3(0, 0, -0.05));
		renderer.Draw(object, shader);
	}
};