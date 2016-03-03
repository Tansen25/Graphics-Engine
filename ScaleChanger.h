
#ifndef SCALE_CHANGER_H
#define SCALE_CHANGER_H

#include "MathEngine\MathEngine.h"

class ScaleChanger
{
	public:
		ScaleChanger();

		void setMinMax(float inMinX, float inMaxX, float inMinY, float inMaxY, float inMinZ, float inMaxZ);

		void setRate(float inX, float inY, float inZ);

		void constantScaleChange(float& scaleX, float& scaleY, float& scaleZ);

		void constantScaleChangeMinMax(bool& growScaleX, bool& growScaleY, bool& growScaleZ, float& scaleX, float& scaleY, float& scaleZ);

	private:
		float minX;
		float maxX;
		float minY;
		float maxY;
		float minZ;
		float maxZ;
		
		float rateX;
		float rateY;
		float rateZ;

		void determineAddSubtract(bool& growScaleX, bool& growScaleY, bool& growScaleZ, float& scaleX, float& scaleY, float& scaleZ);
};

#endif