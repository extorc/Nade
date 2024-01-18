#pragma once
#include "GameObject.h"
#include "TriangleIntersectionDetector.h"

namespace Nade{
  class ObjectCollisionDetector{
  public:
    static void Detect(GameObject& object1, GameObject& object2);
  };
}