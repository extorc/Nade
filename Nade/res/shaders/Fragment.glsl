#version 330 core

out vec4 Pixel;

in vec2 Texture_Coords;

uniform vec4 color;
uniform sampler2D Texture;
uniform float ambient;

void main(){
	vec3 light_color = vec3(1.0,1.0,1.0);
	vec3 final_ambient = light_color * ambient;
	Pixel = texture(Texture, Texture_Coords) * vec4(final_ambient, 1.0);
}
