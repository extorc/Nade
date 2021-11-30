#include "Main.h"

void Sandbox::Init()
{
    Nade::Material material;
    light.SetPosition(20, 20, 20);
    light.SetColor(1, 1, 1);
    object.SetModel(Nade::OBJLoader::Load("../res/models/high_poly_suzanne.obj"));
    object.SetMaterial(material);
    object2.SetModel(Nade::OBJLoader::Load("../res/models/high_poly_suzanne.obj"));
    object2.SetMaterial(material);
    object.Scale(10, 1, 10);
    object2.Translate(0, 10, 0);
    camera.Translate(0.0, 5.0, 20.0);
    object2.Scale(1.5);
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