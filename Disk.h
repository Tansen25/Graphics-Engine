
#ifndef DISK_H
#define DISK_H

#include "OpenGLWrapper.h"

extern GLTriangleBatch diskBatch;

class Disk
{
	public:
		Disk();

		void draw();

		static Disk* getInstance(void);

	private:
		static Disk* privGetInstance();

		void createDisk();
};


#endif