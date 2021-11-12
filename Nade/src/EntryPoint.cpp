#include <iostream>
#include "Nade.h"
#include "Core/Main.h"

int main() {
	Main app;

	app.Init();

	

	while (!app.window->ShouldClose()) {
		app.window->Update();
		app.Update();

		if (glfwGetKey(app.window->GetWindow(), GLFW_KEY_S)) {
			app.camera.Translate(0, 0, 0.05);
		}
		else if (glfwGetKey(app.window->GetWindow(), GLFW_KEY_W)) {
			app.camera.Translate(0, 0, -0.05);
		}
		else if (glfwGetKey(app.window->GetWindow(), GLFW_KEY_A)) {
			app.camera.Translate(-0.05, 0, 0);
		}
		else if (glfwGetKey(app.window->GetWindow(), GLFW_KEY_D)) {
			app.camera.Translate(0.05, 0, 0);
		}

		Nade::Shader::SetMat4(app.shader->GetProgram(), "p", app.camera.projection);
		Nade::Shader::SetMat4(app.shader->GetProgram(), "v", app.camera.view);
		app.window->Render();
	}

	return 0;
}
	
