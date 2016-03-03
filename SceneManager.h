

#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <list>
#include "SceneBase.h"
#include "GraphicsManager.h"
#include "GlobalVariableManager.h"

//Forward declare
class SceneBase;

class SceneManager
{
	public:

		void addScene(SceneBase *p);
		void clearList();
		void nextScene();
		void loadScene();
		void drawScene();
		void unloadScene();
		void updateScene();
		static SceneManager *getInstance(void);

	private:
		static SceneManager *privGetInstance();
		int currentScene;
		std::list<SceneBase*> sceneList;

		SceneManager()
		{
			currentScene = 0;
		}
};



#endif