
#ifndef SCENE_6_H
#define SCENE_6_H

#include "SceneBase.h"

class Scene6 : public SceneBase
{
	#define TEXTURECOUNT 5

	public:
		Scene6();

		~Scene6();

		void load();
		void unload();
		void update();

	private:
		const char *textureFiles[TEXTURECOUNT];
		Vect colorArray[4];
		Vect colorArray1[4];

		float lightAxisRotation;

		Vect lightPos;


		//Objects in scene
		FloorObject *f;
		BoxObject *b;
		SphereObject *s;
		TorusObject *t;
};

#endif