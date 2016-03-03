
#include "AirResistance.h"

AirResistance::AirResistance()
{
	this -> randomGust = false;
	this -> calculateEveryFrame = false;

	this -> numberParticles = 0;
	this -> currentParticle = 0;

	this -> randomGustWindX = 0.0f;
	this -> randomGustWindXVariance = 0.0f;
	this -> randomGustWindY = 0.0f;
	this -> randomGustWindYVariance = 0.0f;
	this -> randomGustWindZ = 0.0f;
	this -> randomGustWindZVariance = 0.0f;
	this -> randomGustWindDuration = 0.0f;
	this -> internalRandomGustWindDuration = 0.0f;
	this -> randomGustWindDurationVariance = 0.0f;
	this -> randomGustWindInterval = 0.0f;
	this -> internalRandomGustWindInterval = 0.0f;
	this -> randomGustWindIntervalVariance = 0.0f;

	this -> durationCounter = 0;
	this -> intervalCounter = 0;

	this -> force = Vect(0.0f, 0.0f, 0.0f);
	this -> constantWind = Vect(0.0f, 0.0f, 0.0f);
	this -> randomGustWind = Vect(0.0f, 0.0f, 0.0f);
	this -> internalWind = Vect(0.0f, 0.0f, 0.0f);

	srand(time(NULL));
}

void AirResistance::setConstantWind(const Vect &inWind)
{
	this -> constantWind = inWind;

	this -> internalWind = inWind;
}

void AirResistance::setRandomGust(const bool &recalculateEveryFrame, const float &inRandomGustWindX, const float &inRandomGustWindXVariance,
								  const float &inRandomGustWindY, const float &inRandomGustWindYVariance, const float &inRandomGustWindZ,
								  const float &inRandomGustWindZVariance, const float &inRandomGustDuration, const float &inRandomGustDurationVariance,
								  const float &inRandomGustInterval, const float &inRandomGustIntervalVariance)
{
	this -> randomGust = true;

	this -> calculateEveryFrame = recalculateEveryFrame;

	this -> randomGustWindX = inRandomGustWindX;
	this -> randomGustWindXVariance = inRandomGustWindXVariance;

	this -> randomGustWindY = inRandomGustWindY;
	this -> randomGustWindYVariance = inRandomGustWindYVariance;

	this -> randomGustWindZ = inRandomGustWindZ;
	this -> randomGustWindZVariance = inRandomGustWindZVariance;

	this -> randomGustWindDuration = inRandomGustDuration;
	this -> randomGustWindDurationVariance = inRandomGustDurationVariance;
	
	this -> randomGustWindInterval = inRandomGustInterval;
	this -> randomGustWindIntervalVariance = inRandomGustIntervalVariance;

	this -> calculateRandomVariables();

}

//Hack
Vect AirResistance::evaluate(const Vect &velocity, const float &airResistance, const int &activeParticleSize)
{
	//Hack
	this -> numberParticles = activeParticleSize * 2;
	
	if (randomGust == true)
	{
		this -> calculateGust();
	}

	this -> force = airResistance * (this -> internalWind - velocity);

	return force;
}

void AirResistance::update()
{
	if (calculateEveryFrame == true)
	{
		this -> calculateRandomVariables();
	}
}

void AirResistance::calculateRandomVariables()
{
	this -> randomGustWind[x] = this -> randomGustWindX + (this -> randomGustWindXVariance * (float(rand()) / float(RAND_MAX / 2) - 1.0f));
	this -> randomGustWind[y] = this -> randomGustWindY + (this -> randomGustWindYVariance * (float(rand()) / float(RAND_MAX / 2) - 1.0f));
	this -> randomGustWind[z] = this -> randomGustWindZ + (this -> randomGustWindZVariance * (float(rand()) / float(RAND_MAX / 2) - 1.0f));

	this -> internalRandomGustWindDuration = this -> randomGustWindDuration + (this -> randomGustWindDurationVariance * (float(rand()) / float(RAND_MAX / 2) - 1.0f));

	this -> internalRandomGustWindInterval = this -> randomGustWindInterval + (this -> randomGustWindIntervalVariance * (float(rand()) / float(RAND_MAX / 2) - 1.0f));
}

void AirResistance::calculateGust()
{
	if (this -> intervalCounter >= this -> internalRandomGustWindInterval && this -> durationCounter <= this -> internalRandomGustWindDuration)
	{
		this -> internalWind = this -> constantWind + this -> randomGustWind;
	}
	else
	{
		this -> internalWind = this -> constantWind;
	}

	//Hack
	this -> calculateCounters();

	this -> resetCounters();
}

//Hack
void AirResistance::calculateCounters()
{
	GlobalVariableManager *gvm = GlobalVariableManager::getInstance();
	
	this -> currentParticle++;

	if (this -> currentParticle == this -> numberParticles - 1)
	{
		if (this -> intervalCounter >= this -> internalRandomGustWindInterval && this -> durationCounter <= this -> internalRandomGustWindDuration)
		{
			this -> durationCounter += gvm -> getDeltaTime();
		}
		else
		{
			this -> intervalCounter += gvm -> getDeltaTime();
		}

		currentParticle = 0;
	}
}

void AirResistance::resetCounters()
{
	if (this -> intervalCounter >= this -> internalRandomGustWindInterval && this -> durationCounter >= this -> internalRandomGustWindDuration)
	{
		this -> intervalCounter = 0;
		this -> durationCounter = 0;
	}
}