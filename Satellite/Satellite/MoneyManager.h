#pragma once
#include "Sprite.h"
class CMoneyManager
{
	RECT m_rcClient;
	unsigned int m_imoney;
	unsigned int m_iADD_money;



	CSprite m_spriteMoney;

	unsigned char m_gtime;

	bool m_AccessError;
	int m_AccessErrorTime;


public:
	CMoneyManager();
	~CMoneyManager();
	void OnCreat() {
		m_rcClient = RECT{ 30,0,WIDTH,HEIGHT };
		m_spriteMoney.OnCreatCimg(L"Resorce/Test/moneysprite.bmp");
		m_spriteMoney.OnCreatSprite(0.5f, 8, 0.1);
		m_imoney = 2000;
		m_spriteMoney.SetPos(Point{ 15,15 });
		m_gtime = 0;
		m_iADD_money = 0;
		m_AccessError = false;
		m_AccessErrorTime = 20;
	}

	void ADDmoney_clear() {
		m_imoney += m_iADD_money;
	}

	void plus_money(unsigned int plusM) {
		m_iADD_money += plusM;
	}
	bool using_money(const unsigned int& usingM) {
		ADDmoney_clear();
		if (m_imoney >= usingM) {
			m_imoney -= usingM;
			return true;
		}
		else {
			m_AccessError = true;
			return false;
		}
	}


	void Draw(HDC hdc);
	void Update(bool Pause);
};

