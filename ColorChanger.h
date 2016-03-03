
#ifndef COLOR_CHANGER_H
#define COLOR_CHANGER_H

#include "MathEngine\MathEngine.h"

class ColorChanger
{
	public:
		ColorChanger();

		void setRate(float inX, float inY, float inZ);

		void constantColorChange(Vect& objectColor, bool& growX, bool& growY, bool& growZ);

	private:
		float rateX;
		float rateY;
		float rateZ;

		void determineAddSubtract(Vect& objectColor, bool& growX, bool& growY, bool& growZ);

};

#endif