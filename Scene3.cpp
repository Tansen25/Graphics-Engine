
#include "Scene3.h"

Scene3::Scene3()
{
	textureFiles[0] = "Marble.tga";
	textureFiles[1] = "MoonLike.tga";
	textureFiles[2] = "MarsLike.tga";
}

Scene3::~Scene3()
{
	delete s;
	delete s1;
	delete t;
	delete t1;
}

void Scene3::load()
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
	s -> setTextureID(2);
	s -> setLightPos(lightPos);
	s -> setAmbientColor(Vect(0.1f, 0.1f, 0.1f, 0.1f));
	s -> setDiffuseColor(Vect(1.0f, 1.0f, 1.0f, 1.0f));
	s -> setSpecularColor(Vect(1.0f, 1.0f, 1.0f, 1.0f));
	s -> setShininess(20.0f);
	s -> setScale(3.0f, 3.0f, 3.0f);
	s -> setRotationAngle(90.0f, 0.0f, 45.0f);
	s -> setTranslation(0.0f, 0.0f, 0.0f);
	s -> setRotAxis(Vect(-1.0f, 1.0f, 0.0f));

	s1 = new SphereObject();
	s1 -> setShaderID(TEXTURE_PHONG);
	s1 -> setTextureID(1);
	s1 -> setLightPos(lightPos);
	s1 -> setAmbientColor(Vect(0.1f, 0.1f, 0.1f, 0.1f));
	s1 -> setDiffuseColor(Vect(0.7f, 0.9f, 0.2f, 1.0f));
	s1 -> setSpecularColor(Vect(1.0f, 1.0f, 1.0f, 1.0f));
	s1 -> setShininess(20.0f);
	s1 -> setScale(1.5f, 1.5f, 1.5f);
	s1 -> setRotationAngle(0.0f, 0.0f, 0.0f);
	s1 -> setTranslation(0.0f, 0.0f, 0.0f);
	s1 -> setOrbitTranslation(10.0f, 10.0f, 0.0f);
	s1 -> setOrbitAxis(Vect(-1.0f, 1.0f, 0.0f));

	t = new TorusObject();
	t -> setShaderID(TEXTURE_PHONG);
	t -> setTextureID(0);
	t -> setLightPos(lightPos);
	t -> setAmbientColor(Vect(0.1f, 0.1f, 0.1f, 0.1f));
	t -> setDiffuseColor(Vect(1.0f, 0.5f, 0.0f, 1.0f));
	t -> setSpecularColor(Vect(1.0f, 1.0f, 1.0f, 1.0f));
	t -> setShininess(20.0f);
	t -> setScale(5.0f, 5.0f, 5.0f);
	t -> setRotationAngle(0.0f, 90.0f, 45.0f);
	t -> setTranslation(0.0f, 0.0f, 0.0f);
	t -> setRotAxis(Vect(0.0f, 0.0f, 1.0f));

	t1 = new TorusObject();
	t1 -> setShaderID(TEXTURE_PHONG);
	t1 -> setTextureID(0);
	t1 -> setLightPos(lightPos);
	t1 -> setAmbientColor(Vect(0.1f, 0.1f, 0.1f, 0.1f));
	t1 -> setDiffuseColor(Vect(1.0f, 1.0f, 1.0f, 1.0f));
	t1 -> setSpecularColor(Vect(1.0f, 1.0f, 1.0f, 1.0f));
	t1 -> setShininess(20.0f);
	t1 -> setScale(6.5f, 6.5f, 6.5f);
	t1 -> setRotationAngle(0.0f, 45.0f, 45.0f);
	t1 -> setTranslation(0.0f, 0.0f, 0.0f);
	t1 -> setRotAxis(Vect(-1.0f, 1.0f, 0.0f));

	gm -> addObject(s);
	gm -> addObject(s1);
	gm -> addObject(t);
	gm -> addObject(t1);
}

void Scene3::unload()
{
	//Unload all textures
	TextureManager *tm = TextureManager::getInstance();
	tm -> deleteTextures();

	//Clean up
	s = NULL;
	s1 = NULL;
	t = NULL;
	t1 = NULL;

	delete s;
	delete s1;
	delete t;
	delete t1;
}

void Scene3::update()
{
	bool growX;
	bool growY;
	bool growZ;
	
	float xComp;
	float yComp;
	float zComp;

	//S
	//Axis Rotation Change
	xComp = s -> getAxisRotationAngle();

	rc.setAxisRotationRate(0.5f);
	rc.constantAxisRotation(xComp);

	s -> setAxisRotationAngle(xComp);

	//Translation Change
	s -> getTranslationGrow(growX, growY, growZ);
	s -> getTranslation(xComp, yComp, zComp);

	tc.setRate(0.1f, 0.0f, 0.0f);
	tc.setMinMax(-22.0f, 22.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	tc.constantTranslationChangeMinMax(growX, growY, growZ, xComp, yComp, zComp);

	s -> setTranslationGrow(growX, growY, growZ);
	s -> setTranslation(xComp, yComp, zComp);

	//S1
	//Starting Position Change - Slaved to S
	s -> getTranslation(xComp, yComp, zComp);
	s1 -> setStartPos(s -> getStartPos() + Vect(xComp, yComp, zComp));

	//Rotation Change
	s1 -> getRotationAngle(xComp, yComp, zComp);

	rc.setRate(0.0f, 0.3f, 0.0f);
	rc.constantRotation(xComp, yComp, zComp);

	s1 -> setRotationAngle(xComp, yComp, zComp);

	//Orbit Change
	xComp = s1 -> getOrbitAngle();

	rc.setAxisRotationRate(0.8f);
	rc.constantAxisRotation(xComp);

	s1 -> setOrbitAngle(xComp);

	//t
	//Starting Position Change - Slaved to S
	s -> getTranslation(xComp, yComp, zComp);
	t -> setStartPos(s -> getStartPos() + Vect(xComp, yComp, zComp));

	//Axis Rotation Change
	xComp = t -> getAxisRotationAngle();

	rc.setAxisRotationRate(4.0f);
	rc.constantAxisRotation(xComp);

	t -> setAxisRotationAngle(xComp);

	//t1
	//Starting Position Change - Slaved to S
	s -> getTranslation(xComp, yComp, zComp);
	t1 -> setStartPos(s -> getStartPos() + Vect(xComp, yComp, zComp));

	//Axis Rotation Change
	xComp = t1 -> getAxisRotationAngle();

	rc.setAxisRotationRate(2.0f);
	rc.constantAxisRotation(xComp);

	t1 -> setAxisRotationAngle(xComp);
}