#pragma once
#include "Unit.h"
#include "Sprite.h"
class CPlayer :
	public CUnit
{
	float m_life;//1~0
public:
	CPlayer();
	~CPlayer();
	virtual void draw(HDC hdc) override;
	void OnCreatplayerimg(const Point& pos,const LPCTSTR& pStream
		,float imgsizerate,int spriteframeN,float frameupdatetime
		,float radianspeed=0.01,float speed=2.f) {
		CUnit::OnCreatUnit(pos, pStream, imgsizerate, spriteframeN, frameupdatetime, radianspeed, speed);
		m_life = 1;
	}
	void attack(float fPerdmg = 0.05f) { m_life = max(0.f, m_life - fPerdmg); };
	void cure(float fPerdmg = 0.05f) { m_life = min(1.f, m_life + fPerdmg); };
	void Update()override;
};

