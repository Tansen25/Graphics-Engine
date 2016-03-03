
#ifndef GRAPHICS_OBJECT_H
#define GRAPHICS_OBJECT_H

#include "MathEngine\MathEngine.h"
#include "TextureManager.h"
#include "ShaderManager.h"
#include <cassert>

enum shader_ID
{
	FLAT,
	POINT_LIGHT_DIFFUSE,
	TEXTURE_POINT_LIGHT_DIFFUSE,
	GOURAUD,
	TEXTURE_GOURAUD,
	PHONG,
	TEXTURE_PHONG,
	DISSOLVE,
	CELL
};

class GraphicsObject
{
	public:
		
		GraphicsObject();

		//Assessors
		void blendOn();
		void blendOff();
		void setShaderID(const shader_ID ID);
		void setColorGrow(const bool inX, const bool inY, const bool inZ);
		void setScaleGrow(const bool inX, const bool inY, const bool inZ);
		void setTranslationGrow(const bool inX, const bool inY, const bool inZ);
		void setTextureID(const int ID);
		void setStartPos(const Vect &inPos);
		void setLightPos(const Vect &inLightPos);
		void setColor(const Vect &inTriangleColor);
		void setAmbientColor(const Vect &inAmbientColor);
		void setDiffuseColor(const Vect &inDiffuseColor);
		void setSpecularColor(const Vect &inSpecularColor);
		void setShininess(const float &inShininess);
		void setOrbitAxis(const Vect &inAxis);
		void setRotAxis(const Vect &inAxis);
		void setColorArray(const Vect inArray[], int arraySize);
		void setScale(const float &inX, const float &inY, const float &inZ);
		void setAxisRotationAngle(const float &inAngle);
		void setRotationAngle(const float &inXAngle, const float &inYAngle, const float &inZAngle);
		void setOrbitAngle(const float &inAngle);
		void setTranslation(const float &inX, const float &inY, const float &inZ);
		void setOrbitTranslation(const float& inX, const float& inY, const float& inZ);
		void setDissolveFactor(const float &inDissolveFactor);

		shader_ID getShaderID();
		void getColorGrow(bool& outX, bool& outY, bool& outZ);
		void getScaleGrow(bool& outX, bool& outY, bool& outZ);
		void getTranslationGrow(bool& outX, bool& outY, bool& outZ);
		int getTextureID();
		Vect getStartPos();
		Vect getColor();
		Vect getAmbientColor();
		Vect getDiffuseColor();
		Vect getSpecularColor();
		float getShininess();
		Vect getOrbitAxis();
		Vect getRotAxis();
		void getScale(float& outX, float& outY, float& outZ);
		float getAxisRotationAngle();
		void getRotationAngle(float& outXAngle, float& outYAngle, float& outZAngle);
		float getOrbitAngle();
		void getTranslation(float& outX, float& outY, float& outZ);
		void getOrbitTranslation(float& outX, float& outY, float& outZ);
		float getDissolveFactor();

		//Must be defined by the derived classes
		virtual void transform(void) = 0;
		virtual void draw(void) = 0;
		virtual void setRenderState(void) = 0;

	private:

	protected:

		shader_ID shaderID;

		bool blend;

		bool colorGrowX;
		bool colorGrowY;
		bool colorGrowZ;

		bool scaleGrowX;
		bool scaleGrowY;
		bool scaleGrowZ;

		bool translationGrowX;
		bool translationGrowY;
		bool translationGrowZ;

		int textureID;
		
		float xScale;
		float yScale;
		float zScale;

		float xAngle;
		float yAngle;
		float zAngle;

		float axisRotAngle;
		float orbitAngle;

		float xTrans;
		float yTrans;
		float zTrans;

		float xOrbitTrans;
		float yOrbitTrans;
		float zOrbitTrans;

		float shininess;

		float dissolveFactor;

		Vect startPos;
		Vect lightPos;
		Vect transformedLightPos;
		Vect color;
		Vect ambientColor;
		Vect diffuseColor;
		Vect specularColor;
		Vect orbitAxis;
		Vect rotAxis;

		//Don't like this but it works for now
		Vect colorArray[4];

		Matrix world;
		Matrix modelView;
		Matrix modelViewProj;
		Matrix normal;  //Rotational part of the modelView matrix

};

#endif