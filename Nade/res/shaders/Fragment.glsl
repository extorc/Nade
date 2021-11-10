#version 330 core

out vec4 Pixel;

uniform vec4 color;
uniform int mat_form;

void main(){
	if(mat_form == 0){
		Pixel = color;
	}
}
