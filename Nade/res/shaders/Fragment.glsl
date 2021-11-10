#version 330 core

out vec4 Pixel;

in vec2 Texture_Coords;

uniform vec4 color;
uniform sampler2D Texture;

void main(){
	Pixel = texture(Texture, Texture_Coords);
}
