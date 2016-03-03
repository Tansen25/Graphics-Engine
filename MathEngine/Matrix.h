#ifndef ENGINE_MATH_MATRIX_H
#define ENGINE_MATH_MATRIX_H

// SIMD includes
#include <xmmintrin.h>
#include <smmintrin.h> 

#include "Enum.h"

class Quat;

class Matrix
{
public:

    // Do your magic here:

	//Default Constructor
	Matrix();

	//Copy Constructor
	Matrix(const Matrix &in);

	//Specialized Constructor
	Matrix(const Vect &in1, const Vect &in2, const Vect &in3, const Vect &in4);

	//Specialized Constructor - Identity Or Zero Matrix
	Matrix(const MatrixSpecialType type);

	//Specialized Constructor - Translation Matrix
	Matrix(const MatrixTransType type, const float &x, const float &y, const float &z);

	//Specialized Constructor - Scale Matrix
	Matrix(const MatrixScaleType type, const float &x, const float &y, const float &z);

	//Specialized Constructor - Rot Matrix
	Matrix(const RotType type, const float &rad);

	//specialized Constructor - Quaternion
	Matrix(const Quat &q);

	//Destructor
	~Matrix();

	//Get Row
	Vect get(const MatrixRowType type);

	//Get Transpose
	Matrix getT();

	//Get Inverse
	Matrix getInv();
	
	//Set Identity Or Zero Matrix
	void set(const MatrixSpecialType type);

	//Set Translation Matrix
	void set(const MatrixTransType type, const float &x, const float &y, const float &z);

	//Set Scale Matrix
	void set(const MatrixScaleType type, const float &x, const float &y, const float &z);

	//Set Rot Matrix
	void set(const RotType type, const float &rad);

	//Set Rotation Matrix About Arbitrary Axis
	void set(const RotAxisAngleType type, const Vect &axis, const float &rad);

	//Set Orientation Rotation Matrix
	void set(const RotOrientType type, const Vect &dof, const Vect &up);

	//Set Row
	void set(const MatrixRowType type, const Vect &in);

	//Set Matrix Through Vectors
	void set(const Vect &v1, const Vect &v2, const Vect &v3, const Vect &v4);

	//Set Matrix Through Quaternion
	void set(const Quat &q);

	//Assignment Operator
	void operator = (const Matrix &in);

	//+= Operator
	void operator +=(const Matrix &in);

	//-= Operator
	void operator -= (const Matrix &in);

	//*= Operator - Matrix
	void operator *= (const Matrix &in);

	//*= Operator - Scalar
	void operator *= (const float &s);

	//Bracket Operator - Get
	float operator[](const m0_enum) const;
	float operator[](const m1_enum) const;
	float operator[](const m2_enum) const;
	float operator[](const m3_enum) const;
	float operator[](const m4_enum) const;
	float operator[](const m5_enum) const;
	float operator[](const m6_enum) const;
	float operator[](const m7_enum) const;
	float operator[](const m8_enum) const;
	float operator[](const m9_enum) const;
	float operator[](const m10_enum) const;
	float operator[](const m11_enum) const;
	float operator[](const m12_enum) const;
	float operator[](const m13_enum) const;
	float operator[](const m14_enum) const;
	float operator[](const m15_enum) const;

	//Bracket Operator - Set
	float& operator[](const m0_enum);
	float& operator[](const m1_enum);
	float& operator[](const m2_enum);
	float& operator[](const m3_enum);
	float& operator[](const m4_enum);
	float& operator[](const m5_enum);
	float& operator[](const m6_enum);
	float& operator[](const m7_enum);
	float& operator[](const m8_enum);
	float& operator[](const m9_enum);
	float& operator[](const m10_enum);
	float& operator[](const m11_enum);
	float& operator[](const m12_enum);
	float& operator[](const m13_enum);
	float& operator[](const m14_enum);
	float& operator[](const m15_enum);

	//Test For Equality
	bool isEqual(const Matrix &in);

	//Test For Identity
	bool isIdentity() const;

	//Test For Identity
	bool isIdentity(const float &epsilon);

	//Determinant
	float det() const;

	//Transpose
	void T();

	//Inverse
	void inv();

	

private:

// Level 4 complains nameless struct/union ...
#pragma warning( disable : 4201)

union 
		{
		struct 
			{
			Vect v0;
			Vect v1;
			Vect v2;
			Vect v3;
			};

		struct 
			{
			float m0;
			float m1;
			float m2;
			float m3;
			float m4;
			float m5;
			float m6;	
			float m7;
			float m8;
			float m9;
			float m10;
			float m11;
			float m12;
			float m13;
			float m14;
			float m15;
			};
		};
};

//Adding Matrices
Matrix operator + (const Matrix &m, const Matrix &n);

//Subtracting Matrices
Matrix operator - (const Matrix &m, const Matrix &n);

//Multiply Matrices
Matrix operator * (const Matrix &m, const Matrix &n);

//Scalar Times A Matrix
Matrix operator * (const float &s, const Matrix &n);

//Matrix Times A Scalar
Matrix operator * (const Matrix &n, const float &s);

//Unary +
Matrix operator + (const Matrix &in);

//Unary -
Matrix operator - (const Matrix &in);

#endif