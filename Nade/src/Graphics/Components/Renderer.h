#pragma once
#include "glad/glad.h"
#include "Components/GameObject.h"
#include "Graphics/Components/Shader.h"
#include "Graphics/Components/RawModel.h"
#include "Graphics/Loaders/TextureLoader.h"

namespace Nade {
	class Renderer {
	public:
		void Draw(GameObject object, Shader* shader) {
			RawModel model = object.GetData().model;
			TextureLoader::Bind(object.GetData().texture.texture);
			Nade::Shader::SetMat4(shader->GetProgram(), "m", object.transform);
			Nade::Shader::Set1i(shader->GetProgram(), "Texture", 0);
			glDrawElements(GL_TRIANGLES, model.VertexCount, GL_UNSIGNED_INT, nullptr);
		}
	};
}