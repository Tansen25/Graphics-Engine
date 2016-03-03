
#ifndef SCENE_5_H
#define SCENE_5_H

#include "SceneBase.h"
#include "TextureManager.h"

class Scene5 : public SceneBase
{
	#define TEXTURECOUNT 3

	public:
		Scene5();

		~Scene5();
		
		void load();
		void unload();
		void update();

	private:
		const char *textureFiles[TEXTURECOUNT];

		SphereObject* s;
};

#endif