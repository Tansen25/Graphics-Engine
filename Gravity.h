
#ifndef GRAVITY_H
#define GRAVITY_H

#include "Force.h"

class Gravity : public Force
{
	public:

		Gravity();

		void setGravity(const Vect &inGravity);

		//Hack
		Vect evaluate(const Vect &velocity, const float &airResistance, const int &activeParticleSize);

		void update();

	private:

		Vect force;

};

#endif