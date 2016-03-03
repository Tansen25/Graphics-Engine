

#include "Cylinder.h"

Cylinder::Cylinder()
{
	//Create the cylinder
	this -> createCylinder();
}

void Cylinder::draw()
{
	cylinderBatch.Draw();
}

Cylinder* Cylinder::getInstance()
{
	return privGetInstance();
}

Cylinder* Cylinder::privGetInstance()
{
	static Cylinder t;
	return &t;
}

void Cylinder::createCylinder()
{
	gltMakeCylinder(cylinderBatch, 0.5f, 0.5f, 4.0f, 60, 30);
}