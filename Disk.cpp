

#include "Disk.h"

Disk::Disk()
{
	//Create the Pyramid
	this -> createDisk();
}

void Disk::draw()
{
	diskBatch.Draw();
}

Disk* Disk::getInstance()
{
	return privGetInstance();
}

Disk* Disk::privGetInstance()
{
	static Disk t;
	return &t;
}

void Disk::createDisk()
{
	gltMakeDisk(diskBatch, 0.5f, 1.0f, 60, 30);
}