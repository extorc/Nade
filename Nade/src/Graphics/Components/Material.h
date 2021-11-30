#pragma once
#include "Shader.h"
#include "glm/glm.hpp"
#include <iostream>

namespace Nade {
class Material {
public:
    void SetTexture(unsigned int pTexture)
    {
        texture = pTexture;
        matform = 1;
    }
    void SetColor(glm::vec3 pcolor)
    {
        color = pcolor;
        matform = 0;
    }
    void SetSpecular(float pSpecular)
    {
        specular = pSpecular;
    }
    void SetReflective(float pReflective)
    {
        reflective = pReflective;
    }
    void Bind(unsigned int shader)
    {
        Shader::Set1i(shader, "Texture", 0);
        Shader::SetVec3(shader, "color", color);
        Shader::Set1f(shader, "reflective", reflective);
        Shader::Set1f(shader, "specular", specular);
        Shader::Set1i(shader, "matform", matform);
    }
    unsigned int texture;
    float reflective = 1.0f, specular = 10.0f;
    glm::vec3 color = glm::vec3(1, 1, 1);
    int matform = 0;
};
}