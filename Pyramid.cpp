
#include "Pyramid.h"

Pyramid::Pyramid()
{
	//Create the Pyramid
	this -> createPyramid();
}

void Pyramid::draw()
{
	pyramidBatch.Draw();
}

Pyramid* Pyramid::getInstance()
{
	return privGetInstance();
}

Pyramid* Pyramid::privGetInstance()
{
	static Pyramid t;
	return &t;
}

void Pyramid::createPyramid()
{
	//Vertices
	Vect apex(0.0f, 7.07f, 0.0f);
	Vect frontLeft(-5.0f, 0.0f, 5.0f);
	Vect frontRight(5.0f, 0.0f, 5.0f);
	Vect backLeft(-5.0f, 0.0f, -5.0f);
	Vect backRight(5.0f, 0.0f, -5.0f);

	//Normals
	Vect frontNormal = (frontRight - frontLeft).cross(apex - frontRight);
	Vect rightNormal = (backRight - frontRight).cross(apex - backRight);
	Vect backNormal = (backLeft - backRight).cross(apex - backLeft);
	Vect leftNormal = (frontLeft - backLeft).cross(apex - frontLeft);
	Vect bottomNormal1 = (frontLeft - frontRight).cross(backLeft - frontLeft);
	Vect bottomNormal2 = (backRight - backLeft).cross(frontRight - backRight);

	pyramidBatch.Begin(GL_TRIANGLES, 18, 1);

	//Front side of pyramid
	//Front left
	pyramidBatch.Normal3f(frontNormal[x], frontNormal[y], frontNormal[z]);
	pyramidBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
	pyramidBatch.Vertex3f(frontLeft[x], frontLeft[y], frontLeft[z]);

	//Front right
	pyramidBatch.Normal3f(frontNormal[x], frontNormal[y], frontNormal[z]);
	pyramidBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	pyramidBatch.Vertex3f(frontRight[x], frontRight[y], frontRight[z]);

	//Apex
	pyramidBatch.Normal3f(frontNormal[x], frontNormal[y], frontNormal[z]);
	pyramidBatch.MultiTexCoord2f(0, 0.5f, 1.0f);
	pyramidBatch.Vertex3f(apex[x], apex[y], apex[z]);

	//Right side of pyramid
	//Front right
	pyramidBatch.Normal3f(rightNormal[x], rightNormal[y], rightNormal[z]);
	pyramidBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
	pyramidBatch.Vertex3f(frontRight[x], frontRight[y], frontRight[z]);

	//Back right
	pyramidBatch.Normal3f(rightNormal[x], rightNormal[y], rightNormal[z]);
	pyramidBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	pyramidBatch.Vertex3f(backRight[x], backRight[y], backRight[z]);

	//Apex
	pyramidBatch.Normal3f(rightNormal[x], rightNormal[y], rightNormal[z]);
	pyramidBatch.MultiTexCoord2f(0, 0.5f, 1.0f);
	pyramidBatch.Vertex3f(apex[x], apex[y], apex[z]);

	//Back side of pyramid
	//Back right
	pyramidBatch.Normal3f(backNormal[x], backNormal[y], backNormal[z]);
	pyramidBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
	pyramidBatch.Vertex3f(backRight[x], backRight[y], backRight[z]);

	//Back left
	pyramidBatch.Normal3f(backNormal[x], backNormal[y], backNormal[z]);
	pyramidBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	pyramidBatch.Vertex3f(backLeft[x], backLeft[y], backLeft[z]);

	//Apex
	pyramidBatch.Normal3f(backNormal[x], backNormal[y], backNormal[z]);
	pyramidBatch.MultiTexCoord2f(0, 0.5f, 1.0f);
	pyramidBatch.Vertex3f(apex[x], apex[y], apex[z]);

	//Left side of pyramid
	//Back left
	pyramidBatch.Normal3f(leftNormal[x], leftNormal[y], leftNormal[z]);
	pyramidBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
	pyramidBatch.Vertex3f(backLeft[x], backLeft[y], backLeft[z]);

	//Front left
	pyramidBatch.Normal3f(leftNormal[x], leftNormal[y], leftNormal[z]);
	pyramidBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	pyramidBatch.Vertex3f(frontLeft[x], frontLeft[y], frontLeft[z]);

	//Apex
	pyramidBatch.Normal3f(backNormal[x], backNormal[y], backNormal[z]);
	pyramidBatch.MultiTexCoord2f(0, 0.5f, 1.0f);
	pyramidBatch.Vertex3f(apex[x], apex[y], apex[z]);

	//Bottom 1 of pyramid
	//Front right
	pyramidBatch.Normal3f(bottomNormal1[x], bottomNormal1[y], bottomNormal1[z]);
	pyramidBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	pyramidBatch.Vertex3f(frontRight[x], frontRight[y], frontRight[z]);

	//Front left
	pyramidBatch.Normal3f(bottomNormal1[x], bottomNormal1[y], bottomNormal1[z]);
	pyramidBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
	pyramidBatch.Vertex3f(frontLeft[x], frontLeft[y], frontLeft[z]);

	//Back left
	pyramidBatch.Normal3f(bottomNormal1[x], bottomNormal1[y], bottomNormal1[z]);
	pyramidBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	pyramidBatch.Vertex3f(backLeft[x], backLeft[y], backLeft[z]);

	//Bottom 2 of pyramid
	//Back left
	pyramidBatch.Normal3f(bottomNormal2[x], bottomNormal2[y], bottomNormal2[z]);
	pyramidBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	pyramidBatch.Vertex3f(backLeft[x], backLeft[y], backLeft[z]);

	//Back right
	pyramidBatch.Normal3f(bottomNormal2[x], bottomNormal2[y], bottomNormal2[z]);
	pyramidBatch.MultiTexCoord2f(0, 1.0f, 1.0f);
	pyramidBatch.Vertex3f(backRight[x], backRight[y], backRight[z]);

	//Front right
	pyramidBatch.Normal3f(bottomNormal2[x], bottomNormal2[y], bottomNormal2[z]);
	pyramidBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	pyramidBatch.Vertex3f(frontRight[x], frontRight[y], frontRight[z]);

	pyramidBatch.End();
}