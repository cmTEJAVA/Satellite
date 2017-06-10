#pragma once
#include "BitmapObject.h"
#include <list>
#include "CirBullet.h"
class CBulletManager
{
	std::list<CirBullet> m_listCirBullet;
	RECT m_rcClent;
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
		m_rcClent = RECT{ 0,0,WIDTH,HEIGHT };
	}
	void insertbullet(ENUM_BULLET ID,const Point& pos,const Point& dir,float speed) {
		switch (ID)
		{
		case ENUM_BULLET::STANDARD:
			m_listCirBullet.push_back(CirBullet());
			m_listCirBullet.back().Oncreat(pos, dir, speed);
			break;
		default:
			break;
		}
	}


};

