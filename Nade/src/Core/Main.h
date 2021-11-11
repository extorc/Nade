#pragma once
#include "Application.h"

class Main : public Nade::Application {
public:
	ND_GLOBAL_CREATE(Nade::RawModel) model;

	Nade::GameObject player{};

	void Init() override {
		model = Nade::ModelLoader::Load(Quadposition, Quadindex, Quadcoords, 12, 6, 8);
		Nade::Texture texture;
		texture.texture = Nade::TextureLoader::Load("C:/dev/Nade/Nade/res/textures/Blackhole.jpg");
		player = { model.value(), texture };
	}

	void Update() override {
		Nade::Shader::Set1i(shader->GetProgram(), "Texture", 0);
		renderer.Draw(player);
	}
};