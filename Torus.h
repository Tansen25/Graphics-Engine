
#ifndef TORUS_H
#define TORUS_H

#include "OpenGLWrapper.h"

extern GLTriangleBatch torusBatch;

class Torus
{
	public:
		Torus();

		void draw();

		static Torus* getInstance(void);

	private:
		static Torus* privGetInstance();

		void createTorus();
};


#endif