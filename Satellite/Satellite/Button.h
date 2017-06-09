#pragma once
#include "BitmapObject.h"
class Cbutton :
	public CBitmapObject
{

	bool m_bon;
	bool m_bselect;
	

	void SetOn(bool q) {
		m_bon = q;

		if (m_bon) {
			Setsizerate(1.2f);
		}
		else {
			Setsizerate(1.0f);

		}

	}


public:
	Cbutton();
	virtual ~Cbutton();
	virtual void draw(HDC hdc);
	

	bool GetOn() {
		return m_bon;
	}
	bool Getselect() {
		return m_bselect;
	}

	void Setselect(bool q) {
		m_bselect = q;
	}

	void SetMouseMove(const POINT& mouse);
	void SetMouseLUp(const POINT& mouse);

};

