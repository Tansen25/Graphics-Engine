
#include "Square.h"

Square::Square()
{
	//Create the square
	this -> createSquare();
}

void Square::draw()
{
	squareBatch.Draw();
}

Square* Square::getInstance()
{
	return privGetInstance();
}

Square* Square::privGetInstance()
{
	static Square t;
	return &t;
}

void Square::createSquare()
{
	Vect bottomLeft(-0.5f, -0.5f, 0.0f);
	Vect bottomRight(0.5f, -0.5f, 0.0f);
	Vect topLeft(-0.5f, 0.5f, 0.0f);
	Vect topRight(0.5f, 0.5f, 0.0f);

	Vect leftNormal = (bottomLeft - topLeft).cross(bottomRight - bottomLeft);
	Vect rightNormal = (topRight - bottomRight).cross(topLeft - topRight);

	leftNormal.norm();
	rightNormal.norm();

	squareBatch.Begin(GL_TRIANGLES, 6, 1);


	//Front
	//Left triangle
	//Top left
	squareBatch.Normal3f(leftNormal[x], leftNormal[y], leftNormal[z]);
	squareBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	squareBatch.Vertex3f(topLeft[x], topLeft[y], topLeft[z]);

	//Bottom left
	squareBatch.Normal3f(leftNormal[x], leftNormal[y], leftNormal[z]);
	squareBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
	squareBatch.Vertex3f(bottomLeft[x], bottomLeft[y], bottomLeft[z]);

	//Bottom right
	squareBatch.Normal3f(leftNormal[x], leftNormal[y], leftNormal[z]);
	squareBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	squareBatch.Vertex3f(bottomRight[x], bottomRight[y], bottomRight[z]);

	//Right triangle
	//Bottom right
	squareBatch.Normal3f(rightNormal[x], rightNormal[y], rightNormal[z]);
	squareBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	squareBatch.Vertex3f(bottomRight[x], bottomRight[y], bottomRight[z]);

	//Top right
	squareBatch.Normal3f(rightNormal[x], rightNormal[y], rightNormal[z]);
	squareBatch.MultiTexCoord2f(0, 1.0f, 1.0f);
	squareBatch.Vertex3f(topRight[x], topRight[y], topRight[z]);

	//Top left
	squareBatch.Normal3f(rightNormal[x], rightNormal[y], rightNormal[z]);
	squareBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	squareBatch.Vertex3f(topLeft[x], topLeft[y], topLeft[z]);
	
	squareBatch.End();
}