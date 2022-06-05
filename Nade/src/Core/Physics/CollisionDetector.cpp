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
    float k1 = -glm::dot(normal1, triangle1.at(0));
    float k2 = -glm::dot(normal2, triangle2.at(0));
    // std::cout<<ND_CHECK_SIGN(glm::dot(normal2, triangle1.at(0)) + k2)<<std::endl;
    // std::cout<<ND_CHECK_SIGN(glm::dot(normal2, triangle1.at(1)) + k2)<<std::endl;
    // std::cout<<ND_CHECK_SIGN(glm::dot(normal2, triangle1.at(2)) + k2)<<std::endl;
    // std::cout<<ND_CHECK_SIGN(glm::dot(normal1, triangle2.at(0)) + k1)<<std::endl;
    // std::cout<<ND_CHECK_SIGN(glm::dot(normal1, triangle2.at(1)) + k1)<<std::endl;
    // std::cout<<ND_CHECK_SIGN(glm::dot(normal1, triangle2.at(2)) + k1)<<std::endl;
    if(ND_CHECK_SIGN(glm::dot(normal2, triangle1.at(0)) + k2) == ND_CHECK_SIGN(glm::dot(normal2, triangle1.at(1)) + k2) && ND_CHECK_SIGN(glm::dot(normal2, triangle1.at(1)) + k2) == ND_CHECK_SIGN(glm::dot(normal2, triangle1.at(2)) + k2) && ND_CHECK_SIGN(glm::dot(normal2, triangle1.at(2)) + k2) == ND_CHECK_SIGN(glm::dot(normal2, triangle1.at(0)) + k2) && ND_CHECK_SIGN(glm::dot(normal1, triangle2.at(0)) + k1) == ND_CHECK_SIGN(glm::dot(normal1, triangle2.at(1)) + k1) && ND_CHECK_SIGN(glm::dot(normal1, triangle2.at(1)) + k1) ==  ND_CHECK_SIGN(glm::dot(normal1, triangle2.at(2)) + k1) && ND_CHECK_SIGN(glm::dot(normal1, triangle2.at(2)) + k1) ==  ND_CHECK_SIGN(glm::dot(normal1, triangle2.at(1)) + k1)){
      std::cout<<"Not Colliding"<<std::endl;
    }
    else{
      std::cout<<"Colliding"<<std::endl;
    }
  }
}