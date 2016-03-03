#include "CameraManager.h"

CameraManager::CameraManager()
{
	initializeCameras();
}

void CameraManager::updateCurrentCamera()
{
	cam1 -> updateCamera();
}
	
CameraManager * CameraManager::getInstance( void )
{
	return privGetInstance();
}

CameraManager* CameraManager::privGetInstance()
{
	static CameraManager cm;
	return &cm;
}

Camera *CameraManager::getCam1()
{
	return cam1;
}

void CameraManager::initializeCameras(void)
{
	//1280 x 800
	
	cam1 = new Camera();
	//cam1->setViewport( 0, 0, 1280, 800);
	//cam1->setPerspective( 35.0f, float(1280)/float(800), 1.0f, 500.0f);
    //cam1->setOrientAndPosition( Vect(0,1,0), Vect(0,0,0), Vect(0,0,50) );

}