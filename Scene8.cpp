

#include "OpenGLWrapper.h"
#include "Scene8.h"

Scene8::Scene8()
{
	textureFiles[0] = "star.tga";
}

Scene8::~Scene8()
{
	
}

void Scene8::load()
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
	p = new ParticleEmitter(10000, 200, 200);

	//Set starting values for each particle
	p -> setStartPosition(true, 0.0f, 300.0f, 0.0f, 200.0f, -500.0f, 300.0f, Vect(0.0f, 0.0f, 0.0f));
	p -> setParticleLife(700);
	p -> setStartVelocity(false, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, Vect(0.0f, 0.0f, 0.0f));
	p -> setMass(false, 1.0f, 0.0f);
	p -> setStartColor(Vect(1.0f, 1.0f, 1.0f));
	p -> setEndColor(Vect(1.0f, 0.5f, 0.0f));
	p -> setAirResistance(0.0f);

	//Setup forces that will act upon the particles
	p -> setForcesGravity(Vect(0.0f, 0.0f, 9.8f));
}

void Scene8::unload()
{
	//Unload all textures
	TextureManager *tm = TextureManager::getInstance();
	tm -> deleteTextures();

	//Unload objects
	p = NULL;

	delete p;
}

void Scene8::update()
{	
	p -> drawParticles();
}