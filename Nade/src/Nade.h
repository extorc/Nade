#pragma once

//Precompiled Header
#include "pch.h"

// Core Systems
#include "Core/Window.h"
#include "Core/Events/Event.h"
#include "Core/Input/Input.h"

//Physics
#include "Core/Physics/PhysicsObject.h"

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

//Game Components
#include "Components/GameObject.h"
#include "Components/Camera.h"
#include "Components/Light.h"

//Asset Importer Library
#include "assimp/scene.h"
#include "assimp/Importer.hpp"
#include "assimp/postprocess.h"

//General uses
#include <vector>