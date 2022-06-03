#include "CollisionDetector.h"
#include <iostream>
#include <glm/glm.hpp>
#include <vector>

namespace Nade{
  void CollisionDetector::DeriveTriangles(GameObject& object1, GameObject& object2, std::vector<glm::vec3>& triangle1, std::vector<glm::vec3>& triangle2){
    for(int i = 0; i < object1.GetData().model.data.Vsize; i=i+3){
      std::vector<float> pos = object1.GetData().model.data.mPosition;
      float v1 = pos.at(i);
      float v2 = pos.at(i+1);
      float v3 = pos.at(i+2);
      triangle1.push_back(glm::vec3(v1, v2, v3));
    }
    for(int i = 0; i < object2.GetData().model.data.Vsize; i=i+3){
      std::vector<float> pos = object2.GetData().model.data.mPosition;
      float v1 = pos.at(i);
      float v2 = pos.at(i+1);
      float v3 = pos.at(i+2);
      triangle2.push_back(glm::vec3(v1, v2, v3));
    }
  }

  void CollisionDetector::CollisionDetector::Detect(GameObject& object1, GameObject& object2){
    std::vector<glm::vec3> triangle1;
    std::vector<glm::vec3> triangle2;
    DeriveTriangles(object1, object2, triangle1, triangle2);
    glm::vec3 normal1 = ND_EXTNORM(triangle1);
    glm::vec3 normal2 = ND_EXTNORM(triangle2);
    ND_PRINT_VEC(normal1);
    ND_PRINT_VEC(normal2);
  }
}