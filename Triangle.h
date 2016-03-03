
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "OpenGLWrapper.h"
#include "MathEngine\MathEngine.h"

extern GLBatch triangleBatch;

class Triangle
{
	public:
		Triangle();

		void draw();

		static Triangle* getInstance(void);

	private:
		static Triangle* privGetInstance();

		void createTriangle();


};


#endif