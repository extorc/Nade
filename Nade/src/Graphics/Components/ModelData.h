#pragma once
#include <vector>

namespace Nade{
    struct ModelData{
        std::vector<float> mPosition;
        std::vector<unsigned int> mIndex;
        std::vector<float> mCoords;
        std::vector<float>mNormals;
        int Vsize;
        int Isize;
        int Csize;
        int Nsize;
    };
}
