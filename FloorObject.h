
#ifndef FLOOR_OBJECT_H
#define FLOOR_OBJECT_H

#include "GraphicsObject.h"
#include "MathEngine\MathEngine.h"
#include "CameraManager.h"
#include "GlobalVariableManager.h"
#include "Floor.h"

class FloorObject : public GraphicsObject
{
	public:
		FloorObject();

		// must define, base class has abstract methods
		void transform( void );
		void draw( void );
		void setRenderState(void);

	private:
};


#endif