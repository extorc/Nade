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
			Shader::SetMat4(shader->GetProgram(), "m", object.transform);
			Shader::Set1i(shader->GetProgram(), "Texture", 0);
			Shader::Set1f(shader->GetProgram(), "reflective", object.GetData().texture.reflective);
			Shader::Set1f(shader->GetProgram(), "specular", object.GetData().texture.specular);
			glDrawElements(GL_TRIANGLES, model.VertexCount, GL_UNSIGNED_INT, nullptr);
		}
	};
}