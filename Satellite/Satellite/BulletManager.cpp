#include "stdafx.h"
#include "BulletManager.h"


CBulletManager::CBulletManager()
{
}


CBulletManager::~CBulletManager()
{
}

void CBulletManager::draw(HDC hdc)
{
	RECT tmp=m_bullet[(int)ENUM_BULLET::STANDARD].GetObjRECT();
	for (auto &cirB : m_listCirBullet)
	{
		RECT rctmp = tmp+cirB.m_Pos.GetPOINT();
		m_bullet[0].draw(hdc, rctmp);
	}
}

void CBulletManager::Update()
{
	for (auto &cirB : m_listCirBullet)
	{
		cirB.m_Pos += cirB.m_Dir*2.f;
	}
	
}
