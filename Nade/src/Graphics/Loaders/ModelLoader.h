#pragma once
#include "RawModel.h"
#include "glad/glad.h"
#include "ModelData.h"

namespace Nade {
	class ModelLoader {
	public:
		static RawModel Load(ModelData data);
		static void LoadAttribute(int index, int size, void* data, int layout);
	};
}