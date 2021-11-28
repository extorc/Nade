#include "pch.h"
#include "Nade.h"
#include "Main.h"

int main() {
	Sandbox app;

	app.Init();

	while (app.window->mRunningState) {
		app.window->Update();

		Nade::Shader::Set1f(app.shader->GetProgram(), "ambient", 0.1);

		app.Update();

		Nade::Shader::SetMat4(app.shader->GetProgram(), "p", app.camera.projection);
		Nade::Shader::SetMat4(app.shader->GetProgram(), "v", app.camera.view);
		app.window->Render();
	}

	return 0;
}
	
