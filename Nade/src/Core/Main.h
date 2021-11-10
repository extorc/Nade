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
		renderer.Draw(model.value());
	}
};