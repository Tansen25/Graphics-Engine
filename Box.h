

#ifndef BOX_H
#define BOX_H

#include "OpenGLWrapper.h"
#include "MathEngine\MathEngine.h"

extern GLBatch boxBatch;

class Box
{
	public:
		Box();

		void draw();

		static Box* getInstance(void);

	private:
		static Box* privGetInstance();

		void createBox();
};

#endif