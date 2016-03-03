
#include "UserInterface.h"

void specialKeys(int key, int x, int y)
{
	if (key == GLUT_KEY_F1)
	{
		SceneManager *sm = SceneManager::getInstance();
		sm -> unloadScene();
		sm -> nextScene();
		sm -> loadScene();
	}

	if (key == GLUT_KEY_UP)
	{
		moveCamera(NEG_X_ROT);
	}

	if (key == GLUT_KEY_DOWN)
	{
		moveCamera(POS_X_ROT);
	}

	if (key == GLUT_KEY_RIGHT)
	{
		moveCamera(POS_Y_ROT);
	}
	
	if (key == GLUT_KEY_LEFT)
	{
		moveCamera(NEG_Y_ROT);
	}

	if (key == GLUT_KEY_HOME)
	{
		moveCamera(POS_Z_ROT);
	}

	if (key == GLUT_KEY_END)
	{
		moveCamera(NEG_Z_ROT);
	}

	if (key == GLUT_KEY_PAGE_UP)
	{
		moveCamera(ZOOM_IN);
	}

	if (key == GLUT_KEY_PAGE_DOWN)
	{
		moveCamera(ZOOM_OUT);
	}

	if (key == GLUT_KEY_F12)
	{
		GlobalVariableManager* gvm = GlobalVariableManager::getInstance();

		gvm -> wireFrameModeOnOff();
	}
}

void ChangeSize(int w, int h)
{
	CameraManager *cm = CameraManager::getInstance();

	cm ->getCam1()->setViewport(0, 0, w, h);
	cm ->getCam1()->setPerspective(35.0f, float(w)/float(h), 1.0f, 500.0f);
	cm ->getCam1()->setOrientAndPosition(Vect(0.0f, 1.0f, 0.0f), Vect(0.0f, 0.0f, 0.0f), Vect(0.0f, 00.0f, 50.0f));
}

void moveCamera(CameraMovement camMov)
{
	Vect camPos;
	Vect camDir;
	Vect camLookAtPos;
	Vect camUp;

	Matrix camDirTransform(IDENTITY);
	Matrix camUpRot(IDENTITY);

	CameraManager* cm = CameraManager::getInstance();

	cm -> getCam1() -> getPos(camPos);
	cm -> getCam1() -> getLookAtPos(camLookAtPos);
	cm -> getCam1() -> getUp(camUp);

	camDir = camLookAtPos - camPos;

	switch(camMov)
	{
		case POS_X_ROT:
		{
			camDirTransform = Matrix(ROT_X, ROTATIONMULTIPLIER * MATH_PI / 180.0f);

			break;
		}

		case NEG_X_ROT:
		{
			camDirTransform = Matrix(ROT_X, ROTATIONMULTIPLIER * -MATH_PI / 180.0f);

			break;
		}
	
		case POS_Y_ROT:
		{
			camDirTransform = Matrix(ROT_Y, ROTATIONMULTIPLIER * MATH_PI / 180.0f);

			break;
		}	
	
		case NEG_Y_ROT:
		{
			camDirTransform = Matrix(ROT_Y, ROTATIONMULTIPLIER * -MATH_PI / 180.0f);

			break;
		}

		case POS_Z_ROT:
		{
			camUpRot = Matrix(ROT_Z, ROTATIONMULTIPLIER * MATH_PI / 180.0f);

			break;
		}

		case NEG_Z_ROT:
		{
			camUpRot = Matrix(ROT_Z, ROTATIONMULTIPLIER * -MATH_PI / 180.0f);

			break;
		}

		case ZOOM_IN:
		{
			camDirTransform = Matrix(SCALE, ZOOMINFACTOR, ZOOMINFACTOR, ZOOMINFACTOR);

			break;
		}

		case ZOOM_OUT:
		{
			camDirTransform = Matrix(SCALE, ZOOMOUTFACTOR, ZOOMOUTFACTOR, ZOOMOUTFACTOR);

			break;
		}

		default:
		{
			//Should never get here

			break;
		}
	}

	camDir *= camDirTransform;

	camUp *= camUpRot;

	camPos = camLookAtPos - camDir;

	cm -> getCam1() ->setOrientAndPosition(camUp, camLookAtPos, camPos);
}