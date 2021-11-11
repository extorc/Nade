#pragma once
#include "glad/glad.h"
#include "Nade.h"

namespace Nade {
	class Renderer {
	public:
		void Draw(GameObject gameObject) {
			RawModel model = gameObject.model;
			TextureLoader::Bind(gameObject.texture.texture);
			glDrawElements(GL_TRIANGLES, model.VertexCount, GL_UNSIGNED_INT, nullptr);
		}
	};
}