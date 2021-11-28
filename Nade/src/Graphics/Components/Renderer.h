#pragma once
#include "glad/glad.h"
#include "GameObject.h"
#include "Shader.h"
#include "RawModel.h"
#include "TextureLoader.h"

namespace Nade {
	class Renderer {
	public:
		void Draw(GameObject& object, Shader* shader) {
			if (object.is_physics_object) {
				object.velocity += ND_PHYSICS_GRAVITATIONAL_ACCELERATION;
			}
			object.Translate(0, object.velocity, 0);
			RawModel model = object.GetData().model;
			TextureLoader::Bind(object.GetData().material.texture);
			Shader::SetMat4(shader->GetProgram(), "m", object.transform);
			object.GetData().material.Bind(shader->GetProgram());
			glDrawElements(GL_TRIANGLES, model.VertexCount, GL_UNSIGNED_INT, nullptr);
		}
	};
}