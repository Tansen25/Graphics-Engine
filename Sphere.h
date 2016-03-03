
#ifndef SPHERE_H
#define SPHERE_H

#include "OpenGLWrapper.h"

extern GLTriangleBatch sphereBatch;

class Sphere
{
	public:
		Sphere();

		void draw();

		static Sphere* getInstance(void);

	private:
		static Sphere* privGetInstance();

		void createSphere();
};


#endif