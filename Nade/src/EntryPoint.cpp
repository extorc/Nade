#include "pch.h"
#include "Nade.h"
#include "Application.h"

extern Nade::Application* CreateApplication();

int main() {
	Nade::Application *app = CreateApplication();

	app->Init();

	while (app->window->mRunningState) {
		app->window->Update();
		app->world.Bind(app->shader->GetProgram());
		app->Update();
		app->camera.Bind(app->shader->GetProgram());
		app->window->Render();
	}

	return 0;
}