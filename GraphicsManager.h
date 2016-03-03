
#ifndef GRAPHICS_MANAGER_H
#define GRAPHICS_MANAGER_H

#include <list>
#include "GraphicsObject.h"

//forward declare
class GraphicsObject;

class GraphicsManager
{
	public:

		void addObject(GraphicsObject *p);
		void clearList();
		void drawObjectsList(void);
		static GraphicsManager* getInstance(void);

	private:
		static GraphicsManager* privGetInstance();

		std::list<GraphicsObject*> graphicsList;

};


#endif