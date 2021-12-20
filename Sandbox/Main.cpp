#include "Main.h"

void Sandbox::Init()
{
    Nade::Material material;
    light.SetPosition(20, 20, 20);
    light.SetColor(1, 1, 1);
    material.SetTexture(Nade::TextureLoader::Load("../../res/textures/crat.jpg"));
    object.SetModel(Nade::OBJLoader::Load("../../res/models/individual_face_cube.obj"));
    object.SetMaterial(material);
    object2.SetModel(Nade::OBJLoader::Load("../../res/models/Cube.obj"));
    object2.Scale(10,1,10);
    object2.Translate(0,-6,0);
    camera.Translate(0,0,15);
    for(int i = 0; i < object.GetData().model.data.Vsize; i++){
        std::cout<<object.GetData().model.data.mPosition.at(i)<<std::endl;
    }
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
