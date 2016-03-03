
#ifndef FORCE_H
#define FORCE_H

#include "MathEngine\MathEngine.h"

class Force
{
	public:
		//Hack
		virtual Vect evaluate(const Vect &velocity, const float &airResistance, const int &activeParticeSize) = 0; 

		virtual void update() = 0;
};


#endif