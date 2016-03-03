
#ifndef SCENE_10_H
#define SCENE_10_H

#include "SceneBase.h"
#include "ParticleEmitter.h"

class Scene10 : public SceneBase
{
	#define TEXTURECOUNT 1

	public:
		Scene10();

		~Scene10();

		void load();
		void unload();
		void update();

	private:
		const char *textureFiles[TEXTURECOUNT];

		//Objects in scene
		ParticleEmitter *p;
		ParticleEmitter *q;
		ParticleEmitter *r;
		ParticleEmitter *s;
};

#endif