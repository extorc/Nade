#pragma once

namespace Nade{
class ModelData{
    public:
        ModelData(float position[], unsigned int index[], float coords[], float normals[], int vsize, int isize, int csize, int nsize)
        :mPosition(position), mIndex(index), mCoords(coords), mNormals(normals), Vsize(vsize), Isize(isize),Csize(csize),Nsize(nsize)
        {

        }
        static ModelData GetModelData(float position[], unsigned int index[], float coords[], float normals[], int vsize, int isize, int csize, int nsize){
            return ModelData(position, index, coords,normals,vsize,isize,csize,nsize);
        }

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