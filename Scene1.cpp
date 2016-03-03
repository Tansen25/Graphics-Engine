
#include "OpenGLWrapper.h"
#include "Scene1.h"

Scene1::Scene1()
{
	textureFiles[0] = "Stone.tga";
	textureFiles[1] = "Brick.tga";
	textureFiles[2] = "Ceiling.tga";
	textureFiles[3] = "Floor.tga";
}

Scene1::~Scene1()
{
	delete r;
	delete s;
	delete t;
	delete u;
}

void Scene1::load()
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
	Vect lightPos(100.0f, 100.0f, 100.0f);

	//Objects to be drawn
	r = new RectangleObject();
	r -> setShaderID(POINT_LIGHT_DIFFUSE);
	r -> setTextureID(1);
	r -> setLightPos(lightPos);
	r -> setAmbientColor(Vect(0.1f, 0.1f, 0.1f, 1.0f));
	r -> setDiffuseColor(Vect(1.0f, 1.0f, 1.0f, 1.0f));
	r -> setSpecularColor(Vect(1.0f, 1.0f, 1.0f, 1.0f));
	r -> setShininess(128.0f);
	r -> setScale(4.0f, 4.0f, 4.0f);
	r -> setRotationAngle(0.0f, 0.0f, 0.0f);
	r -> setTranslation(0.0f, 0.0f, 0.0f);

	s = new SquareObject();
	s -> blendOn();
	s -> setShaderID(POINT_LIGHT_DIFFUSE);
	s -> setTextureID(0);
	s -> setLightPos(lightPos);
	s -> setAmbientColor(Vect(0.1f, 0.1f, 0.1f, 1.0f));
	s -> setDiffuseColor(Vect(1.0f, 0.0f, 0.0f, 1.0f));
	s -> setSpecularColor(Vect(1.0f, 1.0f, 1.0f, 1.0f));
	s -> setShininess(128.0f);
	s -> setScale(4.0f, 4.0f, 4.0f);
	s -> setRotationAngle(0.0f, 0.0f, 0.0f);
	s -> setTranslation(0.0f, 0.0f, 1.0f);

	t = new TriangleObject();
	t -> setShaderID(POINT_LIGHT_DIFFUSE);
	t -> setTextureID(2);
	t -> setLightPos(lightPos);
	t -> setDiffuseColor(Vect(1.0f, 1.0f, 1.0f, 1.0f));
	t -> setScale(3.0f, 3.0f, 3.0f);
	t -> setRotationAngle(0.0f, 0.0f, 0.0f);
	t -> setTranslation(-10.0f, 0.0f, 0.0f);

	u = new TriangleObject();
	u -> setShaderID(POINT_LIGHT_DIFFUSE);
	u -> setTextureID(3);
	u -> setLightPos(lightPos);
	u -> setDiffuseColor(Vect(1.0f, 1.0f, 1.0f, 1.0f));
	u -> setScale(1.5f, 1.5f, 1.5f);
	u -> setRotationAngle(0.0f, 0.0f, 0.0f);
	u -> setTranslation(2.25f, 0.0f, 0.0f);

	//Add objects to the graphics list
	gm -> addObject(r);
	gm -> addObject(s);
	gm -> addObject(t);
	gm -> addObject(u);
}

void Scene1::unload()
{
	//Unload all textures
	TextureManager *tm = TextureManager::getInstance();
	tm -> deleteTextures();

	//Clean up
	r = NULL;
	s = NULL;
	t = NULL;
	u = NULL;

	delete r;
	delete s;
	delete t;
	delete u;

}

void Scene1::update()
{	
	bool growX;
	bool growY;
	bool growZ;

	float xComp;
	float yComp;
	float zComp;

	//r
	//Color Change
	Vect lightColor = r -> getColor();

	r -> getColorGrow(growX, growY, growZ);

	cc.setRate(0.001f, 0.0001f, 0.01f);
	cc.constantColorChange(lightColor, growX, growY, growZ);

	r -> setColor(lightColor);
	r -> setColorGrow(growX, growY, growZ);

	//s
	//Color Change
	lightColor = s -> getColor();

	s -> getColorGrow(growX, growY, growZ);

	cc.setRate(0.0f, 0.01f, 0.0f);
	cc.constantColorChange(lightColor, growX, growY, growZ);

	s -> setColor(lightColor);
	s -> setColorGrow(growX, growY, growZ);

	//t
	//Color Change
	lightColor = t -> getColor();
	
	t -> getColorGrow(growX, growY, growZ);

	cc.setRate(0.01f, 0.02f, 0.03f);
	cc.constantColorChange(lightColor, growX, growY, growZ);

	t -> setColor(lightColor);
	t -> setColorGrow(growX, growY, growZ);

	//Scale Change
	t -> getScaleGrow(growX, growY, growZ);
	t -> getScale(xComp, yComp, zComp);

	sc.setMinMax(0.5f, 3.0f, 0.5f, 3.0f, 0.0f, 0.0f);
	sc.setRate(0.01f, 0.01f, 0.0f);
	sc.constantScaleChangeMinMax(growX, growY, growZ, xComp, yComp, zComp);

	t -> setScaleGrow(growX, growY, growZ);
	t -> setScale(xComp, yComp, zComp);

	//Rotation Change
	t -> getRotationAngle(xComp, yComp, zComp);

	rc.setRate(0.0f, 1.0f, 0.0f);
	rc.constantRotation(xComp, yComp, zComp);

	t -> setRotationAngle(xComp, yComp, zComp);

	//Translation
	t -> getTranslationGrow(growX, growY, growZ);
	t -> getTranslation(xComp, yComp, zComp);

	tc.setRate(0.1f, 0.1f, 0.00f);
	tc.setMinMax(-24.0f, 24.0f, -17.0f, 13.0f, 0.0f, 0.0f);
	tc.constantTranslationChangeMinMax(growX, growY, growZ, xComp, yComp, zComp);

	t -> setTranslationGrow(growX, growY, growZ);
	t -> setTranslation(xComp, yComp, zComp);

	//u
	//Color Change
	lightColor = u -> getColor();

	u -> getColorGrow(growX, growY, growZ);

	cc.setRate(0.03f, 0.01f, 0.015f);
	cc.constantColorChange(lightColor, growX, growY, growZ);

	u -> setColor(lightColor);
	u -> setColorGrow(growX, growY, growZ);

	//Scale Change
	u -> getScaleGrow(growX, growY, growZ);
	u -> getScale(xComp, yComp, zComp);

	sc.setMinMax(0.5f, 3.0f, 0.5f, 3.0f, 0.0f, 0.0f);
	sc.setRate(0.01f, 0.01f, 0.0f);
	sc.constantScaleChangeMinMax(growX, growY, growZ, xComp, yComp, zComp);

	u -> setScaleGrow(growX, growY, growZ);
	u -> setScale(xComp, yComp, zComp);

	//Rotation Change
	u -> getRotationAngle(xComp, yComp, zComp);

	rc.setRate(1.0f, 0.0f, 0.0f);
	rc.constantRotation(xComp, yComp, zComp);

	u -> setRotationAngle(xComp, yComp, zComp);

	//Translation
	u -> getTranslationGrow(growX, growY, growZ);
	u -> getTranslation(xComp, yComp, zComp);

	tc.setRate(0.05f, 0.05f, 0.0f);
	tc.setMinMax(-24.0f, 24.0f, -17.0f, 13.0f, 0.0f, 0.0f);
	tc.constantTranslationChangeMinMax(growX, growY, growZ, xComp, yComp, zComp);

	u -> setTranslationGrow(growX, growY, growZ);
	u -> setTranslation(xComp, yComp, zComp);
}