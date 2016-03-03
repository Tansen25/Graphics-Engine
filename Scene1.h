
#ifndef SCENE_1_H
#define SCENE_1_H

#include "SceneBase.h"

class Scene1 : public SceneBase
{
	#define TEXTURECOUNT 4

	public:
		Scene1();

		~Scene1();

		void load();
		void unload();
		void update();

	private:
		const char *textureFiles[TEXTURECOUNT];

		//Objects in scene
		RectangleObject *r;
		SquareObject *s;
		TriangleObject *t;
		TriangleObject *u;
};

#endif