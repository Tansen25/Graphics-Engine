

#include "Sphere.h"

Sphere::Sphere()
{
	//Create the Pyramid
	this -> createSphere();
}

void Sphere::draw()
{
	sphereBatch.Draw();
}

Sphere* Sphere::getInstance()
{
	return privGetInstance();
}

Sphere* Sphere::privGetInstance()
{
	static Sphere t;
	return &t;
}

void Sphere::createSphere()
{
	gltMakeSphere(sphereBatch, 1.0f, 60, 30);
}