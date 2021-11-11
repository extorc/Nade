#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 coords;

out vec2 Texture_Coords;

uniform mat4 p;
uniform mat4 m;
uniform mat4 v;
void main(){
	gl_Position = p * v * m * vec4(pos,1.0);
	Texture_Coords = coords;
}
