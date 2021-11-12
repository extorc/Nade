#include "OBJLoader.h"
#include "Nade.h"

namespace Nade {
	RawModel OBJLoader::Load(const char* file) {
		Assimp::Importer importer;

		const aiScene* mModel = importer.ReadFile(file, aiProcess_Triangulate | aiProcess_JoinIdenticalVertices);
		const aiMesh* mMesh = mModel->mMeshes[0];
		int vertNum = mMesh->mNumVertices;

		std::vector<float> vertices;
		std::vector<float> textureCoords;
		std::vector<unsigned int> indices;

		for (int i = 0; i < mMesh->mNumVertices; i++) {
			vertices.push_back(mMesh->mVertices[i].x);
			vertices.push_back(mMesh->mVertices[i].y);
			vertices.push_back(mMesh->mVertices[i].z);
			textureCoords.push_back(mMesh->mTextureCoords[0][i].x);
			textureCoords.push_back(mMesh->mTextureCoords[0][i].y);
		}

		for (unsigned int i = 0; i < mMesh->mNumFaces; i++) {
			const aiFace& mFace = mMesh->mFaces[i];
			indices.push_back(mFace.mIndices[0]);
			indices.push_back(mFace.mIndices[1]);
			indices.push_back(mFace.mIndices[2]);
		}

		float* position = &vertices[0];
		float* coords = &textureCoords[0];
		unsigned int* index = &indices[0];

		return ModelLoader::Load(position, index, coords, vertices.size(), indices.size(), textureCoords.size());
	}
}