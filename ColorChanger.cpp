
#include "ColorChanger.h"

ColorChanger::ColorChanger()
{
	this -> rateX = 0.0f;
	this -> rateY = 0.0f;
	this -> rateZ = 0.0f;
}

void ColorChanger::setRate(float inX, float inY, float inZ)
{
	this -> rateX = inX;
	this -> rateY = inY;
	this -> rateZ = inZ;
}

void ColorChanger::constantColorChange(Vect& objectColor, bool& growX, bool& growY, bool& growZ)
{
	this -> determineAddSubtract(objectColor, growX, growY, growZ);

	if (growX)
	{
		objectColor[X] += this -> rateX;
	}
	else
	{
		objectColor[X] -= this -> rateX;
	}

	if (growY)
	{
		objectColor[Y] += this -> rateY;
	}
	else
	{
		objectColor[Y] -= this -> rateY;
	}

	if (growZ)
	{
		objectColor[Z] += this -> rateZ;
	}
	else
	{
		objectColor[Z] -= this -> rateZ;
	}
}

void ColorChanger::determineAddSubtract(Vect& objectColor, bool& growX, bool& growY, bool& growZ)
{
	//Hard set numbers - might change in the future
	if (objectColor[X] > 1.0f)
	{
		growX = false;
	}
	else if (objectColor[X] < 0.0f)
	{
		growX = true;
	}

	if (objectColor[Y] > 1.0f)
	{
		growY = false;
	}
	else if (objectColor[Y] < 0.0f)
	{
		growY = true;
	}

	if (objectColor[Z] > 1.0f)
	{
		growZ = false;
	}
	else if (objectColor[Z] < 0.0f)
	{
		growZ = true;
	}
}