#include "CollisionDetector.h"
#include <iostream>
#include <glm/glm.hpp>
#include <vector>

namespace Nade{
  void CollisionDetector::CollisionDetector::Detect(GameObject& object1, GameObject& object2){
    std::vector<glm::vec3> triVec;
    for(int i = 0; i < object2.GetData().model.data.Vsize; i=i+3){
      std::vector<float> pos2 = object2.GetData().model.data.mPosition;
      float v1 = pos2.at(i);
      float v2 = pos2.at(i+1);
      float v3 = pos2.at(i+2);
      glm::vec3 v = glm::vec3(v1, v2, v3);
      glm::vec3 f(0,0,0);
      for(int p = 0; p < object1.GetData().model.data.Vsize; p=p+3){
        std::vector<float> pos1 = object1.GetData().model.data.mPosition;
        float v12 = pos1.at(p);
        float v22 = pos1.at(p+1);
        float v32 = pos1.at(p+2);
        glm::vec3 vf = glm::vec3(v12, v22, v32);
        f += (vf-v);
      }
      f = glm::normalize(f);
      triVec.push_back(f);
      f = glm::vec3(0,0,0);
    }
    for(int i = 0; i < 3; i++){
      if(i == 2){
        std::cout<<glm::dot(triVec.at(i), triVec.at(0))<<std::endl;
      }
      else{
        std::cout<<glm::dot(triVec.at(i), triVec.at(i+1))<<std::endl;
      }
      // std::cout<<triVec.at(i).x << " " << triVec.at(i).y << " " << triVec.at(i).z << std::endl;
    }
    //***
  }
}