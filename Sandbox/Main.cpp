#include "Main.h"

void Sandbox::Init()
{
    Nade::Material material;
    light.SetPosition(10, 10, 10);
    light.SetColor(1, 1, 1);
    material.SetColor(glm::vec3(.6,.6,.6));
    object.SetModel(Nade::OBJLoader::Load("C:/Users/mitta/dev/Nade/res/models/t1.obj"));
    object2.SetModel(Nade::OBJLoader::Load("C:/Users/mitta/dev/Nade/res/models/cube.obj"));
    object.SetMaterial(material);
    object2.SetMaterial(material);
    object2.Translate(1,5,0);
    camera.Translate(0,0,15);
}

void Sandbox::Update()
{
    light.Bind(shader->GetProgram());
    camera.UseDebugViewportMovement(window);
    if (Nade::Input::IsKeyPressed(window, GLFW_KEY_SPACE)) {
        Nade::PhysicsObject::SetPhysicsObject(object2, true);
    }
    renderer.Draw(object, shader);
    renderer.Draw(object2, shader);
    Nade::ObjectCollisionDetector::Detect(object, object2);
}

Nade::Application* CreateApplication(){
	return new Sandbox();
}