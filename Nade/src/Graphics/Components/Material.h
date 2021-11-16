#pragma once
#include "Texture.h"

namespace Nade {
	class Material {
	public:
		void SetTexture(Texture pTexture) {
			texture = pTexture;
		}
		void SetSpecular(float pSpecular) {
			specular = pSpecular;
		}
		void SetReflective(float pReflective) {
			reflective = pReflective;
		}
		Texture texture;
		float reflective, specular;
	};
}