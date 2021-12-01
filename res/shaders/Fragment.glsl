#version 330 core

out vec4 Pixel;

in vec2 Texture_Coords;
in vec3 normal;
in vec3 toLightVector;
in vec3 toCameraVector;

uniform vec3 color;
uniform int matform;
uniform sampler2D Texture;
uniform float ambient;
uniform vec3 light_color;
uniform float reflective;
uniform float specular;

void main(){

	vec3 unitNormal = normalize(normal);
	vec3 unitToLightVector = normalize(toLightVector);
	vec3 unitToCameraVector = normalize(toCameraVector);

	float light_factor = dot(unitNormal, unitToLightVector);
	float brightness = max(light_factor, ambient);
	vec3 diffuse = brightness * light_color;
	vec3 light_direction = -unitToLightVector;

	vec3 reflection = reflect(light_direction, unitNormal);
	float specular_factor = dot(reflection, unitToCameraVector);
	specular_factor = max(specular_factor, 0.0);

	float damped_specular = pow(specular_factor, specular);
	vec3 final_specular = damped_specular * reflective * light_color;

	if(matform == 1){
		Pixel = vec4(diffuse,1.0) * texture(Texture, Texture_Coords) + vec4(final_specular, 1.0);
	}
	if(matform == 0){
		Pixel = vec4(diffuse,1.0) * vec4(color, 1.0) + vec4(final_specular, 1.0);
	}
}
