#pragma once
#include "GameObject.h"

namespace Nade{
  class CollisionDetector{
  public:
    static void Detect(GameObject& object1, GameObject& object2);
    static void DeriveTriangles(GameObject& object1, GameObject& object2, std::vector<glm::vec3>& triangle1, std::vector<glm::vec3>& triangle2);
  };
}