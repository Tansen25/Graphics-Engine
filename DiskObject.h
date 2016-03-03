
#ifndef DISK_OBJECT_H
#define DISK_OBJECT_H

#include "GraphicsObject.h"
#include "MathEngine\MathEngine.h"
#include "CameraManager.h"
#include "GlobalVariableManager.h"
#include "Disk.h"

extern GLShaderManager shaderManager;

class DiskObject : public GraphicsObject
{
	public:
		DiskObject();

		// must define, base class has abstract methods
		void transform( void );
		void draw( void );
		void setRenderState(void);

	private:

};


#endif