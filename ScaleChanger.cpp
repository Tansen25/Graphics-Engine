
#include "ScaleChanger.h"

ScaleChanger::ScaleChanger()
{
	this -> rateX = 0.0f;
	this -> rateY = 0.0f;
	this -> rateZ = 0.0f;
}

void ScaleChanger::setMinMax(float inMinX, float inMaxX, float inMinY, float inMaxY, float inMinZ, float inMaxZ)
{
	this -> minX = inMinX;
	this -> maxX = inMaxX;

	this -> minY = inMinY;
	this -> maxY = inMaxY;

	this -> minZ = inMinZ;
	this -> maxZ = inMaxZ;

}

void ScaleChanger::setRate(float inX, float inY, float inZ)
{
	this -> rateX = inX;
	this -> rateY = inY;
	this -> rateZ = inZ;
}

void ScaleChanger::constantScaleChange(float& scaleX, float& scaleY, float& scaleZ)
{
	scaleX += this -> rateX;
	scaleY += this -> rateY;
	scaleZ += this -> rateZ;
}

void ScaleChanger::constantScaleChangeMinMax(bool& growScaleX, bool& growScaleY, bool& growScaleZ, float& scaleX, float& scaleY, float& scaleZ)
{
	this -> determineAddSubtract(growScaleX, growScaleY, growScaleZ, scaleX, scaleY, scaleZ);

	if (growScaleX)
	{
		scaleX += this -> rateX;
	}
	else
	{
		scaleX -= this -> rateY;
	}

	if (growScaleY)
	{
		scaleY += this -> rateY;
	}
	else
	{
		scaleY -= this -> rateY;
	}

	if (growScaleZ)
	{
		scaleZ += this -> rateZ;
	}
	else
	{
		scaleZ -= this -> rateZ;
	}
}

void ScaleChanger::determineAddSubtract(bool& growScaleX, bool& growScaleY, bool& growScaleZ, float& scaleX, float& scaleY, float& scaleZ)
{
	if (scaleX > this -> maxX)
	{
		growScaleX = false;
	}
	else if (scaleX < this -> minX)
	{
		growScaleX = true;
	}

	if (scaleY > this -> maxY)
	{
		growScaleY = false;
	}
	else if (scaleY < this -> minY)
	{
		growScaleY = true;
	}

	if (scaleZ > this -> maxZ)
	{
		growScaleZ = false;
	}
	else if (scaleZ < this -> minZ)
	{
		growScaleZ = true;
	}
}