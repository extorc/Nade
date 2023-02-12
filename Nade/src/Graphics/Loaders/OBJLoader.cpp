#include "OBJLoader.h"
#include "pch.h"

#include "fast_obj.h"

#include "ModelData.h"
#include "ModelLoader.h"

namespace Nade {
RawModel OBJLoader::Load(const char* file)
{
    fastObjMesh* mesh = fast_obj_read(file); 
    auto vertNum = mesh->position_count-1; //Eliminating dummy entries from fast_obj
    auto texnum = mesh->texcoord_count-1;
    auto normnum = mesh->normal_count-1;

    std::vector<float> vertices;
    std::vector<float> textureCoords;
    std::vector<float> normals;
    std::vector<unsigned int> indices;
    std::cout<<vertNum<<std::endl;
    std::cout<<texnum<<std::endl;
    std::cout<<normnum<<std::endl;
    std::cout<<mesh->index_count<<std::endl;

    for (int i = 0; i < vertNum; i++) {
        vertices.push_back(mesh->positions[3*i+3]);
        vertices.push_back(mesh->positions[3*i+4]);
        vertices.push_back(mesh->positions[3*i+5]);
        std::cout<<"Vertex positions : "<<mesh->positions[3*i+3]<<" "<<mesh->positions[3*i+4]<<" "<<mesh->positions[3*i+5]<<std::endl;
    }
    for (int i = 0; i < texnum; i++) {
        textureCoords.push_back(mesh->texcoords[2*i+2]);
        textureCoords.push_back(mesh->texcoords[2*i+3]);
        std::cout<<"Texture coordinates : "<<mesh->texcoords[2*i+2]<<" "<<mesh->texcoords[2*i+3]<<std::endl;
    }

    for (int i = 0; i < normnum; i++) {
        normals.push_back(mesh->normals[3*i+3]);
        normals.push_back(mesh->normals[3*i+4]);
        normals.push_back(mesh->normals[3*i+5]);
        std::cout<<"Normal positions : "<<mesh->normals[3*i+3]<<" "<<mesh->normals[3*i+4]<<" "<<mesh->normals[3*i+5]<<std::endl;
        
    }
    for (unsigned int i = 0; i < mesh->index_count; i++) {
        indices.push_back(mesh->indices[i].n);
        indices.push_back(mesh->indices[i].p);
        indices.push_back(mesh->indices[i].t);
        std::cout<<"Indices : "<<mesh->indices[i].n<<" "<<mesh->indices[i].p<<" "<<mesh->indices[i].t<<std::endl;
    }
    // The indices are no longer in the form of a single index string like in assimp, instead they are Bare OBJ indices in the npt form which would need parsing.

    ModelData data = {vertices, indices, textureCoords, normals, (int)vertices.size(), (int)indices.size(), (int)textureCoords.size(), (int)normals.size()};
    return ModelLoader::Load(data);
}
}
