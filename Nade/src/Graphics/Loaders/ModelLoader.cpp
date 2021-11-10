#include "ModelLoader.h"

namespace Nade {
	RawModel ModelLoader::Load(float position[], unsigned int index[], int vsize, int isize) {
		unsigned int vao, vbo, ibo;

		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, vsize * sizeof(float), position, GL_STATIC_DRAW);

		glGenBuffers(1, &ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, isize * sizeof(unsigned int), index, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

		RawModel model = { vao, isize };
		return model;
	}
}