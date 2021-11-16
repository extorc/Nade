#pragma once
#include "RawModel.h"

namespace Nade {
	class OBJLoader {
	public:
		static RawModel Load(const char* file);
	};
}