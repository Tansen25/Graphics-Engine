
#include "Particle.h"

Particle::Particle()
{
	//Create the particle
	this -> createParticle();
}

void Particle::draw()
{
	particleBatch.Draw();
}

Particle* Particle::getInstance()
{
	return privGetInstance();
}

Particle* Particle::privGetInstance()
{
	static Particle t;
	return &t;
}

void Particle::createParticle()
{
	particleBatch.Begin(GL_POINTS, 1, 0);

	particleBatch.Vertex3f(0.0f, 0.0f, 0.0f);

	particleBatch.End();
}