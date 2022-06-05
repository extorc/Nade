#pragma once
#include "GameObject.h"

#define ND_PRINT_VEC(t) std::cout<< t.x << " " << t.y << " " << t.z << std::endl;
#define ND_EXTNORM(t) (glm::normalize(glm::cross(t.at(1) - t.at(0), t.at(2) - t.at(0))))
#define ND_CHECK_SIGN(t) ((t>0)?1:-1)
namespace Nade{
  class CollisionDetector{
  public:
    static void Detect(GameObject& object1, GameObject& object2);
    static void DeriveTriangles(GameObject& object1, GameObject& object2, std::vector<glm::vec3>& triangle1, std::vector<glm::vec3>& triangle2);
  };
}