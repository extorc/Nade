#pragma once
#include "Application.h"

class Main : public Nade::Application {
public:
	Nade::GameObject object;

	void Init() override {
		object.SetModel(Nade::OBJLoader::Load("res/models/test.obj"));
		object.SetTexture(Nade::TextureLoader::Load("res/textures/Blackhole.jpg"));
	}

	void Update() override {
		Nade::Shader::Set1f(shader->GetProgram(), "ambient", 0.1);
		object.Rotate(-0.5f,-1,0);
		renderer.Draw(object, shader);
	}
};