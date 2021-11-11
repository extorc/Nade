#pragma once
#include "Application.h"

class Main : public Nade::Application {
public:
	float position[12] = {
		0.5,0.5,0,
		-0.5,0.5,0,
		-0.5,-0.5,0,
		0.5,0-.5,0
	};

	unsigned int index[6] = {
		0,1,2,0,2,3
	};

	float coords[8] = {
		1,1,0,1,0,0,1,0
	};
	std::optional<Nade::RawModel> model;
	
	Nade::Texture texture;

	void Init() override {
		model = Nade::ModelLoader::Load(position, index, coords, 12, 6, 8);
		texture.CreateTexture("C:/dev/Nade/Nade/res/textures/Blackhole.jpg");
		texture.Bind();
	}

	void Update() override {
		Nade::Shader::Set1i(shader->GetProgram(), "Texture", 0);
		renderer.Draw(model.value());
	}
};