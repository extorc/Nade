#pragma once
#include "Nade.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

namespace Nade {
	struct ObjectData {
		RawModel model;
		unsigned int texture;
	};

	class GameObject {
	public:
		GameObject() {

		}
		GameObject(RawModel model, unsigned int texture) {
			mData = { model, texture };
		}
		ObjectData GetData() const { return mData; }

		void SetModel(RawModel model) {
			mData.model = model;
		}
		void SetTexture(unsigned int texture) {
			mData.texture = texture;
		}
		void Translate(double x, double y, double z) {
			transform = glm::translate(transform, glm::vec3((float)x, (float)y, (float)z));
		}
		void Rotate(double x, double y, double z) {
			transform = glm::rotate(transform, glm::radians((float)x), glm::vec3(1, 0, 0));
			transform = glm::rotate(transform, glm::radians((float)y), glm::vec3(0, 1, 0));
			transform = glm::rotate(transform, glm::radians((float)z), glm::vec3(0, 0, 1));
		}
		glm::mat4 transform = glm::mat4(1.0f);
	private:
		ObjectData mData;
	};
}