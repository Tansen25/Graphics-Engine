
#include "GlobalVariableManager.h"

GlobalVariableManager::GlobalVariableManager()
{
	this -> wireFrameMode = false;

	this -> oldTime = 0;

	this -> timeSinceStart = 0;

	this -> wireFrameLineWidth = 2.0f;

	this -> wireFrameColor = Vect(1.0f, 0.0f, 0.0f);
}

void GlobalVariableManager::wireFrameModeOnOff()
{
	if (this -> wireFrameMode == true)
	{
		this -> wireFrameMode = false;
	}

	else
	{
		this -> wireFrameMode = true;
	}
}

bool GlobalVariableManager::getWireFrameMode()
{
	return this -> wireFrameMode;
}

float GlobalVariableManager::getDeltaTime()
{
	return this -> deltaTime / 1000.0f;
}

float GlobalVariableManager::getWireFrameLineWidth()
{
	return this -> wireFrameLineWidth;
}

Vect GlobalVariableManager::getWireFrameColor()
{
	return this -> wireFrameColor;
}

void GlobalVariableManager::updateTime()
{
	this -> timeSinceStart = glutGet(GLUT_ELAPSED_TIME);

	this -> deltaTime = this -> timeSinceStart - this -> oldTime;
	
	this -> oldTime = this -> timeSinceStart;
}

GlobalVariableManager* GlobalVariableManager::getInstance()
{
	return privGetInstance();
}

GlobalVariableManager* GlobalVariableManager::privGetInstance()
{
	static GlobalVariableManager gvm;

	return &gvm;
}