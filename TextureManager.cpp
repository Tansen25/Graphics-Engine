
#include "TextureManager.h"

TextureManager::TextureManager()
{
	textureCount = 0;
	texture1DCount = 0;
}

void TextureManager::bind1DTexture(const int textureID)
{
	//Make sure we are binding a valid texture
	//If valid, bind texture as usual
	//If invalid, bind default texture
	if (textureID < 0 || textureID >= textureCount - 1)
	{
		glBindTexture(GL_TEXTURE_1D, textures[0]);
	}
	else
	{
		glBindTexture(GL_TEXTURE_1D, textures[0]);
	}
}

void TextureManager::bind2DTexture(const int textureID)
{
	//Make sure we are binding a valid texture
	//If valid, bind texture as usual
	//If invalid, bind default texture
	if (textureID < 0 || textureID >= textureCount - 1)
	{
		glBindTexture(GL_TEXTURE_2D, textures[0]);
	}
	else
	{
		glBindTexture(GL_TEXTURE_2D, textures[textureID + 1]);
	}
}

void TextureManager::load1DTexture(const Vect colorValues[], int arraySize)
{
	assert(arraySize == 4);
	
	this -> texture1DCount = 1;

	//Create the textureID array
	this -> textures1D = new GLuint[texture1DCount];

	//Load the color table
	this -> loadColorTable(colorValues, GL_NEAREST, GL_NEAREST, GL_CLAMP_TO_EDGE);
}

void TextureManager::load2DTextures(const char **textureFiles, int count)
{
	//Add one to the count to account for the default texture
	this -> textureCount = count + 1;

	//Create the textureID array
	this -> textures = new GLuint[textureCount];

	this -> loadTGATextures(textureFiles, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR, GL_CLAMP_TO_EDGE);
}

void TextureManager::deleteTextures()
{
	if (textureCount > 0)
	{
		glDeleteTextures(textureCount, textures);
		textureCount = 0;
		delete[] textures;
	}
	if (texture1DCount > 0)
	{
		glDeleteTextures(texture1DCount, textures1D);
		texture1DCount = 0;
		delete[] textures1D;
	}
}

TextureManager *TextureManager::getInstance()
{
	return privGetInstance();
}

TextureManager *TextureManager::privGetInstance()
{
	static TextureManager tm;
	return &tm;
}

void TextureManager::loadTGATextures(const char **textureName, GLenum minFilter, GLenum magFilter, GLenum wrapMode)
{
	GLbyte *pBits;
	int width, height, components;
	GLenum format;

	//Generate the textures
	glGenTextures(textureCount, textures);

	//Load the default texture
	this -> loadDefault2DTexture(0);

	//Load the textures
	for (int i = 1; i < textureCount; i++)
	{
		//Bind the next texture object
		glBindTexture(GL_TEXTURE_2D, textures[i]);

		//Load texture, set filter and wrap modes
		//if failure occurs, load default texture
		pBits = gltReadTGABits(textureName[i - 1], &width, &height, &components, &format);

		if (pBits == NULL)
		{
			this -> loadDefault2DTexture(i);
		}
		else
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);

			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

			glTexImage2D(GL_TEXTURE_2D, 0, components, width, height, 0, format, GL_UNSIGNED_BYTE, pBits);

			//Generate mipmaps if neccessary
			if (minFilter == GL_LINEAR_MIPMAP_LINEAR || minFilter == GL_LINEAR_MIPMAP_NEAREST
				|| minFilter == GL_NEAREST_MIPMAP_NEAREST || minFilter == GL_NEAREST_MIPMAP_NEAREST)
			{
				glGenerateMipmap(GL_TEXTURE_2D);
			}
		}

		free(pBits);

	}
};

void TextureManager::loadColorTable(const Vect colorValues[], GLenum minFilter, GLenum magFilter, GLenum wrapMode)
{
	
	//Generate the textures
	glGenTextures(textureCount, textures1D);

	//Load the color table
	//Bind the texture object
	glBindTexture(GL_TEXTURE_1D, textures1D[0]);

	//Create the table from colorValues array
	GLubyte textureData[4][3] = {   (GLubyte)colorValues[0][x], (GLubyte)colorValues[0][y], (GLubyte)colorValues[0][z],
									(GLubyte)colorValues[1][x], (GLubyte)colorValues[1][y], (GLubyte)colorValues[1][z],
									(GLubyte)colorValues[2][x], (GLubyte)colorValues[2][y], (GLubyte)colorValues[2][z],
									(GLubyte)colorValues[3][x], (GLubyte)colorValues[3][y], (GLubyte)colorValues[3][z] };

	//Load color table, set filter and wrap modes
	glTexImage1D(GL_TEXTURE_1D, 0, GL_RGB, 4, 0, GL_RGB, GL_UNSIGNED_BYTE, textureData);

	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, minFilter);
	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, magFilter);
	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, wrapMode);
}

void TextureManager::loadDefault2DTexture(const int i)
{
	GLbyte *pBits;
	int width, height, components;
	GLenum format;

	glBindTexture(GL_TEXTURE_2D, textures[i]);

	//Load texture, set filter and wrap modes
	pBits = gltReadTGABits("CheckerBoard.tga", &width, &height, &components, &format);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glTexImage2D(GL_TEXTURE_2D, 0, components, width, height, 0, format, GL_UNSIGNED_BYTE, pBits);

	//Generate mipmaps
	glGenerateMipmap(GL_TEXTURE_2D);

	delete pBits;
};