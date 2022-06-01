#pragma once
#include "GameObject.h"

namespace Nade{
  class CollisionDetector{
  public:
    static void Detect(GameObject& object1, GameObject& object2);
  };
}