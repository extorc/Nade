#pragma once

namespace Nade {
	class Material {
	public:
		void SetTexture(unsigned int pTexture) {
			texture = pTexture;
		}
		void SetSpecular(float pSpecular) {
			specular = pSpecular;
		}
		void SetReflective(float pReflective) {
			reflective = pReflective;
		}
		unsigned int texture;
		float reflective, specular;
	};
}