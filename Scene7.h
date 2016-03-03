
#ifndef SCENE_7_H
#define SCENE_7_H

#include "SceneBase.h"
#include "ParticleEmitter.h"

class Scene7 : public SceneBase
{
	#define TEXTURECOUNT 1

	public:
		Scene7();

		~Scene7();

		void load();
		void unload();
		void update();

	private:
		const char *textureFiles[TEXTURECOUNT];

		//Objects in scene
		ParticleEmitter *p;
};

#endif