
#ifndef TRANSLATION_CHANGER_H
#define TRANSLATION_CHANGER_H

#include "MathEngine\MathEngine.h"

class TranslationChanger
{
	public:
		TranslationChanger();

		void setMinMax(float inMinX, float inMaxX, float inMinY, float inMaxY, float inMinZ, float inMaxZ);

		void setRate(float inX, float inY, float inZ);

		void constantTranslationChange(float& translationX, float& translationY, float& translationZ);

		void constantTranslationChangeMinMax(bool& translationGrowX, bool& translationGrowY, bool& translationGrowZ, 
										     float& translationX, float& translationY, float& translationZ);

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

		void determineAddSubtract(bool& translationGrowX, bool& translationGrowY, bool& translationGrowZ, 
								  float& translationX, float& translationY, float& translationZ);

};

#endif