
#ifndef SCENE_3_H
#define SCENE_3_H

#include "SceneBase.h"
#include "TextureManager.h"

class Scene3 : public SceneBase
{
	#define TEXTURECOUNT 3

	public:
		Scene3();

		~Scene3();
		
		void load();
		void unload();
		void update();

	private:
		const char *textureFiles[TEXTURECOUNT];

		SphereObject* s;
		SphereObject* s1;
		TorusObject *t;
		TorusObject * t1;
};

#endif