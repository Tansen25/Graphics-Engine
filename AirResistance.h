
#ifndef AIR_RESISTANCE_H
#define AIR_RESISTANCE_H

#include "Force.h"
#include "GlobalVariableManager.h"
#include <time.h>

class AirResistance: public Force
{
	public:
		AirResistance();

		void setConstantWind(const Vect &inWind);
		void setRandomGust(const bool &recalculateEveryFrame, const float &inRandomGustWindX, const float &inRandomGustWindXVariance,
						   const float &inRandomGustWindY, const float &inRandomGustWindYVariance, const float &inRandomGustWindZ,
						   const float &inRandomGustWindZVariance, const float &inRandomGustDuration, const float &inRandomGustDurationVariance,
						   const float &inRandomGustInterval, const float &inRandomGustIntervalVariance);

		//Hack
		Vect evaluate(const Vect &velocity, const float &airResistance, const int &activeParticleSize);

		void update();

	private:
		bool randomGust;
		bool calculateEveryFrame;

		int numberParticles;
		int currentParticle;

		float randomGustWindX;
		float randomGustWindXVariance;
		float randomGustWindY;
		float randomGustWindYVariance;
		float randomGustWindZ;
		float randomGustWindZVariance;
		float randomGustWindDuration;
		float internalRandomGustWindDuration;
		float randomGustWindDurationVariance;
		float randomGustWindInterval;
		float internalRandomGustWindInterval;
		float randomGustWindIntervalVariance;

		float durationCounter;
		float intervalCounter;

		Vect force;
		Vect randomGustWind;
		Vect constantWind;
		Vect internalWind;

		void calculateRandomVariables();
		void calculateGust();
		void calculateCounters();
		void resetCounters();


};


#endif