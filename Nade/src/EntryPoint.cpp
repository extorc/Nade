#include <iostream>
#include "Nade.h"
#include "Core/Main.h"

int main() {
	Main app;

	app.Init();

	while (!app.window->ShouldClose()) {
		app.window->Update();
		app.Update();
		Nade::Shader::SetMat4(app.shader->GetProgram(), "p", app.projection);
		app.window->Render();
	}

	return 0;
}
	
