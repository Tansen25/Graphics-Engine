
//Cell Shader
//Fragment Shader
#version 130

//Incoming per fragment
smooth in float textureCoordinate;

//Set per batch
uniform sampler1D colorTable;

//Outgoing
out vec4 fragColor;


void main(void)
{ 
	fragColor = texture(colorTable, textureCoordinate);
}