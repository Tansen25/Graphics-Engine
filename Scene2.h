
#ifndef SCENE_2_H
#define SCENE_2_H

#include "SceneBase.h"
#include "GraphicsManager.h"
#include "TriangleObject.h"
#include "ColorChanger.h"

class Scene2 : public SceneBase
{
	#define TEXTURECOUNT 4

	public:
		Scene2();

		~Scene2();

		void load();
		void unload();
		void update();

	private:
		const char *textureFiles[TEXTURECOUNT];

		//Objects in scene
		PyramidObject *p;
};


#endif