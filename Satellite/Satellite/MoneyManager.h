#pragma once
#include "Sprite.h"


class Sound_Func;


class CMoneyManager
{
	RECT m_rcClient;
	unsigned int m_imoney;
	unsigned int m_iADD_money;



	CSprite m_spriteMoney;

	unsigned char m_gtime;

	bool m_AccessError;
	int m_AccessErrorTime;

	Sound_Func* m_ptrSound;

	
public:
	CMoneyManager();
	~CMoneyManager();
	void OnCreat(Sound_Func* ptrS) {
		m_ptrSound = ptrS;
		m_rcClient = RECT{ 30,0,WIDTH,HEIGHT };
		m_spriteMoney.OnCreatCimg(L"Resorce/Test/moneysprite.bmp");
		m_spriteMoney.OnCreatSprite(0.5f, 8, 0.1);
		m_imoney = 1500;
		m_spriteMoney.SetPos(Point{ 15,15 });
		m_gtime = 0;
		m_iADD_money = 0;
		m_AccessError = false;
		m_AccessErrorTime = 20;
	}

	void ADDmoney_clear() {
		m_imoney += m_iADD_money;
	}

	bool plus_money(unsigned int plusM) {
		if(plusM==0)return false;

		m_iADD_money += plusM;
		return true;
	}
	bool using_money(const unsigned int& usingM);


	void Draw(HDC hdc);
	void Update(bool Pause);
};

