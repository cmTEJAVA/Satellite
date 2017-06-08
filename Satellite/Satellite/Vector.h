#pragma once
#include "Matrix.h"

class CVector {
public:
	float get_x() { return x; }
	float get_y() { return y; }
	float get_z() { return z; }
	float get_w() { return w; }

	void set_x(float p) { x = p; }
	void set_y(float p) { y = p; }
	void set_z(float p) { z = p; }
	void set_w(float p) { w = p; }

	static CVector* create_vector(float x = 0, float y = 0, float z = 0);

	void transform(CMatrix mtx);
	void transform_coord(CMatrix mtx);
private:
	float x{0.f};
	float y{0.f}; 
	float z{0.f};
	float w{0.f};
public:
	CVector(float x = 0.f, float y = 0.f, float z = 0.f, float w = 0.f) : x(x), y(y), z(z), w(w) {};
	//CVector();
	~CVector(){};
};