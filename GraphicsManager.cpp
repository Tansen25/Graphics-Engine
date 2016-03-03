
#include "GraphicsManager.h"
#include "GraphicsObject.h"

void GraphicsManager::addObject(GraphicsObject *p)
{
	this -> graphicsList.push_front(p);
}

void GraphicsManager::clearList()
{
	this -> graphicsList.clear();
}

void GraphicsManager::drawObjectsList()
{
	//Walk the graphics list
	std::list<GraphicsObject*>::iterator it;

	for (it = graphicsList.begin(); it != graphicsList.end(); it++)
	{
		GraphicsObject *go = *it;

		//Transform and draw the graphics object
		go -> transform();
		go -> setRenderState();
		go -> draw();
	}
}

GraphicsManager* GraphicsManager::getInstance(void)
{
	return privGetInstance();
}

GraphicsManager* GraphicsManager::privGetInstance(void)
{
	static GraphicsManager gM;
	return &gM;
}

