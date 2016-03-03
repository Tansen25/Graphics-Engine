
#ifndef SQUARE_OBJECT_H
#define SQUARE_OBJECT_H

#include "GraphicsObject.h"
#include "MathEngine\MathEngine.h"
#include "CameraManager.h"
#include "GlobalVariableManager.h"
#include "Square.h"

extern GLShaderManager shaderManager;

class SquareObject : public GraphicsObject
{
	public:
		SquareObject();

		// must define, base class has abstract methods
		void transform( void );
		void draw( void );
		void setRenderState(void);

	private:

};

#endif