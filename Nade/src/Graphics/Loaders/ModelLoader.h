#pragma once
#include "RawModel.h"
#include "glad/glad.h"

namespace Nade {
	class ModelLoader {
	public:
		static RawModel Load(float position[], unsigned int index[], float coords[], float normals[], int vsize, int isize, int csize, int nsize);
		static void LoadAttribute(int index, int size, void* data, int layout);
	};
}