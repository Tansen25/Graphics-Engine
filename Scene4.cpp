

#include "Scene4.h"

Scene4::Scene4()
{
	textureFiles[0] = "Marble.tga";
	textureFiles[1] = "MoonLike.tga";
	textureFiles[2] = "MarsLike.tga";
}

Scene4::~Scene4()
{
	delete s;
}

void Scene4::load()
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
	s -> setShaderID(TEXTURE_GOURAUD);
	s -> setTextureID(1);
	s -> setLightPos(lightPos);
	s -> setAmbientColor(Vect(0.1f, 0.1f, 0.1f, 1.0f));
	s -> setDiffuseColor(Vect(.0f, .0f, 1.0f, 1.0f));
	s -> setSpecularColor(Vect(1.0f, 1.0f, 1.0f, 1.0f));
	s -> setShininess(128.0f);
	s -> setScale(9.0f, 9.0f, 9.0f);
	s -> setRotationAngle(0.0f, 0.0f, 0.0f);
	s -> setTranslation(0.0f, 0.0f, 0.0f);
	s -> setRotAxis(Vect(0.0f, 1.0f, 0.0f));

	gm -> addObject(s);
}

void Scene4::unload()
{
	//Unload all textures
	TextureManager *tm = TextureManager::getInstance();
	tm -> deleteTextures();

	//Clean up
	s = NULL;

	delete s;
}

void Scene4::update()
{
	float xComp;

	//S
	//Axis Rotation Change
	xComp = s -> getAxisRotationAngle();

	rc.setAxisRotationRate(0.1f);
	rc.constantAxisRotation(xComp);

	s -> setAxisRotationAngle(xComp);

}