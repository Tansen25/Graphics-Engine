

#include "Torus.h"

Torus::Torus()
{
	//Create the Pyramid
	this -> createTorus();
}

void Torus::draw()
{
	torusBatch.Draw();
}

Torus* Torus::getInstance()
{
	return privGetInstance();
}

Torus* Torus::privGetInstance()
{
	static Torus t;
	return &t;
}

void Torus::createTorus()
{
	gltMakeTorus(torusBatch, 1.0f, 0.1f, 60, 30);
}