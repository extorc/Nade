#pragma once
#include "Application.h"

class Sandbox : public Nade::Application {
public:
	Nade::GameObject object;
	Nade::GameObject object2;
	Nade::Light light;
	void Init() override;
	void Update() override;
};