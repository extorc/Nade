#include "CollisionDetector.h"
#include <iostream>
#include <glm/glm.hpp>
#include <vector>

namespace Nade{
  void CollisionDetector::CollisionDetector::Detect(GameObject& object1, GameObject& object2){
    std::vector<glm::vec3> triangle1;
    std::vector<glm::vec3> triangle2;
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
    glm::vec3 normal1 = glm::normalize(glm::cross(triangle1.at(1) - triangle1.at(0), triangle1.at(2) - triangle1.at(0)));
    glm::vec3 normal2 = glm::normalize(glm::cross(triangle2.at(1) - triangle2.at(0), triangle2.at(2) - triangle2.at(0)));
    std::cout<< normal1.x << " " << normal1.y << " " << normal1.z << std::endl;
    std::cout<< normal2.x << " " << normal2.y << " " << normal2.z << std::endl;
  }
}