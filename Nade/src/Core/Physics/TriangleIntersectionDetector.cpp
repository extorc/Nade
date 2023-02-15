#include "TriangleIntersectionDetector.h"
#include <iostream>
#include <glm/glm.hpp>
#include <vector>

namespace Nade{
    void TraingleIntersectionDetector::TraingleIntersectionDetector::Detect(std::vector<glm::vec3> triangle1, std::vector<glm::vec3> triangle2){
    
    glm::vec3 normal1 = ND_EXTNORM(triangle1);                             //Extract Normal vectors of the triangle
    glm::vec3 normal2 = ND_EXTNORM(triangle2);
    float k1 = -glm::dot(normal1, triangle1.at(0));                        //Calculate D value for plane based on the equation D = -N.V
    float k2 = -glm::dot(normal2, triangle2.at(0));

    int distSign1 = ND_CHECK_SIGN(glm::dot(normal2, triangle1.at(0)) + k2);     //Insert Vertices of the first plane in the equation of second to get the signed distance
    int distSign2 = ND_CHECK_SIGN(glm::dot(normal2, triangle1.at(1)) + k2);
    int distSign3 = ND_CHECK_SIGN(glm::dot(normal2, triangle1.at(2)) + k2);
    int distSign4 = ND_CHECK_SIGN(glm::dot(normal1, triangle2.at(0)) + k1);
    int distSign5 = ND_CHECK_SIGN(glm::dot(normal1, triangle2.at(1)) + k1);
    int distSign6 = ND_CHECK_SIGN(glm::dot(normal1, triangle2.at(2)) + k1);

    if(distSign1 == distSign2 && distSign2 == distSign3 && distSign3 == distSign1){         //Check if the sign of the distances of all the Vertices from the plane are same, else they are colliding.
    }
    else if(distSign4 == distSign5 && distSign5 == distSign6 && distSign6 == distSign4){
    }
    else{
      std::cout<<"Colliding"<<std::endl;
    }
  }
}