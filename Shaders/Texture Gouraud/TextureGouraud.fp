
//Texture Gouraud Shader
//Fragment Shader
#version 130

//Incoming per fragment
smooth in vec4 varyingColor;
smooth in vec2 varyingTextureCoords;

//Set per batch
uniform sampler2D colorMap;

//Outcoming fragment color
out vec4 fragColor;

void main(void)
{
	//Add in the color
	fragColor = varyingColor;

	//Modulate in the texture
    fragColor *= texture(colorMap, varyingTextureCoords);
}