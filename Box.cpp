

#include "Box.h"

Box::Box()
{
	//Create the square
	this -> createBox();
}

void Box::draw()
{
	boxBatch.Draw();
}

Box* Box::getInstance()
{
	return privGetInstance();
}

Box* Box::privGetInstance()
{
	static Box t;
	return &t;
}

void Box::createBox()
{
	Vect frontBottomLeft(-0.5f, -0.5f, 0.5f);
	Vect frontBottomRight(0.5f, -0.5f, 0.5f);
	Vect frontTopLeft(-0.5f, 0.5f, 0.5f);
	Vect frontTopRight(0.5f, 0.5f, 0.5f);

	Vect backBottomLeft(-0.5f, -0.5f, -0.5f);
	Vect backBottomRight(0.5f, -0.5f, -0.5f);
	Vect backTopLeft(-0.5f, 0.5f, -0.5f);
	Vect backTopRight(0.5f, 0.5f, -0.5f);

	Vect frontLeftNormal = (frontBottomLeft - frontTopLeft).cross(frontBottomRight - frontBottomLeft);
	Vect frontRightNormal = (frontTopRight - frontBottomRight).cross(frontTopLeft - frontTopRight);

	Vect rightSideLeftNormal = (frontBottomRight - frontTopRight).cross(backBottomRight - frontBottomRight);
	Vect rightSideRightNormal = (backTopRight - backBottomRight).cross(frontTopRight - backTopRight);

	Vect backLeftNormal = (backBottomRight - backTopRight).cross(backBottomLeft - backBottomRight);
	Vect backRightNormal = (backTopLeft - backBottomLeft).cross(backTopRight - backTopLeft);

	Vect leftSideLeftNormal = (backBottomLeft - backTopLeft).cross(frontBottomLeft - backBottomLeft);
	Vect leftSideRightNormal = (frontTopLeft - frontBottomLeft).cross(backTopLeft - frontTopLeft);

	Vect topLeftNormal = (frontTopLeft - backTopLeft).cross(frontTopRight - frontTopLeft);
	Vect topRightNormal = (backTopRight - frontTopRight).cross(backTopLeft - backTopRight);

	Vect bottomLeftNormal = (backBottomLeft - frontBottomLeft).cross(backBottomRight - backBottomLeft);
	Vect bottomRightNormal = (frontBottomRight - backBottomRight).cross(frontBottomLeft - frontBottomRight);

	frontLeftNormal.norm();
	frontRightNormal.norm();
	rightSideLeftNormal.norm();
	rightSideLeftNormal.norm();
	backLeftNormal.norm();
	backRightNormal.norm();
	leftSideLeftNormal.norm();
	leftSideRightNormal.norm();
	topLeftNormal.norm();
	topRightNormal.norm();
	bottomLeftNormal.norm();
	bottomRightNormal.norm();

	boxBatch.Begin(GL_TRIANGLES, 36, 1);

#if 1

	//Test - Vertex Normals - No break angle - Need to work on this more - possibly when I hook in models from 3DSMax
	Vect ftl = frontRightNormal + leftSideRightNormal + topLeftNormal;
	Vect ftr = frontRightNormal + rightSideLeftNormal + topLeftNormal;
	Vect fbl = frontLeftNormal + leftSideLeftNormal  + bottomLeftNormal;
	Vect fbr = frontLeftNormal + rightSideLeftNormal + bottomRightNormal;

	Vect btl = backRightNormal + leftSideLeftNormal + topLeftNormal;
	Vect btr = backLeftNormal + rightSideRightNormal + topRightNormal;
	Vect bbl = backLeftNormal + leftSideLeftNormal + bottomLeftNormal;
	Vect bbr = backLeftNormal + rightSideRightNormal + bottomLeftNormal;

	ftl.norm();
	ftr.norm();
	fbl.norm();
	fbr.norm();
	btl.norm();
	btr.norm();
	bbl.norm();
	bbr.norm();

	//Front
	//Left triangle
	//Top left
	boxBatch.Normal3f(ftl[x], ftl[y], ftl[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	boxBatch.Vertex3f(frontTopLeft[x], frontTopLeft[y], frontTopLeft[z]);

	//Bottom left
	boxBatch.Normal3f(fbl[x], fbl[y], fbl[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
	boxBatch.Vertex3f(frontBottomLeft[x], frontBottomLeft[y], frontBottomLeft[z]);

	//Bottom right
	boxBatch.Normal3f(fbr[x], fbr[y], fbr[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	boxBatch.Vertex3f(frontBottomRight[x], frontBottomRight[y], frontBottomRight[z]);

	//Right triangle
	//Bottom right
	boxBatch.Normal3f(fbr[x], fbr[y], fbr[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	boxBatch.Vertex3f(frontBottomRight[x], frontBottomRight[y], frontBottomRight[z]);

	//Top right
	boxBatch.Normal3f(ftr[x], ftr[y], ftr[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 1.0f);
	boxBatch.Vertex3f(frontTopRight[x], frontTopRight[y], frontTopRight[z]);

	//Top left
	boxBatch.Normal3f(ftl[x], ftl[y], ftl[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	boxBatch.Vertex3f(frontTopLeft[x], frontTopLeft[y], frontTopLeft[z]);

	//Right Side
	//Left triangle
	//Top left
	boxBatch.Normal3f(ftr[x], ftr[y], ftr[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	boxBatch.Vertex3f(frontTopRight[x], frontTopRight[y], frontTopRight[z]);

	//Bottom left
	boxBatch.Normal3f(fbr[x], fbr[y], fbr[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
	boxBatch.Vertex3f(frontBottomRight[x], frontBottomRight[y], frontBottomRight[z]);

	//Bottom right
	boxBatch.Normal3f(bbr[x], bbr[y], bbr[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	boxBatch.Vertex3f(backBottomRight[x], backBottomRight[y], backBottomRight[z]);

	//Right triangle
	//Bottom right
	boxBatch.Normal3f(bbr[x], bbr[y], bbr[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	boxBatch.Vertex3f(backBottomRight[x], backBottomRight[y], backBottomRight[z]);

	//Top right
	boxBatch.Normal3f(btr[x], btr[y], btr[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 1.0f);
	boxBatch.Vertex3f(backTopRight[x], backTopRight[y], backTopRight[z]);

	//Top left
	boxBatch.Normal3f(ftr[x], ftr[y], ftr[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	boxBatch.Vertex3f(frontTopRight[x], frontTopRight[y], frontTopRight[z]);

	//Back
	//Left triangle
	//Top left
	boxBatch.Normal3f(btr[x], btr[y], btr[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	boxBatch.Vertex3f(backTopRight[x], backTopRight[y], backTopRight[z]);

	//Bottom left
	boxBatch.Normal3f(bbr[x], bbr[y], bbr[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
	boxBatch.Vertex3f(backBottomRight[x], backBottomRight[y], backBottomRight[z]);

	//Bottom right
	boxBatch.Normal3f(bbl[x], bbl[y], bbl[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	boxBatch.Vertex3f(backBottomLeft[x], backBottomLeft[y], backBottomLeft[z]);

	//Right triangle
	//Bottom right
	boxBatch.Normal3f(bbl[x], bbl[y], bbl[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	boxBatch.Vertex3f(backBottomLeft[x], backBottomLeft[y], backBottomLeft[z]);

	//Top right
	boxBatch.Normal3f(btl[x], btl[y], btl[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 1.0f);
	boxBatch.Vertex3f(backTopLeft[x], backTopLeft[y], backTopLeft[z]);

	//Top left
	boxBatch.Normal3f(btr[x], btr[y], btr[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	boxBatch.Vertex3f(backTopRight[x], backTopRight[y], backTopRight[z]);

	//Left Side
	//Left triangle
	//Top left
	boxBatch.Normal3f(btl[x], btl[y], btl[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	boxBatch.Vertex3f(backTopLeft[x], backTopLeft[y], backTopLeft[z]);

	//Bottom left
	boxBatch.Normal3f(bbl[x], bbl[y], bbl[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
	boxBatch.Vertex3f(backBottomLeft[x], backBottomLeft[y], backBottomLeft[z]);

	//Bottom right
	boxBatch.Normal3f(fbl[x], fbl[y], fbl[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	boxBatch.Vertex3f(frontBottomLeft[x], frontBottomLeft[y], frontBottomLeft[z]);

	//Right triangle
	//Bottom right
	boxBatch.Normal3f(fbl[x], fbl[y], fbl[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	boxBatch.Vertex3f(frontBottomLeft[x], frontBottomLeft[y], frontBottomLeft[z]);

	//Top right
	boxBatch.Normal3f(ftl[x], ftl[y], ftl[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 1.0f);
	boxBatch.Vertex3f(frontTopLeft[x], frontTopLeft[y], frontTopLeft[z]);

	//Top left
	boxBatch.Normal3f(btl[x], btl[y], btl[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	boxBatch.Vertex3f(backTopLeft[x], backTopLeft[y], backTopLeft[z]);

	//Top
	//Left triangle
	//Top left
	boxBatch.Normal3f(btl[x], btl[y], btl[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	boxBatch.Vertex3f(backTopLeft[x], backTopLeft[y], backTopLeft[z]);

	//Bottom left
	boxBatch.Normal3f(ftl[x], ftl[y], ftl[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
	boxBatch.Vertex3f(frontTopLeft[x], frontTopLeft[y], frontTopLeft[z]);

	//Bottom right
	boxBatch.Normal3f(ftr[x], ftr[y], ftr[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	boxBatch.Vertex3f(frontTopRight[x], frontTopRight[y], frontTopRight[z]);

	//Right triangle
	//Bottom right
	boxBatch.Normal3f(ftr[x], ftr[y], ftr[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	boxBatch.Vertex3f(frontTopRight[x], frontTopRight[y], frontTopRight[z]);

	//Top right
	boxBatch.Normal3f(btr[x], btr[y], btr[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 1.0f);
	boxBatch.Vertex3f(backTopRight[x], backTopRight[y], backTopRight[z]);

	//Top left
	boxBatch.Normal3f(btl[x], btl[y], btl[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	boxBatch.Vertex3f(backTopLeft[x], backTopLeft[y], backTopLeft[z]);

	//Bottom
	//Left triangle
	//Top left
	boxBatch.Normal3f(fbl[x], fbl[y], fbl[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	boxBatch.Vertex3f(frontBottomLeft[x], frontBottomLeft[y], frontBottomLeft[z]);

	//Bottom left
	boxBatch.Normal3f(bbl[x], bbl[y], bbl[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
	boxBatch.Vertex3f(backBottomLeft[x], backBottomLeft[y], backBottomLeft[z]);

	//Bottom right
	boxBatch.Normal3f(bbr[x], bbr[y], bbr[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	boxBatch.Vertex3f(backBottomRight[x], backBottomRight[y], backBottomRight[z]);

	//Right triangle
	//Bottom right
	boxBatch.Normal3f(bbr[x], bbr[y], bbr[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	boxBatch.Vertex3f(backBottomRight[x], backBottomRight[y], backBottomRight[z]);

	//Top right
	boxBatch.Normal3f(fbr[x], fbr[y], fbr[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 1.0f);
	boxBatch.Vertex3f(frontBottomRight[x], frontBottomRight[y], frontBottomRight[z]);

	//Top left
	boxBatch.Normal3f(fbl[x], fbl[y], fbl[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	boxBatch.Vertex3f(frontBottomLeft[x], frontBottomLeft[y], frontBottomLeft[z]);

#else

	//Front
	//Left triangle
	//Top left
	boxBatch.Normal3f(frontLeftNormal[x], frontLeftNormal[y], frontLeftNormal[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	boxBatch.Vertex3f(frontTopLeft[x], frontTopLeft[y], frontTopLeft[z]);

	//Bottom left
	boxBatch.Normal3f(frontLeftNormal[x], frontLeftNormal[y], frontLeftNormal[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
	boxBatch.Vertex3f(frontBottomLeft[x], frontBottomLeft[y], frontBottomLeft[z]);

	//Bottom right
	boxBatch.Normal3f(frontLeftNormal[x], frontLeftNormal[y], frontLeftNormal[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	boxBatch.Vertex3f(frontBottomRight[x], frontBottomRight[y], frontBottomRight[z]);

	//Right triangle
	//Bottom right
	boxBatch.Normal3f(frontRightNormal[x], frontRightNormal[y], frontRightNormal[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	boxBatch.Vertex3f(frontBottomRight[x], frontBottomRight[y], frontBottomRight[z]);

	//Top right
	boxBatch.Normal3f(frontRightNormal[x], frontRightNormal[y], frontRightNormal[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 1.0f);
	boxBatch.Vertex3f(frontTopRight[x], frontTopRight[y], frontTopRight[z]);

	//Top left
	boxBatch.Normal3f(frontRightNormal[x], frontRightNormal[y], frontRightNormal[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	boxBatch.Vertex3f(frontTopLeft[x], frontTopLeft[y], frontTopLeft[z]);

	//Right Side
	//Left triangle
	//Top left
	boxBatch.Normal3f(rightSideLeftNormal[x], rightSideLeftNormal[y], rightSideLeftNormal[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	boxBatch.Vertex3f(frontTopRight[x], frontTopRight[y], frontTopRight[z]);

	//Bottom left
	boxBatch.Normal3f(rightSideLeftNormal[x], rightSideLeftNormal[y], rightSideLeftNormal[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
	boxBatch.Vertex3f(frontBottomRight[x], frontBottomRight[y], frontBottomRight[z]);

	//Bottom right
	boxBatch.Normal3f(rightSideLeftNormal[x], rightSideLeftNormal[y], rightSideLeftNormal[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	boxBatch.Vertex3f(backBottomRight[x], backBottomRight[y], backBottomRight[z]);

	//Right triangle
	//Bottom right
	boxBatch.Normal3f(rightSideRightNormal[x], rightSideRightNormal[y], rightSideRightNormal[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	boxBatch.Vertex3f(backBottomRight[x], backBottomRight[y], backBottomRight[z]);

	//Top right
	boxBatch.Normal3f(rightSideRightNormal[x], rightSideRightNormal[y], rightSideRightNormal[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 1.0f);
	boxBatch.Vertex3f(backTopRight[x], backTopRight[y], backTopRight[z]);

	//Top left
	boxBatch.Normal3f(rightSideRightNormal[x], rightSideRightNormal[y], rightSideRightNormal[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	boxBatch.Vertex3f(frontTopRight[x], frontTopRight[y], frontTopRight[z]);

	//Back
	//Left triangle
	//Top left
	boxBatch.Normal3f(backLeftNormal[x], backLeftNormal[y], backLeftNormal[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	boxBatch.Vertex3f(backTopRight[x], backTopRight[y], backTopRight[z]);

	//Bottom left
	boxBatch.Normal3f(backLeftNormal[x], backLeftNormal[y], backLeftNormal[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
	boxBatch.Vertex3f(backBottomRight[x], backBottomRight[y], backBottomRight[z]);

	//Bottom right
	boxBatch.Normal3f(backLeftNormal[x], backLeftNormal[y], backLeftNormal[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	boxBatch.Vertex3f(backBottomLeft[x], backBottomLeft[y], backBottomLeft[z]);

	//Right triangle
	//Bottom right
	boxBatch.Normal3f(backRightNormal[x], backRightNormal[y], backRightNormal[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	boxBatch.Vertex3f(backBottomLeft[x], backBottomLeft[y], backBottomLeft[z]);

	//Top right
	boxBatch.Normal3f(backRightNormal[x], backRightNormal[y], backRightNormal[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 1.0f);
	boxBatch.Vertex3f(backTopLeft[x], backTopLeft[y], backTopLeft[z]);

	//Top left
	boxBatch.Normal3f(backRightNormal[x], backRightNormal[y], backRightNormal[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	boxBatch.Vertex3f(backTopRight[x], backTopRight[y], backTopRight[z]);

	//Left Side
	//Left triangle
	//Top left
	boxBatch.Normal3f(leftSideLeftNormal[x], leftSideLeftNormal[y], leftSideLeftNormal[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	boxBatch.Vertex3f(backTopLeft[x], backTopLeft[y], backTopLeft[z]);

	//Bottom left
	boxBatch.Normal3f(leftSideLeftNormal[x], leftSideLeftNormal[y], leftSideLeftNormal[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
	boxBatch.Vertex3f(backBottomLeft[x], backBottomLeft[y], backBottomLeft[z]);

	//Bottom right
	boxBatch.Normal3f(leftSideLeftNormal[x], leftSideLeftNormal[y], leftSideLeftNormal[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	boxBatch.Vertex3f(frontBottomLeft[x], frontBottomLeft[y], frontBottomLeft[z]);

	//Right triangle
	//Bottom right
	boxBatch.Normal3f(leftSideRightNormal[x], leftSideRightNormal[y], leftSideRightNormal[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	boxBatch.Vertex3f(frontBottomLeft[x], frontBottomLeft[y], frontBottomLeft[z]);

	//Top right
	boxBatch.Normal3f(leftSideRightNormal[x], leftSideRightNormal[y], leftSideRightNormal[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 1.0f);
	boxBatch.Vertex3f(frontTopLeft[x], frontTopLeft[y], frontTopLeft[z]);

	//Top left
	boxBatch.Normal3f(leftSideRightNormal[x], leftSideRightNormal[y], leftSideRightNormal[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	boxBatch.Vertex3f(backTopLeft[x], backTopLeft[y], backTopLeft[z]);

	//Top
	//Left triangle
	//Top left
	boxBatch.Normal3f(topLeftNormal[x], topLeftNormal[y], topLeftNormal[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	boxBatch.Vertex3f(backTopLeft[x], backTopLeft[y], backTopLeft[z]);

	//Bottom left
	boxBatch.Normal3f(topLeftNormal[x], topLeftNormal[y], topLeftNormal[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
	boxBatch.Vertex3f(frontTopLeft[x], frontTopLeft[y], frontTopLeft[z]);

	//Bottom right
	boxBatch.Normal3f(topLeftNormal[x], topLeftNormal[y], topLeftNormal[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	boxBatch.Vertex3f(frontTopRight[x], frontTopRight[y], frontTopRight[z]);

	//Right triangle
	//Bottom right
	boxBatch.Normal3f(topRightNormal[x], topRightNormal[y], topRightNormal[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	boxBatch.Vertex3f(frontTopRight[x], frontTopRight[y], frontTopRight[z]);

	//Top right
	boxBatch.Normal3f(topRightNormal[x], topRightNormal[y], topRightNormal[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 1.0f);
	boxBatch.Vertex3f(backTopRight[x], backTopRight[y], backTopRight[z]);

	//Top left
	boxBatch.Normal3f(topRightNormal[x], topRightNormal[y], topRightNormal[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	boxBatch.Vertex3f(backTopLeft[x], backTopLeft[y], backTopLeft[z]);

	//Bottom
	//Left triangle
	//Top left
	boxBatch.Normal3f(bottomLeftNormal[x], bottomLeftNormal[y], bottomLeftNormal[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	boxBatch.Vertex3f(frontBottomLeft[x], frontBottomLeft[y], frontBottomLeft[z]);

	//Bottom left
	boxBatch.Normal3f(bottomLeftNormal[x], bottomLeftNormal[y], bottomLeftNormal[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
	boxBatch.Vertex3f(backBottomLeft[x], backBottomLeft[y], backBottomLeft[z]);

	//Bottom right
	boxBatch.Normal3f(bottomLeftNormal[x], bottomLeftNormal[y], bottomLeftNormal[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	boxBatch.Vertex3f(backBottomRight[x], backBottomRight[y], backBottomRight[z]);

	//Right triangle
	//Bottom right
	boxBatch.Normal3f(bottomRightNormal[x], bottomRightNormal[y], bottomRightNormal[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
	boxBatch.Vertex3f(backBottomRight[x], backBottomRight[y], backBottomRight[z]);

	//Top right
	boxBatch.Normal3f(bottomRightNormal[x], bottomRightNormal[y], bottomRightNormal[z]);
	boxBatch.MultiTexCoord2f(0, 1.0f, 1.0f);
	boxBatch.Vertex3f(frontBottomRight[x], frontBottomRight[y], frontBottomRight[z]);

	//Top left
	boxBatch.Normal3f(bottomRightNormal[x], bottomRightNormal[y], bottomRightNormal[z]);
	boxBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
	boxBatch.Vertex3f(frontBottomLeft[x], frontBottomLeft[y], frontBottomLeft[z]);

#endif
	
	boxBatch.End();
}