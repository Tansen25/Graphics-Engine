#include "MathEngine.h"
#include <math.h>
#include <cassert>

//Default Constructor
Quat::Quat()
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
	w = 1.0;
}

//Copy Constructor
Quat::Quat(const Vect &in)
{
	x = in.x;
	y = in.y;
	z = in.z;
	w = in.w;
}

//Specialized Constructor
Quat::Quat(float inX, float inY, float inZ, float inW)
{
	x = inX;
	y = inY;
	z = inZ;
	w = inW;
}

//Specialized Constructor - From Vector
Quat::Quat(const Vect &inVect, float inW)
{
	x = inVect.x;
	y = inVect.y;
	z = inVect.z;
	w = inW;
}

//Specialized Constructor - From Matrix
Quat::Quat(const Matrix &inMatrix)
{
	assert(Util::isEqual(inMatrix.det(), 1.0, MATH_TOLERANCE));

	float trace = inMatrix[m0] + inMatrix[m5] + inMatrix[m10];

	if (trace > 0.0f)
	{
		float s = sqrtf(trace + 1.0f) * 2.0f; //s = 4 * w

		x = -(inMatrix[m9] - inMatrix[m6]) / s;

		y = -(inMatrix[m2] - inMatrix[m8]) / s;

		z = -(inMatrix[m4] - inMatrix[m1]) / s;

		w = 0.25f * s;
	}

	else if ((inMatrix[m0] > inMatrix[m5]) && (inMatrix[m0] > inMatrix[m10]))
	{
		float s = sqrtf(1.0f + inMatrix[m0] - inMatrix[m5] - inMatrix[m10]) * 2.0f; //s = 4 * x

		x = 0.25f * s;

		y = (inMatrix[m1] + inMatrix[m4]) / s;

		z = (inMatrix[m2] + inMatrix[m8]) / s;

		w = -(inMatrix[m9] - inMatrix[m6]) / s;
	}

	else if (inMatrix[m5] > inMatrix[m10])
	{
		float s = sqrtf(1.0f + inMatrix[m5] - inMatrix[m0] - inMatrix[m10]) * 2.0f; //s = 4 * y

		x = (inMatrix[m1] + inMatrix[m4]) / s;

		y = 0.25f * s;

		z = (inMatrix[m6] + inMatrix[m9]) / s;

		w = -(inMatrix[m2] - inMatrix[m8]) / s;
	}

	else
	{
		float s = sqrtf(1.0f + inMatrix[m10] - inMatrix[m0] - inMatrix[m5]) * 2.0f; // s = 4 * z

		x = (inMatrix[m2] + inMatrix[m8]) / s;

		y = (inMatrix[m6] + inMatrix[m9]) / s;

		z = 0.25f * s;

		w = -(inMatrix[m4] - inMatrix[m1]) / s;
	}
}

//Specialized Constructor - Identity
Quat::Quat(const MatrixSpecialType type)
{
	//Determine if it is an identity or zero quaternion
	if (type == 0)
	{
		x = 0.0f;

		y = 0.0f;

		z = 0.0f;

		w = 0.0f;
	}
	
	else
	{
		x = 0.0;
		y = 0.0;
		z = 0.0;
		w = 1.0;
	}
}

//Specialized Constructor - Rot
Quat::Quat(const RotType type, const float &rad)
{
	float cos = cosf(rad / 2.0f);
	float sin = sinf(rad / 2.0f);

	//Rotation about x axis
	if (type == 0)
	{
		x = sin;

		y = 0.0f;

		z = 0.0f;

		w = cos;
	}

	//Rotation about y axis
	else if (type == 1)
	{
		x = 0.0f;

		y = sin;

		z = 0.0f;

		w = cos;
	}

	//Rotation about z axis
	else
	{
		x = 0.0f;

		y = 0.0f;

		z = sin;

		w = cos;
	}
}

//Specialized Constructor - 3 Rotations
Quat::Quat(const Rot3AxisType type, const float &radOne, const float &radTwo, const float &radThree)
{
	if (type == ROT_XYZ)
	{
		Quat quatX(ROT_X, radOne);
		Quat quatY(ROT_Y, radTwo);
		Quat quatZ(ROT_Z, radThree);

		Quat temp = quatX * quatY * quatZ;

		x = temp[X];

		y = temp[Y];

		z = temp[Z];

		w = temp[W];
	}
}

//Specialized Constructor - Rotation About Arbitrary Axis
Quat::Quat(const RotAxisAngleType type, const Vect &axis, const float &rad)
{
	if (type == 0)
	{
		float fSin = sinf(rad / 2.0f);

		float fCos = cosf(rad / 2.0f);

		Vect v = axis;

		v.norm();

		x = (v[X] * fSin);

		y = (v[Y] * fSin);

		z = (v[Z] * fSin);

		w = fCos;
	}
}

//Specialized Constructor - Orientation Rotation
Quat::Quat(const RotOrientType type, const Vect &dof, const Vect &up)
{
	if (type == 0)
	{
		//Vectors to represent the default z-forward and y-up
		Vect zForward(0.0f, 0.0f, 1.0f);
		Vect yUp(0.0f, 1.0f, 0.0f);

		//First quaternion
		//Correct up vector and normalize
		Vect upCorrected = dof.cross(up.cross(dof));

		upCorrected.norm();

		//Create a vector to rotate yUp around
		Vect upRotAxis = yUp.cross(upCorrected);

		//Calculate rotation angle
		float upRotAngle = yUp.getAngle(upCorrected);

		//Create first quaternion about the above arbitrary axis
		Quat q1(ROT_AXIS_ANGLE, upRotAxis, upRotAngle);

		//Second quaternion
		//Correct zForward by the same rotation used on the up vector
		Vect zForwardCorrected;

		q1.Lqcvq(zForward, zForwardCorrected);

		//Calculate rotation angle between zForwardCorrected and dof
		float rotAngle = zForwardCorrected.getAngle(dof);

		//Create second quaternion about the corrected up axis
		Quat q2(ROT_AXIS_ANGLE, upCorrected, rotAngle);

		//Multiply the two quaternions together to produce the complete rotation
		*this = q1 * q2;
	}

	else
	{
		//Vectors to represent the default z-forward and y-up
		Vect zForward(0.0f, 0.0f, 1.0f);
		Vect yUp(0.0f, 1.0f, 0.0f);

		//First quaternion
		//Correct up vector and normalize
		Vect upCorrected = dof.cross(up.cross(dof));

		upCorrected.norm();

		//Create a vector to rotate yUp around
		Vect upRotAxis = yUp.cross(upCorrected);

		//Calculate rotation angle
		float upRotAngle = yUp.getAngle(upCorrected);

		//Create first quaternion about the above arbitrary axis
		Quat q1(ROT_AXIS_ANGLE, upRotAxis, upRotAngle);

		//Second quaternion
		//Correct zForward by the same rotation used on the up vector
		Vect zForwardCorrected;

		q1.Lqcvq(zForward, zForwardCorrected);

		//Calculate rotation angle between zForwardCorrected and dof
		float rotAngle = zForwardCorrected.getAngle(dof);

		//Create second quaternion about the corrected up axis
		Quat q2(ROT_AXIS_ANGLE, upCorrected, rotAngle);

		//Multiply the two quaternions together to produce the complete rotation
		Quat q3 = q1 * q2;

		*this = q3;

		//Take the transpose of q3 to return to the original orientation
		//*this = q3.getT();
	}
}

//Destructor
Quat::~Quat()
{
	//Does nothing
}

//set Quaternion
void Quat::set(const float &inX, const float &inY, const float &inZ, const float &inW)
{
	x = inX;
	y = inY;
	z = inZ;
	w = inW;
}

//Set Quaternion From Matrix
void Quat::set(const Matrix &inMatrix)
{
	//Check if it is an identity matrix
	if (inMatrix.isIdentity())
	{
		x = 0.0;
		y = 0.0;
		z = 0.0;
		w = 1.0;
	}

	//Check if it is a zero matrix
	else if (Util::isEqual(inMatrix.det(), 0.0f, MATH_TOLERANCE))
	{
		x = 0.0f;

		y = 0.0f;

		z = 0.0f;

		w = 0.0f;
	}
	
	else
	{
		assert(Util::isEqual(inMatrix.det(), 1.0, MATH_TOLERANCE));

		Quat s(inMatrix);
		*this = s;
	}
}

//set Quaternion From Vector + W Component
void Quat::set(const Vect &inV, const float inW)
{
	x = inV[X];

	y = inV[Y];

	z = inV[Z];

	w = inW;
}

//Set Quaternion From Vector Only
void Quat::setVect(const Vect &inV)
{
	x = inV[X];

	y = inV[Y];

	z = inV[Z];

	w = 0.0f;
}

//Set Constructor - Rot
void Quat::set(const RotType type, const float &rad)
{
	float cos = cosf(rad / 2.0f);
	float sin = sinf(rad / 2.0f);

	//Rotation about x axis
	if (type == 0)
	{
		x = sin;

		y = 0.0f;

		z = 0.0f;

		w = cos;
	}

	//Rotation about y axis
	else if (type == 1)
	{
		x = 0.0f;

		y = sin;

		z = 0.0f;

		w = cos;
	}

	//Rotation about z axis
	else
	{
		x = 0.0f;

		y = 0.0f;

		z = sin;

		w = cos;
	}
}

//Set Quaternion - Rotation About Arbitrary Axis
void Quat::set(const RotAxisAngleType type, const Vect &axis, const float &rad)
{
	if (type == 0)
	{
		float fSin = sinf(rad / 2.0f);

		float fCos = cosf(rad / 2.0f);

		Vect v = axis;

		v.norm();

		x = (v[X] * fSin);

		y = (v[Y] * fSin);

		z = (v[Z] * fSin);

		w = fCos;
	}
}

//Set Quaternion - Orientation Rotation
void Quat::set(const RotOrientType type, const Vect &dof, const Vect &up)
{
	if (type == 0)
	{
		//Vectors to represent the default z-forward and y-up
		Vect zForward(0.0f, 0.0f, 1.0f);
		Vect yUp(0.0f, 1.0f, 0.0f);

		//First quaternion
		//Correct up vector and normalize
		Vect upCorrected = dof.cross(up.cross(dof));

		upCorrected.norm();

		//Create a vector to rotate yUp around
		Vect upRotAxis = yUp.cross(upCorrected);

		//Calculate rotation angle
		float upRotAngle = yUp.getAngle(upCorrected);

		//Create first quaternion about the above arbitrary axis
		Quat q1(ROT_AXIS_ANGLE, upRotAxis, upRotAngle);

		//Second quaternion
		//Correct zForward by the same rotation used on the up vector
		Vect zForwardCorrected;

		q1.Lqcvq(zForward, zForwardCorrected);

		//Calculate rotation angle between zForwardCorrected and dof
		float rotAngle = zForwardCorrected.getAngle(dof);

		//Create second quaternion about the corrected up axis
		Quat q2(ROT_AXIS_ANGLE, upCorrected, rotAngle);

		//Multiply the two quaternions together to produce the complete rotation
		*this = q1 * q2;
	}

	else
	{
		//Vectors to represent the default z-forward and y-up
		Vect zForward(0.0f, 0.0f, 1.0f);
		Vect yUp(0.0f, 1.0f, 0.0f);

		//First quaternion
		//Correct up vector and normalize
		Vect upCorrected = dof.cross(up.cross(dof));

		upCorrected.norm();

		//Create a vector to rotate yUp around
		Vect upRotAxis = yUp.cross(upCorrected);

		//Calculate rotation angle
		float upRotAngle = yUp.getAngle(upCorrected);

		//Create first quaternion about the above arbitrary axis
		Quat q1(ROT_AXIS_ANGLE, upRotAxis, upRotAngle);

		//Second quaternion
		//Correct zForward by the same rotation used on the up vector
		Vect zForwardCorrected;

		q1.Lqcvq(zForward, zForwardCorrected);

		//Calculate rotation angle between zForwardCorrected and dof
		float rotAngle = zForwardCorrected.getAngle(dof);

		//Create second quaternion about the corrected up axis
		Quat q2(ROT_AXIS_ANGLE, upCorrected, rotAngle);

		//Multiply the two quaternions together to produce the complete rotation
		Quat q3 = q1 * q2;

		*this = q3;

		//Take the transpose of q3 to return to the original orientation
		//*this = q3.getT();
	}
}

//Assignment Operator
void Quat::operator = (const Quat &in)
{
	x = in[X];

	y = in[Y];

	z = in[Z];

	w = in[W];
}

//+= Operator - Quat
void Quat::operator +=(const Quat &in)
{
	x += in[X];

	y += in[Y];

	z += in[Z];

	w += in[W];
}

//+= Operator - Constant
void Quat::operator +=(const float &inValue)
{
	x += inValue;

	y += inValue;

	z += inValue;

	w += inValue;
}

//-= Operator - Quat
void Quat::operator -=(const Quat &in)
{
	x -= in[X];

	y -= in[Y];

	z -= in[Z];

	w -= in[W];
}

//-= Operator - Constant
void Quat::operator -=(const float &inValue)
{
	x -= inValue;

	y -= inValue;

	z -= inValue;

	w -= inValue;
}

//*= Operator - Matrix
void Quat::operator *=(const Matrix &in)
{
	Matrix tmp(*this);

	tmp *= in;

	Quat q;

	q.set(tmp);

	x = q[X];

	y = q[Y];

	z = q[Z];

	w = q[W];
}

//*= Operator - Quat
void Quat::operator *=(const Quat &in)
{
	Vect pv(x, y, z);
	Vect qv(in[X], in[Y], in[Z]);

	Vect vectOut = (-pv.cross(qv) + (in[W] * pv) + (w * qv));

	float wOut = (w * in[W] - pv.dot(qv));

	x = vectOut[X];

	y = vectOut[Y];

	z = vectOut[Z];

	w = wOut;
}

//*= Operator - Constant
void Quat::operator *=(const float &inValue)
{
	x *= inValue;

	y *= inValue;

	z *= inValue;

	w *= inValue;
}

// /= Operator - Quat
void Quat::operator /=(const Quat &q)
{
	x /= q[X];

	y /= q[Y];

	z /= q[Z];

	w /= q[W];
}

// /= Operator - Quat
void Quat::operator /=(const float &a)
{
	x /= a;

	y /= a;

	z /= a;

	w /= a;
}

//Multiply Quaternion By Another Quaternion Element By Element
Quat Quat::multByElement(const Quat &in)
{
	float tmpX = x * in[X];

	float tmpY = y * in[Y];

	float tmpZ = z * in[Z];

	float tmpW = w * in[W];

	return Quat(tmpX, tmpY, tmpZ, tmpW);
}

//Multiply Vector By A Quaternion - qConj * V * q
void Quat::Lqcvq(const Vect &inV, Vect &outV)
{
	Vect tempV(x, y, z);
	
	outV = 2 * w * (tempV.cross(inV)) + (w * w - tempV.dot(tempV)) * inV + 2 * (tempV.dot(inV)) * tempV;
}

//Multiply Vector By A Quaternion - q * V * qConj
void Quat::Lqvqc(const Vect &inV, Vect &outV)
{
	Vect tempV(x, y, z);

	outV = 2 * w * (inV.cross(tempV)) + (w * w - tempV.dot(tempV)) * inV + 2 * (tempV.dot(inV)) * tempV;
}


//X Bracket Operator - Get
float Quat::operator[](const x_enum) const
{
	return x;
}

//Y Bracket Operator - Get
float Quat::operator[](const y_enum) const
{
	return y;
}

//Z Bracket Operator - Get
float Quat::operator[](const z_enum) const
{
	return z;
}

//W Bracket Operator - Get
float Quat::operator[](const w_enum) const
{
	return w;
}

//Get Conjugate
Quat Quat::getConj()
{
	return Quat(-x, -y, -z, w);
}

//Get Transpose
Quat Quat::getT()
{
	if (this -> isNormalized(0.1f))
	{
		return Quat(-x, -y, -z, w);
	}

	else
	{
		float a = this -> mag();
		
		return Quat(-x / a, -y / a, -z / a, w / a);
	}
}

//Get Magnitude
float Quat::mag()
{
	return sqrtf(x * x + y * y + z * z + w * w);
}

//Get Magnitude Squared
float Quat::magSquared()
{
	return x * x + y * y + z * z + w * w;
}

//Get Inverse Magnitude
float Quat::invMag()
{
	return (1 / this -> mag());
}

//Set Normalized Quaternion
Quat Quat::getNorm()
{
	float a = this -> mag();

	return Quat(x / a, y / a, z / a, w / a);
}

//Get Inverse
Quat Quat::getInv()
{
	Quat temp = this -> getConj();

	float a = this -> magSquared();

	return Quat(temp[X] / a, temp[Y] / a, temp[Z] / a, temp[W] / a);
}

//Get Vector
void Quat::getVect(Vect &outV)
{
	outV[X] = x;

	outV[Y] = y;

	outV[Z] = z;

	outV[W] = 1.0f;
}

//Get Angle
float Quat::getAngle()
{
	return 2 * acosf(w);
}

//Get Axis
void Quat::getAxis(Vect &outV)
{
	outV[X] = x;

	outV[Y] = y;

	outV[Z] = z;

	outV[W] = 1.0f;
}

//X Bracket Operator - Set
float& Quat::operator[](const x_enum)
{
	return x;
}

//Y Bracket Operator - Set
float& Quat::operator[](const y_enum)
{
	return y;
}

//Z Bracket Operator - Set
float& Quat::operator[](const z_enum)
{
	return z;
}

//W Bracket Operator - Set
float& Quat::operator[](const w_enum)
{
	return w;
}

//Set Conjugate
void Quat::conj()
{
	//Determine quaternions conjugate - Note: w component stays the same
	x = -x;

	y = -y;

	z = -z;
}

//Set Transpose
void Quat::T()
{
	if (this -> isNormalized(0.1f))
	{
		x = - x;

		y = -y;

		z = -z;

		//W component stays the same
	}

	else
	{
		float a = this -> mag();
		
		x = -x / a;

		y = -y / a;

		z = -z / a;

		w = w / a;
	}
}

//Set Normalized Quaternion
Quat Quat::norm()
{
	float a = this -> mag();

	x = x / a;

	y = y / a;

	z = z / a;

	w = w / a;

	return *this;
}

//Set Inverse
void Quat::inv()
{
	float a = this -> magSquared();

	x = -x / a;

	y = -y / a;

	z = -z / a;

	w = w / a;
}

//Test For Equality
bool Quat::isEqual(const Quat &q, const float &epsilon)
{
	bool equal = false;

	//Check X
	if (Util::isEqual(x, q[X], epsilon))
	{
		equal = true;
	}

	else
	{
		return (equal = false);
	}

	//Check Y
	if (Util::isEqual(y, q[Y], epsilon))
	{
		equal = true;
	}

	else
	{
		return (equal = false);
	}

	//Check Z
	if (Util::isEqual(z, q[Z], epsilon))
	{
		equal = true;
	}

	else
	{
		return (equal = false);
	}

	//Check W
	if (Util::isEqual(w, q[W], epsilon))
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
bool Quat::isNegEqual(const Quat &q, const float &epsilon)
{
	bool equal = false;

	//Check X
	if (Util::isEqual(-x, q[X], epsilon))
	{
		equal = true;
	}

	else
	{
		return (equal = false);
	}

	//Check Y
	if (Util::isEqual(-y, q[Y], epsilon))
	{
		equal = true;
	}

	else
	{
		return (equal = false);
	}

	//Check Z
	if (Util::isEqual(-z, q[Z], epsilon))
	{
		equal = true;
	}

	else
	{
		return (equal = false);
	}

	//Check W
	if (Util::isEqual(-w, q[W], epsilon))
	{
		equal = true;
	}

	else
	{
		return (equal = false);
	}

	return equal;
}

//Test If It Is Equivalent
bool Quat::isEquivalent(const Quat &q, const float &epsilon)
{
	bool test;

	//Test for equality
	test = this -> isEqual(q, epsilon);

	if (test == false)
	{
		//Test for negative equality
		test = this -> isNegEqual(q, epsilon);
	}

	return test;
}

//Test If It Is A Conjugate
bool Quat::isConjugateEqual(const Quat &q, const float &epsilon)
{
	bool equal = false;

	//Check X
	if (Util::isEqual(x, -q[X], epsilon))
	{
		equal = true;
	}

	else
	{
		return (equal = false);
	}

	//Check Y
	if (Util::isEqual(y, -q[Y], epsilon))
	{
		equal = true;
	}

	else
	{
		return (equal = false);
	}

	//Check Z
	if (Util::isEqual(z, -q[Z], epsilon))
	{
		equal = true;
	}

	else
	{
		return (equal = false);
	}

	//Check W
	if (Util::isEqual(w, q[W], epsilon))
	{
		equal = true;
	}

	else
	{
		return (equal = false);
	}

	return equal;
}

//Test For Identity
bool Quat::isIdentity(const float &epsilon)
{
	Quat temp(0.0f, 0.0f, 0.0f, 1.0f);

	bool test;

	//Test for equality
	test = this -> isEqual(temp, epsilon);

	return test;
}

//Test If It Is Normalized
bool Quat::isNormalized(const float &epsilon)
{
	float mag;

	bool test;
	
	mag = x * x + y * y + z * z + w * w;

	//Check if mag equals 1.0
	test = Util::isEqual(mag, 1.0f, epsilon);

	return test;
}

//Test If It Is Zero
bool Quat::isZero(const float &epsilon)
{
	bool test;
	
	Quat temp(0.0f, 0.0f, 0.0f, 0.0f);

	test = this -> isEqual(temp, epsilon);

	return test;
}

//Add Quaternions
Quat operator +(const Quat &q1, const Quat &q2)
{
	return Quat(q1[x] + q2[x], q1[y] + q2[y], q1[z] + q2[z], q1[w] + q2[w]);
}

//Add Quaternion With A Constant
Quat operator +(const Quat &q1, const float &inValue)
{
	return Quat(q1[x] + inValue, q1[y] + inValue, q1[z] + inValue, q1[w] + inValue);
}

//Add Constant To A Quaternion
Quat operator +(const float &inValue, const Quat &q1)
{
	return Quat(q1[x] + inValue, q1[y] + inValue, q1[z] + inValue, q1[w] + inValue);
}

//Subtract Quaternions
Quat operator -(const Quat &q1, const Quat &q2)
{
	return Quat(q1[x] - q2[x], q1[y] - q2[y], q1[z] - q2[z], q1[w] - q2[w]);
}

//Subtract Quaternion With A Constant
Quat operator -(const Quat &q1, const float &inValue)
{
	return Quat(q1[x] - inValue, q1[y] - inValue, q1[z] - inValue, q1[w] - inValue);
}

//Subtract Constant To A Quaternion
Quat operator -(const float &inValue, const Quat &q1)
{
	return Quat(inValue - q1[x], inValue - q1[y], inValue - q1[z], inValue - q1[w]);
}

//Multiply Quaternions
Quat operator * (const Quat &p, const Quat &q)
{
	Vect pv(p[x], p[y], p[z]);
	Vect qv(q[x], q[y], q[z]);

	Vect vectOut = (-pv.cross(qv) + (q[w] * pv) + (p[w] * qv));

	float wOut = (p[w] * q[w] - pv.dot(qv));

	return Quat(vectOut[x], vectOut[y], vectOut[z], wOut);
}

//Multiply Quaternion With A Matrix
Matrix operator * (const Quat &p, const Matrix &m)
{
	Matrix tmp(p);
	tmp *= m;
	Quat q;
	q.set(tmp);
	return q;
}

//Multiply Matrix With A Quaternion
Matrix operator * (const Matrix &m, const Quat &p)
{
	Matrix tempQuat(p);
	Matrix temp(m);

	temp *= tempQuat;

	Quat q;

	q.set(temp);

	return q;
}

//Multiply Quaternion With A Constant
Quat operator *(const Quat &q1, const float &inValue)
{
	return Quat(q1[x] * inValue, q1[y] * inValue, q1[z] * inValue, q1[w] * inValue);
}

//Multiply Constant To A Quaternion
Quat operator *(const float &inValue, const Quat &q1)
{
	return Quat(inValue * q1[x], inValue * q1[y], inValue * q1[z], inValue * q1[w]);
}

//Divide Quaternion By A Quaternion
Quat operator /(const Quat &p, const Quat &q)
{
	return Quat(p[x] / q[x], p[y] / q[y], p[z] / q[z], p[w] / q[w]);
}

//Divide Quaternion By A Constant
Quat operator /(const Quat &p, const float &a)
{
	return Quat(p[x] / a, p[y] / a, p[z] / a, p[w] / a);
}

//Divide Constant By A Quaternion
Quat operator /(const float &a, const Quat &p)
{
	return Quat(a / p[x], a / p[y], a / p[z], a / p[w]);
}

//Unary +
Quat operator +(const Quat &in)
{
	return Quat(in[x], in[y], in[z], in[w]);
}

//Unary -
Quat operator -(const Quat &in)
{
	return Quat(-in[x], -in[y], -in[z], -in[w]);
}