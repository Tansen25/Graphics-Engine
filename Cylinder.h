
#ifndef Cylinder_H
#define Cylinder_H

#include "OpenGLWrapper.h"

extern GLTriangleBatch cylinderBatch;

class Cylinder
{
	public:
		Cylinder();

		void draw();

		static Cylinder* getInstance(void);

	private:
		static Cylinder* privGetInstance();

		void createCylinder();
};


#endif