#include "stdafx.h"
#include "MoneyManager.h"


CMoneyManager::CMoneyManager()
{
}


CMoneyManager::~CMoneyManager()
{
}

void CMoneyManager::Draw(HDC hdc)
{
	HFONT myFont = CreateFont(30, 0, 0, 0, 800, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, L"Arial Rounded MT Bold");
	HFONT oldFont = (HFONT)SelectObject(hdc, myFont);

	auto oldtxtcolor = SetTextColor(hdc, RGB(255, 255, 255));
	auto oldBk = SetBkMode(hdc, TRANSPARENT);
	//	SetBkMode(backDC, TRANSPARENT);
	//score = 876543210;
	CString strmoney;

	strmoney.Format(L"%.3d", m_imoney);

	//strmoney = inttmp + strscore;

	//score % 1000;

	//strscore = "score: " + strscore;
	//wsprintf(asdf, L" score : %d ", score);//<<dlrj 100³ÑÀ¸¸é ÅÍÁü »¡¸® °íÄ¡¼¾

	
	DrawText(hdc, strmoney, lstrlen(strmoney),&m_rcClient,DT_TOP|DT_LEFT);




	SelectObject(hdc, oldFont);
	DeleteObject(myFont);
	myFont = nullptr;

	m_spriteMoney.draw(hdc);

}

void CMoneyManager::Update()
{
	m_spriteMoney.Update();
}
