
#ifndef SCENE_4_H
#define SCENE_4_H

#include "SceneBase.h"
#include "TextureManager.h"

class Scene4 : public SceneBase
{
	#define TEXTURECOUNT 3

	public:
		Scene4();

		~Scene4();
		
		void load();
		void unload();
		void update();

	private:
		const char *textureFiles[TEXTURECOUNT];

		SphereObject* s;
};

#endif