#ifndef CAMERA_H
#define CAMERA_H

#include "MathEngine\MathEngine.h"
#include "OpenGLWrapper.h"

class Camera
{
public:
	Camera();
	void setPerspective(const float FieldOfView_Degs, const float AspectRatio, const float NearDist, const float FarDist);
	void setViewport(const int inX, const int inY, const int width, const int height);
	void setOrientAndPosition(const Vect &inUp, const Vect &inLookAt, const Vect &pos);

	void updateCamera(void);

	Matrix &getViewMatrix();
	Matrix &getProjMatrix();

	// accessors
	void getDir( Vect &outDir) const;
	void setDir( const Vect &inDir);

	void getLookAtPos( Vect &outLookAt) const;
	void setLookAtPos( const Vect &inLookAt);

	void getPos( Vect &outPos) const;
	void setPos( const Vect &inPos);

	void getUp( Vect &outUp) const;
			
	void getFieldOfView( float &Value) const;
	void setFieldOfView( const float Value);

	void getNearDist( float &Value) const;
	void setNearDist( const float Value);

private:  // methods
    void privSetViewState( void );
	void privCalcPlaneHeightWidth( void );
	void privCalcFrustumVerts( void );
	void privCalcFrustumCollisionNormals( void );
	void privUpdateProjectionMatrix( void );
	void privUpdateViewMatrix( void );

private:  // data

	// camera unit vectors (up, dir, right)
	Vect	vUp;
	Vect	vDir;
	Vect	vRight;  // derived by up and dir
	Vect	vPos;    
	Vect    vLookAtPos;

	// Define the frustum inputs
	float	nearDist;
	float	farDist;
	float	fovy;
	float	aspectRatio;

	// Screen size in world space
	float	near_height;
	float	near_width;
	float	far_height;
	float	far_width;

	// viewports
	int		viewport_x;
	int		viewport_y;
	int		viewport_width;
	int		viewport_height;

	// world space coords for viewing frustum
	Vect	nearTopLeft;
	Vect	nearTopRight;
	Vect	nearBottomLeft;
	Vect	nearBottomRight;	
	Vect	farTopLeft;
	Vect	farTopRight;
	Vect	farBottomLeft;
	Vect	farBottomRight;

	// Normals of the frustum
	Vect	frontNorm;
	Vect	backNorm;
	Vect	rightNorm;
	Vect	leftNorm;
	Vect	topNorm;
	Vect	bottomNorm;

	// Projection Matrix
	Matrix	projMatrix;
	Matrix	viewMatrix;
};


#endif