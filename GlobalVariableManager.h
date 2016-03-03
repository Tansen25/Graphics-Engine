
#ifndef GLOBAL_VARIABLE_MANAGER_H
#define GLOBAL_VARIABLE_MANAGER_H

#include "MathEngine\MathEngine.h"
#include "OpenGLWrapper.h"

class GlobalVariableManager
{
	public:

		void wireFrameModeOnOff();

		bool getWireFrameMode();
		float getDeltaTime();
		float getWireFrameLineWidth();
		Vect getWireFrameColor();

		void updateTime();

		static GlobalVariableManager* getInstance();

	private:
		bool wireFrameMode;
		int deltaTime;
		int oldTime;
		int timeSinceStart;
		float wireFrameLineWidth;
		Vect wireFrameColor;

		GlobalVariableManager();

		static GlobalVariableManager* privGetInstance();

};


#endif