
#include "RenderScene.h"
#include "Triangle.h"


void renderScene()
{
	//Clear the window with the current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	
	CameraManager* cm = CameraManager::getInstance();

	cm -> updateCurrentCamera();

	SceneManager* sm = SceneManager::getInstance();

	sm -> updateScene();

	sm -> drawScene();

	//Swap current buffer with the back buffer
	glutSwapBuffers();

	glutPostRedisplay();
}