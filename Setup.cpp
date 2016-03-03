

#include "Setup.h"

void createGraphicsWindow()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);

	glutInitWindowSize(1280, 800);

	glutCreateWindow("Graphics Engine");

	//Callbacks
	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(specialKeys);
	glutDisplayFunc(renderScene);

}

void setupRC()
{
	//Set the color used when clearing the window
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	//Startup shaders
	ShaderManager *sm = ShaderManager::getInstance();
	
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	//Initialize global variables
	GlobalVariableManager* gvm = GlobalVariableManager::getInstance();

	//create primitives
	Box *box = Box::getInstance();
	Cylinder *cylinder = Cylinder::getInstance();
	Disk *disk = Disk::getInstance();
	Floor *floor = Floor::getInstance();
	Pyramid* pyramid = Pyramid::getInstance();
	MyRectangle* rectangle = MyRectangle::getInstance();
	Sphere* sphere = Sphere::getInstance();
	Square* square = Square::getInstance();
	Torus *torus = Torus::getInstance();
	Triangle *triangle = Triangle::getInstance();
	Particle *particle = Particle::getInstance();

	//Test
	Scene1 *test1 = new Scene1();
	Scene2 *test2 = new Scene2();
	Scene3 *test3 = new Scene3();
	Scene4 *test4 = new Scene4();
	Scene5 *test5 = new Scene5();
	Scene6 *test6 = new Scene6();
	Scene7 *test7 = new Scene7();
	Scene8 *test8 = new Scene8();
	Scene9 *test9 = new Scene9();
	Scene10 *test10 = new Scene10();


	SceneManager *sMgr = SceneManager::getInstance();
	sMgr -> clearList();
	sMgr -> addScene(test1);
	sMgr -> addScene(test2);
	sMgr -> addScene(test3);
	sMgr -> addScene(test4);
	sMgr -> addScene(test5);
	sMgr -> addScene(test6);
	sMgr -> addScene(test7);
	sMgr -> addScene(test8);
	sMgr -> addScene(test9);
	sMgr -> addScene(test10);
	sMgr -> loadScene();

	//Clean up
	test1 = NULL;
	test2 = NULL;
	test3 = NULL;
	test4 = NULL;
	test5 = NULL;
	test6 = NULL;
	test7 = NULL;
	test8 = NULL;
	test9 = NULL;
	test10 = NULL;

	delete test1;
	delete test2;
	delete test3;
	delete test4;
	delete test5;
	delete test6;
	delete test7;
	delete test8;
	delete test9;
	delete test10;

}