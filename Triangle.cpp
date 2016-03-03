
#include "Triangle.h"

Triangle::Triangle()
{
	//Create the triangle
	this -> createTriangle();
}

void Triangle::draw()
{
	triangleBatch.Draw();
}

Triangle* Triangle::getInstance()
{
	return privGetInstance();
}

Triangle* Triangle::privGetInstance()
{
	static Triangle t;
	return &t;
}

void Triangle::createTriangle()
{
	Vect top(0.0f, 0.866f, 0.0f);
	Vect bottomLeft(-0.5f, 0.0f, 0.0f);
	Vect bottomRight(0.5f, 0.0f, 0.0f);

	Vect frontNormal = (bottomRight - bottomLeft).cross(top - bottomRight);

	triangleBatch.Begin(GL_TRIANGLES, 3, 1);

	//Front
	//Bottom left
	triangleBatch.Normal3f(frontNormal[x], frontNormal[y], frontNormal[z]);
	triangleBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
	triangleBatch.Vertex3f(bottomLeft[x], bottomLeft[y], bottomLeft[z]);

	//Bottom right
	triangleBatch.Normal3f(frontNormal[x], frontNormal[y], frontNormal[z]);
	triangleBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	triangleBatch.Vertex3f(bottomRight[x], bottomRight[y], bottomRight[z]);

	//Top
	triangleBatch.Normal3f(frontNormal[x], frontNormal[y], frontNormal[z]);
	triangleBatch.MultiTexCoord2f(0, 0.5f, 1.0f);
	triangleBatch.Vertex3f(top[x], top[y], top[z]);

	triangleBatch.End();
}