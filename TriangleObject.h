
#ifndef TRIANGLE_OBJECT_H
#define TRIANGLE_OBJECT_H

//Gouraud Not Supported
//Phong Not Supported
//Defaults To Flat Shading

#include "GraphicsObject.h"
#include "MathEngine\MathEngine.h"
#include "CameraManager.h"
#include "GlobalVariableManager.h"
#include "Triangle.h"

extern GLShaderManager shaderManager;

class TriangleObject : public GraphicsObject
{
	public:
		TriangleObject();

		// must define, base class has abstract methods
		void transform( void );
		void draw( void );
		void setRenderState(void);

	private:

};

#endif