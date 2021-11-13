#pragma once
// GLFW vendor Window Class
#include "Core/Window.h"

//Raw Model Data Credentials
#include "Graphics/Components/RawModel.h"

//Loaders
#include "Graphics/Loaders/ModelLoader.h"
#include "Graphics/Loaders/TextureLoader.h"
#include "Graphics/Loaders/OBJLoader.h"

//Graphics Componenets
#include "Graphics/Components/Shader.h"
#include "Graphics/Components/Renderer.h"

//For Global Object Creation
#include <optional>

#define ND_GLOBAL_CREATE(x) std::optional<x>

//GLM Mathematics Header Library
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

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