#pragma once
#include "Sprite.h"
class CMoneyManager
{
	RECT m_rcClient;
	int m_imoney;
	CSprite m_spriteMoney;
public:
	CMoneyManager();
	~CMoneyManager();
	void OnCreat() {
		m_rcClient = RECT{ 30,0,WIDTH,HEIGHT };
		m_spriteMoney.OnCreatCimg(L"Resorce/Test/moneysprite.bmp");
		m_spriteMoney.OnCreatSprite(0.5f,8,0.1);
		m_imoney = 1000;
		m_spriteMoney.SetPos(Point{15,15});
	}

	void Draw(HDC hdc);
	void Update();
};

