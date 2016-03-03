#ifndef ENGINE_MATH_VECT_H
#define ENGINE_MATH_VECT_H

// Includes to handle SIMD register types
#include <xmmintrin.h>
#include <smmintrin.h> 

#include "Enum.h"

// forward declare
class Matrix;
class Quat;

class Vect
{
public:
    // Do your magic here:
	//Default Constructor
	Vect();

	//Copy Constructor
	Vect(const Vect &in);

	//Specialized Constructors
	Vect(float inX, float inY, float inZ);
	Vect(float inX, float inY, float inZ, float inW);

	//Destructor
	~Vect();

	//Set
	void set(const float x_set, const float y_set, const float z_set);

	//Set
	void set(const float x_set, const float y_set, const float z_set, const float w_set);

	//Set
	void set(const Vect &in);

	//Assignment Operator
	void operator = (const Vect &in);

	//+= Operator
	void operator +=(const Vect &in);

	//-= Operator
	void operator -=(const Vect &in);

	//*= Operator - Scalar
	void operator *=(const float &s);

	//*= Operator - Matrix
	void operator *=(const Matrix &m);

	//Dot Product
	float dot(const Vect &in) const;

	//Cross Product
	Vect cross(const Vect &in) const;

	//Normalize
	void norm();

	//Get Normal
	Vect getNorm();

	//Magnitude
	float mag();

	//Magnitude squared
	float magSqr();

	//Get Angle
	float getAngle(const Vect &in);

	//Bracket Operator - Get
	float operator[](const x_enum) const;
	float operator[](const y_enum) const;
	float operator[](const z_enum) const;
	float operator[](const w_enum) const;

	//Bracket Operator - Set
	float& operator[](const x_enum);
	float& operator[](const y_enum);
	float& operator[](const z_enum);
	float& operator[](const w_enum);

	//Test For Equality
	bool isEqual(const Vect &v);
	bool isEqual(const Vect &v, const float &epsilon);

	//Test For Zero
	bool isZero();
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

//Adding Vectors
Vect operator +(const Vect &v, const Vect &w);

//Subtracting Vectors
Vect operator -(const Vect &v, const Vect &w);

//Multiplying A Scalar By A Vector
Vect operator *(const float &s, const Vect &v);

//Multiplying A Vector By A Scalar
Vect operator *(const Vect &v, const float &s);

//Multiplying A Vector By A Matrix
Vect operator *(const Vect &v, const Matrix &m);

//Multiplying A Vector By A Quaternion
Vect operator *(const Vect &v, const Quat &q);

//Unary +
Vect operator +(const Vect &in);

//Unary -
Vect operator -(const Vect &in);


#endif