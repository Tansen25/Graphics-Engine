
#include "DissolveChanger.h"

DissolveChanger::DissolveChanger()
{

}

void DissolveChanger::reset()
{
	timer.Reset();
}

void DissolveChanger::constantDissolveChange(float &dissolveFactor, float rate, float maxDissolve)
{
	assert(maxDissolve >= 0.0 && maxDissolve <= 1.0f);
	
	dissolveFactor = timer.GetElapsedSeconds() / rate;

	if (dissolveFactor >= maxDissolve)
	{
		this -> reset();
	}
}