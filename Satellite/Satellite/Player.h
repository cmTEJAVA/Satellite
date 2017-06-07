#pragma once
#include "GameMoveObject.h"
#include "Sprite.h"
class CPlayer :
	public CGameMoveObject
{
	CSprite m_imgplayer;
	float m_life;//1~0
	float m_fradianplayer;
public:
	CPlayer();
	~CPlayer();
	virtual void draw(HDC hdc) override;
	void OnCreatplayerimg(const Point& pos,const LPCTSTR& pStream,float imgsizerate,int spriteframeN,float frameupdatetime,float speed=0.01) {
		m_imgplayer.OnCreatCimg(pStream);
		m_imgplayer.OnCreatSprite(imgsizerate, spriteframeN, frameupdatetime);
		
		m_imgplayer.SetPos(pos);
	//	SetObjRECT(m_imgplayer.GetObjRECT());
	//	SetPos(pos);
	//	m_rcobjsize=m_rcobjsize - pos.GetPOINT();
		SetSpeed(speed);
		m_fradianplayer = 0;
		m_life = 1;
	}
	void attack(float fPerdmg = 0.1) { m_life = max(0, m_life - fPerdmg); };
	void Update()override;
};

