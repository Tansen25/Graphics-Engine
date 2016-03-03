
#ifndef TORUS_OBJECT_H
#define TORUS_OBJECT_H

#include "GraphicsObject.h"
#include "MathEngine\MathEngine.h"
#include "CameraManager.h"
#include "GlobalVariableManager.h"
#include "Torus.h"

extern GLShaderManager shaderManager;

class TorusObject : public GraphicsObject
{
	public:
		TorusObject();

		// must define, base class has abstract methods
		void transform( void );
		void draw( void );
		void setRenderState(void);

	private:

};


#endif