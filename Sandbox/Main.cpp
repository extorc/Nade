#include "Main.h"

void Sandbox::Init() {
	light.SetPosition(20,20,20);
	light.SetColor(1, 1, 1);
	object.SetModel(Nade::OBJLoader::Load("../../res/models/dragon.obj"));
	object.SetTexture(Nade::TextureLoader::Load("../../res/textures/white.png"));
	object.Translate(0, -5, 0);
	object.SetReflective(1.0f);
	object.SetSpecular(5.0f);
}

void Sandbox::Update() {
	light.Bind(shader->GetProgram());
	renderer.Draw(object, shader);
}