
//Point Light Diffuse Shader
//Fragment Shader
#version 130

out vec4 fragColor;
smooth in vec4 varyingColor;

void main(void)
{ 
   fragColor = varyingColor;
}