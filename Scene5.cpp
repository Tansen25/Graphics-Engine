

#include "Scene5.h"

Scene5::Scene5()
{
	textureFiles[0] = "Marble.tga";
	textureFiles[1] = "MoonLike.tga";
	textureFiles[2] = "MarsLike.tga";
}

Scene5::~Scene5()
{
	delete s;
}

void Scene5::load()
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

	//Scene light source
	Vect lightPos(100.0f, 100.0f, 100.0f, 1.0f);

	//Objects to be drawn
	s = new SphereObject();
	s -> setShaderID(TEXTURE_PHONG);
	s -> setTextureID(0);
	s -> setLightPos(lightPos);
	s -> setAmbientColor(Vect(0.15f, 0.15f, 0.15f, 1.0f));
	s -> setDiffuseColor(Vect(1.0f, 0.0f, 0.0f, 1.0f));
	s -> setSpecularColor(Vect(1.0f, 1.0f, 1.0f, 1.0f));
	s -> setShininess(50.0f);
	s -> setScale(9.0f, 9.0f, 9.0f);
	s -> setRotationAngle(0.0f, 0.0f, 0.0f);
	s -> setTranslation(0.0f, 0.0f, 0.0f);
	s -> setRotAxis(Vect(0.0f, 1.0f, 0.0f));

	gm -> addObject(s);
}

void Scene5::unload()
{
	//Unload all textures
	TextureManager *tm = TextureManager::getInstance();
	tm -> deleteTextures();

	//Clean up
	s = NULL;

	delete s;
}

void Scene5::update()
{
	float xComp;

	//S
	//Axis Rotation Change
	xComp = s -> getAxisRotationAngle();

	rc.setAxisRotationRate(0.8f);
	rc.constantAxisRotation(xComp);

	s -> setAxisRotationAngle(xComp);

}