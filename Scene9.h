
#ifndef SCENE_9_H
#define SCENE_9_H

#include "SceneBase.h"
#include "ParticleEmitter.h"

class Scene9 : public SceneBase
{
	#define TEXTURECOUNT 1

	public:
		Scene9();

		~Scene9();

		void load();
		void unload();
		void update();

	private:
		const char *textureFiles[TEXTURECOUNT];

		//Objects in scene
		ParticleEmitter *p;
};

#endif