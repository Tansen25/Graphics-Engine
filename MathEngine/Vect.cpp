#include "MathEngine.h"
#include <math.h>
#include <iostream>
//Default Constructor
Vect::Vect()
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
	w = 1.0;
}

//Copy Constructor
Vect::Vect(const Vect &in)
{
	x = in.x;
	y = in.y;
	z = in.z;
	w = in.w;
}

//Specialized Constructor
Vect::Vect(float inX, float inY, float inZ)
{
	x = inX;
	y = inY;
	z = inZ;
	w = 1.0;
}

//Specialized Constructor
Vect::Vect(float inX, float inY, float inZ, float inW)
{
	x = inX;
	y = inY;
	z = inZ;
	w = inW;
}

//Destructor
Vect::~Vect()
{
	//Do Nothing
}

//Set
void Vect::set(const float x_set, const float y_set, const float z_set)
{
	x = x_set;
	y = y_set;
	z = z_set;
	w = 1.0;
}

//Set
void Vect::set(const float x_set, const float y_set, const float z_set, const float w_set)
{
	x = x_set;
	y = y_set;
	z = z_set;
	w = w_set;
}

//Set
void Vect::set(const Vect &in)
{
	x = in.x;
	y = in.y;
	z = in.z;
	w = in.w;
}

//Assignment Operator
void Vect::operator = (const Vect& in)
{
	x = in.x;
	y = in.y;
	z = in.z;
	w = in.w;
}

//+= Operator
void Vect::operator +=(const Vect &in)
{
	x += in.x;
	y += in.y;
	z += in.z;
	w = 1.0;
}

//-= Operator
void Vect::operator -=(const Vect &in)
{
	x -= in.x;
	y -= in.y;
	z -= in.z;
	w = 1.0;
}

//*= Operator - Scalar
void Vect::operator *=(const float &s)
{
	x *= s;
	y *= s;
	z *= s;
	w = 1.0;
}

//*= Operator - Matrix
void Vect::operator *=(const Matrix &m)
{
	float a = x;
	float b = y;
	float c = z;
	float d = w;
	
	//Carry out 1x4 * 4x4 matrix multiplication
	x = a * m[m0] + b * m[m4] + c * m[m8] + d * m[m12];
	
	y = a * m[m1] + b * m[m5] + c * m[m9] + d * m[m13];

	z = a * m[m2] + b * m[m6] + c * m[m10] + d * m[m14];

	w = a * m[m3] + b * m[m7] + c * m[m11] + d * m[m15];
}

//Dot Product
float Vect::dot(const Vect &in) const
{
	return x * in.x + y * in.y + z * in.z;
}

//Cross Product
Vect Vect::cross(const Vect &in) const
{
	float out_x = y * in.z - in.y * z;

	float out_y = z * in.x - in.z * x;

	float out_z = x * in.y - in.x * y;

	return Vect(out_x, out_y, out_z);
}

//Normalize
void Vect::norm()
{
	float length = sqrt(pow(x,2) + pow(y,2) + pow(z,2));

	x = x / length;
	
	y = y / length;

	z = z / length;

	w = 1.0;
}

//Get Normal
Vect Vect::getNorm()
{
	float length = sqrt(pow(x,2) + pow(y,2) + pow(z,2));

	return Vect(x / length, y / length, z / length, 1.0);
}

//Magnitude
float Vect::mag()
{
	return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
}

//Magnitude squared
float Vect::magSqr()
{
	return pow(x,2) + pow(y,2) + pow(z,2);
}

//Get Angle
float Vect::getAngle(const Vect &in)
{
	return acos((x * in.x + y * in.y + z * in.z) / (sqrt(pow(x,2) + pow(y,2) + pow(z,2)) * sqrt(pow(in.x,2) + pow(in.y,2) + pow(in.z,2))));
}

//X Bracket Operator - Get
float Vect::operator[](const x_enum) const
{
	return x;
}

//Y Bracket Operator - Get
float Vect::operator[](const y_enum) const
{
	return y;
}

//Z Bracket Operator - Get
float Vect::operator[](const z_enum) const
{
	return z;
}

//W Bracket Operator - Get
float Vect::operator[](const w_enum) const
{
	return w;
}

//X Bracket Operator - Set
float& Vect::operator[](const x_enum)
{
	return x;
}

//Y Bracket Operator - Set
float& Vect::operator[](const y_enum)
{
	return y;
}

//Z Bracket Operator - Set
float& Vect::operator[](const z_enum)
{
	return z;
}

//W Bracket Operator - Set
float& Vect::operator[](const w_enum)
{
	return w;
}

//Test For Equality
bool Vect::isEqual(const Vect &v)
{
	bool equal = false;

	//Check X
	if (Util::isEqual(x, v.x, 1e-10f))
	{
		equal = true;
	}

	else
	{
		return (equal = false);
	}

	//Check Y
	if (Util::isEqual(y, v.y, 1e-10f))
	{
		equal = true;
	}

	else
	{
		return (equal = false);
	}

	//Check Z
	if (Util::isEqual(z, v.z, 1e-10f))
	{
		equal = true;
	}

	else
	{
		return (equal = false);
	}

	//Check W
	if (Util::isEqual(w, v.w, 1e-10f))
	{
		equal = true;
	}

	else
	{
		return (equal = false);
	}

	return equal;
}

//Test For Equality
bool Vect::isEqual(const Vect &v, const float &epsilon)
{
	bool equal = false;

	//Check X
	if (Util::isEqual(x, v.x, epsilon))
	{
		equal = true;
	}

	else
	{
		return (equal = false);
	}

	//Check Y
	if (Util::isEqual(y, v.y, epsilon))
	{
		equal = true;
	}

	else
	{
		return (equal = false);
	}

	//Check Z
	if (Util::isEqual(z, v.z, epsilon))
	{
		equal = true;
	}

	else
	{
		return (equal = false);
	}

	//Check W
	if (Util::isEqual(w, v.w, epsilon))
	{
		equal = true;
	}

	else
	{
		return (equal = false);
	}

	return equal;
}

//Test For Zero
bool Vect::isZero()
{
	bool equal = false;

	//Check X
	if (Util::isZero(x, 1e-10f))
	{
		equal = true;
	}

	else
	{
		return (equal = false);
	}

	//Check Y
	if (Util::isZero(y, 1e-10f))
	{
		equal = true;
	}

	else
	{
		return (equal = false);
	}

	//Check Z
	if (Util::isZero(z, 1e-10f))
	{
		equal = true;
	}

	else
	{
		return (equal = false);
	}

	//Check w
	if (Util::isZero(w, 1e-10f))
	{
		equal = true;
	}

	else
	{
		return (equal = false);
	}

	return equal;
}

//Test For Zero
bool Vect::isZero(const float &epsilon)
{
	bool equal = false;

	//Check X
	if (Util::isZero(x, epsilon))
	{
		equal = true;
	}

	else
	{
		return (equal = false);
	}

	//Check Y
	if (Util::isZero(y, epsilon))
	{
		equal = true;
	}

	else
	{
		return (equal = false);
	}

	//Check Z
	if (Util::isZero(z, epsilon))
	{
		equal = true;
	}

	else
	{
		return (equal = false);
	}

	return equal;
}

//Adding Vectors
Vect operator +(const Vect &v, const Vect &w)
{
	return Vect(v[x] + w[x], v[y] + w[y], v[z] + w[z]);
}

//Subtracting Vectors
Vect operator -(const Vect &v, const Vect &w)
{
	return Vect(v[x] - w[x], v[y] - w[y], v[z] - w[z]);
}

//Multiplying A Scalar By A Vector
Vect operator *(const float &s, const Vect &v)
{
	return Vect(s * v[x], s * v[y], s * v[z]);
}

//Multiplying A Vector By A Scalar
Vect operator *(const Vect &v, const float &s)
{
	return Vect(v[x] * s, v[y] * s, v[z] * s);
}

//Multiplying A Vector By A Matrix
Vect operator *(const Vect &v, const Matrix &m)
{
	//Carry out 1x4 * 4x4 matrix multiplication
	float a = v[x] * m[m0] + v[y] * m[m4] + v[z] * m[m8] + v[w] * m[m12];
	
	float b = v[x] * m[m1] + v[y] * m[m5] + v[z] * m[m9] + v[w] * m[m13];

	float c = v[x] * m[m2] + v[y] * m[m6] + v[z] * m[m10] + v[w] * m[m14];

	float d = v[x] * m[m3] + v[y] * m[m7] + v[z] * m[m11] + v[w] * m[m15];

	return Vect(a, b, c, d);
}

//Multiplying A Vector By A Quaternion
Vect operator *(const Vect &v, const Quat &q)
{
	float a = 2.0f * q[w] * q[y] * v[z] - 2.0f * q[w] * q[z] * v[y] + q[w] * q[w] * v[x] - q[x] * q[x] * v[x] 
				- q[y] * q[y] * v[x] - q[z] * q[z] * v[x] + 2.0f * q[x] * v[x] * q[x] + 2.0f * q[y] * v[y] * q[x]
				+ 2.0f * q[z] * v[z] * q[x];

	float b = 2.0f * q[w] * q[z] * v[x] - 2.0f * q[w] * q[x] * v[z] + q[w] * q[w] * v[y] - q[x] * q[x] * v[y] 
				- q[y] * q[y] * v[y] - q[z] * q[z] * v[y] + 2.0f * q[x] * v[x] * q[y] + 2.0f * q[y] * v[y] * q[y]
				+ 2.0f * q[z] * v[z] * q[y];

	float c = 2.0f * q[w] * q[x] * v[y] - 2.0f * q[w] * q[y] * v[x] + q[w] * q[w] * v[z] - q[x] * q[x] * v[z] 
				- q[y] * q[y] * v[z] - q[z] * q[z] * v[z] + 2.0f * q[x] * v[x] * q[z] + 2.0f * q[y] * v[y] * q[z]
				+ 2.0f * q[z] * v[z] * q[z];

	float d = 1.0f;

	return Vect(a, b, c, d);
}

//Unary +
Vect operator +(const Vect &in)
{
	return Vect(in[x], in[y], in[z], 1.0);
}

//Unary -
Vect operator -(const Vect &in)
{
	return Vect(-in[x], -in[y], -in[z], 1.0);
}