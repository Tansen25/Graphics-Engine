
#include "GraphicsObject.h"

GraphicsObject::GraphicsObject()
{
	this -> shaderID = FLAT;
	
	this -> blend = false;

	this -> colorGrowX = true;
	this -> colorGrowY = true;
	this -> colorGrowZ = true;

	this -> scaleGrowX = true;
	this -> scaleGrowY = true;
	this -> scaleGrowZ = true;

	this -> translationGrowX = true;
	this -> translationGrowY = true;
	this -> translationGrowZ = true;

	this -> textureID = 0;
	
	//Set the default transforms
	this -> xScale = 1.0f;
	this -> yScale = 1.0f;
	this -> zScale = 1.0f;

	this -> xAngle = 0.0f;
	this -> yAngle = 0.0f;
	this -> zAngle = 0.0f;

	this -> axisRotAngle = 0.0f;
	this -> orbitAngle = 0.0f;

	this -> xTrans = 0.0f;
	this -> yTrans = 0.0f;
	this -> zTrans = 0.0f;

	this -> xOrbitTrans = 0.0f;
	this -> yOrbitTrans = 0.0f;
	this -> zOrbitTrans = 0.0f;

	this -> shininess = 128.0f;

	this -> dissolveFactor = 0.0f;

	this -> startPos = Vect(0.0f, 0.0f, 0.0f);
	this -> lightPos = Vect(0.0f, 100.0f, 0.0f);
	this -> transformedLightPos = Vect(0.0f, 100.0f, 0.0f);
	this -> color = Vect(1.0f, 1.0f, 1.0f, 1.0f);
	this -> ambientColor = Vect(1.0f, 1.0f, 1.0f, 1.0f);
	this -> diffuseColor = Vect(1.0f, 1.0f, 1.0f, 1.0f);
	this -> specularColor = Vect(1.0f, 1.0f, 1.0f, 1.0f);
	this -> orbitAxis = Vect(0.0f, 1.0f, 0.0f);
	this -> rotAxis = Vect(0.0f, 1.0f, 0.0f);

	this -> world.set(IDENTITY);
	this -> modelView.set(IDENTITY);
	this -> modelViewProj.set(IDENTITY);
	this -> normal.set(IDENTITY);
}

void GraphicsObject::blendOn()
{
	blend = true;
}

void GraphicsObject::blendOff()
{
	blend = false;
}

void GraphicsObject::setShaderID(const shader_ID ID)
{
	this -> shaderID = ID;
}

void GraphicsObject::setColorGrow(const bool inX, const bool inY, const bool inZ)
{
	this -> colorGrowX = inX;
	this -> colorGrowY = inY;
	this -> colorGrowZ = inZ;
}

void GraphicsObject::setScaleGrow(const bool inX, const bool inY, const bool inZ)
{
	this -> scaleGrowX = inX;
	this -> scaleGrowY = inY;
	this -> scaleGrowZ = inZ;
}

void GraphicsObject::setTranslationGrow(const bool inX, const bool inY, const bool inZ)
{
	this -> translationGrowX = inX;
	this -> translationGrowY = inY;
	this -> translationGrowZ = inZ;
}

void GraphicsObject::setTextureID(const int ID)
{
	this -> textureID = ID;
}

void GraphicsObject::setStartPos(const Vect &inPos)
{
	this -> startPos = inPos;
}

void GraphicsObject::setLightPos(const Vect &inLightPos)
{
	this -> lightPos = inLightPos;
}

void GraphicsObject::setColor(const Vect &inTriangleColor)
{
	this -> diffuseColor = inTriangleColor;
}

void GraphicsObject::setAmbientColor(const Vect &inAmbientColor)
{
	this -> ambientColor = inAmbientColor;
}

void GraphicsObject::setDiffuseColor(const Vect &inDiffuseColor)
{
	this -> diffuseColor = inDiffuseColor;
}

void GraphicsObject::setSpecularColor(const Vect &inSpecularColor)
{
	this -> specularColor = inSpecularColor;
}

void GraphicsObject::setShininess(const float &inShininess)
{
	this -> shininess = inShininess;
}

void GraphicsObject::setOrbitAxis(const Vect &inAxis)
{
	this -> orbitAxis = inAxis;
}

void GraphicsObject::setRotAxis(const Vect &inAxis)
{
	this -> rotAxis = inAxis;
}

void GraphicsObject::setColorArray(const Vect inArray[], int arraySize)
{
	assert(arraySize == 4);

	this -> colorArray[0][x] = inArray[0][x];
	this -> colorArray[0][y] = inArray[0][y];
	this -> colorArray[0][z] = inArray[0][z];

	this -> colorArray[1][x] = inArray[1][x];
	this -> colorArray[1][y] = inArray[1][y];
	this -> colorArray[1][z] = inArray[1][z];

	this -> colorArray[2][x] = inArray[2][x];
	this -> colorArray[2][y] = inArray[2][y];
	this -> colorArray[2][z] = inArray[2][z];

	this -> colorArray[3][x] = inArray[3][x];
	this -> colorArray[3][y] = inArray[3][y];
	this -> colorArray[3][z] = inArray[3][z];
}

void GraphicsObject::setScale(const float &inX, const float &inY, const float &inZ)
{
	this -> xScale = inX;
	this -> yScale = inY;
	this -> zScale = inZ;
}

void GraphicsObject::setAxisRotationAngle(const float &inAngle)
{
	this -> axisRotAngle = inAngle;
}

void GraphicsObject::setRotationAngle(const float &inXAngle, const float &inYAngle, const float &inZAngle)
{
	this -> xAngle = inXAngle;
	this -> yAngle = inYAngle;
	this -> zAngle = inZAngle;
}

void GraphicsObject::setOrbitAngle(const float &inAngle)
{
	this -> orbitAngle = inAngle;
}

void GraphicsObject::setTranslation(const float &inX, const float &inY, const float &inZ)
{
	this -> xTrans = inX;
	this -> yTrans = inY;
	this -> zTrans = inZ;
}

void GraphicsObject::setOrbitTranslation(const float &inX, const float &inY, const float &inZ)
{
	this -> xOrbitTrans = inX;
	this -> yOrbitTrans = inY;
	this -> zOrbitTrans = inZ;
}

void GraphicsObject::setDissolveFactor(const float &inDissolveFactor)
{
	this -> dissolveFactor = inDissolveFactor;
}

shader_ID GraphicsObject::getShaderID()
{
	return this -> shaderID;
}

void GraphicsObject::getColorGrow(bool& outX, bool& outY, bool& outZ)
{
	outX = this -> colorGrowX;
	outY = this -> colorGrowY;
	outZ = this -> colorGrowZ;
}

void GraphicsObject::getScaleGrow(bool& outX, bool& outY, bool& outZ)
{
	outX = this -> scaleGrowX;
	outY = this -> scaleGrowY;
	outZ = this -> scaleGrowZ;
}

void GraphicsObject::getTranslationGrow(bool& outX, bool& outY, bool& outZ)
{
	outX = this -> translationGrowX;
	outY = this -> translationGrowY;
	outZ = this -> translationGrowZ;
}

int GraphicsObject::getTextureID()
{
	return this -> textureID;
}

Vect GraphicsObject::getStartPos()
{
	return this -> startPos;
}

Vect GraphicsObject::getColor()
{
	return this -> diffuseColor;
}

Vect GraphicsObject::getAmbientColor()
{
	return this -> ambientColor;
}

Vect GraphicsObject::getDiffuseColor()
{
	return this -> diffuseColor;
}

Vect GraphicsObject::getSpecularColor()
{
	return this -> specularColor;
}

float GraphicsObject::getShininess()
{
	return this -> shininess;
}

Vect GraphicsObject::getOrbitAxis()
{
	return this -> orbitAxis;
}

Vect GraphicsObject::getRotAxis()
{
	return this -> rotAxis;
}

void GraphicsObject::getScale(float& outX, float& outY, float& outZ)
{
	outX = this -> xScale;
	outY = this -> yScale;
	outZ = this -> zScale;
}

void GraphicsObject::getRotationAngle(float& outXAngle, float& outYAngle, float& outZAngle)
{
	outXAngle = this -> xAngle;
	outYAngle = this -> yAngle;
	outZAngle = this -> zAngle;
}

float GraphicsObject::getAxisRotationAngle()
{
	return this -> axisRotAngle;
}

float GraphicsObject::getOrbitAngle()
{
	return this -> orbitAngle;
}

void GraphicsObject::getTranslation(float& outX, float& outY, float& outZ)
{
	outX = this -> xTrans;
	outY = this -> yTrans;
	outZ = this -> zTrans;
}

void GraphicsObject::getOrbitTranslation(float &outX, float &outY, float& outZ)
{
	outX = this -> xOrbitTrans;
	outY = this -> yOrbitTrans;
	outZ = this -> zOrbitTrans;
}

float GraphicsObject::getDissolveFactor()
{
	return this -> dissolveFactor;
}