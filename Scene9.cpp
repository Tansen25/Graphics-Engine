

#include "OpenGLWrapper.h"
#include "Scene9.h"

Scene9::Scene9()
{
	textureFiles[0] = "star.tga";
}

Scene9::~Scene9()
{
	
}

void Scene9::load()
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
	p = new ParticleEmitter(10000, 100, 10);

	//Set starting values for each particle
	p -> setStartPosition(true, 0.0f, 70.0f, 25.0f, 5.0f, 0.0f, 70.0f, Vect(0.0f, 0.0f, 0.0f));
	p -> setParticleLife(150);
	p -> setStartVelocity(false, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, Vect(-20.0f, -20.0f, 0.0f));
	p -> setMass(false, 1.0f, 0.0f);
	p -> setStartColor(Vect(1.0f, 1.0f, 1.0f));
	p -> setEndColor(Vect(1.0f, 1.0f, 1.0f));
	p -> setAirResistance(1.0f);

	//Setup forces that will act upon the particles
	p -> setForcesGravity(Vect(0.0f, -9.8f, 0.0f));
	p -> setForcesAirResistance(false, false, Vect(-20.0f, -20.0f, 0.0f), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.1f, 0.0f, 0.1f, 0.0f);
}

void Scene9::unload()
{
	//Unload all textures
	TextureManager *tm = TextureManager::getInstance();
	tm -> deleteTextures();

	//Unload objects
	p = NULL;

	delete p;
}

void Scene9::update()
{	
	p -> drawParticles();
}