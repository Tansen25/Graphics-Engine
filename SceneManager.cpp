
#include "SceneManager.h"

void SceneManager::addScene(SceneBase *p)
{
	this -> sceneList.push_back(p);
}

void SceneManager::clearList()
{
	this -> sceneList.clear();
}

void SceneManager::nextScene()
{
	if (currentScene < this -> sceneList.size() - 1)
	{
		currentScene++;
	}
	else
	{
		//Wrap around back to the first scene
		currentScene = 0;
	}
}

void SceneManager::loadScene()
{
	std::list<SceneBase*>::iterator it;
	int count = 0;

	for(it = sceneList.begin(); it != sceneList.end(); it++)
	{
		if (count == currentScene)
		{
			break;
		}
		else
		{
			count++;
		}
	}

	SceneBase *sb = *it;

	sb -> load();
}

void SceneManager::drawScene()
{
	GraphicsManager* gm = GraphicsManager::getInstance();

	gm -> drawObjectsList();
}

void SceneManager::unloadScene()
{
	std::list<SceneBase*>::iterator it;
	int count = 0;

	for(it = sceneList.begin(); it != sceneList.end(); it++)
	{
		if (count == currentScene)
		{
			break;
		}
		else
		{
			count++;
		}
	}

	SceneBase *sb = *it;

	sb -> unload();
}

void SceneManager::updateScene()
{
	std::list<SceneBase*>::iterator it;
	int count = 0;

	for(it = sceneList.begin(); it != sceneList.end(); it++)
	{
		if (count == currentScene)
		{
			break;
		}
		else
		{
			count++;
		}
	}

	SceneBase *sb = *it;

	//Update the time
	GlobalVariableManager* gvm = GlobalVariableManager::getInstance();
	gvm -> updateTime();

	sb -> update();
}

SceneManager *SceneManager::getInstance(void)
{
	return privGetInstance();
}

SceneManager *SceneManager::privGetInstance(void)
{
	static SceneManager sm;
	return &sm;
}

