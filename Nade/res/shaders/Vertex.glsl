#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 coords;
layout (location = 2) in vec3 normals;

out vec2 Texture_Coords;
out vec3 normal;
out vec3 toLightVector;

uniform mat4 p;
uniform mat4 m;
uniform mat4 v;
uniform vec3 light_position;

void main(){
	vec4 world_position = m * vec4(pos,1.0);
	gl_Position = p * v * world_position;

	Texture_Coords = coords;
	
	vec3 final_normal = (vec4(normals,0.0) * m).xyz;
	normal = final_normal;

	toLightVector = light_position - world_position.xyz;
}