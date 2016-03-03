

#include "OpenGLWrapper.h"
#include "Scene7.h"

Scene7::Scene7()
{
	textureFiles[0] = "star.tga";
}

Scene7::~Scene7()
{
	
}

void Scene7::load()
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
	p = new ParticleEmitter(1000, 100, 1);

	//Set starting values for each particle
	p -> setStartPosition(true, 0.0f, 1.0f, -5.0f, 1.0f, -20.0f, 2.0f, Vect(0.0f, 0.0f, -20.0f));
	p -> setParticleLife(10);
	p -> setStartVelocity(true, 0.5f, 0.0f, 0.0f, 1.0f, 20.0f, 10.0f, Vect(0.0f, 0.0f, 10.0f));
	p -> setMass(true, 1.5f, 0.5f);
	p -> setStartColor(Vect(1.0f, 1.0f, 1.0f));
	p -> setEndColor(Vect(1.0f, 0.5f, 0.0f));
	p -> setAirResistance(0.3f);

	//Setup forces that will act upon the particles
	p -> setForcesGravity(Vect(0.0f, -9.8f, 0.0f));
	p -> setForcesAirResistance(true, true, Vect(0.0f, 0.0f, 0.0f), 0.0f, 600.0f, 600.0f, 400.0f, 0.0f, 600.0f, 1.0f, 0.0f, 0.05f, 0.0f);
	p -> setForcesAirResistance(true, true, Vect(0.0f, 0.0f, 0.0f), 800.0f, 400.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.1f, 0.0f, 0.2f, 0.0f);
	p -> setForcesAirResistance(true, true, Vect(0.0f, 0.0f, 0.0f), -800.0f, 400.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.1f, 0.0f, 0.3f, 0.0f);
	p -> setForcesAirResistance(true, false, Vect(0.0f, 0.0f, 0.0f), 500.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 10.0f, 0.0f, 30.0f, 0.0f);
}

void Scene7::unload()
{
	//Unload all textures
	TextureManager *tm = TextureManager::getInstance();
	tm -> deleteTextures();

	//Unload objects
	p = NULL;

	delete p;
}

void Scene7::update()
{	
	p -> updateForces();
	
	p -> drawParticles();
}