#pragma once
#include "Application.h"

class Main : public Nade::Application {
public:
	float position[9] = {
		1,1,0,0,1,0,0,0,0
	};

	unsigned int index[6] = {
		0,1,2,0,2,3
	};

	std::optional<Nade::RawModel> model;

	void Init() override {
		model = Nade::ModelLoader::Load(position, index, 9, 6);
	}

	void Update() override {
		Nade::Shader::Set4F(shader->GetProgram(), "color", 1, 1, 0, 1);
		Nade::Shader::Set1i(shader->GetProgram(), "mat_from", 0);
		renderer.Draw(model.value());
	}
};