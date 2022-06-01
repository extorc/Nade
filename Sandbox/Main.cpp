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

Nade::Application* CreateApplication(){
	return new Sandbox();
}