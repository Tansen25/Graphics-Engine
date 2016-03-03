
#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "OpenGLWrapper.h"
#include "MathEngine\MathEngine.h"
#include <cassert>

class TextureManager
{
	public:
		TextureManager();

		void bind1DTexture(const int textureID);
		void bind2DTexture(const int textureID);

		void load1DTexture(const Vect colorValues[], int arraySize);	//Array size muse be 4
		void load2DTextures(const char **textureFiles, int count);

		void deleteTextures();

		static TextureManager *getInstance();

	private:

		int textureCount;
		int texture1DCount;
		GLuint *textures;
		GLuint *textures1D;

		static TextureManager *privGetInstance();

		void loadColorTable(const Vect colorValues[], GLenum minFilter, GLenum magFilter, GLenum wrapMode);
		void loadTGATextures(const char **textureName, GLenum minFilter, GLenum magFilter, GLenum wrapMode);

		void loadDefault2DTexture(const int i);


};

#endif