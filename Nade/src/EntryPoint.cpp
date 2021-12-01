#include "pch.h"
#include "Nade.h"
#include "Main.h"

int main() {
	Sandbox app;

	app.Init();

	while (app.window->mRunningState) {
		app.window->Update();
		app.world.Bind(app.shader->GetProgram());
		app.Update();
		app.camera.Bind(app.shader->GetProgram());
		app.window->Render();
	}

	return 0;
}