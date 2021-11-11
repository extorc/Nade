#pragma once
#include "Nade.h"

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
	private:
		ObjectData mData;
	};
}