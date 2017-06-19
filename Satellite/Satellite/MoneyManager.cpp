#include "stdafx.h"
#include "MoneyManager.h"
#include "Sound.h"

CMoneyManager::CMoneyManager()
{
}


CMoneyManager::~CMoneyManager()
{
}

bool CMoneyManager::using_money(const unsigned int & usingM)
{
	ADDmoney_clear();
	if (m_imoney >= usingM) {
		m_imoney -= usingM;
		return true;
	}
	else {
		m_AccessError = true;

		m_ptrSound->Play_effect(ENUM_SOUND::MONEY);

		return false;
	}
}

void CMoneyManager::Draw(HDC hdc)
{
	HFONT myFont = CreateFont(30, 0, 0, 0, 800, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, L"Consolas");
	HFONT oldFont = (HFONT)SelectObject(hdc, myFont);

	COLORREF textColor;
	if (m_AccessError) {
		textColor = RGB(255, 50, 50);
	}
	else {
		textColor = RGB(255, 255, 255);

	}


	auto oldtxtcolor = SetTextColor(hdc, textColor);
	auto oldBk = SetBkMode(hdc, TRANSPARENT);
	//	SetBkMode(backDC, TRANSPARENT);
	//score = 876543210;
	CString strmoney;

	strmoney.Format(L"%d", m_imoney);

	//strmoney = inttmp + strscore;

	//score % 1000;

	//strscore = "score: " + strscore;
	//wsprintf(asdf, L" score : %d ", score);//<<dlrj 100넘으면 터짐 빨리 고치센

	
	DrawText(hdc, strmoney, lstrlen(strmoney),&m_rcClient,DT_TOP|DT_LEFT);




	SelectObject(hdc, oldFont);
	DeleteObject(myFont);
	myFont = nullptr;

	m_spriteMoney.draw(hdc);

}

void CMoneyManager::Update(bool Pause)
{
	m_spriteMoney.Update();


	if (m_AccessError) {
		m_AccessErrorTime--;
		if (m_AccessErrorTime < 0) {
			m_AccessError = false;
			m_AccessErrorTime = 20;
		}
	}


#pragma region /	plusMoney term 처리

	if (m_iADD_money>0) {
		auto tmpM = m_iADD_money / 7;
		m_iADD_money -= tmpM;
		m_imoney += tmpM;
	}
	else if (m_iADD_money<10) {
		ADDmoney_clear();

	}
#pragma endregion


#pragma region /	일정시간->돈++
	if (!Pause) {
		m_gtime++;
		if (m_gtime > MONEY_TERM) {
			m_imoney++;
			m_gtime = 0;
		}
	}
#pragma endregion


}
