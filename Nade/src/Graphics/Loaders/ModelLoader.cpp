#include "ModelLoader.h"

namespace Nade {
	RawModel ModelLoader::Load(float position[], unsigned int index[], float coords[], float normals[], int vsize, int isize, int csize, int nsize) {
		unsigned int vao, ibo;

		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		LoadAttribute(0, vsize, position, 3);
		LoadAttribute(1, csize, coords, 2);
		LoadAttribute(2, nsize, normals, 3);
		
		glGenBuffers(1, &ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, isize * sizeof(unsigned int), index, GL_STATIC_DRAW);

		RawModel model = { vao, isize };
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