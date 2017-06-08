#pragma once
#include "Point.h"
#include <math.h>

class  Point3	//Vector3
{


public:
	float x, y, z;
	Point3();
	Point3(const float&, const float&, const float&);
	Point3(const LONG&, const LONG&, const LONG&);
	Point3(const Point3&);
	~Point3();

	Point3 operator+(const Point3&);
	Point3 operator+(const int&);
	Point3 operator*(const float&);

	Point3 operator*(const Point3&);
	Point3 operator-(const Point3&);


	Point3& operator=(const Point3&&);

	Point3& operator=(const Point3&);


	Point3 operator+=(const Point3& rhs)
	{
		this->x = (this->x + rhs.x);
		this->y = (this->y + rhs.y);
		this->z = (this->z + rhs.z);
		return *this;
	}
	Point3 operator/=(const float& rhs)
	{
		this->x = (this->x / rhs);
		this->y = (this->y / rhs);
		this->z = (this->z / rhs);
		return *this;
	}

	const float& length() { return static_cast<float>(sqrt(x*x + y*y + z*z)); }

	const float  normalize()
	{
		float le = length();
		*this /= le;
		return le;

	}


	void SetPoint3(const float& a, const float& b, const float& c);
/*
	void DrawPoint3(HDC hdc) {

		GetPoint2().DrawPoint(hdc);
	}

	void DrawPoint3(HDC hdc, const Point3& uV, const Point3& pPos) {

		GetPoint2(uV, pPos).DrawPoint(hdc);
	}
*/
	// ¿ÜÀû
	Point3 cross(const Point3& other)
	{
		
		return Point3(other.z*y-z*other.y,z*other.x-x*other.z,x*other.y-y*other.x);
	}
	const float inner(const Point3& other) {
		return x*other.x + y*other.y + z*other.z;
	}


	void  Reflection(const Point3& q) {
		Point3 n = q;
		n.normalize();
		Point3 P{ x,y,z };
		P = P + n*((P*-1).inner(n))*2;

		*this = P;
	}
	Point GetPoint2() {
	//
	//	float rate = (500 - z) / (float)500;
	//	float x1 = WIDTH / 2 * (1 - rate);
	//	float y1 = HEIGHT / 2 * (1 - rate);
	//	return Point{ x1 + (x)* rate , y1 + (y)* rate };
//	return Point{ (x),(y)};
		Point tmp{ (x / z),(y / z)};
		return tmp;
	}


	/*
	Point GetPoint2(const Point3& uV, const Point3& pPos) {
		float distance = uV.x*(x - pPos.x) + uV.y*(y - pPos.y) + uV.z*(z - pPos.z);
		//float distance = sqrt((pPos.x - x)*(pPos.x - x) + (pPos.y - y)*(pPos.y - y) + (pPos.z - z)*(pPos.z - z)  );

		if (distance > 0) {
			int e = 122;
			e = 33;
		}
		*this = *this - pPos;

		//		float rate = (CLIENT_Z - z) / (float)CLIENT_Z;
		float rate = (CLIENT_Z - distance) / (float)CLIENT_Z;
		float x1 = CLIENT_WIDTH / 2 * (1 - rate);
		float y1 = CLIENT_HEIGHT / 2 * (1 - rate);
		//return Point{ x1 + (x-pPos.x)* rate , y1 + (y-pPos.y)* rate };

		return Point{ x1 + (x)* rate , y1 + (y)* rate };

	}
	*/


		POINT GetPOINT(const Point3& pPos) {

		*this = *this - pPos;
		int CLIENT_Z = 500;
		float rate = (CLIENT_Z - z) / (float)CLIENT_Z;
		//float rate = (CLIENT_Z-distance) / (float)CLIENT_Z;
		float x1 = WIDTH / 2 * (1 - rate);
		float y1 = HEIGHT / 2 * (1 - rate);
		//return Point{ x1 + (x-pPos.x)* rate , y1 + (y-pPos.y)* rate };

		return POINT{ LONG(x1 + (x)* rate) , LONG(y1 + (y)* rate) };
		}

		POINT GetPOINT() 
		{
			int CLIENT_Z = 500;

			float rate = (CLIENT_Z - z) / (float)CLIENT_Z;
			float x1 = WIDTH / 2 * (1 - rate);
			float y1 = HEIGHT / 2 * (1 - rate);
			return POINT{ LONG(x1 + (x)* rate) ,LONG(y1 + (y)* rate) };
		}
		/*
		*/

	};
