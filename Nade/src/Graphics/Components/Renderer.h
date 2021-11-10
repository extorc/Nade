#pragma once
#include "glad/glad.h"
#include "RawModel.h"

namespace Nade {
	class Renderer {
	public:
		void Draw(RawModel model) {
			glDrawElements(GL_TRIANGLES, model.VertexCount, GL_UNSIGNED_INT, nullptr);
		}
	};
}