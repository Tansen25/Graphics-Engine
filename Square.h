
#ifndef SQUARE_H
#define SQUARE_H

#include "OpenGLWrapper.h"
#include "MathEngine\MathEngine.h"

extern GLBatch squareBatch;

class Square
{
	public:
		Square();

		void draw();

		static Square* getInstance(void);

	private:
		static Square* privGetInstance();

		void createSquare();
};

#endif