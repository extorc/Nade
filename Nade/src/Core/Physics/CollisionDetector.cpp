#include "CollisionDetector.h"
#include <iostream>
#include <glm/glm.hpp>

namespace Nade{
  void CollisionDetector::CollisionDetector::Detect(GameObject& object1, GameObject& object2){
    for(int i = 0; i < object2.GetData().model.data.Vsize; i=i+3){
      float v1 = object2.GetData().model.data.mPosition.at(i);
      float v2 = object2.GetData().model.data.mPosition.at(i+1);
      float v3 = object2.GetData().model.data.mPosition.at(i+2);
      glm::vec3 v = glm::vec3(v1, v2, v3);
      glm::vec3 f(0,0,0);
      for(int p = 0; p < object1.GetData().model.data.Vsize; p=p+3){
        float v12 = object1.GetData().model.data.mPosition.at(p);
        float v22 = object1.GetData().model.data.mPosition.at(p+1);
        float v32 = object1.GetData().model.data.mPosition.at(p+2);
        glm::vec3 vf = glm::vec3(v12, v22, v32);
        f = (vf-v);
        std::cout<<f.x << " " << f.y << " " << f.z << std::endl;
      }
    }
  }
}