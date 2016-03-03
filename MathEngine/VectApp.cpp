#include "MathApp.h"

void VectApp::Lerp( Vect &out, const Vect &a, const Vect &b,  const float t )
{
	out = a + t * (b - a);
}

void VectApp::LerpArray(Vect *out, const Vect *a, const Vect *b,   const float t, const int numVects )
{
	for (int i = 0; i < numVects; i++)
	{
		out[i] = a[i] + t * (b[i] - a[i]);
	}
}