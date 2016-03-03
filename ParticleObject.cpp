
#include "ParticleObject.h"

ParticleObject::ParticleObject()
{
	//Default Values
	this -> life = 0;
	this -> textureID = 0;

	this -> airResistance = 0.0f;
	this -> mass = 1.0f;

	this -> position = Vect(0.0f, 0.0f, 0.0f);
	this -> velocity = Vect(0.0f, 0.0f, 0.0f);
	this -> acceleration = Vect(0.0f, 0.0f, 0.0f);
	this -> startColor = Vect(1.0f, 1.0f, 1.0f);
	this -> endColor = Vect(1.0f, 1.0f, 1.0f);
	this -> deltaColor = Vect(0.0f, 0.0f, 0.0f);
	this -> currentColor = Vect(1.0f, 1.0f, 1.0f);
}

int ParticleObject::getLife()
{
	return this -> life;
}

int ParticleObject::getTextureID()
{
	return this -> textureID;
}

float ParticleObject::getAirResistance()
{
	return this -> airResistance;
}

float ParticleObject::getMass()
{
	return this -> mass;
}

Vect ParticleObject::getPosition()
{
	return this -> position;
}

Vect ParticleObject::getVelocity()
{
	return this -> velocity;
}

Vect ParticleObject::getAcceleration()
{
	return this -> acceleration;
}

Vect ParticleObject::getStartColor()
{
	return this -> startColor;
}

Vect ParticleObject::getEndColor()
{
	return this -> endColor;
}

void ParticleObject::setLife(const int &inLife)
{
	this -> life = inLife;
}

void ParticleObject::setTextureID(const int &inTextureID)
{
	this -> textureID = inTextureID;
}

void ParticleObject::setAirResistance(const float &inAirResistance)
{
	this -> airResistance = inAirResistance;
}

void ParticleObject::setMass(const float &inMass)
{
	this -> mass = inMass;
}

void ParticleObject::setPosition(const Vect &inPosition)
{
	this -> position = inPosition;
}

void ParticleObject::setVelocity(const Vect &inVelocity)
{
	this -> velocity = inVelocity;
}

void ParticleObject::setAcceleration(const Vect &inAcceleration)
{
	this -> acceleration = inAcceleration;
}

void ParticleObject::setStartColor(const Vect &inColor)
{
	this -> startColor = inColor;
	this -> currentColor = inColor;
}

void ParticleObject::setEndColor(const Vect &inColor)
{
	this -> endColor = inColor;
}

void ParticleObject::calculateDeltaColor()
{
	deltaColor = (endColor - startColor);
	deltaColor[x] /= life;
	deltaColor[y] /= life;
	deltaColor[z] /= life;
}

void ParticleObject::update()
{
	this -> life -= 1;

	currentColor += deltaColor;

	CameraManager* cm = CameraManager::getInstance();

	//Since we are using the supplier flat shader we need to send it the
	//combined modelView and Projection Matrices
	this -> modelViewProj = cm -> getCam1() -> getViewMatrix() * cm -> getCam1() -> getProjMatrix();
}

void ParticleObject::setRenderState()
{
	CameraManager* cm = CameraManager::getInstance();
	GlobalVariableManager* gvm = GlobalVariableManager::getInstance();

	Vect temp;
	cm -> getCam1() -> getPos(temp);

	//Disable depth and stencil testing
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_STENCIL_TEST);

	//Turn on point sprites
	glEnable(GL_POINT_SPRITE);

	//Turn on additive blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);

	//Let the vertex program determine point size
	glEnable(GL_PROGRAM_POINT_SIZE);

	//Bind the texture
	TextureManager *tm = TextureManager::getInstance();
	tm -> bind2DTexture(this -> textureID);

	ShaderManager *sm = ShaderManager::getInstance();
	sm -> useParticleShader(this -> modelViewProj,
							this -> position,
							temp,
							this -> currentColor);

	
}

void ParticleObject::draw()
{
	GlobalVariableManager* gvm = GlobalVariableManager::getInstance();
	Particle* particle = Particle::getInstance();

	particle -> draw();

	//Put everything back to the default
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDisable(GL_POLYGON_OFFSET_LINE);
	glLineWidth(1.0f);
	glDisable(GL_BLEND);
	glDisable(GL_LINE_SMOOTH);
	glDisable(GL_POINT_SPRITE);
	glDisable(GL_PROGRAM_POINT_SIZE);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_STENCIL_TEST);
	
}