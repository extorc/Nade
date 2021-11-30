#pragma once
#include "RawModel.h"
#include "Material.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "glm/gtc/matrix_access.hpp"

namespace Nade {
	struct ObjectData {
		RawModel model;
		Material material;
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
		void SetMaterial(Material material) {
			mData.material = material;
		}
		void Translate(double x, double y, double z) {
			transform = glm::translate(transform, glm::vec3((float)x, (float)y, (float)z));
		}
		void Rotate(double x, double y, double z) {
			transform = glm::rotate(transform, glm::radians((float)x), glm::vec3(1, 0, 0));
			transform = glm::rotate(transform, glm::radians((float)y), glm::vec3(0, 1, 0));
			transform = glm::rotate(transform, glm::radians((float)z), glm::vec3(0, 0, 1));
		}
		void Scale(double factor) {
			transform = glm::scale(transform, glm::vec3(factor, factor, factor));
		}
		void Scale(double x, double y,double z) {
			transform = glm::scale(transform, glm::vec3(x, y, z));
		}
		glm::vec3 GetPosition() {
			return glm::vec3(glm::row(transform,0)[3], glm::row(transform, 1)[3], glm::row(transform, 2)[3]);
		}

		glm::vec3  GetScale() {
			glm::vec4 row = glm::row(transform, 0);
			glm::vec4 row1 = glm::row(transform, 1);
			glm::vec4 row2 = glm::row(transform, 2);
			return glm::vec3(row[0], row1[1], row2[2]);
		}
		float  GetScaleFactor() {
			glm::vec4 row = glm::row(transform, 0);
			glm::vec4 row1 = glm::row(transform, 1);
			glm::vec4 row2 = glm::row(transform, 2);
			return sqrt(row[0] * row[0] + row[1] * row[1] + row[2] * row[2]);
		}
		glm::mat4 transform = glm::mat4(1.0f);

		bool is_physics_object = false;
		float velocity = 0;
	private:
		ObjectData mData;
	};
}