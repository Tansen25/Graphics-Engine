

#include "OpenGLWrapper.h"
#include "Scene10.h"

Scene10::Scene10()
{
	textureFiles[0] = "star.tga";
}

Scene10::~Scene10()
{
	
}

void Scene10::load()
{
	//Set the color used when clearing the window
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	//Graphics Manager Instance
	GraphicsManager* gm = GraphicsManager::getInstance();

	//Load textures
	TextureManager *tm = TextureManager::getInstance();
	tm -> load2DTextures(textureFiles, TEXTURECOUNT);

	//Clear the list
	gm ->clearList();

	//Create particle emitter
	p = new ParticleEmitter(200, 200, 150);

	//Set starting values for each particle
	p -> setStartPosition(false, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, Vect(-15.0f, 20.0f, -15.0f));
	p -> setParticleLife(100);
	p -> setStartVelocity(true, 0.0f, 1.5f, 0.0f, 1.5f, 10.0f, 5.0f, Vect(0.0f, 0.0f, 0.0f));
	p -> setMass(false, 1.0f, 0.0f);
	p -> setStartColor(Vect(1.0f, 0.5f, 0.0f));
	p -> setEndColor(Vect(0.3f, 0.4f, 0.7f));
	p -> setAirResistance(0.5f);

	//Setup forces that will act upon the particles
	p -> setForcesGravity(Vect(0.0f, -9.8f, 0.0f));
	p -> setForcesAirResistance(false, false, Vect(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

	q = new ParticleEmitter(200, 200, 160);

	//Set starting values for each particle
	q -> setStartPosition(false, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, Vect(0.0f, 10.0f, -100.0f));
	q -> setParticleLife(100);
	q -> setStartVelocity(true, 0.0f, 1.5f, 0.0f, 1.5f, 10.0f, 5.0f, Vect(0.0f, 0.0f, 0.0f));
	q -> setMass(false, 1.0f, 0.0f);
	q -> setStartColor(Vect(1.0f, 0.0f, 0.0f));
	q -> setEndColor(Vect(1.0f, 0.5f, 0.0f));
	q -> setAirResistance(0.5f);

	//Setup forces that will act upon the particles
	q -> setForcesGravity(Vect(0.0f, -9.8f, 0.0f));
	q -> setForcesAirResistance(false, false, Vect(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

	//Create particle emitter
	r = new ParticleEmitter(200, 200, 170);

	//Set starting values for each particle
	r -> setStartPosition(false, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, Vect(15.0f, 20.0f, -50.0f));
	r -> setParticleLife(100);
	r -> setStartVelocity(true, 0.0f, 1.5f, 0.0f, 1.5f, 10.0f, 5.0f, Vect(0.0f, 0.0f, 0.0f));
	r -> setMass(false, 1.0f, 0.0f);
	r -> setStartColor(Vect(0.0f, 0.0f, 1.0f));
	r -> setEndColor(Vect(0.0f, 0.5f, 1.0f));
	r -> setAirResistance(0.5f);

	//Setup forces that will act upon the particles
	r -> setForcesGravity(Vect(0.0f, -9.8f, 0.0f));
	r -> setForcesAirResistance(false, false, Vect(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

	s = new ParticleEmitter(200, 200, 180);

	//Set starting values for each particle
	s -> setStartPosition(false, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, Vect(5.0f, 18.0f, -60.0f));
	s -> setParticleLife(100);
	s -> setStartVelocity(true, 0.0f, 1.5f, 0.0f, 1.5f, 10.0f, 5.0f, Vect(0.0f, 0.0f, 0.0f));
	s -> setMass(false, 1.0f, 0.0f);
	s -> setStartColor(Vect(1.0f, 1.0f, 0.0f));
	s -> setEndColor(Vect(0.2f, 0.4f, 0.8f));
	s -> setAirResistance(0.5f);

	//Setup forces that will act upon the particles
	s -> setForcesGravity(Vect(0.0f, -9.8f, 0.0f));
	s -> setForcesAirResistance(false, false, Vect(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
}

void Scene10::unload()
{
	//Unload all textures
	TextureManager *tm = TextureManager::getInstance();
	tm -> deleteTextures();

	//Unload objects
	p = NULL;

	delete p;
}

void Scene10::update()
{	
	p -> drawParticles();
	q -> drawParticles();
	r -> drawParticles();
	s -> drawParticles();
}