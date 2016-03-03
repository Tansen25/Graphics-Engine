
#ifndef DISSOLVE_CHANGER_H
#define DISSOLVE_CHANGER_H

#include "StopWatch.h"
#include <cassert>

//maxDissolve must be between 0.0f and 1.0f

class DissolveChanger
{
	public:
	
		DissolveChanger();

		void reset();

		void constantDissolveChange(float &dissolveFactor, float rate, float maxDissolve);

	private:
		CStopWatch timer; //Hack until I build my own timer

};


#endif