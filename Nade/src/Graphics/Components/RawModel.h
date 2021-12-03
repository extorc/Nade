#pragma once
#include "ModelData.h"

namespace Nade {
	struct RawModel {
		unsigned int ID;
		int VertexCount;
		ModelData data;
	};
}