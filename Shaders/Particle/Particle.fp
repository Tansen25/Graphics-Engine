
// Particle Shader
// Fragment Shader
#version 130

//Incoming from the vertex shader
in vec4 outColor;

//Set per batch
uniform sampler2D image;

//Outgoing color
out vec4 fragColor;

void main(void)
{ 
	fragColor = texture(image, gl_PointCoord) * outColor;
}
    