

#ifndef BOX_OBJECT_H
#define BOX_OBJECT_H

#include "GraphicsObject.h"
#include "MathEngine\MathEngine.h"
#include "CameraManager.h"
#include "GlobalVariableManager.h"
#include "Box.h"

class BoxObject : public GraphicsObject
{
	public:
		BoxObject();

		// must define, base class has abstract methods
		void transform( void );
		void draw( void );
		void setRenderState(void);

	private:

};

#endif