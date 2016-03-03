
#ifndef SCENE_8_H
#define SCENE_8_H

#include "SceneBase.h"
#include "ParticleEmitter.h"

class Scene8 : public SceneBase
{
	#define TEXTURECOUNT 1

	public:
		Scene8();

		~Scene8();

		void load();
		void unload();
		void update();

	private:
		const char *textureFiles[TEXTURECOUNT];

		//Objects in scene
		ParticleEmitter *p;
};

#endif