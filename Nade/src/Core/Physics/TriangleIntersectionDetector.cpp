#include "TriangleIntersectionDetector.h"
#include <iostream>
#include <glm/glm.hpp>
#include <vector>

namespace Nade{
  void TraingleIntersectionDetector::DeriveTriangles(GameObject& object, std::vector<glm::vec3>& triangle){
    for(int i = 0; i < object.GetData().model.data.Vsize; i=i+3){
      std::vector<float> pos = object.GetData().model.data.mPosition;
      float v1 = pos.at(i);
      float v2 = pos.at(i+1);
      float v3 = pos.at(i+2);
      triangle.push_back(glm::vec3(v1, v2, v3));
    }
  }

  void TraingleIntersectionDetector::Detect(std::vector<glm::vec3> triangle1, std::vector<glm::vec3> triangle2){
    glm::vec3 normal1 = ND_EXTNORM(triangle1);
    glm::vec3 normal2 = ND_EXTNORM(triangle2);
    float k1 = -glm::dot(normal1, triangle1.at(0));
    float k2 = -glm::dot(normal2, triangle2.at(0));

    int dif1 = ND_CHECK_SIGN(glm::dot(normal2, triangle1.at(0)) + k2);
    int dif2 = ND_CHECK_SIGN(glm::dot(normal2, triangle1.at(1)) + k2);
    int dif3 = ND_CHECK_SIGN(glm::dot(normal2, triangle1.at(2)) + k2);
    int dif4 = ND_CHECK_SIGN(glm::dot(normal1, triangle2.at(0)) + k1);
    int dif5 = ND_CHECK_SIGN(glm::dot(normal1, triangle2.at(1)) + k1);
    int dif6 = ND_CHECK_SIGN(glm::dot(normal1, triangle2.at(2)) + k1);

    if(dif1 == dif2 && dif2 == dif3 && dif3 == dif1){
    }
    else if(dif4 == dif5 && dif5 == dif6 && dif6 == dif4){
    }
    else{
      std::cout<<"Colliding"<<std::endl;
    }
  }
}