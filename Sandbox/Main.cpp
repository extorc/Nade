#include "Main.h"

void Sandbox::Init()
{
    Nade::Material material;
    light.SetPosition(20, 20, 20);
    light.SetColor(1, 1, 1);
    material.SetColor(glm::vec3(.6,.6,.6));
    object.SetModel(Nade::OBJLoader::Load("../../res/models/t1.obj"));
    object2.SetModel(Nade::OBJLoader::Load("../../res/models/t2.obj"));
    object.SetMaterial(material);
    object2.SetMaterial(material);
    object2.Translate(0,1,0);
    camera.Translate(0,0,15);
    Nade::TraingleIntersectionDetector::Detect(object, object2);
}

void Sandbox::Update()
{
    light.Bind(shader->GetProgram());
    camera.UseDebugViewportMovement(window);
    if (Nade::Input::IsKeyPressed(window, GLFW_KEY_SPACE)) {
        Nade::PhysicsObject::SetPhysicsObject(object2);
    }
    renderer.Draw(object, shader);
    renderer.Draw(object2, shader);
}

Nade::Application* CreateApplication(){
	return new Sandbox();
}