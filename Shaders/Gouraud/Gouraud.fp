
//Gouraud Shader
//Fragment Shader
#version 130

//Incoming per fragment
smooth in vec4 varyingColor;

//Outcoming fragment color
out vec4 fragColor;

void main(void)
{
	fragColor = varyingColor;
}