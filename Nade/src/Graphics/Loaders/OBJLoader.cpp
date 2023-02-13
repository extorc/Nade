#include "OBJLoader.h"
#include "pch.h"

#include "fast_obj.h"

#include "ModelData.h"
#include "ModelLoader.h"

namespace Nade {
RawModel OBJLoader::Load(const char* file)
{
    fastObjMesh* mesh = fast_obj_read(file); 
    int vertNum = mesh->position_count-1; //Eliminating dummy entries from fast_obj
    int texnum = mesh->texcoord_count-1;
    int normnum = mesh->normal_count-1;

    std::vector<float> vertices;
    std::vector<float> textureCoords;
    std::vector<float> normals;
    std::vector<unsigned int> indices;

    for (unsigned int i = 0; i < mesh->index_count; i++) {
        auto p = mesh->indices[i].p-1;
        auto t = mesh->indices[i].t-1;
        auto n = mesh->indices[i].n-1;

        vertices.push_back(mesh->positions[3*p+3]);
        vertices.push_back(mesh->positions[3*p+4]);
        vertices.push_back(mesh->positions[3*p+5]);

        textureCoords.push_back(mesh->texcoords[2*t+2]);
        textureCoords.push_back(mesh->texcoords[2*t+3]);

        normals.push_back(mesh->normals[3*n+3]);
        normals.push_back(mesh->normals[3*n+4]);
        normals.push_back(mesh->normals[3*n+5]);

        indices.push_back(i);
    }

    ModelData data = {vertices, indices, textureCoords, normals, (int)vertices.size(), (int)indices.size(), (int)textureCoords.size(), (int)normals.size()};
    return ModelLoader::Load(data);
}
}
