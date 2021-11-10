#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 coords;

out vec2 Texture_Coords;

void main(){
	gl_Position = vec4(pos,1.0);
	Texture_Coords = coords;
}
