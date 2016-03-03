
#ifndef PARTICLE_OBJECT_H
#define PARTICLE_OBJECT_H

#include "MathEngine\MathEngine.h"
#include "CameraManager.h"
#include "GlobalVariableManager.h"
#include "Particle.h"
#include "ShaderManager.h"
#include "TextureManager.h"

class ParticleObject
{
	public:
		ParticleObject();

		int getLife();
		int getTextureID();
		float getAirResistance();
		float getMass();
		Vect getPosition();
		Vect getVelocity();
		Vect getAcceleration();
		Vect getStartColor();
		Vect getEndColor();

		void setLife(const int &inLife);
		void setTextureID(const int &inTextureID);
		void setAirResistance(const float &inAirResistance);
		void setMass(const float &inMass);
		void setPosition(const Vect &inPosition);
		void setVelocity(const Vect &inVelocity);
		void setAcceleration(const Vect &inAcceleration);
		void setStartColor(const Vect &inColor);
		void setEndColor(const Vect &inColor);

		void calculateDeltaColor();

		void update( void );
		void draw( void );
		void setRenderState(void);

	private:
		int life;
		int textureID;
		
		float airResistance;
		float mass;
		
		Vect position;
		Vect velocity;
		Vect acceleration;
		Vect startColor;
		Vect endColor;
		Vect deltaColor;
		Vect currentColor;

		Matrix modelViewProj;

};

#endif