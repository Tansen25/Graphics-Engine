/** @file */ 
/*****************************************************************************/
/*                                                                           */
/* file: Quat.h                                                              */
/*                                                                           */
/*****************************************************************************/

#ifndef ENGINE_MATH_QUAT_H
#define ENGINE_MATH_QUAT_H

/*****************************************************************************/
/* Includes:                                                                 */
/*****************************************************************************/
#include "Matrix.h"
#include "Enum.h"


	/*************************************************************************
	*
	* This class contains functions and data structure for a 4-dimensional 
	* Quaternions.  The quaternions are internally stored interms of the 
	* imaginary components (x,y,z) and the real components (real).
	*
	* In the Math library, quaternions can be thought of as "rotational"
	* matrices, everything that you can represent with rotational matrices
	* you can use with quaternions.  Such as quaternion concatenation,
	* inverses, transpose, normalize, multiplying with matrices, and with
	* vectors.
	*  
	*  
	**************************************************************************/

class Quat 
{
public:
   
   
    // Do your magic here:

	//Default Constructor
	Quat();

	//Copy Constructor
	Quat(const Vect &in);

	//Specialized Constructor
	Quat(float inX, float inY, float inZ, float inW);

	//Specialized Constructor - From Vector
	Quat(const Vect &inVect, float inW);

	//Specialized Constructor - From Matrix
	Quat(const Matrix &inMatrix);

	//Specialized Constructor - Identity Or Zero
	Quat(const MatrixSpecialType type);

	//Specialized Constructor - Rot
	Quat(const RotType type, const float &rad);

	//Specialized Constructor - 3 Rotations
	Quat(const Rot3AxisType type, const float &radOne, const float &radTwo, const float &radThree);

	//Specialized Constructor - Rotation About Arbitrary Axis
	Quat(const RotAxisAngleType type, const Vect &axis, const float &rad);

	//Specialized Constructor - Orientation Rotation
	Quat(const RotOrientType type, const Vect &dof, const Vect &up);

	//Destructor
	~Quat();

	//set Quaternion
	void set(const float &inX, const float &inY, const float &inZ, const float &inW);
	
	//Set Quaternion From Matrix
	void set(const Matrix &inMatrix);

	//set Quaternion From Vector + W Component
	void set(const Vect &inV, const float inW);

	//Set Quaternion From Vector Only
	void setVect(const Vect &inV);

	//Set Quaternion - Rot
	void set(const RotType type, const float &rad);

	//Set Quaternion - Rotation About Arbitrary Axis
	void set(const RotAxisAngleType type, const Vect &axis, const float &rad);

	//Set Quaternion - Orientation Rotation
	void set(const RotOrientType type, const Vect &dof, const Vect &up);

	//Assignment Operator
	void operator = (const Quat &in);
	
	//+= Operator - Quat
	void operator +=(const Quat &in);

	//+= Operator - Constant
	void operator +=(const float &inValue);

	//-= Operator - Quat
	void operator -=(const Quat &in);

	//-= Operator - Constant
	void operator -=(const float &inValue);

	//*= Operator - Matrix
	void operator *=(const Matrix &in);

	//*= Operator - Quat
	void operator *=(const Quat &in);

	//*= Operator - Constant
	void operator *=(const float &inValue);

	// /= Operator - Quat
	void operator /=(const Quat &q);

	// /= Operator - Quat
	void operator /=(const float &a);

	//Multiply Quaternion By Another Quaternion Element By Element
	Quat multByElement(const Quat &in);

	//Multiply Vector By A Quaternion - qConj * V * q
	void Lqcvq(const Vect &inV, Vect &outV); 

	//Multiply Vector By A Quaternion - q * V * qConj
	void Lqvqc(const Vect &inV, Vect &outV);

	//Bracket Operator - Get
	float operator[](const x_enum) const;
	float operator[](const y_enum) const;
	float operator[](const z_enum) const;
	float operator[](const w_enum) const;

	//Get Conjugate
	Quat getConj();

	//Get Transpose
	Quat getT();

	//Get Magnitude
	float mag();

	//Get Magnitude Squared
	float magSquared();

	//Get Inverse Magnitude
	float invMag();

	//Get Normalized Quaternion
	Quat getNorm();

	//Get Inverse
	Quat getInv();

	//Get Vector
	void getVect(Vect &outV);

	//Get Angle
	float getAngle();

	//Get Axis
	void getAxis(Vect &outV);

	//Bracket Operator - Set
	float& operator[](const x_enum);
	float& operator[](const y_enum);
	float& operator[](const z_enum);
	float& operator[](const w_enum);

	//Set Conjugate
	void conj();

	//Set Transpose
	void T();

	//Set Normalized Quaternion
	Quat norm();

	//Set Inverse
	void inv();

	//Test For Equality
	bool isEqual(const Quat &q, const float &epsilon);
	bool isNegEqual(const Quat &q, const float &epsilon);
	
	//Test If It Is Equivalent
	bool isEquivalent(const Quat &q, const float &epsilon);

	//Test If It Is A Conjugate
	bool isConjugateEqual(const Quat &q, const float &epsilon);

	//Test For Identity
	bool isIdentity(const float &epsilon);

	//Test If It Is Normalized
	bool isNormalized(const float &epsilon);

	//Test If It Is Zero
	bool isZero(const float &epsilon);

	
private:

// Level 4 complains nameless struct/union ...
#pragma warning( disable : 4201)
	// anonymous union
	union 
	{
		__m128	m;

		// anonymous struct
		struct 
			{
			float x;
			float y;
			float z;
			float w;
			};
	};


};

//Add Quaternions
Quat operator +(const Quat &q1, const Quat &q2);

//Add Quaternion With A Constant
Quat operator +(const Quat &q1, const float &inValue);

//Add Constant To A Quaternion
Quat operator +(const float &inValue, const Quat &q1);

//Subtract Quaternions
Quat operator -(const Quat &q1, const Quat &q2);

//Subtract Quaternion With A Constant
Quat operator -(const Quat &q1, const float &inValue);

//Subtract Constant To A Quaternion
Quat operator -(const float &inValue, const Quat &q1);

//Multiply Quaternions
Quat operator * (const Quat &p, const Quat &q);

//Multiply Quaternion With A Matrix
Matrix operator * (const Quat &p, const Matrix &m);

//Multiply Matrix With A Quaternion
Matrix operator * (const Matrix &m, const Quat &p);

//Multiply Quaternion With A Constant
Quat operator *(const Quat &q1, const float &inValue);

//Multiply Constant To A Quaternion
Quat operator *(const float &inValue, const Quat &q1);

//Divide Quaternion By A Quaternion
Quat operator /(const Quat &p, const Quat &q);

//Divide Quaternion By A Constant
Quat operator /(const Quat &p, const float &a);

//Divide Constant By A Quaternion
Quat operator /(const float &a, const Quat &p);

//Unary +
Quat operator +(const Quat &in);

//Unary -
Quat operator -(const Quat &in);








#endif // #ifndef QUAT_H

/**** END of Quat.h ********************************************************/
