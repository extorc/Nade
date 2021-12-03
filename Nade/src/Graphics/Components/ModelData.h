#pragma once

namespace Nade{
    struct ModelData{
        float *mPosition;
        unsigned int *mIndex;
        float *mCoords;
        float *mNormals;
        int Vsize;
        int Isize;
        int Csize;
        int Nsize;
    };
}