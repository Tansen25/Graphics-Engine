
#include "ShaderManager.h"

ShaderManager::ShaderManager()
{
	this -> initializeShaders();
}

ShaderManager* ShaderManager::getInstance()
{
	return privGetInstance();
}

void ShaderManager::useFlatShader(Matrix &mvp, Vect &color)
{
	glUseProgram(flatShader);

	//Locate uniforms
	locMVP = glGetUniformLocation(flatShader, "mvp");
	locColor = glGetUniformLocation(flatShader, "color");

	//Convert to openGL friendly variables
	GLfloat vColor[] = { color[x], color[y], color[z], color[w]} ;

	GLfloat vMVP[] = { mvp[m0], mvp[m1], mvp[m2], mvp[m3], mvp[m4], mvp[m5], mvp[m6], mvp[m7],
		mvp[m8], mvp[m9], mvp[m10], mvp[m11], mvp[m12], mvp[m13], mvp[m14], mvp[m15] };
	
	//Load up the uniforms
	glUniform4fv(locColor, 1, vColor);
	glUniformMatrix4fv(locMVP, 1, GL_FALSE, vMVP);
}

void ShaderManager::usePointLightDiffuseShader(Matrix &mvp, Matrix &mv, Matrix &normal, Vect &color, Vect &lightPos)
{
	glUseProgram(pointLightDiffuseShader);

	//Locate uniforms
	locMVP			= glGetUniformLocation(pointLightDiffuseShader, "mvp");
	locMV			= glGetUniformLocation(pointLightDiffuseShader, "mv");
	locNormal		= glGetUniformLocation(pointLightDiffuseShader, "normal");
	locColor		= glGetUniformLocation(pointLightDiffuseShader, "diffuseColor");
	locLightPos     = glGetUniformLocation(pointLightDiffuseShader, "lightPosition");

	//Convert to openGL friendly variables
	GLfloat vMVP[] = { mvp[m0], mvp[m1], mvp[m2], mvp[m3], mvp[m4], mvp[m5], mvp[m6], mvp[m7],
		mvp[m8], mvp[m9], mvp[m10], mvp[m11], mvp[m12], mvp[m13], mvp[m14], mvp[m15] };

	GLfloat vMV[] = { mv[m0], mv[m1], mv[m2], mv[m3], mv[m4], mv[m5], mv[m6], mv[m7],
		mv[m8], mv[m9], mv[m10], mv[m11], mv[m12], mv[m13], mv[m14], mv[m15] };

	GLfloat vNormal[] = { normal[m0], normal[m1], normal[m2], normal[m4], normal[m5], normal[m6], normal[m8], normal[m9],
		normal[m10] };

	GLfloat vColor[] = { color[x], color[y], color[z], color[w] } ;

	GLfloat vLightPos[] = { lightPos[x], lightPos[y], lightPos[z] };

	//Load up the uniforms
	glUniformMatrix4fv(locMVP, 1, GL_FALSE, vMVP);
	glUniformMatrix4fv(locMV, 1, GL_FALSE, vMV);
	glUniformMatrix3fv(locNormal, 1, GL_FALSE, vNormal);
	glUniform4fv(locColor, 1, vColor);
	glUniform3fv(locLightPos, 1, vLightPos);
}

void ShaderManager::useTexturePointLightDiffuseShader(Matrix &mvp, Matrix &mv, Matrix &normal, Vect &color, Vect &lightPos)
{
	glUseProgram(texturePointLightDiffuseShader);

	//Locate uniforms
	locMVP			= glGetUniformLocation(texturePointLightDiffuseShader, "mvp");
	locMV			= glGetUniformLocation(texturePointLightDiffuseShader, "mv");
	locNormal		= glGetUniformLocation(texturePointLightDiffuseShader, "normal");
	locColor		= glGetUniformLocation(texturePointLightDiffuseShader, "diffuseColor");
	locLightPos     = glGetUniformLocation(texturePointLightDiffuseShader, "lightPosition");
	locTexture0		= glGetUniformLocation(texturePointLightDiffuseShader, "colorMap");

	//Convert to openGL friendly variables
	GLfloat vMVP[] = { mvp[m0], mvp[m1], mvp[m2], mvp[m3], mvp[m4], mvp[m5], mvp[m6], mvp[m7],
		mvp[m8], mvp[m9], mvp[m10], mvp[m11], mvp[m12], mvp[m13], mvp[m14], mvp[m15] };

	GLfloat vMV[] = { mv[m0], mv[m1], mv[m2], mv[m3], mv[m4], mv[m5], mv[m6], mv[m7],
		mv[m8], mv[m9], mv[m10], mv[m11], mv[m12], mv[m13], mv[m14], mv[m15] };

	GLfloat vNormal[] = { normal[m0], normal[m1], normal[m2], normal[m4], normal[m5], normal[m6], normal[m8], normal[m9],
		normal[m10] };

	GLfloat vColor[] = { color[x], color[y], color[z], color[w] } ;

	GLfloat vLightPos[] = { lightPos[x], lightPos[y], lightPos[z] };

	//Load up the uniforms
	glUniformMatrix4fv(locMVP, 1, GL_FALSE, vMVP);
	glUniformMatrix4fv(locMV, 1, GL_FALSE, vMV);
	glUniformMatrix3fv(locNormal, 1, GL_FALSE, vNormal);
	glUniform4fv(locColor, 1, vColor);
	glUniform3fv(locLightPos, 1, vLightPos);
	glUniform1i(locTexture0, 0);
}

void ShaderManager::useGouraudShader(Matrix &mvp, Matrix &mv, Matrix &normal, Vect &ambientColor, Vect &diffuseColor, Vect &specularColor, float &shininess, Vect &lightPos)
{
	glUseProgram(gouraudShader);

	//Locate uniforms
	locMVP				= glGetUniformLocation(gouraudShader, "mvp");
	locMV				= glGetUniformLocation(gouraudShader, "mv");
	locNormal			= glGetUniformLocation(gouraudShader, "normal");
	locAmbientColor		= glGetUniformLocation(gouraudShader, "ambientColor");
	locDiffuseColor		= glGetUniformLocation(gouraudShader, "diffuseColor");
	locSpecularColor	= glGetUniformLocation(gouraudShader, "specularColor");
	locShininess		= glGetUniformLocation(gouraudShader, "shininess");
	locLightPos			= glGetUniformLocation(gouraudShader, "lightPosition");

	//Convert to openGL friendly variables
	GLfloat vMVP[] = { mvp[m0], mvp[m1], mvp[m2], mvp[m3], mvp[m4], mvp[m5], mvp[m6], mvp[m7],
		mvp[m8], mvp[m9], mvp[m10], mvp[m11], mvp[m12], mvp[m13], mvp[m14], mvp[m15] };

	GLfloat vMV[] = { mv[m0], mv[m1], mv[m2], mv[m3], mv[m4], mv[m5], mv[m6], mv[m7],
		mv[m8], mv[m9], mv[m10], mv[m11], mv[m12], mv[m13], mv[m14], mv[m15] };

	GLfloat vNormal[] = { normal[m0], normal[m1], normal[m2], normal[m4], normal[m5], normal[m6], normal[m8], normal[m9],
		normal[m10] };

	GLfloat vAmbientColor[] = { ambientColor[x], ambientColor[y], ambientColor[z], ambientColor[w] } ;

	GLfloat vDiffuseColor[] = { diffuseColor[x], diffuseColor[y], diffuseColor[z], diffuseColor[w] } ;

	GLfloat vSpecularColor[] = { specularColor[x], specularColor[y], specularColor[z], specularColor[w] } ;

	GLfloat vShininess = shininess;

	GLfloat vLightPos[] = { lightPos[x], lightPos[y], lightPos[z] };

	//Load up the uniforms
	glUniformMatrix4fv(locMVP, 1, GL_FALSE, vMVP);
	glUniformMatrix4fv(locMV, 1, GL_FALSE, vMV);
	glUniformMatrix3fv(locNormal, 1, GL_FALSE, vNormal);
	glUniform4fv(locAmbientColor, 1, vAmbientColor);
	glUniform4fv(locDiffuseColor, 1, vDiffuseColor);
	glUniform4fv(locSpecularColor, 1, vSpecularColor);
	glUniform1f(locShininess, vShininess);
	glUniform3fv(locLightPos, 1, vLightPos);
}

void ShaderManager::useTextureGouraudShader(Matrix &mvp, Matrix &mv, Matrix &normal, Vect &ambientColor, Vect &diffuseColor, Vect &specularColor, 
	float &shininess, Vect &lightPos)
{
	glUseProgram(textureGouraudShader);

	//Locate uniforms
	locMVP				= glGetUniformLocation(textureGouraudShader, "mvp");
	locMV				= glGetUniformLocation(textureGouraudShader, "mv");
	locNormal			= glGetUniformLocation(textureGouraudShader, "normal");
	locAmbientColor		= glGetUniformLocation(textureGouraudShader, "ambientColor");
	locDiffuseColor		= glGetUniformLocation(textureGouraudShader, "diffuseColor");
	locSpecularColor	= glGetUniformLocation(textureGouraudShader, "specularColor");
	locShininess		= glGetUniformLocation(textureGouraudShader, "shininess");
	locLightPos			= glGetUniformLocation(textureGouraudShader, "lightPosition");
	locTexture0			= glGetUniformLocation(textureGouraudShader, "colorMap");

	//Convert to openGL friendly variables
	GLfloat vMVP[] = { mvp[m0], mvp[m1], mvp[m2], mvp[m3], mvp[m4], mvp[m5], mvp[m6], mvp[m7],
		mvp[m8], mvp[m9], mvp[m10], mvp[m11], mvp[m12], mvp[m13], mvp[m14], mvp[m15] };

	GLfloat vMV[] = { mv[m0], mv[m1], mv[m2], mv[m3], mv[m4], mv[m5], mv[m6], mv[m7],
		mv[m8], mv[m9], mv[m10], mv[m11], mv[m12], mv[m13], mv[m14], mv[m15] };

	GLfloat vNormal[] = { normal[m0], normal[m1], normal[m2], normal[m4], normal[m5], normal[m6], normal[m8], normal[m9],
		normal[m10] };

	GLfloat vAmbientColor[] = { ambientColor[x], ambientColor[y], ambientColor[z], ambientColor[w] } ;

	GLfloat vDiffuseColor[] = { diffuseColor[x], diffuseColor[y], diffuseColor[z], diffuseColor[w] } ;

	GLfloat vSpecularColor[] = { specularColor[x], specularColor[y], specularColor[z], specularColor[w] } ;

	GLfloat vShininess = shininess;

	GLfloat vLightPos[] = { lightPos[x], lightPos[y], lightPos[z] };

	//Load up the uniforms
	glUniformMatrix4fv(locMVP, 1, GL_FALSE, vMVP);
	glUniformMatrix4fv(locMV, 1, GL_FALSE, vMV);
	glUniformMatrix3fv(locNormal, 1, GL_FALSE, vNormal);
	glUniform4fv(locAmbientColor, 1, vAmbientColor);
	glUniform4fv(locDiffuseColor, 1, vDiffuseColor);
	glUniform4fv(locSpecularColor, 1, vSpecularColor);
	glUniform1f(locShininess, vShininess);
	glUniform3fv(locLightPos, 1, vLightPos);
	glUniform1i(locTexture0, 0);
}

void ShaderManager::usePhongShader(Matrix &mvp, Matrix &mv, Matrix &normal, Vect &ambientColor, Vect &diffuseColor, Vect &specularColor, float &shininess, Vect &lightPos)
{
	glUseProgram(phongShader);

	//Locate uniforms
	locMVP				= glGetUniformLocation(phongShader, "mvp");
	locMV				= glGetUniformLocation(phongShader, "mv");
	locNormal			= glGetUniformLocation(phongShader, "normal");
	locAmbientColor		= glGetUniformLocation(phongShader, "ambientColor");
	locDiffuseColor		= glGetUniformLocation(phongShader, "diffuseColor");
	locSpecularColor	= glGetUniformLocation(phongShader, "specularColor");
	locShininess		= glGetUniformLocation(phongShader, "shininess");
	locLightPos			= glGetUniformLocation(phongShader, "lightPosition");

	//Convert to openGL friendly variables
	GLfloat vMVP[] = { mvp[m0], mvp[m1], mvp[m2], mvp[m3], mvp[m4], mvp[m5], mvp[m6], mvp[m7],
		mvp[m8], mvp[m9], mvp[m10], mvp[m11], mvp[m12], mvp[m13], mvp[m14], mvp[m15] };

	GLfloat vMV[] = { mv[m0], mv[m1], mv[m2], mv[m3], mv[m4], mv[m5], mv[m6], mv[m7],
		mv[m8], mv[m9], mv[m10], mv[m11], mv[m12], mv[m13], mv[m14], mv[m15] };

	GLfloat vNormal[] = { normal[m0], normal[m1], normal[m2], normal[m4], normal[m5], normal[m6], normal[m8], normal[m9],
		normal[m10] };

	GLfloat vAmbientColor[] = { ambientColor[x], ambientColor[y], ambientColor[z], ambientColor[w] } ;

	GLfloat vDiffuseColor[] = { diffuseColor[x], diffuseColor[y], diffuseColor[z], diffuseColor[w] } ;

	GLfloat vSpecularColor[] = { specularColor[x], specularColor[y], specularColor[z], specularColor[w] } ;

	GLfloat vShininess = shininess;

	GLfloat vLightPos[] = { lightPos[x], lightPos[y], lightPos[z] };

	//Load up the uniforms
	glUniformMatrix4fv(locMVP, 1, GL_FALSE, vMVP);
	glUniformMatrix4fv(locMV, 1, GL_FALSE, vMV);
	glUniformMatrix3fv(locNormal, 1, GL_FALSE, vNormal);
	glUniform4fv(locAmbientColor, 1, vAmbientColor);
	glUniform4fv(locDiffuseColor, 1, vDiffuseColor);
	glUniform4fv(locSpecularColor, 1, vSpecularColor);
	glUniform1f(locShininess, vShininess);
	glUniform3fv(locLightPos, 1, vLightPos);
}

void ShaderManager::useTexturePhongShader(Matrix &mvp, Matrix &mv, Matrix &normal, Vect &ambientColor, Vect &diffuseColor, Vect &specularColor, 
	float &shininess, Vect &lightPos)
{
	glUseProgram(texturePhongShader);

	//Locate uniforms
	locMVP				= glGetUniformLocation(texturePhongShader, "mvp");
	locMV				= glGetUniformLocation(texturePhongShader, "mv");
	locNormal			= glGetUniformLocation(texturePhongShader, "normal");
	locAmbientColor		= glGetUniformLocation(texturePhongShader, "ambientColor");
	locDiffuseColor		= glGetUniformLocation(texturePhongShader, "diffuseColor");
	locSpecularColor	= glGetUniformLocation(texturePhongShader, "specularColor");
	locShininess		= glGetUniformLocation(texturePhongShader, "shininess");
	locLightPos			= glGetUniformLocation(texturePhongShader, "lightPosition");
	locTexture0			= glGetUniformLocation(texturePhongShader, "colorMap");

	//Convert to openGL friendly variables
	GLfloat vMVP[] = { mvp[m0], mvp[m1], mvp[m2], mvp[m3], mvp[m4], mvp[m5], mvp[m6], mvp[m7],
		mvp[m8], mvp[m9], mvp[m10], mvp[m11], mvp[m12], mvp[m13], mvp[m14], mvp[m15] };

	GLfloat vMV[] = { mv[m0], mv[m1], mv[m2], mv[m3], mv[m4], mv[m5], mv[m6], mv[m7],
		mv[m8], mv[m9], mv[m10], mv[m11], mv[m12], mv[m13], mv[m14], mv[m15] };

	GLfloat vNormal[] = { normal[m0], normal[m1], normal[m2], normal[m4], normal[m5], normal[m6], normal[m8], normal[m9],
		normal[m10] };

	GLfloat vAmbientColor[] = { ambientColor[x], ambientColor[y], ambientColor[z], ambientColor[w] } ;

	GLfloat vDiffuseColor[] = { diffuseColor[x], diffuseColor[y], diffuseColor[z], diffuseColor[w] } ;

	GLfloat vSpecularColor[] = { specularColor[x], specularColor[y], specularColor[z], specularColor[w] } ;

	GLfloat vShininess = shininess;

	GLfloat vLightPos[] = { lightPos[x], lightPos[y], lightPos[z] };

	//Load up the uniforms
	glUniformMatrix4fv(locMVP, 1, GL_FALSE, vMVP);
	glUniformMatrix4fv(locMV, 1, GL_FALSE, vMV);
	glUniformMatrix3fv(locNormal, 1, GL_FALSE, vNormal);
	glUniform4fv(locAmbientColor, 1, vAmbientColor);
	glUniform4fv(locDiffuseColor, 1, vDiffuseColor);
	glUniform4fv(locSpecularColor, 1, vSpecularColor);
	glUniform1f(locShininess, vShininess);
	glUniform3fv(locLightPos, 1, vLightPos);
	glUniform1i(locTexture0, 0);
}

void ShaderManager::useDissolveShader(Matrix &mvp, Matrix &mv, Matrix &normal, Vect &ambientColor, Vect &diffuseColor, Vect &specularColor, 
	float &shininess, Vect &lightPos, float &dissolveFactor)
{
	glUseProgram(dissolveShader);

	//Locate uniforms
	locMVP				= glGetUniformLocation(dissolveShader, "mvp");
	locMV				= glGetUniformLocation(dissolveShader, "mv");
	locNormal			= glGetUniformLocation(dissolveShader, "normal");
	locAmbientColor		= glGetUniformLocation(dissolveShader, "ambientColor");
	locDiffuseColor		= glGetUniformLocation(dissolveShader, "diffuseColor");
	locSpecularColor	= glGetUniformLocation(dissolveShader, "specularColor");
	locShininess		= glGetUniformLocation(dissolveShader, "shininess");
	locLightPos			= glGetUniformLocation(dissolveShader, "lightPosition");
	locTexture0			= glGetUniformLocation(dissolveShader, "colorMap");
	locDissolveFactor   = glGetUniformLocation(dissolveShader, "dissolveFactor");

	//Convert to openGL friendly variables
	GLfloat vMVP[] = { mvp[m0], mvp[m1], mvp[m2], mvp[m3], mvp[m4], mvp[m5], mvp[m6], mvp[m7],
		mvp[m8], mvp[m9], mvp[m10], mvp[m11], mvp[m12], mvp[m13], mvp[m14], mvp[m15] };

	GLfloat vMV[] = { mv[m0], mv[m1], mv[m2], mv[m3], mv[m4], mv[m5], mv[m6], mv[m7],
		mv[m8], mv[m9], mv[m10], mv[m11], mv[m12], mv[m13], mv[m14], mv[m15] };

	GLfloat vNormal[] = { normal[m0], normal[m1], normal[m2], normal[m4], normal[m5], normal[m6], normal[m8], normal[m9],
		normal[m10] };

	GLfloat vAmbientColor[] = { ambientColor[x], ambientColor[y], ambientColor[z], ambientColor[w] } ;

	GLfloat vDiffuseColor[] = { diffuseColor[x], diffuseColor[y], diffuseColor[z], diffuseColor[w] } ;

	GLfloat vSpecularColor[] = { specularColor[x], specularColor[y], specularColor[z], specularColor[w] } ;

	GLfloat vShininess = shininess;

	GLfloat vLightPos[] = { lightPos[x], lightPos[y], lightPos[z] };

	GLfloat vDissolveFactor = dissolveFactor;

	//Load up the uniforms
	glUniformMatrix4fv(locMVP, 1, GL_FALSE, vMVP);
	glUniformMatrix4fv(locMV, 1, GL_FALSE, vMV);
	glUniformMatrix3fv(locNormal, 1, GL_FALSE, vNormal);
	glUniform4fv(locAmbientColor, 1, vAmbientColor);
	glUniform4fv(locDiffuseColor, 1, vDiffuseColor);
	glUniform4fv(locSpecularColor, 1, vSpecularColor);
	glUniform1f(locShininess, vShininess);
	glUniform3fv(locLightPos, 1, vLightPos);
	glUniform1i(locTexture0, 0);
	glUniform1f(locDissolveFactor, vDissolveFactor);
}

void ShaderManager::useCellShader(Matrix &mvp, Matrix &mv, Matrix &normal, Vect &lightPos)
{
	glUseProgram(cellShader);

	//Locate uniforms
	locMVP				= glGetUniformLocation(cellShader, "mvp");
	locMV				= glGetUniformLocation(cellShader, "mv");
	locNormal			= glGetUniformLocation(cellShader, "normal");
	locLightPos			= glGetUniformLocation(cellShader, "lightPosition");
	locTexture0			= glGetUniformLocation(cellShader, "colorMap");

	//Convert to openGL friendly variables
	GLfloat vMVP[] = { mvp[m0], mvp[m1], mvp[m2], mvp[m3], mvp[m4], mvp[m5], mvp[m6], mvp[m7],
		mvp[m8], mvp[m9], mvp[m10], mvp[m11], mvp[m12], mvp[m13], mvp[m14], mvp[m15] };

	GLfloat vMV[] = { mv[m0], mv[m1], mv[m2], mv[m3], mv[m4], mv[m5], mv[m6], mv[m7],
		mv[m8], mv[m9], mv[m10], mv[m11], mv[m12], mv[m13], mv[m14], mv[m15] };

	GLfloat vNormal[] = { normal[m0], normal[m1], normal[m2], normal[m4], normal[m5], normal[m6], normal[m8], normal[m9],
		normal[m10] };

	GLfloat vLightPos[] = { lightPos[x], lightPos[y], lightPos[z] };

	//Load up the uniforms
	glUniformMatrix4fv(locMVP, 1, GL_FALSE, vMVP);
	glUniformMatrix4fv(locMV, 1, GL_FALSE, vMV);
	glUniformMatrix3fv(locNormal, 1, GL_FALSE, vNormal);
	glUniform3fv(locLightPos, 1, vLightPos);
	glUniform1i(locTexture0, 1);
}

void ShaderManager::useParticleShader(Matrix &mvp, Vect &position, Vect &cameraPosition, Vect &color)
{
	glUseProgram(particleShader);

	//Locate the uniforms
	locMVP				= glGetUniformLocation(particleShader, "mvp");
	locPosition			= glGetUniformLocation(particleShader, "position");
	locCameraPosition	= glGetUniformLocation(particleShader, "cameraPosition");
	locColor			= glGetUniformLocation(particleShader, "color");
	locTexture0			= glGetUniformLocation(particleShader, "image");

	//Convert to openGL friendly variables
	GLfloat vMVP[] = { mvp[m0], mvp[m1], mvp[m2], mvp[m3], mvp[m4], mvp[m5], mvp[m6], mvp[m7],
		mvp[m8], mvp[m9], mvp[m10], mvp[m11], mvp[m12], mvp[m13], mvp[m14], mvp[m15] };

	GLfloat vPosition[] = { position[x], position[y], position[z], position[w] };

	GLfloat vCameraPosition[] = { cameraPosition[x], cameraPosition[y], cameraPosition[z], cameraPosition[w] };

	GLfloat vColor[] = { color[x], color[y], color[z], color[w] };

	//Load up the uniforms
	glUniformMatrix4fv(locMVP, 1, GL_FALSE, vMVP);
	glUniform4fv(locPosition, 1, vPosition);
	glUniform4fv(locCameraPosition, 1, vCameraPosition);
	glUniform4fv(locColor, 1, vColor);
	glUniform1i(locTexture0, 0);
}

ShaderManager* ShaderManager::privGetInstance()
{
	static ShaderManager sm;
	return &sm;
}

void ShaderManager::initializeShaders()
{
	this -> initializeFlatShader();
	this -> initializePointLightDiffuseShader();
	this -> initializeTexturePointLightDiffuseShader();
	this -> initializeGouraudShader();
	this -> initializeTextureGouraudShader();
	this -> initializePhongShader();
	this -> initializeTexturePhongShader();
	this -> initializeDissolveShader();
	this -> initializeCellShader();
	this -> initializeParticleShader();
}

void ShaderManager::initializeFlatShader()
{
	//Load the flat shader
	flatShader = gltLoadShaderPairWithAttributes("Shaders/Flat/Flat.vp", "Shaders/Flat/Flat.fp", 1, GLT_ATTRIBUTE_VERTEX, "vertex");
}

void ShaderManager::initializePointLightDiffuseShader()
{
	//Load the point light diffuse shader
	pointLightDiffuseShader = gltLoadShaderPairWithAttributes("Shaders/Point Light Diffuse/PointLightDiffuse.vp", "Shaders/Point Light Diffuse/PointLightDiffuse.fp",
																2, GLT_ATTRIBUTE_VERTEX, "vertex", GLT_ATTRIBUTE_NORMAL, "vNormal");
}

void ShaderManager::initializeTexturePointLightDiffuseShader()
{
	//Load the point light diffuse shader
	texturePointLightDiffuseShader = gltLoadShaderPairWithAttributes("Shaders/Texture Point Light Diffuse/TexturePointLightDiffuse.vp", 
																		"Shaders/Texture Point Light Diffuse/TexturePointLightDiffuse.fp",
																		3, GLT_ATTRIBUTE_VERTEX, "vertex", GLT_ATTRIBUTE_NORMAL, "vNormal",
																		GLT_ATTRIBUTE_TEXTURE0, "texture0");
}

void ShaderManager::initializeGouraudShader()
{
	//Load the gouraud shader
	gouraudShader = gltLoadShaderPairWithAttributes("Shaders/Gouraud/Gouraud.vp", "Shaders/Gouraud/Gouraud.fp",
														2, GLT_ATTRIBUTE_VERTEX, "vertex", GLT_ATTRIBUTE_NORMAL, "vNormal");
}

void ShaderManager::initializeTextureGouraudShader()
{
	//Load the texture gouraud shader
	textureGouraudShader = gltLoadShaderPairWithAttributes("Shaders/Texture Gouraud/TextureGouraud.vp", "Shaders/Texture Gouraud/TextureGouraud.fp",
														3, GLT_ATTRIBUTE_VERTEX, "vertex", GLT_ATTRIBUTE_NORMAL, "vNormal", GLT_ATTRIBUTE_TEXTURE0, "texture0");
}

void ShaderManager::initializePhongShader()
{
	//Load the phong shader
	phongShader = gltLoadShaderPairWithAttributes("Shaders/Phong/Phong.vp", "Shaders/Phong/Phong.fp",
													2, GLT_ATTRIBUTE_VERTEX, "vertex", GLT_ATTRIBUTE_NORMAL, "vNormal");
}

void ShaderManager::initializeTexturePhongShader()
{
	//Load the texture phong shader
	texturePhongShader = gltLoadShaderPairWithAttributes("Shaders/Texture Phong/TexturePhong.vp", "Shaders/Texture Phong/TexturePhong.fp",
													3, GLT_ATTRIBUTE_VERTEX, "vertex", GLT_ATTRIBUTE_NORMAL, "vNormal", GLT_ATTRIBUTE_TEXTURE0, "texture0");
}

void ShaderManager::initializeDissolveShader()
{
	//Load the dessolve shader
	dissolveShader = gltLoadShaderPairWithAttributes("Shaders/Dissolve/Dissolve.vp", "Shaders/Dissolve/Dissolve.fp",
													3, GLT_ATTRIBUTE_VERTEX, "vertex", GLT_ATTRIBUTE_NORMAL, "vNormal", GLT_ATTRIBUTE_TEXTURE0, "texture0");
}

void ShaderManager::initializeCellShader()
{
	//Load the cell shader
	cellShader = gltLoadShaderPairWithAttributes("Shaders/Cell Shader/Cell.vp", "Shaders/Cell Shader/Cell.fp",
													2, GLT_ATTRIBUTE_VERTEX, "vertex", GLT_ATTRIBUTE_NORMAL, "vNormal");
}

void ShaderManager::initializeParticleShader()
{
	//Load the particle shader
	particleShader = gltLoadShaderPairWithAttributes("Shaders/Particle/Particle.vp", "Shaders/Particle/Particle.fp",
														1, GLT_ATTRIBUTE_VERTEX, "vertex");
}