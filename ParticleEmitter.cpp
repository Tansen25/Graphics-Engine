
#include "ParticleEmitter.h"

ParticleEmitter::ParticleEmitter(int numParticles, int particlesPerFrame, int spawnEveryXFrames)
{
	this -> randomPosition = false;
	this -> randomVelocity = false;
	this -> randomMass = false;
	
	this -> spawnCount = particlesPerFrame;

	this -> spawnPerXFrames = spawnEveryXFrames;

	this -> count = 0;
	
	this -> particleLife = 0;

	this -> posX = 0.0f;
	this -> posXVariance = 0.0f;
	this -> posY = 0.0f;
	this -> posYVariance = 0.0f;
	this -> posZ = 0.0f;
	this -> posZVariance = 0.0f;

	this -> yaw = 0.0f;
	this -> yawVariance = 0.0f;
	this -> pitch = 0.0f;
	this -> pitchVariance = 0.0f;
	this -> speed = 0.0f;
	this -> speedVariance = 0.0f;

	this -> mass = 0.0f;
	this -> massVariance = 0.0f;
	this -> calculatedMass = 0.0f;

	this -> airResistance = 0.0f;

	this -> startPos = Vect(0.0f, 0.0f, 0.0f);
	this -> startVelocity = Vect(0.0f, 0.0f, 0.0f);
	this -> startColor = Vect(0.0f, 0.0f, 0.0f);
	this -> endColor = Vect(0.0f, 0.0f, 0.0f);

	this -> spawnParticleList(numParticles);

	srand(time(NULL));
}

void ParticleEmitter::clearList()
{
	this -> activeList.clear();
	this -> inActiveList.clear();
	this -> forceList.clear();
}

void ParticleEmitter::setStartPosition(const bool &random, const int &randX, const int &randXVariance, const int &randY, const int &randYVariance,
									   const int &randZ, const int &randZVariance, const Vect &inPos)
{
	this -> randomPosition = random;

	this -> posX = randX;
	this -> posXVariance = randXVariance;
	this -> posY = randY;
	this -> posYVariance = randYVariance;
	this -> posZ = randZ;
	this -> posZVariance = randZVariance;

	this -> startPos = inPos;
}

void ParticleEmitter::setParticleLife(const int &life)
{
	this -> particleLife = life;
}

void ParticleEmitter::setStartVelocity(const bool &random, const float & randPitch, const float &randPitchVariance, const float &randYaw, 
									   const float &randYawVariance, const float &randSpeed, const float &randSpeedVariance, const Vect &inVelocity)
{
	this -> randomVelocity = random;

	this -> pitch = randPitch;

	this -> pitchVariance = randPitchVariance;

	this -> yaw = randYaw;

	this -> yawVariance = randYawVariance;

	this -> speed = randSpeed;

	this -> speedVariance = randSpeedVariance;

	this -> startVelocity = inVelocity;
}

void ParticleEmitter::setMass(const bool &random, const float &inMass, const float &randMassVariance)
{
	this -> randomMass = random;

	this -> mass = inMass;

	this -> massVariance = randMassVariance;
}

void ParticleEmitter::setStartColor(const Vect &inColor)
{
	this -> startColor = inColor;
}

void ParticleEmitter::setEndColor(const Vect &inColor)
{
	this -> endColor = inColor;
}

void ParticleEmitter::setAirResistance(const float &inResistance)
{
	this -> airResistance = inResistance;
}

void ParticleEmitter::setForcesGravity(const Vect &inGravity)
{
	Gravity *g = new Gravity();
	g -> setGravity(inGravity);

	this -> forceList.push_front(g);

	//Clean up
	g = NULL;
	delete g;
}

void ParticleEmitter::setForcesAirResistance(const bool &randomWind, const bool &calculateEveryFrame, const Vect &constantWind, const float &inRandomGustWindX, 
											 const float &inRandomGustWindXVariance, const float &inRandomGustWindY, const float &inRandomGustWindYVariance, 
											 const float &inRandomGustWindZ,const float &inRandomGustWindZVariance, const float &inRandomGustDuration, 
											 const float &inRandomGustDurationVariance, const float &inRandomGustInterval, const float &inRandomGustIntervalVariance)
{
	
	AirResistance *ar = new AirResistance();
	ar -> setConstantWind(constantWind);

	if (randomWind == true)
	{	
		ar -> setRandomGust(calculateEveryFrame, inRandomGustWindX, inRandomGustWindXVariance, inRandomGustWindY, inRandomGustWindYVariance, inRandomGustWindZ, 
							inRandomGustWindZVariance, inRandomGustDuration, inRandomGustDurationVariance, inRandomGustInterval, inRandomGustIntervalVariance);
	}

	this -> forceList.push_front(ar);

	//Clean up
	ar = NULL;
	delete ar;
}

void ParticleEmitter::updateForces()
{
	std::list<Force*>::iterator it;

	for (it = forceList.begin(); it != forceList.end(); it++)
	{
		Force *f = *it;

		//Hack
		f -> update();
	}
}

void ParticleEmitter::drawParticles()
{
	this -> spawnParticles();

	this -> updateAndDrawParticles();
}

void ParticleEmitter::spawnParticleList(int numParticles)
{
	for (int i = 0; i < numParticles; i++)
	{
		ParticleObject *p = new ParticleObject();

		this -> inActiveList.push_front(p);

		p = NULL;

		delete p;
	}
}

void ParticleEmitter::spawnParticles()
{
	
	int temp = count % spawnPerXFrames;

	if (temp == 0)
	{
	
		count = 0;

		for (int i = 0; i < spawnCount; i++)
		{
			if (inActiveList.size() > 0)
			{
				ParticleObject *po = inActiveList.front();

				//Set the particles starting position
				this -> calculateStartPosition();
				po -> setPosition(this -> startPos);

				//Set the particles life span
				po -> setLife(this -> particleLife);

				//Set the particles velocity
				this -> calculateStartVelocity();
				po -> setVelocity(this -> startVelocity);

				//set the particles mass
				this -> calculateMass();
				po -> setMass(this -> calculatedMass);

				//Set the particles start, end, and delta color
				po -> setStartColor(this -> startColor);

				po -> setEndColor(this -> endColor);

				po -> calculateDeltaColor();

				//Set the particles air resistance
				po -> setAirResistance(this -> airResistance);

				//Add particle to the active list and delete it from the inactive list
				activeList.push_front(po);
				inActiveList.pop_front();
			}
		}
	}

	count++;
}

void ParticleEmitter::calculateStartPosition()
{
	//How I am calculating the random numbers should probably be replaced with something from boost at some point
	
	if (randomPosition == true)
	{
	
		this -> startPos[x] = this -> posX + (this -> posXVariance * (float(rand()) / float(RAND_MAX / 2) - 1.0f));
		this -> startPos[y] = this -> posY + (this -> posYVariance * (float(rand()) / float(RAND_MAX / 2) - 1.0f));
		this -> startPos[z] = this -> posZ + (this -> posZVariance * (float(rand()) / float(RAND_MAX / 2) - 1.0f));

	}
}

void ParticleEmitter::calculateStartVelocity()
{
	//How I am calculating the random numbers should probably be replaced with something from boost at some point
	
	if (randomVelocity == true)
	{
		//Calculate the starting rotation
		float tempYaw = this -> yaw + (this -> yawVariance * (float(rand()) / float(RAND_MAX / 2) - 1.0f));
		float tempPitch = this -> pitch + (this -> pitchVariance * (float(rand()) / float(RAND_MAX / 2) - 1.0f));

		//Convert the rotation to a vector
		startVelocity = rotationToDirection(tempPitch, tempYaw);

		//Multiply in the speed factor
		float tempSpeed = this -> speed + (this -> speedVariance * (float(rand()) / float(RAND_MAX / 2) - 1.0f));
		startVelocity *= tempSpeed;
	}
}

void ParticleEmitter::calculateMass()
{
	//How I am calculating the random numbers should probably be replaced with something from boost at some point

	if (randomMass == true)
	{
		this -> calculatedMass = this -> mass + (this -> massVariance * (float(rand()) / float(RAND_MAX / 2) - 1.0f));

		if (calculatedMass < 0.0f)
		{
			this -> calculatedMass = 0.0f;
		}
	}
	else
	{
		this -> calculatedMass = this -> mass;
	}
}

void ParticleEmitter::updateAndDrawParticles()
{
	//Walk the active list
	std::list<ParticleObject*>::iterator it = activeList.begin();

	for (it = activeList.begin(); it != activeList.end(); it++)
	{
		ParticleObject *po = *it;
		
		//Once the particle has outlived its lifespan
		while (po -> getLife() <= 0)
		{
			//Remove particle from the active list
			it = activeList.erase(it);

			//Add particle to the inactive list
			inActiveList.push_front(po);

			if(it == activeList.end())
			{
				return;
			}

			po = *it;
		}

		//Calculate force, position, velocity, and acceleration change
		improvedEuler(po);

		//Update the particles parameters
		po -> update();

		//Draw the particle
		po -> setRenderState();
		po -> draw();
		
	}
}

//Probably should be moved to the math engine at some point
void ParticleEmitter::improvedEuler(ParticleObject *p)
{
	GlobalVariableManager* gvm = GlobalVariableManager::getInstance();

	//Get delta time
	float deltaTime = gvm -> getDeltaTime();
	
	//Calculate the acceleration now
	Vect force = Vect(0.0f, 0.0f, 0.0f);

	std::list<Force*>::iterator it;

	for (it = forceList.begin(); it != forceList.end(); it++)
	{
		Force *f = *it;

		//Hack
		force += f -> evaluate(p -> getVelocity(), p -> getAirResistance(), this -> activeList.size());
	}

	Vect acceleration;

	acceleration[x] = force[x] / p -> getMass();
	acceleration[y] = force[y] / p -> getMass();
	acceleration[z] = force[z] / p -> getMass();

	//Calculate the position after h seconds
	Vect tempPos = p -> getPosition() + p -> getVelocity() * deltaTime;
	Vect tempVel = p -> getVelocity() + acceleration * deltaTime;

	//Recalculate the force using tempVel
	force = Vect(0.0f, 0.0f, 0.0f);

	for (it = forceList.begin(); it != forceList.end(); it++)
	{
		Force *f = *it;

		force += f -> evaluate(tempVel, p -> getAirResistance(), this -> activeList.size());
	}
	
	Vect acceleration2;

	acceleration2[x] = force[x] / p -> getMass();
	acceleration2[y] = force[y] / p -> getMass();
	acceleration2[z] = force[z] / p -> getMass();

	//Use the averages of the velocity and acceleration to
	//update the original positions and velocitys
	Vect pos = p -> getPosition() + (p -> getVelocity() + tempVel) * (deltaTime / 2.0f);
	Vect vel = p -> getVelocity() + (acceleration + acceleration2) * (deltaTime / 2.0f);

	p -> setPosition(pos);
	p -> setVelocity(vel);
}

Vect ParticleEmitter::rotationToDirection(const float &pitch, const float &yaw)
{
	Vect direction;

	direction[x] = -sinf(yaw) * cosf(pitch);
	direction[y] = sinf(pitch);
	direction[z] = cosf(pitch) * cosf(yaw);

	return direction;
}