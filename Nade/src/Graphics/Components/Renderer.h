#pragma once
#include "glad/glad.h"
#include "GameObject.h"
#include "Shader.h"
#include "RawModel.h"
#include "TextureLoader.h"

namespace Nade {
	class Renderer {
	public:
		void Draw(GameObject object, Shader* shader) {
			RawModel model = object.GetData().model;
			TextureLoader::Bind(object.GetData().material.texture.texture);
			Shader::SetMat4(shader->GetProgram(), "m", object.transform);
			Shader::Set1i(shader->GetProgram(), "Texture", 0);
			Shader::Set1f(shader->GetProgram(), "reflective", object.GetData().material.reflective);
			Shader::Set1f(shader->GetProgram(), "specular", object.GetData().material.specular);
			glDrawElements(GL_TRIANGLES, model.VertexCount, GL_UNSIGNED_INT, nullptr);
		}
	};
}