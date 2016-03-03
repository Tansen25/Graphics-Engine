

#include "OpenGLWrapper.h"
#include "Scene6.h"

Scene6::Scene6()
{
	textureFiles[0] = "Stone.tga";
	textureFiles[1] = "Brick.tga";
	textureFiles[2] = "Ceiling.tga";
	textureFiles[3] = "Floor.tga";
	textureFiles[4] = "Marble.tga";
	
	colorArray[0]  = Vect(32, 0, 0);
	colorArray[1]  = Vect(64, 0, 0);
	colorArray[2]  = Vect(128, 0, 0);
	colorArray[3]  = Vect(255, 0, 0);
				   
	colorArray1[0]  = Vect(0, 32, 0);
	colorArray1[1]  = Vect(0, 64, 0);
	colorArray1[2]  = Vect(0, 128, 0);
	colorArray1[3]  = Vect(0, 255, 0);

	//Scene light source
	lightPos = Vect(000.0f, 100.0f, 000.0f);

	lightAxisRotation = 0.0f;
}

Scene6::~Scene6()
{
	printf ("Hello");
}

void Scene6::load()
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

	//Objects to be drawn
	f = new FloorObject();
	f -> setShaderID(TEXTURE_PHONG);
	f -> setTextureID(1);
	f -> setLightPos(lightPos);
	f -> setAmbientColor(Vect(0.15f, 0.15f, 0.15f, 1.0f));
	f -> setDiffuseColor(Vect(1.0f, 1.0f, 1.0f, 1.0f));
	f -> setSpecularColor(Vect(1.0f, 1.0f, 1.0f, 1.0f));
	f -> setShininess(128.0);
	f -> setScale(2.0f, 2.0f, 2.0f);
	f -> setRotationAngle(0.0f, -45.0f, 0.0f);
	f -> setTranslation(0.0f, 0.0f, 0.0f);
	f -> setRotAxis(Vect(0.0f, 1.0f, 0.0f));

	b = new BoxObject();
	b -> setShaderID(TEXTURE_PHONG);
	b -> setTextureID(0);
	b -> setLightPos(lightPos);
	b -> setAmbientColor(Vect(0.15f, 0.15f, 0.15f, 1.0f));
	b -> setDiffuseColor(Vect(1.0f, 1.0f, 1.0f, 1.0f));
	b -> setSpecularColor(Vect(1.0f, 1.0f, 1.0f, 1.0f));
	b -> setShininess(128.0);
	b -> setScale(10.0f, 10.0f, 10.0f);
	b -> setRotationAngle(0.0f, 45.0f, 0.0f);
	b -> setTranslation(0.0f, 5.0f, 0.0f);
	b -> setRotAxis(Vect(0.0f, 1.0f, 0.0f));

	s = new SphereObject();
	s -> setShaderID(TEXTURE_PHONG);
	s -> setTextureID(4);
	s -> setLightPos(lightPos);
	s -> setAmbientColor(Vect(0.15f, 0.15f, 0.15f, 1.0f));
	s -> setDiffuseColor(Vect(1.0f, 1.0f, 1.0f, 1.0f));
	s -> setSpecularColor(Vect(1.0f, 1.0f, 1.0f, 1.0f));
	s -> setShininess(128.0);
	s -> setStartPos(Vect(0.0f, 20.0f, 0.0f));
	s -> setScale(5.0f, 5.0f, 5.0f);
	s -> setRotationAngle(0.0f, 0.0f, 0.0f);
	s -> setTranslation(0.0f, 0.0f, 0.0f);
	b -> setRotAxis(Vect(0.0f, 1.0f, 0.0f));

	t = new TorusObject();
	t -> setShaderID(TEXTURE_PHONG);
	t -> setTextureID(2);
	t -> setLightPos(lightPos);
	t -> setAmbientColor(Vect(0.15f, 0.15f, 0.15f, 1.0f));
	t -> setDiffuseColor(Vect(1.0f, 1.0f, 1.0f, 1.0f));
	t -> setSpecularColor(Vect(1.0f, 1.0f, 1.0f, 1.0f));
	t -> setShininess(128.0);
	t -> setStartPos(s -> getStartPos());
	t -> setScale(7.0f, 7.0f, 7.0f);
	t -> setRotationAngle(0.0f, 0.0f, 0.0f);
	t -> setTranslation(0.0f, 0.0f, 0.0f);
	t -> setRotAxis(Vect(1.0f, 0.0f, 0.0f));

	gm -> addObject(f);
	gm -> addObject(b);
	gm -> addObject(s);
	gm -> addObject(t);

	//Setup the camera
	CameraManager *cm = CameraManager::getInstance();

	cm ->getCam1()->setOrientAndPosition(Vect(0.0f, 1.0f, 0.0f), Vect(0.0f, 15.0f, 0.0f), Vect(0.0f, 35.0f, 55.0f));
}

void Scene6::unload()
{
	//Unload all textures
	TextureManager *tm = TextureManager::getInstance();
	tm -> deleteTextures();

	//Unload objects
	f = NULL;
	b = NULL;
	s = NULL;
	t = NULL;

	delete f;
	delete b;
	delete s;
	delete t;

	//Reset the camera
	CameraManager *cm = CameraManager::getInstance();

	cm ->getCam1()->setOrientAndPosition(Vect(0.0f, 1.0f, 0.0f), Vect(0.0f, 0.0f, 0.0f), Vect(0.0f, 00.0f, 50.0f));
}

void Scene6::update()
{	
	bool growX = true;
	bool growY = true;
	bool growZ = true;
	
	float xComp = 0.0f;
	float yComp = 0.0f;
	float zComp = 0.0f;

	//Hack to get the light to move around - Need to make somesort of light object
	//at some point
	Vect rotAxis = Vect(0.0f, 0.0f, 1.0f);

	lightAxisRotation += 0.5f;

	Matrix axisRot(IDENTITY);
	axisRot.set(ROT_AXIS_ANGLE, rotAxis, this -> lightAxisRotation * MATH_PI / 180.0f);

	lightPos = Vect(000.0f, 100.0f, 000.0f);

	lightPos *= axisRot;

	//f
	//Set the light
	f -> setLightPos(lightPos);

	//b
	//Set the light
	b -> setLightPos(lightPos);

	//S
	//Set the light
	s -> setLightPos(lightPos);

	//Axis Rotation Change
	xComp = s -> getAxisRotationAngle();

	rc.setAxisRotationRate(0.5f);
	rc.constantAxisRotation(xComp);

	s -> setAxisRotationAngle(xComp);

	//Translation Change
	s -> getTranslationGrow(growX, growY, growZ);
	s -> getTranslation(xComp, yComp, zComp);

	tc.setRate(0.0f, 0.1f, 0.0f);
	tc.setMinMax(0.0f, 0.0f, -2.0f, 6.0f, 0.0f, 0.0f);
	tc.constantTranslationChangeMinMax(growX, growY, growZ, xComp, yComp, zComp);

	s -> setTranslationGrow(growX, growY, growZ);
	s -> setTranslation(xComp, yComp, zComp);

	//T
	//Set the light
	t -> setLightPos(lightPos);

	//Starting Position Change
	s -> getTranslation(xComp, yComp, zComp);

	t -> setTranslation(xComp, yComp, zComp);

	//Axis Rotation Change
	xComp = t -> getAxisRotationAngle();

	rc.setAxisRotationRate(1.5f);
	rc.constantAxisRotation(xComp);

	t -> setAxisRotationAngle(xComp);
}