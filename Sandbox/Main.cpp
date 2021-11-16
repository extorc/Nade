#include "Main.h"

void Sandbox::Init() {
	light.SetPosition(20,20,20);
	light.SetColor(1, 1, 1);
	material.SetTexture(Nade::TextureLoader::Load("../../res/textures/white.png"));
	object.SetModel(Nade::OBJLoader::Load("../../res/models/dragon.obj"));
	object.SetMaterial(material);
	object.Translate(0, -5, 0);
	material.SetReflective(1.0f);
	material.SetSpecular(5.0f);
}

void Sandbox::Update() {
	light.Bind(shader->GetProgram());
	renderer.Draw(object, shader);
}