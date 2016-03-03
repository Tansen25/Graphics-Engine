
#ifndef RECTANGLE_OBJECT_H
#define RECTANGLE_OBJECT_H

//Gouraud Not Supported
//Phong Not Supported
//Defaults To Flat Shading

#include "GraphicsObject.h"
#include "MathEngine\MathEngine.h"
#include "CameraManager.h"
#include "GlobalVariableManager.h"
#include "Rectangle.h"

extern GLShaderManager shaderManager;

class RectangleObject : public GraphicsObject
{
	public:
		RectangleObject();

		// must define, base class has abstract methods
		void transform( void );
		void draw( void );
		void setRenderState(void);

	private:

};

#endif