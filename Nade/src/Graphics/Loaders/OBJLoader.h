#pragma once
#include "Nade.h"

namespace Nade {
	class OBJLoader {
	public:
		static RawModel Load(const char* file);
	};
}