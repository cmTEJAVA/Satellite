#pragma once
#include "GameMoveObject.h"
#include "Sprite.h"
class CUnit :
	public CGameMoveObject
{

	float	m_fRadianUnit;
	float	m_fradianspeed;
	Point	m_ptmidpos;
	int		m_iRadius;//¹ÝÁö¸§
public:
	CSprite m_imgUnit;
	CUnit();
	~CUnit();
	virtual void draw(HDC hdc) override;
	void OnCreatUnit(const Point& midpos, const int radius
		, const LPCTSTR& pStream
		, float imgsizerate, int spriteframeN, float frameupdatetime
		, float radianspeed = 0.01, float speed = 0.02f) {
		m_imgUnit.OnCreatCimg(pStream);
		m_imgUnit.OnCreatSprite(imgsizerate, spriteframeN, frameupdatetime);
		m_imgUnit.SetPos(Point{ midpos.x+ radius,midpos.y});
		m_ptmidpos = midpos;
	//	SetObjRECT(m_imgUnit.GetObjRECT());
	//	SetPos(pos);
	//	m_rcobjsize=m_rcobjsize - pos.GetPOINT();
		SetSpeed(speed);
		m_fradianspeed = radianspeed;
		m_fRadianUnit = 0;
	}
	void Update()override;

};

