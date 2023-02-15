#pragma once
#include "Shader.h"

namespace Nade{
    class World{
    public:
        int skyboxType = 0;
        float ambient = (float)0.1;
        void Bind(unsigned int shader){
		    Nade::Shader::Set1f(shader, "ambient", ambient);
        }
        void SetWorldAmbient(float pAmbient){
            ambient = pAmbient;
            skyboxType = 0;
        }
    };
}