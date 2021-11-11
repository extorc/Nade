#pragma once
#include "glad/glad.h"
#include "Components/GameObject.h"
#include "Graphics/Components/RawModel.h"

namespace Nade {
	class Renderer {
	public:
		void Draw(GameObject object) {
			RawModel model = object.GetData().model;
			TextureLoader::Bind(object.GetData().texture);
			glDrawElements(GL_TRIANGLES, model.VertexCount, GL_UNSIGNED_INT, nullptr);
		}
	};
}