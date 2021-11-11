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
		Nade::Shader::Set1i(shader->GetProgram(), "Texture", 0);
		renderer.Draw(object);
	}
};