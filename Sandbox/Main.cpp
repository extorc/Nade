#include "Main.h"

void Sandbox::Init() {
	light.SetPosition(20,20,20);
	light.SetColor(1, 1, 1);
	object.SetModel(Nade::OBJLoader::Load("C:/dev/Nade/res/models/dragon.obj"));
	object.SetMaterial(material);
	object.Translate(0, -5, 0);
	camera.Translate(0.0, 0.0, 5.0);
}

void Sandbox::Update() {
	light.Bind(shader->GetProgram());
	renderer.Draw(object, shader);
}