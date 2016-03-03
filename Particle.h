
#ifndef PARTICLE_H
#define PARTICLE_H

#include "OpenGLWrapper.h"
#include "MathEngine\MathEngine.h"

extern GLBatch particleBatch;

class Particle
{
	public:
		Particle();

		void draw();

		static Particle* Particle::getInstance();
			
	private:

		void createParticle();

		static Particle* Particle::privGetInstance();
};

#endif