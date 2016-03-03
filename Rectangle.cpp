
#include "Rectangle.h"

MyRectangle::MyRectangle()
{
	//Create the rectangle
	this -> createRectangle();
}

void MyRectangle::draw()
{
	rectangleBatch.Draw();
}

MyRectangle* MyRectangle::getInstance()
{
	return privGetInstance();
}

MyRectangle* MyRectangle::privGetInstance()
{
	static MyRectangle t;
	return &t;
}

void MyRectangle::createRectangle()
{
	
	Vect bottomLeft(-1.0f, -0.5f, 0.0f);
	Vect bottomRight(1.0f, -0.5f, 0.0f);
	Vect topLeft(-1.0f, 0.5f, 0.0f);
	Vect topRight(1.0f, 0.5f, 0.0f);

	Vect leftNormal = (bottomLeft - topLeft).cross(bottomRight - bottomLeft);
	Vect rightNormal = (topRight - bottomRight).cross(topLeft - topRight);

	rectangleBatch.Begin(GL_TRIANGLES, 6, 1);

	//Front
	//Left triangle
	//Top left
	rectangleBatch.Normal3f(leftNormal[x], leftNormal[y], leftNormal[z]);
	rectangleBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	rectangleBatch.Vertex3f(topLeft[x], topLeft[y], topLeft[z]);

	//Bottom left
	rectangleBatch.Normal3f(leftNormal[x], leftNormal[y], leftNormal[z]);
	rectangleBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
	rectangleBatch.Vertex3f(bottomLeft[x], bottomLeft[y], bottomLeft[z]);

	//Bottom right
	rectangleBatch.Normal3f(leftNormal[x], leftNormal[y], leftNormal[z]);
	rectangleBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	rectangleBatch.Vertex3f(bottomRight[x], bottomRight[y], bottomRight[z]);

	//Right triangle
	//Bottom right
	rectangleBatch.Normal3f(rightNormal[x], rightNormal[y], rightNormal[z]);
	rectangleBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	rectangleBatch.Vertex3f(bottomRight[x], bottomRight[y], bottomRight[z]);

	//Top right
	rectangleBatch.Normal3f(rightNormal[x], rightNormal[y], rightNormal[z]);
	rectangleBatch.MultiTexCoord2f(0, 1.0f, 1.0f);
	rectangleBatch.Vertex3f(topRight[x], topRight[y], topRight[z]);

	//Top left
	rectangleBatch.Normal3f(rightNormal[x], rightNormal[y], rightNormal[z]);
	rectangleBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	rectangleBatch.Vertex3f(topLeft[x], topLeft[y], topLeft[z]);
	
	rectangleBatch.End();
}