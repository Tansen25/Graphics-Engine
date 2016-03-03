#include "MathEngine.h"
#include <math.h>
#include <iostream>

//Default Constructor
Matrix::Matrix()
{
	m0  = 0.0;
	m1  = 0.0;
	m2  = 0.0;
	m3  = 0.0;

	m4  = 0.0;
	m5  = 0.0;
	m6  = 0.0;
	m7  = 0.0;

	m8  = 0.0;
	m9  = 0.0;
	m10 = 0.0;
	m11 = 0.0;

	m12 = 0.0;
	m13 = 0.0;
	m14 = 0.0;
	m15 = 0.0;
}

//Copy Constructor
Matrix::Matrix(const Matrix &in)
{
	m0  = in.m0;
	m1  = in.m1;
	m2  = in.m2;
	m3  = in.m3;

	m4  = in.m4;
	m5  = in.m5;
	m6  = in.m6;
	m7  = in.m7;

	m8  = in.m8;
	m9  = in.m9;
	m10 = in.m10;
	m11 = in.m11;

	m12 = in.m12;
	m13 = in.m13;
	m14 = in.m14;
	m15 = in.m15;
}

//Specialized Constructor
Matrix::Matrix(const Vect &in1, const Vect &in2, const Vect &in3, const Vect &in4)
{
	m0  = in1[x];
	m1  = in1[y];
	m2  = in1[z];
	m3  = in1[w];

	m4  = in2[x];
	m5  = in2[y];
	m6  = in2[z];
	m7  = in2[w];

	m8  = in3[x];
	m9  = in3[y];
	m10 = in3[z];
	m11 = in3[w];

	m12 = in4[x];
	m13 = in4[y];
	m14 = in4[z];
	m15 = in4[w];
}

//Specialized Constructor - Identity Or Zero Matrix
Matrix::Matrix(const MatrixSpecialType type)
{
	float value;

	//Determine identity matrix or zero matrix
	if (type == 1)
	{
		value = 1.0;
	}

	else
	{
		value = 0.0;
	}

	//Set up identity matrix or zero matrix
	m0 = value;
	m1 = 0.0;
	m2 = 0.0;
	m3 = 0.0;

	m4 = 0.0;
	m5 = value;
	m6 = 0.0;
	m7 = 0.0;

	m8  = 0.0;
	m9  = 0.0;
	m10 = value;
	m11 = 0.0;

	m12 = 0.0;
	m13 = 0.0;
	m14 = 0.0;
	m15 = value;
}

//Specialized Constructor - Translation Matrix
Matrix::Matrix(const MatrixTransType type, const float &x, const float &y, const float &z)
{
	//If translation matrix
	if (type == 0)
	{
		//Set up translation matrix
		m0 = 1.0;
		m1 = 0.0;
		m2 = 0.0;
		m3 = 0.0;

		m4 = 0.0;
		m5 = 1.0;
		m6 = 0.0;
		m7 = 0.0;

		m8  = 0.0;
		m9  = 0.0;
		m10 = 1.0;
		m11 = 0.0;

		m12 = x;
		m13 = y;
		m14 = z;
		m15 = 1.0;
	}
}

//Specialized Constructor - Scale Matrix
Matrix::Matrix(const MatrixScaleType type, const float &x, const float &y, const float &z)
{
	//If scale matrix
	if (type == 0)
	{
		//Set up scale matrix
		m0 = x;
		m1 = 0.0;
		m2 = 0.0;
		m3 = 0.0;

		m4 = 0.0;
		m5 = y;
		m6 = 0.0;
		m7 = 0.0;

		m8  = 0.0;
		m9  = 0.0;
		m10 = z;
		m11 = 0.0;

		m12 = 0.0;
		m13 = 0.0;
		m14 = 0.0;
		m15 = 1.0;
	}
}

//Specialized Constructor - Rot Matrix
Matrix::Matrix(const RotType type, const float &rad)
{
	float rot1 = cos(rad);
	float rot2 = sin(rad);
	
	//If rotaton about x
	if (type == 0)
	{	
		//Set up rotation matrix
		m0 = 1.0;
		m1 = 0.0;
		m2 = 0.0;
		m3 = 0.0;

		m4 = 0.0;
		m5 = rot1;
		m6 = rot2;
		m7 = 0.0;

		m8  = 0.0;
		m9  = -rot2;
		m10 = rot1;
		m11 = 0.0;

		m12 = 0.0;
		m13 = 0.0;
		m14 = 0.0;
		m15 = 1.0;
	}

	//If rotation about y
	else if (type == 1)
	{
		//Set up rotation matrix
		m0 = rot1;
		m1 = 0.0;
		m2 = -rot2;
		m3 = 0.0;

		m4 = 0.0;
		m5 = 1.0;
		m6 = 0.0;
		m7 = 0.0;

		m8  = rot2;
		m9  = 0.0;
		m10 = rot1;
		m11 = 0.0;

		m12 = 0.0;
		m13 = 0.0;
		m14 = 0.0;
		m15 = 1.0;
	}

	//If rotation about z
	else
	{
		//Set up rotation matrix
		m0 = rot1;
		m1 = rot2;
		m2 = 0.0;
		m3 = 0.0;

		m4 = -rot2;
		m5 = rot1;
		m6 = 0.0;
		m7 = 0.0;

		m8  = 0.0;
		m9  = 0.0;
		m10 = 1.0;
		m11 = 0.0;

		m12 = 0.0;
		m13 = 0.0;
		m14 = 0.0;
		m15 = 1.0;
	}
}

//specialized Constructor - Quaternion
Matrix::Matrix(const Quat &q)
{
	//Set first row
	m0 = 1 - 2 * (q[y] * q[y] + q[z] * q[z]);
	m1 = 2 * (q[x] * q[y] + q[w] * q[z]);
	m2 = 2 * (q[x] * q[z] - q[w] * q[y]); 
	m3 = 0.0;

	//Set second row
	m4 = 2 * (q[x] * q[y] - q[w] * q[z]);
	m5 = 1 - 2 * (q[x] * q[x] + q[z] * q[z]);
	m6 = 2 * (q[y] * q[z] + q[w] * q[x]);
	m7 = 0.0;

	//Set third row
	m8  = 2 * (q[x] * q[z] + q[w] * q[y]);
	m9  = 2 * (q[y] * q[z] - q[w] * q[x]);
	m10 = 1 - 2 * (q[x] * q[x] + q[y] * q[y]);
	m11 = 0.0;

	//Set fourth row
	m12 = 0.0;
	m13 = 0.0;
	m14 = 0.0;
	m15 = 1.0;
}

//Destructor
Matrix::~Matrix()
{
	//Does nothing
}

//Get Row
Vect Matrix::get(const MatrixRowType type)
{
	//If row0
	if (type == 0)
	{
		return Vect(m0, m1, m2, m3);
	}

	//If row1
	else if (type == 1)
	{
		return Vect(m4, m5, m6, m7);
	}

	//If row2
	else if (type == 2)
	{
		return Vect(m8, m9, m10, m11);
	}

	//If row3
	else
	{
		return Vect(m12, m13, m14, m15);
	}
}

//Get Transpose
Matrix Matrix::getT()
{
	//Setup vectors for transpose
	Vect v1(m0, m4, m8, m12);
	Vect v2(m1, m5, m9, m13);
	Vect v3(m2, m6, m10, m14);
	Vect v4(m3, m7, m11, m15);

	//Transpose the matrix
	return Matrix(v1, v2, v3, v4);
}

//Get Inverse
Matrix Matrix::getInv()
{
	//Setup matrix to pass
	Vect v1(m0, m1, m2, m3);
	Vect v2(m4, m5, m6, m7);
	Vect v3(m8, m9, m10, m11);
	Vect v4(m12, m13, m14, m15);

	Matrix r(v1, v2, v3, v4);

	//Get determinant
	float det = r.det();

	//Take inverse
	float a = (m5 * m10 * m15 + m6 * m11 * m13 + m7 * m9 * m14 - m5 * m11 * m14 - m6 * m9 * m15 - m7 * m10 * m13) / det;

	float b = (m1 * m11 * m14 + m2 * m9 * m15 + m3 * m10 * m13 - m1 * m10 * m15 - m2 * m11 * m13 - m3 * m9 * m14) / det;

	float c = (m1 * m6 * m15 + m2 * m7 * m13 + m3 * m5 * m14 - m1 * m7 * m14 - m2 * m5 * m15 - m3 * m6 * m13) / det;

	float d = (m1 * m7 * m10 + m2 * m5 * m11 + m3 * m6 * m9 - m1 * m6 * m11 - m2 * m7 * m9 - m3 * m5 * m10) / det;

	float e = (m4 * m11 * m14 + m6 * m8 * m15 + m7 * m10 * m12 - m4 * m10 * m15 - m6 * m11 * m12 - m7 * m8 * m14) / det;

	float f = (m0 * m10 * m15 + m2 * m11 * m12 + m3 * m8 * m14 - m0 * m11 * m14 - m2 * m8 * m15 - m3 * m10 * m12) / det;

	float g = (m0 * m7 * m14 + m2 * m4 * m15 + m3 * m6 * m12 - m0 * m6 * m15 - m2 * m7 * m12 - m3 * m4 * m14) / det;

	float h = (m0 * m6 * m11 + m2 * m7 * m8 + m3 * m4 * m10 - m0 * m7 * m10 - m2 * m4 * m11 - m3 * m6 * m8) / det;

	float i = (m4 * m9 * m15 + m5 * m11 * m12 + m7 * m8 * m13 - m4 * m11 * m13 - m5 * m8 * m15 - m7 * m9 * m12) / det;

	float j = (m0 * m11 * m13 + m1 * m8 * m15 + m3 * m9 * m12 - m0 * m9 * m15 - m1 * m11 * m12 - m3 * m8 * m13) / det;

	float k = (m0 * m5 * m15 + m1 * m7 * m12 + m3 * m4 * m13 - m0 * m7 * m13 - m1 * m4 * m15 - m3 * m5 * m12) / det;

	float l = (m0 * m7 * m9 + m1 * m4 * m11 + m3 * m5 * m8 - m0 * m5 * m11 - m1 * m7 * m8 - m3 * m4 * m9) / det;

	float m = (m4 * m10 * m13 + m5 * m8 * m14 + m6 * m9 * m12 - m4 * m9 * m14 - m5 * m10 * m12 - m6 * m8 * m13) / det;

	float n = (m0 * m9 * m14 + m1 * m10 * m12 + m2 * m8 * m13 - m0 * m10 * m13 - m1 * m8 * 14 - m2 * m9 * m12) / det;

	float o = (m0 * m6 * m13 + m1 * m4 * m14 + m2 * m5 * m12 - m0 * m5 * m14 - m1 * m6 * m12 - m2 * m4 * m13) / det;

	float p = (m0 * m5 * m10 + m1 * m6 * m8 + m2 * m4 * m9 - m0 * m6 * m9 - m1 * m4 * m10 - m2 * m5 * m8) / det;

	//Setup return matrix
	v1[x] = a;
	v1[y] = b;
	v1[z] = c;
	v1[w] = d;

	v2[x] = e;
	v2[y] = f;
	v2[z] = g;
	v2[w] = h;

	v3[x] = i;
	v3[y] = j;
	v3[z] = k;
	v3[w] = l;

	v4[x] = m;
	v4[y] = n;
	v4[z] = o;
	v4[w] = p;

	r.set(ROW_0, v1);
	r.set(ROW_1, v2);
	r.set(ROW_2, v3);
	r.set(ROW_3, v4);

	return r;
}

//Set Identity Or Zero Matrix
void Matrix::set(const MatrixSpecialType type)
{
	float value;

	//Determine identity matrix or zero matrix
	if (type == 1)
	{
		value = 1.0;
	}

	else
	{
		value = 0.0;
	}

	//Set up identity matrix or zero matrix
	m0 = value;
	m1 = 0.0;
	m2 = 0.0;
	m3 = 0.0;

	m4 = 0.0;
	m5 = value;
	m6 = 0.0;
	m7 = 0.0;

	m8  = 0.0;
	m9  = 0.0;
	m10 = value;
	m11 = 0.0;

	m12 = 0.0;
	m13 = 0.0;
	m14 = 0.0;
	m15 = value;
}

//Set Translation Matrix
void Matrix::set(const MatrixTransType type, const float &x, const float &y, const float &z)
{
	//If translation matrix
	if (type == 0)
	{
		//Set up translation matrix
		m0 = 1.0;
		m1 = 0.0;
		m2 = 0.0;
		m3 = 0.0;

		m4 = 0.0;
		m5 = 1.0;
		m6 = 0.0;
		m7 = 0.0;

		m8  = 0.0;
		m9  = 0.0;
		m10 = 1.0;
		m11 = 0.0;

		m12 = x;
		m13 = y;
		m14 = z;
		m15 = 1.0;
	}
}

//Set Scale Matrix
void Matrix::set(const MatrixScaleType type, const float &x, const float &y, const float &z)
{
	//If scale matrix
	if (type == 0)
	{
		//Set up scale matrix
		m0 = x;
		m1 = 0.0;
		m2 = 0.0;
		m3 = 0.0;

		m4 = 0.0;
		m5 = y;
		m6 = 0.0;
		m7 = 0.0;

		m8  = 0.0;
		m9  = 0.0;
		m10 = z;
		m11 = 0.0;

		m12 = 0.0;
		m13 = 0.0;
		m14 = 0.0;
		m15 = 1.0;
	}
}

//Set Rot Matrix
void Matrix::set(const RotType type, const float &rad)
{
	float rot1 = cos(rad);
	float rot2 = sin(rad);
	
	//If rotaton about x
	if (type == 0)
	{	
		//Set up rotation matrix
		m0 = 1.0;
		m1 = 0.0;
		m2 = 0.0;
		m3 = 0.0;

		m4 = 0.0;
		m5 = rot1;
		m6 = rot2;
		m7 = 0.0;

		m8  = 0.0;
		m9  = -rot2;
		m10 = rot1;
		m11 = 0.0;

		m12 = 0.0;
		m13 = 0.0;
		m14 = 0.0;
		m15 = 1.0;
	}

	//If rotation about y
	else if (type == 1)
	{
		//Set up rotation matrix
		m0 = rot1;
		m1 = 0.0;
		m2 = -rot2;
		m3 = 0.0;

		m4 = 0.0;
		m5 = 1.0;
		m6 = 0.0;
		m7 = 0.0;

		m8  = rot2;
		m9  = 0.0;
		m10 = rot1;
		m11 = 0.0;

		m12 = 0.0;
		m13 = 0.0;
		m14 = 0.0;
		m15 = 1.0;
	}

	//If rotation about z
	else
	{
		//Set up rotation matrix
		m0 = rot1;
		m1 = rot2;
		m2 = 0.0;
		m3 = 0.0;

		m4 = -rot2;
		m5 = rot1;
		m6 = 0.0;
		m7 = 0.0;

		m8  = 0.0;
		m9  = 0.0;
		m10 = 1.0;
		m11 = 0.0;

		m12 = 0.0;
		m13 = 0.0;
		m14 = 0.0;
		m15 = 1.0;
	}
}

//Set Rotation Matrix About Arbitrary Axis
void Matrix::set(const RotAxisAngleType type, const Vect &axis, const float &rad)
{
	if (type == 0)
	{
		float c = cosf(rad);

		float s = sinf(rad);

		Vect v = axis;

		v.norm();

		////First row
		//m0 = c + (1 - c) * powf(v[x], 2.0f); 
		//m1 = (1 - c) * v[x] * v[y] - s * v[z]; 
		//m2 = (1 - c) * v[x] * v[z] + s * v[y]; 
		//m3 = 0.0f; 

		////Second row
		//m4 = (1 - c) * v[x] * v[y] + s * v[z]; 
		//m5 = c + (1 - c) * powf(v[y], 2.0f); 
		//m6 = (1 - c) * v[y] * v[z] - s * v[x]; 
		//m7 = 0.0f; 

		////Third row
		//m8 = (1 - c) * v[x] * v[z] - s * v[y]; 
		//m9 = (1 - c) * v[y] * v[z] + s * v[x]; 
		//m10 = c + (1 - c) * powf(v[z], 2.0f); 
		//m11 = 0.0f; 

		////Last row
		//m12 = 0.0f;
		//m13 = 0.0f;
		//m14 = 0.0f;
		//m15 = 1.0f;

		//First row
		m0 = c + (1 - c) * powf(v[x], 2.0f);
		m1 = (1 - c) * v[x] * v[y] + s * v[z];
		m2 = (1 - c) * v[x] * v[z] - s * v[y];
		m3 = 0.0f;

		//Second row
		m4 = (1 - c) * v[x] * v[y] - s * v[z];
		m5 = c + (1 - c) * powf(v[y], 2.0f);
		m6 = (1 - c) * v[y] * v[z] + s * v[x];
		m7 = 0.0f;

		//Third row
		m8 = (1 - c) * v[x] * v[z] + s * v[y];
		m9 = (1 - c) * v[y] * v[z] - s * v[x];
		m10 = c + (1 - c) * powf(v[z], 2.0f);
		m11 = 0.0f;

		//Fourth row
		m12 = 0.0f;
		m13 = 0.0f;
		m14 = 0.0f;
		m15 = 1.0f;
	}
}

//Set Orientation Rotation Matrix
void Matrix::set(const RotOrientType type, const Vect &dof, const Vect &up)
{
	if (type == 0)
	{
		//Grab dof and normalize
		Vect dir = dof;

		dir.norm();

		//Correct up vector and normalize
		Vect upCorrected = dir.cross(up.cross(dir));

		upCorrected.norm();

		//Find the right vector and normalize
		Vect right = -dir.cross(upCorrected);

		//Produce matrix
		//First row
		m0 = right[x];
		m1 = right[y];
		m2 = right[z];
		m3 = 0.0f;

		//Second row
		m4 = upCorrected[x];
		m5 = upCorrected[y];
		m6 = upCorrected[z];
		m7 = 0.0f;

		//Third row
		m8  = dir[x];
		m9  = dir[y];
		m10 = dir[z];
		m11 = 0.0f;

		//Fourth row
		m12 = 0.0f;
		m13 = 0.0f;
		m14 = 0.0f;
		m15 = 1.0f;
	}

	else
	{
		//Grab dof and normalize
		Vect dir = dof;

		dir.norm();

		//Correct up vector and normalize
		Vect upCorrected = dir.cross(up.cross(dir));

		upCorrected.norm();

		//Find the right vector and normalize
		Vect right = -dir.cross(upCorrected);

		//Produce matrix
		//First row
		m0 = right[x];
		m1 = right[y];
		m2 = right[z];
		m3 = 0.0f;

		//Second row
		m4 = upCorrected[x];
		m5 = upCorrected[y];
		m6 = upCorrected[z];
		m7 = 0.0f;

		//Third row
		m8  = dir[x];
		m9  = dir[y];
		m10 = dir[z];
		m11 = 0.0f;

		//Fourth row
		m12 = 0.0f;
		m13 = 0.0f;
		m14 = 0.0f;
		m15 = 1.0f;
	}
}

//Set Row
void Matrix::set(const MatrixRowType type, const Vect &in)
{
	//If row0
	if (type == 0)
	{
		m0 = in[x];
		m1 = in[y];
		m2 = in[z];
		m3 = in[w];
	}

	//If row1
	else if (type == 1)
	{
		m4 = in[x];
		m5 = in[y];
		m6 = in[z];
		m7 = in[w];
	}

	//If row2
	else if (type == 2)
	{
		m8  = in[x];
		m9  = in[y];
		m10 = in[z];
		m11 = in[w];
	}

	//If row3
	else
	{
		m12 = in[x];
		m13 = in[y];
		m14 = in[z];
		m15 = in[w];
	}
}

//Set Matrix Through Vectors
void Matrix::set(const Vect &v1, const Vect &v2, const Vect &v3, const Vect &v4)
{
	//Set first row
	m0 = v1[x];
	m1 = v1[y];
	m2 = v1[z];
	m3 = v1[w];

	//Set second row
	m4 = v2[x];
	m5 = v2[y];
	m6 = v2[z];
	m7 = v2[w];

	//Set third row
	m8  = v3[x];
	m9  = v3[y];
	m10 = v3[z];
	m11 = v3[w];

	//Set fourth row
	m12 = v4[x];
	m13 = v4[y];
	m14 = v4[z];
	m15 = v4[w];
}

//Set Matrix Through Quaternion
void Matrix::set(const Quat &q)
{
	//Set first row
	m0 = 1 - 2 * (q[y] * q[y] + q[z] * q[z]);
	m1 = 2 * (q[x] * q[y] + q[w] * q[z]);
	m2 = 2 * (q[x] * q[z] - q[w] * q[y]); //
	m3 = 0.0;

	//Set second row
	m4 = 2 * (q[x] * q[y] - q[w] * q[z]);
	m5 = 1 - 2 * (q[x] * q[x] + q[z] * q[z]);
	m6 = 2 * (q[y] * q[z] + q[w] * q[x]);
	m7 = 0.0;

	//Set third row
	m8  = 2 * (q[x] * q[z] + q[w] * q[y]);
	m9  = 2 * (q[y] * q[z] - q[w] * q[x]);
	m10 = 1 - 2 * (q[x] * q[x] + q[y] * q[y]);
	m11 = 0.0;

	//Set fourth row
	m12 = 0.0;
	m13 = 0.0;
	m14 = 0.0;
	m15 = 1.0;
}

//Assignment Operator
void Matrix::operator = (const Matrix &in)
{
	m0 = in.m0;
	m1 = in.m1;
	m2 = in.m2;
	m3 = in.m3;

	m4 = in.m4;
	m5 = in.m5;
	m6 = in.m6;
	m7 = in.m7;

	m8  = in.m8;
	m9  = in.m9;
	m10 = in.m10;
	m11 = in.m11;

	m12 = in.m12;
	m13 = in.m13;
	m14 = in.m14;
	m15 = in.m15;
}

//+= Operator
void Matrix::operator +=(const Matrix &in)
{
	//Add like terms
	m0 += in.m0;
	m1 += in.m1;
	m2 += in.m2;
	m3 += in.m3;

	m4 += in.m4;
	m5 += in.m5;
	m6 += in.m6;
	m7 += in.m7;

	m8  += in.m8;
	m9  += in.m9;
	m10 += in.m10;
	m11 += in.m11;

	m12 += in.m12;
	m13 += in.m13;
	m14 += in.m14;
	m15 += in.m15;
}

//-= Operator
void Matrix::operator -= (const Matrix &in)
{
	//Subtract like terms
	m0 -= in.m0;
	m1 -= in.m1;
	m2 -= in.m2;
	m3 -= in.m3;

	m4 -= in.m4;
	m5 -= in.m5;
	m6 -= in.m6;
	m7 -= in.m7;

	m8  -= in.m8;
	m9  -= in.m9;
	m10 -= in.m10;
	m11 -= in.m11;

	m12 -= in.m12;
	m13 -= in.m13;
	m14 -= in.m14;
	m15 -= in.m15;
}

//*= Operator - Matrix
void Matrix::operator *= (const Matrix &in)
{
	//Set up vectors for dot products
	Vect v1(m0, m1, m2, m3);
	Vect v2(m4, m5, m6, m7);
	Vect v3(m8, m9, m10, m11);
	Vect v4(m12, m13, m14, m15);

	Vect v5(in.m0, in.m4, in.m8, in.m12);
	Vect v6(in.m1, in.m5, in.m9, in.m13);
	Vect v7(in.m2, in.m6, in.m10, in.m14);
	Vect v8(in.m3, in.m7, in.m11, in.m15);

	//Take dot products and add the last term
	Vect r1(v1.dot(v5) + m3 * in.m12, v1.dot(v6) + m3 * in.m13, v1.dot(v7) + m3 * in.m14, v1.dot(v8) + m3 * in.m15);

	Vect r2(v2.dot(v5) + m7 * in.m12, v2.dot(v6) + m7 * in.m13, v2.dot(v7) + m7 * in.m14, v2.dot(v8) + m7 * in.m15);

	Vect r3(v3.dot(v5) + m11 * in.m12, v3.dot(v6) + m11 * in.m13, v3.dot(v7) + m11 * in.m14, v3.dot(v8) + m11 * in.m15);

	Vect r4(v4.dot(v5) + m15 * in.m12, v4.dot(v6) + m15 * in.m13, v4.dot(v7) + m15 * in.m14, v4.dot(v8) + m15 * in.m15);

	//Reset the matrix with the calculated values
	m0 = r1[x];
	m1 = r1[y];
	m2 = r1[z];
	m3 = r1[w];

	m4 = r2[x];
	m5 = r2[y];
	m6 = r2[z];
	m7 = r2[w];

	m8  = r3[x];
	m9  = r3[y];
	m10 = r3[z];
	m11 = r3[w];

	m12 = r4[x];
	m13 = r4[y];
	m14 = r4[z];
	m15 = r4[w];
}

//*= Operator - Scalar
void Matrix::operator *= (const float &s)
{
	//Mutliply each term by s
	m0 *= s;
	m1 *= s;
	m2 *= s;
	m3 *= s;

	m4 *= s;
	m5 *= s;
	m6 *= s;
	m7 *= s;

	m8  *= s;
	m9  *= s;
	m10 *= s;
	m11 *= s;

	m12 *= s;
	m13 *= s;
	m14 *= s;
	m15 *= s;
}

//M0 Bracket Operator - Get
float Matrix::operator[](const m0_enum) const
{
	return m0;
}

//M1 Bracket Operator - Get
float Matrix::operator[](const m1_enum) const
{
	return m1;
}

//M2 Bracket Operator - Get
float Matrix::operator[](const m2_enum) const
{
	return m2;
}

//M3 Bracket Operator - Get
float Matrix::operator[](const m3_enum) const
{
	return m3;
}

//M4 Bracket Operator - Get
float Matrix::operator[](const m4_enum) const
{
	return m4;
}

//M5 Bracket Operator - Get
float Matrix::operator[](const m5_enum) const
{
	return m5;
}

//M6 Bracket Operator - Get
float Matrix::operator[](const m6_enum) const
{
	return m6;
}

//M7 Bracket Operator - Get
float Matrix::operator[](const m7_enum) const
{
	return m7;
}

//M8 Bracket Operator - Get
float Matrix::operator[](const m8_enum) const
{
	return m8;
}

//M9 Bracket Operator - Get
float Matrix::operator[](const m9_enum) const
{
	return m9;
}

//M10 Bracket Operator - Get
float Matrix::operator[](const m10_enum) const
{
	return m10;
}

//M11 Bracket Operator - Get
float Matrix::operator[](const m11_enum) const
{
	return m11;
}

//M12 Bracket Operator - Get
float Matrix::operator[](const m12_enum) const
{
	return m12;
}

//M13 Bracket Operator - Get
float Matrix::operator[](const m13_enum) const
{
	return m13;
}

//M14 Bracket Operator - Get
float Matrix::operator[](const m14_enum) const
{
	return m14;
}

//M15 Bracket Operator - Get
float Matrix::operator[](const m15_enum) const
{
	return m15;
}

//M0 Bracket Operator - Set
float& Matrix::operator[](const m0_enum)
{
	return m0;
}

//M1 Bracket Operator - Set
float& Matrix::operator[](const m1_enum)
{
	return m1;
}

//M2 Bracket Operator - Set
float& Matrix::operator[](const m2_enum)
{
	return m2;
}

//M3 Bracket Operator - Set
float& Matrix::operator[](const m3_enum)
{
	return m3;
}

//M4 Bracket Operator - Set
float& Matrix::operator[](const m4_enum)
{
	return m4;
}

//M5 Bracket Operator - Set
float& Matrix::operator[](const m5_enum)
{
	return m5;
}

//M6 Bracket Operator - Set
float& Matrix::operator[](const m6_enum)
{
	return m6;
}

//M7 Bracket Operator - Set
float& Matrix::operator[](const m7_enum)
{
	return m7;
}

//M8 Bracket Operator - Set
float& Matrix::operator[](const m8_enum)
{
	return m8;
}

//M9 Bracket Operator - Set
float& Matrix::operator[](const m9_enum)
{
	return m9;
}

//M10 Bracket Operator - Set
float& Matrix::operator[](const m10_enum)
{
	return m10;
}

//M11 Bracket Operator - Set
float& Matrix::operator[](const m11_enum)
{
	return m11;
}

//M12 Bracket Operator - Set
float& Matrix::operator[](const m12_enum)
{
	return m12;
}

//M13 Bracket Operator - Set
float& Matrix::operator[](const m13_enum)
{
	return m13;
}

//M14 Bracket Operator - Set
float& Matrix::operator[](const m14_enum)
{
	return m14;
}

//M15 Bracket Operator - Set
float& Matrix::operator[](const m15_enum)
{
	return m15;
}

//Test For Equality
bool Matrix::isEqual(const Matrix &in)
{
	//Set up comparison vectors
	Vect v1(m0, m1, m2, m3);
	Vect v2(m4, m5, m6, m7);
	Vect v3(m8, m9, m10, m11);
	Vect v4(m12, m13, m14, m15);

	Vect v5(in.m0, in.m1, in.m2, in.m3);
	Vect v6(in.m4, in.m5, in.m6, in.m7);
	Vect v7(in.m8, in.m9, in.m10, in.m11);
	Vect v8(in.m12, in.m13, in.m14, in.m15);

	bool value = false;

	//Check top row
	if (v1.isEqual(v5))
	{
		value = true;
	}

	else
	{
		return value = false;
	}

	//Check second row
	if (v2.isEqual(v6))
	{
		//If here value already equals true
	}

	else
	{
		return value = false;
	}

	//Check third row
	if (v3.isEqual(v7))
	{
		//If here value already equals true
	}

	else
	{
		return value = false;
	}

	//Check last row
	if (v4.isEqual(v8))
	{
		//If here value already equals true
	}

	else
	{
		return value = false;
	}

	return value;
}

//Test For Identity
bool Matrix::isIdentity() const
{
	//Set up comparison vectors
	Vect v1(m0, m1, m2, m3);
	Vect v2(m4, m5, m6, m7);
	Vect v3(m8, m9, m10, m11);
	Vect v4(m12, m13, m14, m15);

	Vect v5(1.0f, 0.0f, 0.0f, 0.0f);
	Vect v6(0.0f, 1.0f, 0.0f, 0.0f);
	Vect v7(0.0f, 0.0f, 1.0f, 0.0f);
	Vect v8(0.0f, 0.0f, 0.0f, 1.0f);

	bool value = false;

	//Check top row
	if (v1.isEqual(v5))
	{
		value = true;
	}

	else
	{
		return value = false;
	}

	//Check second row
	if (v2.isEqual(v6))
	{
		//If here value already equals true
	}

	else
	{
		return value = false;
	}

	//Check third row
	if (v3.isEqual(v7))
	{
		//If here value already equals true
	}

	else
	{
		return value = false;
	}

	//Check last row
	if (v4.isEqual(v8))
	{
		//If here value already equals true
	}

	else
	{
		return value = false;
	}

	return value;

}

//Test For Identity
bool Matrix::isIdentity(const float &epsilon)
{
	//Set up comparison vectors
	Vect v1(m0, m1, m2, m3);
	Vect v2(m4, m5, m6, m7);
	Vect v3(m8, m9, m10, m11);
	Vect v4(m12, m13, m14, m15);

	Vect v5(1.0f, 0.0f, 0.0f, 0.0f);
	Vect v6(0.0f, 1.0f, 0.0f, 0.0f);
	Vect v7(0.0f, 0.0f, 1.0f, 0.0f);
	Vect v8(0.0f, 0.0f, 0.0f, 1.0f);

	bool value = false;

	//Check top row
	if (v1.isEqual(v5, epsilon))
	{
		value = true;
	}

	else
	{
		return value = false;
	}

	//Check second row
	if (v2.isEqual(v6, epsilon))
	{
		//If here value already equals true
	}

	else
	{
		return value = false;
	}

	//Check third row
	if (v3.isEqual(v7, epsilon))
	{
		//If here value already equals true
	}

	else
	{
		return value = false;
	}

	//Check last row
	if (v4.isEqual(v8, epsilon))
	{
		//If here value already equals true
	}

	else
	{
		return value = false;
	}

	return value;
}

//Determinant
float Matrix::det() const
{
	float a = m0 * m5 * m10 * m15 + m0 * m6 * m11 * m13 + m0 * m7 * m9 * m14 
		      - m0 * m5 * m11 * m14 - m0 * m6 * m9 * m15 - m0 * m7 * m10 * m13;

	float b = m1 * m4 * m11 * m14 + m1 * m6 * m8 * m15 + m1 * m7 * m10 * m12
		      - m1 * m4 * m10 * m15 - m1 * m6 * m11 * m12 - m1 * m7 * m8 * m14;

	float c = m2 * m4 * m9 * m15 + m2 * m5 * m11 * m12 + m2 * m7 * m8 * m13
		      - m2 * m4 * m11 * m13 - m2 * m5 * m8 * m15 - m2 * m7 * m9 * m12;

	float d = m3 * m4 * m10 * m13 + m3 * m5 * m8 * m14 + m3 * m6 * m9 * m12
		      - m3 * m4 * m9 * m14 - m3 * m5 * m10 * m12 - m3 * m6 * m8 * m13;

	return a + b + c + d;
}

//Transpose
void Matrix::T()
{
	//Setup vectors for transpose
	Vect v1(m0, m1, m2, m3);
	Vect v2(m4, m5, m6, m7);
	Vect v3(m8, m9, m10, m11);
	Vect v4(m12, m13, m14, m15);

	//Transpoes the matrix
	m0 = v1[x];
	m1 = v2[x];
	m2 = v3[x];
	m3 = v4[x];

	m4 = v1[y];
	m5 = v2[y];
	m6 = v3[y];
	m7 = v4[y];

	m8  = v1[z];
	m9  = v2[z];
	m10 = v3[z];
	m11 = v4[z];

	m12 = v1[w];
	m13 = v2[w];
	m14 = v3[w];
	m15 = v4[w];
}

//Inverse
void Matrix::inv()
{
	//Setup matrix to pass
	Vect v1(m0, m1, m2, m3);
	Vect v2(m4, m5, m6, m7);
	Vect v3(m8, m9, m10, m11);
	Vect v4(m12, m13, m14, m15);

	Matrix r(v1, v2, v3, v4);

	//Get determinant
	float det = r.det();

	//Take inverse
	float a = (m5 * m10 * m15 + m6 * m11 * m13 + m7 * m9 * m14 - m5 * m11 * m14 - m6 * m9 * m15 - m7 * m10 * m13) / det;

	float b = (m1 * m11 * m14 + m2 * m9 * m15 + m3 * m10 * m13 - m1 * m10 * m15 - m2 * m11 * m13 - m3 * m9 * m14) / det;

	float c = (m1 * m6 * m15 + m2 * m7 * m13 + m3 * m5 * m14 - m1 * m7 * m14 - m2 * m5 * m15 - m3 * m6 * m13) / det;

	float d = (m1 * m7 * m10 + m2 * m5 * m11 + m3 * m6 * m9 - m1 * m6 * m11 - m2 * m7 * m9 - m3 * m5 * m10) / det;

	float e = (m4 * m11 * m14 + m6 * m8 * m15 + m7 * m10 * m12 - m4 * m10 * m15 - m6 * m11 * m12 - m7 * m8 * m14) / det;

	float f = (m0 * m10 * m15 + m2 * m11 * m12 + m3 * m8 * m14 - m0 * m11 * m14 - m2 * m8 * m15 - m3 * m10 * m12) / det;

	float g = (m0 * m7 * m14 + m2 * m4 * m15 + m3 * m6 * m12 - m0 * m6 * m15 - m2 * m7 * m12 - m3 * m4 * m14) / det;

	float h = (m0 * m6 * m11 + m2 * m7 * m8 + m3 * m4 * m10 - m0 * m7 * m10 - m2 * m4 * m11 - m3 * m6 * m8) / det;

	float i = (m4 * m9 * m15 + m5 * m11 * m12 + m7 * m8 * m13 - m4 * m11 * m13 - m5 * m8 * m15 - m7 * m9 * m12) / det;

	float j = (m0 * m11 * m13 + m1 * m8 * m15 + m3 * m9 * m12 - m0 * m9 * m15 - m1 * m11 * m12 - m3 * m8 * m13) / det;

	float k = (m0 * m5 * m15 + m1 * m7 * m12 + m3 * m4 * m13 - m0 * m7 * m13 - m1 * m4 * m15 - m3 * m5 * m12) / det;

	float l = (m0 * m7 * m9 + m1 * m4 * m11 + m3 * m5 * m8 - m0 * m5 * m11 - m1 * m7 * m8 - m3 * m4 * m9) / det;

	float m = (m4 * m10 * m13 + m5 * m8 * m14 + m6 * m9 * m12 - m4 * m9 * m14 - m5 * m10 * m12 - m6 * m8 * m13) / det;

	float n = (m0 * m9 * m14 + m1 * m10 * m12 + m2 * m8 * m13 - m0 * m10 * m13 - m1 * m8 * 14 - m2 * m9 * m12) / det;

	float o = (m0 * m6 * m13 + m1 * m4 * m14 + m2 * m5 * m12 - m0 * m5 * m14 - m1 * m6 * m12 - m2 * m4 * m13) / det;

	float p = (m0 * m5 * m10 + m1 * m6 * m8 + m2 * m4 * m9 - m0 * m6 * m9 - m1 * m4 * m10 - m2 * m5 * m8) / det;

	//Reassign matrix
	m0 = a;
	m1 = b;
	m2 = c;
	m3 = d;

	m4 = e;
	m5 = f;
	m6 = g;
	m7 = h;

	m8 =  i;
	m9 =  j;
	m10 = k;
	m11 = l;

	m12 = m;
	m13 = n;
	m14 = o;
	m15 = p;
}

//Adding Matrices
Matrix operator + (const Matrix &m, const Matrix &n)
{
	//Add like terms
	Vect v1(m[m0] + n[m0], m[m1] + n[m1], m[m2] + n[m2], m[m3] + n[m3]);

	Vect v2(m[m4] + n[m4], m[m5] + n[m5], m[m6] + n[m6], m[m7] + n[m7]);

	Vect v3(m[m8] + n[m8], m[m9] + n[m9], m[m10] + n[m10], m[m11] + n[m11]);

	Vect v4(m[m12] + n[m12], m[m13] + n[m13], m[m14] + n[m14], m[m15] + n[m15]);
	
	return Matrix(v1, v2, v3, v4);
}

//Subtracting Matrices
Matrix operator - (const Matrix &m, const Matrix &n)
{
	//Subtract like terms
	Vect v1(m[m0] - n[m0], m[m1] - n[m1], m[m2] - n[m2], m[m3] - n[m3]);

	Vect v2(m[m4] - n[m4], m[m5] - n[m5], m[m6] - n[m6], m[m7] - n[m7]);

	Vect v3(m[m8] - n[m8], m[m9] - n[m9], m[m10] - n[m10], m[m11] - n[m11]);

	Vect v4(m[m12] - n[m12], m[m13] - n[m13], m[m14] - n[m14], m[m15] - n[m15]);

	return Matrix(v1, v2, v3, v4);
}

//Multiply Matrices
Matrix operator * (const Matrix &m, const Matrix &n)
{
	//Set up vectors for dot products
	Vect v1(m[m0], m[m1], m[m2], m[m3]);
	Vect v2(m[m4], m[m5], m[m6], m[m7]);
	Vect v3(m[m8], m[m9], m[m10], m[m11]);
	Vect v4(m[m12], m[m13], m[m14], m[m15]);

	Vect v5(n[m0], n[m4], n[m8], n[m12]);
	Vect v6(n[m1], n[m5], n[m9], n[m13]);
	Vect v7(n[m2], n[m6], n[m10], n[m14]);
	Vect v8(n[m3], n[m7], n[m11], n[m15]);

	//Take dot products and add the last component
	Vect r1(v1.dot(v5) + m[m3] * n[m12], v1.dot(v6) + m[m3] * n[m13], v1.dot(v7) + m[m3] * n[m14], v1.dot(v8) + m[m3] * n[m15]);

	Vect r2(v2.dot(v5) + m[m7] * n[m12], v2.dot(v6) + m[m7] * n[m13], v2.dot(v7) + m[m7] * n[m14], v2.dot(v8) + m[m7] * n[m15]);

	Vect r3(v3.dot(v5) + m[m11] * n[m12], v3.dot(v6) + m[m11] * n[m13], v3.dot(v7) + m[m11] * n[m14], v3.dot(v8) + m[m11] * n[m15]);

	Vect r4(v4.dot(v5) + m[m15] * n[m12], v4.dot(v6) + m[m15] * n[m13], v4.dot(v7) + m[m15] * n[m14], v4.dot(v8) + m[m15] * n[m15]);

	return Matrix(r1, r2, r3, r4);
}

//Scalar Times A Matrix
Matrix operator * (const float &s, const Matrix &n)
{
	//Mutliply each term by s
	Vect v1(s * n[m0], s * n[m1], s * n[m2], s * n[m3]);
	Vect v2(s * n[m4], s * n[m5], s * n[m6], s * n[m7]);
	Vect v3(s * n[m8], s * n[m9], s * n[m10], s * n[m11]);
	Vect v4(s * n[m12], s * n[m13], s * n[m14], s * n[m15]);

	return Matrix(v1, v2, v3, v4);
}

//Matrix Times A Scalar
Matrix operator * (const Matrix &n, const float &s)
{
	//Mutliply each term by s
	Vect v1(s * n[m0], s * n[m1], s * n[m2], s * n[m3]);
	Vect v2(s * n[m4], s * n[m5], s * n[m6], s * n[m7]);
	Vect v3(s * n[m8], s * n[m9], s * n[m10], s * n[m11]);
	Vect v4(s * n[m12], s * n[m13], s * n[m14], s * n[m15]);

	return Matrix(v1, v2, v3, v4);
}

//Unary +
Matrix operator + (const Matrix &in)
{
	//Take in inbound matrix and return it
	Vect v1(in[m0], in[m1], in[m2], in[m3]); 
	Vect v2(in[m4], in[m5], in[m6], in[m7]); 
	Vect v3(in[m8], in[m9], in[m10], in[m11]); 
	Vect v4(in[m12], in[m13], in[m14], in[m15]);

	return Matrix(v1, v2, v3, v4);
}

//Unary -
Matrix operator - (const Matrix &in)
{
	//Take in inbound matrix and return its negative
	Vect v1(-in[m0], -in[m1], -in[m2], -in[m3]); 
	Vect v2(-in[m4], -in[m5], -in[m6], -in[m7]); 
	Vect v3(-in[m8], -in[m9], -in[m10], -in[m11]); 
	Vect v4(-in[m12], -in[m13], -in[m14], -in[m15]);

	return Matrix(v1, v2, v3, v4);
}

