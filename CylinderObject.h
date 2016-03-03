
#ifndef CYLINDER_OBJECT_H
#define CYLINDER_OBJECT_H

#include "GraphicsObject.h"
#include "MathEngine\MathEngine.h"
#include "CameraManager.h"
#include "GlobalVariableManager.h"
#include "Cylinder.h"

class CylinderObject : public GraphicsObject
{
	public:
		CylinderObject();

		// must define, base class has abstract methods
		void transform( void );
		void draw( void );
		void setRenderState(void);

	private:

};


#endif