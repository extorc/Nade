#include "CollisionDetector.h"
#include <iostream>
namespace Nade{
  void CollisionDetector::CollisionDetector::Detect(GameObject& object1, GameObject& object2){
        for(int i = 0; i < object1.GetData().model.data.Vsize; i=i+3){
          std::cout<<i/3<<"x : "<<object1.GetData().model.data.mPosition.at(i)<<std::endl;
          std::cout<<i/3<<"y : "<<object1.GetData().model.data.mPosition.at(i+1)<<std::endl;
          std::cout<<i/3<<"z : "<<object1.GetData().model.data.mPosition.at(i+2)<<std::endl;
        }
        for(int i = 0; i < object2.GetData().model.data.Vsize; i=i+3){
          std::cout<<i/3<<"x : "<<object2.GetData().model.data.mPosition.at(i)<<std::endl;
          std::cout<<i/3<<"y : "<<object2.GetData().model.data.mPosition.at(i+1)<<std::endl;
          std::cout<<i/3<<"z : "<<object2.GetData().model.data.mPosition.at(i+2)<<std::endl;
        }
  }
}