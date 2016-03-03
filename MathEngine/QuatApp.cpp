#include "MathApp.h"
#include <math.h>
#include "Util.h"
#include "Constants.h"

void QuatApp::Slerp( Quat &result, const Quat &source, const Quat &target, const float slerpFactor )
{
	Quat temp = target;
	
	float tmpCos = source[x] * target[x] + source[y] * target[y] + source[z] * target[z] + source[w] * target[w];

	if (tmpCos < 0.0f)
	{
		tmpCos = -tmpCos;

		temp = -temp;
	}

	if (tmpCos > 1.0f && tmpCos > 1.00000000001)
	{
		tmpCos = 0.99999994f;
	}

	float phi = acosf(tmpCos);

	if (phi == 0)
	{
		result[x] = 0.0f;
		result[y] = 0.0f;
		result[z] = 0.0f;
		result[w] = 0.0f;
	}

	else
	{
		result = source * (sinf((1 - slerpFactor) * phi) / sinf(phi)) + temp * (sinf(slerpFactor * phi) / sinf(phi));
	}
}

void QuatApp::SlerpArray( Quat *result, const Quat *source, const Quat *target, const float slerpFactor, const int numQuats )
{
	for (int i = 0; i < numQuats; i++)
	{
		Slerp(result[i], source[i], target[i], slerpFactor);
	}
}