
//Flat Shader
//Fragment Shader
#version 130

//Make geometry solid
uniform vec4 color;

//Output fragment color
out vec4 fragColor;

void main(void)
{
	gl_FragColor = color;
}