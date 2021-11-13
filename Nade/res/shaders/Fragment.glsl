#version 330 core

out vec4 Pixel;

in vec2 Texture_Coords;
in vec3 normal;
in vec3 toLightVector;

uniform vec4 color;
uniform sampler2D Texture;
uniform float ambient;
uniform vec3 light_color;

void main(){

	vec3 unitNormal = normalize(normal);
	vec3 unitToLightVector = normalize(toLightVector);

	float light_factor = dot(unitNormal, unitToLightVector);
	float brightness = max(light_factor, ambient);
	vec3 diffuse = brightness * light_color;

	Pixel = vec4(diffuse,1.0) * texture(Texture, Texture_Coords);
}
