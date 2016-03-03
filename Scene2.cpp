
#include "Scene2.h"

Scene2::Scene2()
{
	textureFiles[0] = "Stone.tga";
	textureFiles[1] = "Brick.tga";
	textureFiles[2] = "Ceiling.tga";
	textureFiles[3] = "Floor.tga";
}

Scene2::~Scene2()
{
	delete p;
}

void Scene2::load()
{
	//Set the color used when clearing the window
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	//Graphics Manager Instance
	GraphicsManager* gm = GraphicsManager::getInstance();

	//Load textures
	TextureManager *tm = TextureManager::getInstance();

	tm -> load2DTextures(textureFiles, TEXTURECOUNT);

	//Clear the list
	gm -> clearList();

	//Scene light source
	Vect lightPos(100.0f, 100.0f, 100.0f, 1.0f);

	//Objects to be drawn
	p = new PyramidObject();
	p -> drawWithOutlineOff();
	p -> setShaderID(TEXTURE_PHONG);
	p -> setTextureID(3);
	p -> setOutlineColor(Vect(1.0f, 0.6f, 0.0f));
	p -> setLightPos(lightPos);
	p -> setAmbientColor(Vect(0.1f, 0.1f, 0.1f, 1.0f));
	p -> setDiffuseColor(Vect(1.0f, 0.5f, 0.0f, 1.0f));
	p -> setSpecularColor(Vect(1.0f, 1.0f, 1.0f, 1.0f));
	p -> setShininess(128.0f);
	p -> setScale(2.0f, 2.0f, 2.0f);
	p -> setRotationAngle(0.0f, 0.0f, 0.0f);
	p -> setTranslation(0.0f, -5.0f, 0.0f);

	gm -> addObject(p);
}

void Scene2::unload()
{
	//Unload all textures
	TextureManager *tm = TextureManager::getInstance();
	tm -> deleteTextures();

	//Clean up
	p = NULL;

	delete p;
}

void Scene2::update()
{
	float xComp;
	float yComp;
	float zComp;

	//Rotation Change
	p -> getRotationAngle(xComp, yComp, zComp);

	rc.setRate(0.0f, 0.2f, 0.0f);
	rc.constantRotation(xComp, yComp, zComp);

	p -> setRotationAngle(xComp, yComp, zComp);
}