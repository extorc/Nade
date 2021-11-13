#pragma once
#include "Application.h"

class Main : public Nade::Application {
public:
	Nade::GameObject object;
	Nade::Light light;

	void Init() override {
		light.SetPosition(20,20,20);
		light.SetColor(1, 1, 0);
		object.SetModel(Nade::OBJLoader::Load("res/models/dragon.obj"));
		object.SetTexture(Nade::TextureLoader::Load("res/textures/white.png"));
		object.Translate(0, -1, 0);
	}

	void Update() override {
		light.Bind(shader->GetProgram());
		renderer.Draw(object, shader);
	}
};