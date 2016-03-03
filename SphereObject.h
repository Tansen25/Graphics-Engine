
#ifndef SPHERE_OBJECT_H
#define SPHERE_OBJECT_H

#include "GraphicsObject.h"
#include "MathEngine\MathEngine.h"
#include "CameraManager.h"
#include "GlobalVariableManager.h"
#include "Sphere.h"

class SphereObject : public GraphicsObject
{
	public:
		SphereObject();

		// must define, base class has abstract methods
		void transform( void );
		void draw( void );
		void setRenderState(void);

	private:
};


#endif