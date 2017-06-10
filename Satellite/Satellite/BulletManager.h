#pragma once
#include "BitmapObject.h"
#include <list>

struct CirBullet {
	Point m_Pos;
	Point m_Dir;
};

class CBulletManager
{
	std::list<CirBullet> m_listCirBullet;
public:
	CBitmapObject m_bullet[(int)ENUM_BULLET::END];
	
	CBulletManager();
	~CBulletManager() ;
	void draw(HDC hdc) ;
	void Update() ;
	void OnCreateBulletImg() {
		m_bullet[(int)ENUM_BULLET::STANDARD].Setsizerate(0.2f);
		m_bullet[(int)ENUM_BULLET::STANDARD].OnCreatCimg(L"Resorce/Game/bullet.png");
		RECT tmp = m_bullet[(int)ENUM_BULLET::STANDARD].GetObjRECT();
		m_bullet[(int)ENUM_BULLET::STANDARD].Setmidpos(tmp);
		m_bullet[(int)ENUM_BULLET::STANDARD].SetPos(Point{ 0,0 });
	}
	void insertbullet(ENUM_BULLET ID,Point pos,Point dir) {
		switch (ID)
		{
		case ENUM_BULLET::STANDARD:
			m_listCirBullet.push_back(CirBullet());
			m_listCirBullet.back().m_Pos = pos;
			m_listCirBullet.back().m_Dir = dir;
			break;
		default:
			break;
		}
	}


};

