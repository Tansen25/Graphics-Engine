

#include "Floor.h"

Floor::Floor()
{
	//Create the floor
	this -> createFloor();
}

void Floor::draw()
{
	floorBatch.Draw();
}

Floor* Floor::getInstance()
{
	return privGetInstance();
}

Floor* Floor::privGetInstance()
{
	static Floor t;
	return &t;
}

void Floor::createFloor()
{
	int height = 20;
	int width = 20;

	int i = 0;
	int j = 0;

	float texIncrementHeight = 1.0f / (float)height;
	float texIncrementWidth = 1.0f / (float)width;
	
	Vect bottomLeft(-10.0f, 0.0f, 10.0f);
	Vect bottomRight(10.0f, 0.0f, 10.0f);
	Vect topLeft(-10.0f, 0.0f, -10.0f);
	Vect topRight(10.0f, 0.0f, -10.0f);

	Vect leftWallBottomLeft(-10.0f, 0.0f, 10.0f);
	Vect leftWallBottomRight(-10.0f, 0.0f, -10.0f);
	Vect leftWallTopLeft(-10.0f, 10.0f, 10.0f);
	Vect leftWallTopRight(-10.0f, 10.0f, -10.0f);

	Vect frontWallBottomLeft(-10.0f, 0.0f, -10.0f);
	Vect frontWallBottomRight(10.0f, 0.0f, -10.0f);
	Vect frontWallTopLeft(-10.0f, 10.0f, -10.0f);
	Vect frontWallTopRight(10.0f, 10.0f, -10.0f);

	Vect normal = (bottomRight - bottomLeft).cross(topRight - bottomRight);
	normal.norm();

	Vect leftNormal = (leftWallBottomRight - leftWallBottomLeft).cross(leftWallTopRight - leftWallBottomRight);
	leftNormal.norm();

	Vect frontNormal = (frontWallBottomRight - frontWallBottomLeft).cross(frontWallTopRight - frontWallBottomRight);
	frontNormal.norm();

	floorBatch.Begin(GL_TRIANGLES, 7200, 1);

	//Bottom
	for(i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			floorBatch.Normal3f(normal[x], normal[y], normal[z]);
			floorBatch.MultiTexCoord2f(0, texIncrementWidth * j, texIncrementHeight * (i + 1));
			floorBatch.Vertex3f(bottomLeft[x] + j, bottomLeft[y], bottomLeft[z] - (i + 1));

			floorBatch.Normal3f(normal[x], normal[y], normal[z]);
			floorBatch.MultiTexCoord2f(0, texIncrementWidth * j, texIncrementHeight * i);
			floorBatch.Vertex3f(bottomLeft[x] + j, bottomLeft[y], bottomLeft[z] - i);

			floorBatch.Normal3f(normal[x], normal[y], normal[z]);
			floorBatch.MultiTexCoord2f(0, texIncrementWidth * (j + 1), texIncrementHeight * i);
			floorBatch.Vertex3f(bottomLeft[x] + (j + 1), bottomLeft[y], bottomLeft[z] - i);

			floorBatch.Normal3f(normal[x], normal[y], normal[z]);
			floorBatch.MultiTexCoord2f(0, texIncrementWidth * (j + 1), texIncrementHeight * i);
			floorBatch.Vertex3f(bottomLeft[x] + (j + 1), bottomLeft[y], bottomLeft[z] - i);

			floorBatch.Normal3f(normal[x], normal[y], normal[z]);
			floorBatch.MultiTexCoord2f(0, texIncrementWidth * (j + 1), texIncrementHeight * (i + 1));
			floorBatch.Vertex3f(bottomLeft[x] + (j + 1), bottomLeft[y], bottomLeft[z] - (i + 1));

			floorBatch.Normal3f(normal[x], normal[y], normal[z]);
			floorBatch.MultiTexCoord2f(0, texIncrementWidth * j, texIncrementHeight * (i + 1));
			floorBatch.Vertex3f(bottomLeft[x] + j, bottomLeft[y], bottomLeft[z] - (i + 1));

		}

	}

	//Left Wall
	for(i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			floorBatch.Normal3f(leftNormal[x], leftNormal[y], leftNormal[z]);
			floorBatch.MultiTexCoord2f(0, texIncrementWidth * j, texIncrementHeight * (i + 1));
			floorBatch.Vertex3f(leftWallBottomLeft[x], leftWallBottomLeft[y] + (i + 1), leftWallBottomLeft[z] - j);
			
			floorBatch.Normal3f(leftNormal[x], leftNormal[y], leftNormal[z]);
			floorBatch.MultiTexCoord2f(0, texIncrementWidth * j, texIncrementHeight * i);
			floorBatch.Vertex3f(leftWallBottomLeft[x], leftWallBottomLeft[y] + i, leftWallBottomLeft[z] - j);

			floorBatch.Normal3f(leftNormal[x], leftNormal[y], leftNormal[z]);
			floorBatch.MultiTexCoord2f(0, texIncrementWidth * (j + 1), texIncrementHeight * i);
			floorBatch.Vertex3f(leftWallBottomLeft[x], leftWallBottomLeft[y] + i, leftWallBottomLeft[z] - (j + 1));

			floorBatch.Normal3f(leftNormal[x], leftNormal[y], leftNormal[z]);
			floorBatch.MultiTexCoord2f(0, texIncrementWidth * (j + 1), texIncrementHeight * i);
			floorBatch.Vertex3f(leftWallBottomLeft[x], leftWallBottomLeft[y] + i, leftWallBottomLeft[z] - (j + 1));

			floorBatch.Normal3f(leftNormal[x], leftNormal[y], leftNormal[z]);
			floorBatch.MultiTexCoord2f(0, texIncrementWidth * (j + 1), texIncrementHeight * (i + 1));
			floorBatch.Vertex3f(leftWallBottomLeft[x], leftWallBottomLeft[y] + (i + 1), leftWallBottomLeft[z] - (j + 1));

			floorBatch.Normal3f(leftNormal[x], leftNormal[y], leftNormal[z]);
			floorBatch.MultiTexCoord2f(0, texIncrementWidth * j, texIncrementHeight * (i + 1));
			floorBatch.Vertex3f(leftWallBottomLeft[x], leftWallBottomLeft[y] + (i + 1), leftWallBottomLeft[z] - j);
		}
	}

	//Front Wall
	//Left Wall
	for(i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			floorBatch.Normal3f(frontNormal[x], frontNormal[y], frontNormal[z]);
			floorBatch.MultiTexCoord2f(0, texIncrementWidth * j, texIncrementHeight * (i + 1));
			floorBatch.Vertex3f(frontWallBottomLeft[x] + j, frontWallBottomLeft[y] + (i + 1), frontWallBottomLeft[z]);
			
			floorBatch.Normal3f(frontNormal[x], frontNormal[y], frontNormal[z]);
			floorBatch.MultiTexCoord2f(0, texIncrementWidth * j, texIncrementHeight * i);
			floorBatch.Vertex3f(frontWallBottomLeft[x] + j, frontWallBottomLeft[y] + i, frontWallBottomLeft[z]);

			floorBatch.Normal3f(frontNormal[x], frontNormal[y], frontNormal[z]);
			floorBatch.MultiTexCoord2f(0, texIncrementWidth * (j + 1), texIncrementHeight * i);
			floorBatch.Vertex3f(frontWallBottomLeft[x] + (j + 1), frontWallBottomLeft[y] + i, frontWallBottomLeft[z]);

			floorBatch.Normal3f(frontNormal[x], frontNormal[y], frontNormal[z]);
			floorBatch.MultiTexCoord2f(0, texIncrementWidth * (j + 1), texIncrementHeight * i);
			floorBatch.Vertex3f(frontWallBottomLeft[x] + (j + 1), frontWallBottomLeft[y] + i, frontWallBottomLeft[z]);

			floorBatch.Normal3f(frontNormal[x], frontNormal[y], frontNormal[z]);
			floorBatch.MultiTexCoord2f(0, texIncrementWidth * (j + 1), texIncrementHeight * (i + 1));
			floorBatch.Vertex3f(frontWallBottomLeft[x] + (j + 1), frontWallBottomLeft[y] + (i + 1), frontWallBottomLeft[z]);

			floorBatch.Normal3f(frontNormal[x], frontNormal[y], frontNormal[z]);
			floorBatch.MultiTexCoord2f(0, texIncrementWidth * j, texIncrementHeight * (i + 1));
			floorBatch.Vertex3f(frontWallBottomLeft[x] + j, frontWallBottomLeft[y] + (i + 1), frontWallBottomLeft[z]);
		}
	}

	//Front
	//Left triangle
	//Top left
	//rectangleBatch.Normal3f(leftNormal[x], leftNormal[y], leftNormal[z]);
	//rectangleBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	//rectangleBatch.Vertex3f(topLeft[x], topLeft[y], topLeft[z]);

	floorBatch.End();
}