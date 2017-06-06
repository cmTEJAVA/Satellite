#pragma once
#include "GameObject.h"
class Cbutton :
	public CGameObject
{
public:
	Cbutton();
	virtual ~Cbutton();
	virtual void draw(HDC hdc);

};

