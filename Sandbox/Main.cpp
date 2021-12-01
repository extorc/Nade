#include "Main.h"

void Sandbox::Init()
{
    Nade::Material material;
    light.SetPosition(20, 20, 20);
    light.SetColor(1, 1, 1);
    material.SetTexture(Nade::TextureLoader::Load("../../res/textures/crat.jpg"));
    object.SetModel(Nade::OBJLoader::Load("../../res/models/t1.obj"));
    object.SetMaterial(material);
    object2.SetModel(Nade::OBJLoader::Load("../../res/models/t2.obj"));
    object2.SetMaterial(material);
}

void Sandbox::Update()
{
    light.Bind(shader->GetProgram());
    camera.UseDebugViewportMovement(window);
    // if (Nade::Input::IsKeyPressed(window, GLFW_KEY_SPACE)) {
    //     Nade::PhysicsObject::SetPhysicsObject(object);
    // }
    renderer.Draw(object, shader);
    renderer.Draw(object2, shader);
}