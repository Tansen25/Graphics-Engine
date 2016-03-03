
#ifndef FLOOR_H
#define FLOOR_H

#include "OpenGLWrapper.h"
#include "MathEngine\MathEngine.h"

extern GLBatch floorBatch;

class Floor
{
	public:
		Floor();

		void draw();

		static Floor* getInstance(void);

	private:
		static Floor* privGetInstance();

		void createFloor();
};


#endif