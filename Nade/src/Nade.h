#pragma once

//Precompiled Header
#include "pch.h"

// Core Systems
#include "Core/Window.h"
#include "Core/Events/Event.h"
#include "Core/Input/Input.h"

//Game Components
#include "Components/GameObject.h"
#include "Components/Camera.h"
#include "Components/Light.h"
#include "Components/World.h"

//Physics
#include "Core/Physics/PhysicsObject.h"
#include "Core/Physics/TriangleIntersectionDetector.h"
#include "Core/Physics/ObjectCollisionDetector.h"

//Loaders
#include "Graphics/Loaders/ModelLoader.h"
#include "Graphics/Loaders/TextureLoader.h"
#include "Graphics/Loaders/OBJLoader.h"

//Graphics Componenets
#include "Graphics/Components/RawModel.h"
#include "Graphics/Components/Shader.h"
#include "Graphics/Components/Renderer.h"
#include "Graphics/Components/Material.h"

#define ND_GLOBAL_CREATE(x) std::optional<x>

//GLM Mathematics Header Library
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

//Fast Obj imports
#include "fast_obj.h"

//General uses
#include <vector>