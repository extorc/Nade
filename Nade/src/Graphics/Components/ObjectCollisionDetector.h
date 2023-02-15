#pragma once

#include "GameObject.h"
#include <glm/glm.hpp>
#include <vector>

namespace Nade{
  class ObjectCollisionDetector{
    public:
    static std::vector<glm::vec3> DeriveTriangles(GameObject& object);
    static void Detect(GameObject& object1, GameObject& object2);
  };
}