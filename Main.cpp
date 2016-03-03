
#include "OpenGLWrapper.h"
#include "Setup.h"
#include "Shutdown.h"

//Classes to eventually replace
GLShaderManager shaderManager;

GLBatch boxBatch;
GLBatch floorBatch;
GLBatch pyramidBatch;
GLBatch rectangleBatch;
GLBatch squareBatch;
GLBatch triangleBatch;

GLBatch particleBatch;

GLTriangleBatch cylinderBatch;
GLTriangleBatch diskBatch;
GLTriangleBatch sphereBatch;
GLTriangleBatch torusBatch;


int main(int argc, char* argv[])
{
	//Set the working directory
	gltSetWorkingDirectory(argv[0]);

	//Initialize the glut library
	glutInit(&argc, argv);

	createGraphicsWindow();

	//Initalize GLEW library
	GLenum err = glewInit();

	//Check for driver initialization failure
	if (err != GLEW_OK)
	{
		fprintf(stderr, "GLEW Error: %s\n", glewGetErrorString(err));
		
		return 1;
	}

	//Create the initial rendering context
	setupRC();

	//Main program loop
	glutMainLoop();

	shutdownRC();

	return 0;
}