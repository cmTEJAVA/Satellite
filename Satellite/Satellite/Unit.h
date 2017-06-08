#pragma once
#include "GameMoveObject.h"
#include "Sprite.h"
class CUnit :
	public CGameMoveObject
{

	float m_fRadianUnit;
	float m_fradianspeed;
public:
	CSprite m_imgUnit;
	CUnit();
	~CUnit();
	virtual void draw(HDC hdc) override;
	void OnCreatUnit(const Point& pos, const LPCTSTR& pStream
		, float imgsizerate, int spriteframeN, float frameupdatetime
		, float radianspeed = 0.01, float speed = 2.f) {
		m_imgUnit.OnCreatCimg(pStream);
		m_imgUnit.OnCreatSprite(imgsizerate, spriteframeN, frameupdatetime);

		m_imgUnit.SetPos(pos);
	//	SetObjRECT(m_imgUnit.GetObjRECT());
	//	SetPos(pos);
	//	m_rcobjsize=m_rcobjsize - pos.GetPOINT();
		SetSpeed(speed);
		m_fradianspeed = radianspeed;
		m_fRadianUnit = 0;
	}
	void Update()override;

};

