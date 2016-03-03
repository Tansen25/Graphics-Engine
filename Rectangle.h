
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "OpenGLWrapper.h"
#include "MathEngine\MathEngine.h"

extern GLBatch rectangleBatch;

class MyRectangle
{
	public:
		MyRectangle();

		void draw();

		static MyRectangle* getInstance(void);

	private:
		static MyRectangle* privGetInstance();

		void createRectangle();
};


#endif