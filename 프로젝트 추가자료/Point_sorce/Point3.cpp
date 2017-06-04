#pragma once
#include "stdafx.h"
#include "Point3.h"


Point3::Point3() :x(0.0), y(0.0), z(0.0)
{
}

Point3::Point3(const float& a, const float& b, const float& c) : x(a), y(b), z(c) {}
Point3::Point3(const LONG &a, const LONG &b, const LONG &c) : x((LONG)a), y((LONG)b), z((LONG)c)
{
}
;


Point3::Point3(const Point3 & q) :x(q.x), y(q.y), z(q.z) {};

Point3::~Point3()
{
}

Point3 Point3::operator+(const Point3 & a)
{

	return Point3(x + a.x, y + a.y, z + a.z);
}

Point3 Point3::operator+(const int & a)
{
	return Point3(x + a, y + a, z + a);
}

Point3 Point3::operator*(const float & a)
{
	return Point3(x*a, y*a, z*a);
}

Point3 Point3::operator*(const Point3 & a)
{
	return Point3(x*a.x, y*a.y, z*a.z);
}

Point3 Point3::operator-(const Point3 & a)
{
	return Point3(x - a.x, y - a.y, z - a.z);
}

void Point3::SetPoint3(const float& a, const float& b, const float& c)
{
	x = a;
	y = b;
	z = c;
}

Point3 & Point3::operator=(const Point3 && p)
{

	x = p.x;
	y = p.y;
	z = p.z;
	return *this;
	// TODO: 여기에 반환 구문을 삽입합니다.
}

Point3 & Point3::operator=(const Point3 &p)
{

	x = p.x;
	y = p.y;
	z = p.z;
	return *this;
	// TODO: 여기에 반환 구문을 삽입합니다.
}
