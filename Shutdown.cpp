
#include "Shutdown.h"

void shutdownRC()
{
	//Unload all loaded textures
	TextureManager *tm = TextureManager::getInstance();

	tm -> deleteTextures();
}