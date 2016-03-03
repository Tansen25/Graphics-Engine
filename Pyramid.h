
#ifndef PYRAMID_H
#define PYRAMID_H

#include "OpenGLWrapper.h"
#include "MathEngine\MathEngine.h"

extern GLBatch pyramidBatch;

class Pyramid
{
	public:
		Pyramid();

		void draw();

		static Pyramid* getInstance(void);

	private:
		static Pyramid* privGetInstance();

		void createPyramid();
};

#endif