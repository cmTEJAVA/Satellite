#pragma once
#include "Unit.h"
#include "Sprite.h"
class CPlayer :
	public CUnit
{
	LPCTSTR m_destroyedimgPath;
	LPCTSTR m_liveimgPath;
	float m_life;//1~0
public:
	CPlayer();
	~CPlayer();
	virtual void draw(HDC hdc) override;
	void OnCreatplayerimg(const Point& midpos,const LPCTSTR& pStream
		,float imgsizerate,int spriteframeN,float frameupdatetime
		,float radianspeed=0.01,float speed=0.f) {
		CUnit::OnCreatUnit(midpos,midpos, pStream, imgsizerate, spriteframeN, frameupdatetime, radianspeed, speed);
		m_life = 1;
		m_liveimgPath = pStream;
	}
	void Setdestroyedimg(const LPCTSTR& pStream) {
		m_destroyedimgPath = pStream;
		
	}
	void attack(float fPerdmg = 0.05f) {
		m_life = max(0.f, m_life - fPerdmg);
		if (m_life == 0.f) {
			m_imgUnit.releaseCimg();
			m_imgUnit.loadCimg(m_destroyedimgPath);
		}
	};
	void cure(float fPerdmg = 0.05f) {
		if (m_life == 0.f) {
			m_imgUnit.releaseCimg();
			m_imgUnit.loadCimg(m_liveimgPath);
		}
		m_life = min(1.f, m_life + fPerdmg);
	
	};
	void Update()override;
	float GetLife() { return m_life; }
};

