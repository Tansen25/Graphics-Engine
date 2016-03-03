
#ifndef ROTATION_CHANGER_H
#define ROTATION_CHANGER_H

#include "MathEngine\MathEngine.h"

class RotationChanger
{
	public:
		RotationChanger();

		void setRate(float inX, float inY, float inZ);
		void setAxisRotationRate(float inRate);

		void constantRotation(float& rotX, float& rotY, float& rotZ);
		void constantAxisRotation(float &inAxisAngle);

	private:
		float rateX;
		float rateY;
		float rateZ;

};

#endif