
#ifndef PYRAMID_OBJECT_H
#define PYRAMID_OBJECT_H

#include "GraphicsObject.h"
#include "MathEngine\MathEngine.h"
#include "CameraManager.h"
#include "GlobalVariableManager.h"
#include "Pyramid.h"

extern GLShaderManager shaderManager;

class PyramidObject : public GraphicsObject
{
	public:
		PyramidObject();

		void drawWithOutlineOn();
		void drawWithOutlineOff();

		void setOutlineColor(const Vect& inColor);

		// must define, base class has abstract methods
		void transform( void );
		void draw( void );
		void setRenderState(void);

	private:
		bool drawWithOutline;
		Vect outlineColor;

		void setOutlineRenderState();

};

#endif