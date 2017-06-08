#pragma once

class CMatrix {
private:

public:
	float _00{ 1.f }, _01{ 0.f }, _02{ 0.f }, _03{ 0.f };
	float _10{ 0.f }, _11{ 1.f }, _12{ 0.f }, _13{ 0.f };
	float _20{ 0.f }, _21{ 0.f }, _22{ 1.f }, _23{ 0.f };
	float _30{ 0.f }, _31{ 0.f }, _32{ 0.f }, _33{ 1.f };

	void transform(const CMatrix& other);
public:
	//CMatrix(){};
	~CMatrix(){};
	CMatrix(float _00 = 1.f, float _01 = 0.f, float _02 = 0.f, float _03= 0.f,
	float _10 = 0.f, float _11 = 1.f, float _12 = 0.f, float _13 = 0.f,
	float _20 = 0.f, float _21 = 0.f, float _22 = 1.f, float _23 = 0.f,
	float _30 = 0.f, float _31 = 0.f, float _32 = 0.f, float _33 = 1.f
	): _00{ _00 }, _01{ _01 }, _02{ _02 }, _03{ _03 },
		_10{ _10 }, _11{ _11 }, _12{ _12 }, _13{ _13 },
		_20{ _20 }, _21{ _21 }, _22{ _22 }, _23{ _23 },
		_30{ _30 }, _31{ _31 }, _32{ _32 }, _33{ _33 }{};
};