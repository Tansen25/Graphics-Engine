
#ifndef PARTICLE_EMITTER_H
#define PARTICLE_EMITTER_H

#include <list>
#include "ParticleObject.h"
#include "GlobalVariableManager.h"
#include "Force.h"
#include "Gravity.h"
#include "AirResistance.h"
#include <time.h>


class ParticleEmitter
{
	public:
		ParticleEmitter(int numParticles = 100, int particlesPerFrame = 5, int spawnEveryXFrames = 1);

		void clearList();

		void setStartPosition(const bool &random, const int &randX, const int &randXVariance, const int &randY, const int &randYVariance,
							  const int &randZ, const int &randZVariance, const Vect &inPos);
		void setParticleLife(const int &life);
		void setStartVelocity(const bool &random, const float &randPitch, const float &randPitchVariance, const float &randYaw, 
			                  const float &randYawVariance, const float &randSpeed, const float &randSpeedVariance, const Vect &inVelocity);
		void setMass(const bool &random, const float &inMass, const float &randMassVariance);
		void setStartColor(const Vect &inColor);
		void setEndColor(const Vect &inColor);
		void setAirResistance(const float &inResistance);

		void setForcesGravity(const Vect &inGravity);
		void setForcesAirResistance(const bool &randomWind, const bool &calculateEveryFrame, const Vect &constantWind, const float &inRandomGustWindX, const float &inRandomGustWindXVariance,
									const float &inRandomGustWindY, const float &inRandomGustWindYVariance, const float &inRandomGustWindZ,
									const float &inRandomGustWindZVariance, const float &inRandomGustDuration, const float &inRandomGustDurationVariance,
									const float &inRandomGustInterval, const float &inRandomGustIntervalVariance);

		void updateForces();

		void drawParticles(void);

	private:
		std::list<ParticleObject*> activeList;
		std::list<ParticleObject*> inActiveList;
		std::list<Force*> forceList;

		bool randomPosition;
		bool randomVelocity;
		bool randomMass;

		int spawnCount;
		int spawnPerXFrames;  //Spawn particles every x frames
		int count;

		int particleLife;

		float posX;
		float posXVariance;
		float posY;
		float posYVariance;
		float posZ;
		float posZVariance;

		float yaw;
		float yawVariance;
		float pitch;
		float pitchVariance;
		float speed;
		float speedVariance;

		float mass;
		float massVariance;
		float calculatedMass;

		float airResistance;

		Vect startPos;
		Vect startVelocity;
		Vect startColor;
		Vect endColor;

		void spawnParticleList(int numParticles);

		void spawnParticles();

		void calculateStartPosition();

		void calculateStartVelocity();

		void calculateMass();

		void updateAndDrawParticles();

		//Probably should be moved to the math engine at some point
		void improvedEuler(ParticleObject *p);

		//This should also probably be moved to the math engine at some point
		Vect rotationToDirection(const float &pitch, const float &yaw);

};


#endif