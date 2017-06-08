#include "stdafx.h"
#include "Matrix.h"
/*
float _00{ 1.f }, _01{ 0.f }, _02{ 0.f }, _03{ 0.f };
float _10{ 0.f }, _11{ 1.f }, _12{ 0.f }, _13{ 0.f };
float _20{ 0.f }, _21{ 0.f }, _22{ 1.f }, _23{ 0.f };
float _30{ 0.f }, _31{ 0.f }, _32{ 0.f }, _33{ 1.f };
*/
void CMatrix::transform(const CMatrix& other){
	auto tmp = *this;
	_00 = tmp._00 * other._00 + tmp._01 * other._10 + tmp._02 * other._20 + tmp._03 * other._30;
	_01 = tmp._00 * other._01 + tmp._01 * other._11 + tmp._02 * other._21 + tmp._03 * other._31;
	_02 = tmp._00 * other._02 + tmp._01 * other._12 + tmp._02 * other._22 + tmp._03 * other._32;
	_03 = tmp._00 * other._03 + tmp._01 * other._13 + tmp._02 * other._23 + tmp._03 * other._33;

	_10 = tmp._10 * other._00 + tmp._11 * other._10 + tmp._12 * other._20 + tmp._13 * other._30;
	_11 = tmp._10 * other._01 + tmp._11 * other._11 + tmp._12 * other._21 + tmp._13 * other._31;
	_12 = tmp._10 * other._02 + tmp._11 * other._12 + tmp._12 * other._22 + tmp._13 * other._32;
	_13 = tmp._10 * other._03 + tmp._11 * other._13 + tmp._12 * other._23 + tmp._13 * other._33;

	_20 = tmp._20 * other._00 + tmp._21 * other._10 + tmp._22 * other._20 + tmp._23 * other._30;
	_21 = tmp._20 * other._01 + tmp._21 * other._11 + tmp._22 * other._21 + tmp._23 * other._31;
	_22 = tmp._20 * other._02 + tmp._21 * other._12 + tmp._22 * other._22 + tmp._23 * other._32;
	_23 = tmp._20 * other._03 + tmp._21 * other._13 + tmp._22 * other._23 + tmp._23 * other._33;

	_30 = tmp._30 * other._00 + tmp._31 * other._10 + tmp._32 * other._20 + tmp._33 * other._30;
	_31 = tmp._30 * other._01 + tmp._31 * other._11 + tmp._32 * other._21 + tmp._33 * other._31;
	_32 = tmp._30 * other._02 + tmp._31 * other._12 + tmp._32 * other._22 + tmp._33 * other._32;
	_33 = tmp._30 * other._03 + tmp._31 * other._13 + tmp._32 * other._23 + tmp._33 * other._33;
}
