#pragma once
// GLFW vendor Window Class
#include "Core/Window.h"

//Raw Model Data Credentials
#include "Graphics/Components/RawModel.h"

//Loaders
#include "Graphics/Loaders/ModelLoader.h"
#include "Graphics/Loaders/TextureLoader.h"

//Shaders
#include "Graphics/Components/Shader.h"

//Renderer
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

//Predefined Vertices
float Quadposition[12] = {
		0.5, 0.5,0,
	   -0.5, 0.5,0,
	   -0.5,-0.5,0,
		0.5,-0.5,0
};

unsigned int Quadindex[6] = {
	0,1,2,0,2,3
};

float Quadcoords[8] = {
	1,1,0,1,0,0,1,0
};