#include "stdafx.h"
#include "Bullet.h"


CBullet::CBullet()
{
}


CBullet::~CBullet()
{
}

void CBullet::draw(HDC hdc)
{
	RECT tmp = GetObjRECT();

	Ellipse(hdc, tmp.left, tmp.top, tmp.right, tmp.bottom);

}

void CBullet::Update()
{
	CGameMoveObject::Update();

}
