#pragma once
#include "GameMoveObject.h"
class CBullet :
	public CGameMoveObject
{
public:
	CBullet();
	virtual ~CBullet() override;
	virtual void draw(HDC hdc) override;
	virtual void Update() override;
};

