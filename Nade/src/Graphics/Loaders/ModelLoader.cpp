#include "ModelLoader.h"

namespace Nade {
	RawModel ModelLoader::Load(ModelData data) {
		unsigned int vao, ibo;

		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		LoadAttribute(0, data.Vsize, data.mPosition.data(), 3);
		LoadAttribute(1, data.Csize, data.mCoords.data(), 2);
		LoadAttribute(2, data.Nsize, data.mNormals.data(), 3);
		
		glGenBuffers(1, &ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.Isize * sizeof(unsigned int), data.mIndex.data(), GL_STATIC_DRAW);

		RawModel model = { vao, data.Isize , data};
		return model;
	}
	void ModelLoader::LoadAttribute(int index, int size, void* data, int layout) {
		unsigned int id;
		glGenBuffers(1, &id);
		glBindBuffer(GL_ARRAY_BUFFER, id);
		glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), data, GL_STATIC_DRAW);

		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, layout, GL_FLOAT, GL_FALSE, layout * sizeof(float), 0);
	}
}
