#ifndef CAMERA_MANAGER_H
#define CAMERA_MANAGER_H

#include "Camera.h"
#include "MathEngine\MathEngine.h"

// forward declare (get into the habit, it's good to use
class Camera;

// Singleton
class CameraManager
{
public:
	CameraManager();

	void updateCurrentCamera();
	
	static CameraManager * getInstance( void );

	Camera *getCam1();


private:
	static CameraManager *privGetInstance();
	void initializeCameras(void);

	Camera *cam1;
	
};


#endif
