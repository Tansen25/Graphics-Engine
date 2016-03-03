
#ifndef SCENE_BASE_H
#define SCENE_BASE_H

#include "ColorChanger.h"
#include "DissolveChanger.h"
#include "GraphicsManager.h"
#include "RotationChanger.h"
#include "ScaleChanger.h"
#include "TranslationChanger.h"
#include "BoxObject.h"
#include "CylinderObject.h"
#include "DiskObject.h"
#include "FloorObject.h"
#include "PyramidObject.h"
#include "RectangleObject.h"
#include "SphereObject.h"
#include "SquareObject.h"
#include "TorusObject.h"
#include "TriangleObject.h"
#include "TextureManager.h"

class SceneBase
{
	public:

		//Derived classes must define these
		virtual void load(void) = 0;
		virtual void unload() = 0;
		virtual void update(void) = 0;

	protected:
		//Attribute Alterators
		ColorChanger       cc;
		DissolveChanger    dc;
		RotationChanger    rc;
		ScaleChanger       sc;
		TranslationChanger tc;
};


#endif