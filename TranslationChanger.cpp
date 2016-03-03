
#include "TranslationChanger.h"

TranslationChanger::TranslationChanger()
{
	this -> minX = 0.0f;
	this -> maxX = 0.0f;
	this -> minY = 0.0f;
	this -> maxY = 0.0f;
	this -> minZ = 0.0f;
	this -> maxZ = 0.0f;
		
	this -> rateX = 0.0f;
	this -> rateY = 0.0f;
	this -> rateZ = 0.0f;

}

void TranslationChanger::setMinMax(float inMinX, float inMaxX, float inMinY, float inMaxY, float inMinZ, float inMaxZ)
{
	this -> minX = inMinX;
	this -> maxX = inMaxX;
	this -> minY = inMinY;
	this -> maxY = inMaxY;
	this -> minZ = inMinZ;
	this -> maxZ = inMaxZ;
}

void TranslationChanger::setRate(float inX, float inY, float inZ)
{
	this -> rateX = inX;
	this -> rateY = inY;
	this -> rateZ = inZ;
}

void TranslationChanger::constantTranslationChange(float& translationX, float& translationY, float& translationZ)
{
	translationX += this -> rateX;
	translationY += this -> rateY;
	translationZ += this -> rateZ;
}

void TranslationChanger::constantTranslationChangeMinMax(bool& translationGrowX, bool& translationGrowY, bool& translationGrowZ, 
										                 float& translationX, float& translationY, float& translationZ)
{
	this -> determineAddSubtract(translationGrowX, translationGrowY, translationGrowZ, translationX, translationY, translationZ);

	if (translationGrowX)
	{
		translationX += this -> rateX;
	}
	else
	{
		translationX -= this -> rateX;
	}

	if (translationGrowY)
	{
		translationY += this -> rateY;
	}
	else
	{
		translationY -= this -> rateY;
	}

	if (translationGrowZ)
	{
		translationZ += this -> rateZ;
	}
	else
	{
		translationZ -= this -> rateZ;
	}
}

void TranslationChanger::determineAddSubtract(bool& translationGrowX, bool& translationGrowY, bool& translationGrowZ, 
										      float& translationX, float& translationY, float& translationZ)
{
	if (translationX > this -> maxX)
	{
		translationGrowX = false;
	}
	else if (translationX < this -> minX)
	{
		translationGrowX = true;
	}

	if (translationY > this -> maxY)
	{
		translationGrowY = false;
	}
	else if (translationY < this -> minY)
	{
		translationGrowY = true;
	}

	if (translationZ > this -> maxZ)
	{
		translationGrowZ = false;
	}
	else if (translationZ < this -> minZ)
	{
		translationGrowZ = true;
	}
}