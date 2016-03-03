
#include "Gravity.h"

Gravity::Gravity()
{
	this -> force = Vect(0.0f, -9.8f, 0.0f);
}

void Gravity::setGravity(const Vect &inGravity)
{
	this -> force = inGravity;
}

//Hack
Vect Gravity::evaluate(const Vect &velocity, const float &airResistance, const int &activeParticleSize)
{
	return force;
}

void Gravity::update()
{
	//Does not need to do anything
}