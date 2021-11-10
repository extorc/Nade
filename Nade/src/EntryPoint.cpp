#include <iostream>
#include "Nade.h"

int main() {
	Nade::Window window(500, 500, "Nade Engine");

	while (!window.ShouldClose()) {
		window.Render();
		window.Update();
	}

	return 0;
}
	
