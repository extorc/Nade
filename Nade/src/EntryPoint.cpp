#include <iostream>
#include "Nade.h"

int main() {
	Nade::Window window(500, 500, "Nade Engine");

	float position[] = {
		1,1,0,0,1,0,0,0,0
	};

	unsigned int index[] = {
		0,1,2,0,2,3
	};

	Nade::RawModel model = Nade::ModelLoader::Load(position, index, 9, 6);

	while (!window.ShouldClose()) {


		window.Update();
		glDrawElements(GL_TRIANGLES, model.VertexCount, GL_UNSIGNED_INT, nullptr);
		window.Render();
	}

	return 0;
}
	
