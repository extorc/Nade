#pragma once
#include "GameObject.h"

#define ND_PHYSICS_GRAVITATIONAL_ACCELERATION -0.00098

namespace Nade {
	class PhysicsObject {
	public:
		static void SetPhysicsObject(GameObject& object) {
			object.is_physics_object = true;
		}
	};
}