
//Dissolve Shader
//Modified Texture Phong Shader
//Fragment Shader
#version 330

//Incoming per fragment
smooth in vec3 varyingNormal;
smooth in vec3 varyingLightDir;
smooth in vec2 varyingTextureCoords;

//Set per batch
uniform vec4 ambientColor;
uniform vec4 diffuseColor;
uniform vec4 specularColor;
uniform float shininess;

uniform sampler2D colorMap;
uniform float dissolveFactor;

//Outcoming fragment color
out vec4 fragColor;

void main(void)
{
	vec4 dissolveSample = texture2D(colorMap, varyingTextureCoords);

	if (dissolveSample.r < dissolveFactor)
	{
		discard;
	}
	
	//Dot product gives us diffuse intensity
	float t = dot(normalize(varyingNormal), normalize(varyingLightDir));

	float diff = max(0.0, t);

	//Multiply intensity by diffuse color
	fragColor = diff * diffuseColor;

	//Add in ambient light
	fragColor += ambientColor;

	//Specular light
	//If the diffuse light is zero, don't even bother with specular light
	if(diff != 0)
	{
		vec3 reflection = normalize(reflect(-normalize(varyingLightDir), normalize(varyingNormal)));

		float s = dot(normalize(varyingNormal), reflection);

		float spec = max(0.0, s);

		float fSpec = pow(spec, shininess);

		fragColor.rgb += vec3(fSpec, fSpec, fSpec) * specularColor.rgb;
	}

	//Force alpha to 1.0
	fragColor.a = 1.0;
}