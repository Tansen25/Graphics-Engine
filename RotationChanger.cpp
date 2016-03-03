
#include "RotationChanger.h"

RotationChanger::RotationChanger()
{
	this -> rateX = 0.0f;
	this -> rateY = 0.0f;
	this -> rateZ = 0.0f;
}

void RotationChanger::setRate(float inX, float inY, float inZ)
{
	this -> rateX = inX;
	this -> rateY = inY;
	this -> rateZ = inZ;
}

void RotationChanger::setAxisRotationRate(float inRate)
{
	this -> rateX = inRate;
}

void RotationChanger::constantRotation(float& rotX, float& rotY, float& rotZ)
{
	rotX += this -> rateX;
	rotY += this -> rateY;
	rotZ += this -> rateZ;
}

void RotationChanger::constantAxisRotation(float &inAxisAngle)
{
	inAxisAngle += this -> rateX;
}