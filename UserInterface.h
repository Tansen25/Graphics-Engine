
#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "OpenGLWrapper.h"
#include "GlobalVariableManager.h"
#include "SceneManager.h"
#include "CameraManager.h"

#define ROTATIONMULTIPLIER 10.0f
#define ZOOMINFACTOR       0.97f
#define ZOOMOUTFACTOR      1.03f

enum CameraMovement
{
	POS_X_ROT,
	NEG_X_ROT,
	POS_Y_ROT,
	NEG_Y_ROT,
	POS_Z_ROT,
	NEG_Z_ROT,
	ZOOM_IN,
	ZOOM_OUT
};

void specialKeys(int key, int x, int y);

void ChangeSize(int w, int h);

void moveCamera(CameraMovement camMov);


#endif