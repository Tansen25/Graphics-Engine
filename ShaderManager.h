
#ifndef SHADER_MANAGER_H
#define SHADER_MANAGER_H

#include "OpenGLWrapper.h"
#include "MathEngine\MathEngine.h"

class ShaderManager
{
	public:
		ShaderManager();

		static ShaderManager *getInstance();

		void useFlatShader(Matrix &mvp, Vect &color);
		void usePointLightDiffuseShader(Matrix &mvp, Matrix &mv, Matrix &normal, Vect &color, Vect &lightPos);
		void useTexturePointLightDiffuseShader(Matrix &mvp, Matrix &mv, Matrix &normal, Vect &color, Vect &lightPos);
		void useGouraudShader(Matrix &mvp, Matrix &mv, Matrix &normal, Vect &ambientColor, Vect &diffuseColor, Vect &specularColor, float &shininess, Vect &lightPos);
		void useTextureGouraudShader(Matrix &mvp, Matrix &mv, Matrix &normal, Vect &ambientColor, Vect &diffuseColor, Vect &specularColor, float &shininess, Vect &lightPos);
		void usePhongShader(Matrix &mvp, Matrix &mv, Matrix &normal, Vect &ambientColor, Vect &diffuseColor, Vect &specularColor, float &shininess, Vect &lightPos);
		void useTexturePhongShader(Matrix &mvp, Matrix &mv, Matrix &normal, Vect &ambientColor, Vect &diffuseColor, Vect &specularColor, float &shininess, Vect &lightPos);
		void useDissolveShader(Matrix &mvp, Matrix &mv, Matrix &normal, Vect &ambientColor, Vect &diffuseColor, Vect &specularColor, float &shininess, Vect &lightPos, float &dissolveFactor);
		void useCellShader(Matrix &mvp, Matrix &mv, Matrix &normal, Vect &lightPos);
		void useParticleShader(Matrix &mvp, Vect &position, Vect &cameraPosition, Vect &color);


	private:
		GLuint flatShader;							//The flat shader
		GLuint pointLightDiffuseShader;				//The point light diffuse shader
		GLuint texturePointLightDiffuseShader;		//The texture point light diffuse shader
		GLuint gouraudShader;						//The gouraud shader
		GLuint textureGouraudShader;				//The texture gouraud shader
		GLuint phongShader;							//The phong shader
		GLuint texturePhongShader;					//The texture phong shader
		GLuint dissolveShader;						//The dissolve shader
		GLuint cellShader;							//The cell shader
		GLuint particleShader;						//The particle shader

		GLint locMVP;								//The location of the modelViewProjection matrix uniform
		GLint locMV;								//The location of the modelView matrix uniform
		GLint locNormal;							//The location of the normal matrix uniform (the rotational part of the modelView matrix)
		GLint locPosition;							//The location of the position uniform
		GLint locCameraPosition;					//The location of the camera position uniform
		GLint locColor;								//The location of the color value uniform
		GLint locAmbientColor;						//The location of the ambient color uniform
		GLint locDiffuseColor;						//The location of the diffuse color uniform
		GLint locSpecularColor;						//The location of the specular color uniform
		GLint locShininess;							//The location of the shininess uniform
		GLint locLightPos;							//The location of the light pos uniform
		GLint locTexture0;							//The location of the first texture
		GLint locDissolveFactor;					//The location of the disolve factor

		static ShaderManager *privGetInstance();

		void initializeShaders();
		void initializeFlatShader();
		void initializePointLightDiffuseShader();
		void initializeTexturePointLightDiffuseShader();
		void initializeGouraudShader();
		void initializeTextureGouraudShader();
		void initializePhongShader();
		void initializeTexturePhongShader();
		void initializeDissolveShader();
		void initializeCellShader();
		void initializeParticleShader();
};

#endif