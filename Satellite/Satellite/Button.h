#pragma once
#include "BitmapObject.h"
class Cbutton :
	public CBitmapObject
{

	bool m_bon;
	bool m_bselect;
	


public:
	Cbutton();
	virtual ~Cbutton();
	virtual void draw(HDC hdc);
	

	void SetOn(bool q) {
		m_bon = q;

		if (m_bon) {
			Setsizerate(1.2f);
		}
		else {
			Setsizerate(1.0f);

		}

	}
	void Setselect(bool q) {
		m_bselect = q;
	}

	bool GetOn(bool q) {
		return m_bon;
	}
	bool Getselect(bool q) {
		return m_bselect;
	}




};

