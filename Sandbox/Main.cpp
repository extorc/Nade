#include "Main.h"

void Sandbox::Init() {
	Nade::Material material;
	light.SetPosition(20,20,20);
	light.SetColor(1, 1, 1);
	object.SetModel(Nade::OBJLoader::Load("C:/dev/Nade/res/models/dragon.obj"));
	object.SetMaterial(material);
	Nade::PhysicsObject::SetPhysicsObject(object);
	object.Translate(0, -5, 0);
	camera.Translate(0.0, 0.0, 15.0);
}

void Sandbox::Update() {
	light.Bind(shader->GetProgram());
	camera.UseDebugViewportMovement(window);
	renderer.Draw(object, shader);
}