#include "stdafx.h"
#include "Vector.h"

CVector * CVector::create_vector(float x, float y, float z){
	CVector* pVector = new CVector(x, y, z);
	//pVector->set_x(x);
	//pVector->set_y(y);
	//pVector->set_z(z);
	return pVector;
}

void CVector::transform(CMatrix mtx){
	float _x = x;
	float _y = y;
	float _z = z;
	float _w = w;

	x = _x * mtx._00 + _y * mtx._10 + _z * mtx._20 + _w * mtx._30;
	y = _x * mtx._01 + _y * mtx._11 + _z * mtx._21 + _w * mtx._31;
	z = _x * mtx._02 + _y * mtx._12 + _z * mtx._22 + _w * mtx._32;
	w = _x * mtx._03 + _y * mtx._13 + _z * mtx._23 + _w * mtx._33;
}

void CVector::transform_coord(CMatrix mtx){
	float _x = x;
	float _y = y;
	float _z = z;

	x = _x * mtx._00 + _y * mtx._10 + _z * mtx._20 + 1.f * mtx._30;
	y = _x * mtx._01 + _y * mtx._11 + _z * mtx._21 + 1.f * mtx._31;
	z = _x * mtx._02 + _y * mtx._12 + _z * mtx._22 + 1.f * mtx._32;
}
