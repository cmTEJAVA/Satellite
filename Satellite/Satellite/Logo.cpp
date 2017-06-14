#include "stdafx.h"
#include "GameFrameWork.h"
#include "Logo.h"
#include "Sound.h"

Sound_Func		m_snd_logo;

CLogoScene::CLogoScene()
{/*
	m_snd_logo.Add_sound();
	m_snd_logo.Play_effect(ENUM_SOUND::LOGO);
	m_snd_logo.Play_effect(ENUM_SOUND::LOGO2);*/

}


CLogoScene::~CLogoScene()
{
}

void CLogoScene::Update()
{
		m_fFade += (1.f / GAMEFPS);
		if (m_fFade > m_fMaxFade + 2.f) {
			m_Framework->ChangeScene(ENUM_SCENE::MENU);		
		}
	
	//{
	//	m_Framework->ChangeScene(ENUM_SCENE::MENU);
	//}
}

void CLogoScene::Draw(HDC hDC)
{
	RECT rc = m_Framework->GetClientRect();

	//SetDCBrushColor(hDC, RGB(0, 0, 0));
	//FillRect(hDC, &rc, static_cast<HBRUSH>(GetStockObject(DC_BRUSH)));

	//float fFadeColor = min(255.0f, 255.f * (m_fFade / m_fMaxFade));
	//BYTE FadeColor = static_cast<BYTE>(fFadeColor);

	//SetBkMode(hDC, TRANSPARENT);
	//auto txtColor = SetTextColor(hDC, RGB(FadeColor, FadeColor, FadeColor));

	//DrawText(hDC, TEXT("로고 테스트"), -1, &rc
	//	, DT_CENTER | DT_SINGLELINE | DT_VCENTER
	//);

	//SetTextColor(hDC, txtColor);

	m_bmplogo.drawalpha(hDC, min(MAXBYTE,(m_fFade / m_fMaxFade)*MAXBYTE));
	
}

bool CLogoScene::Keyboard(UINT message, WPARAM wParam)
{
	//m_fFade = m_fMaxFade + 2.f;
	return true;
}

bool CLogoScene::Mouse(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDBLCLK:
	case WM_RBUTTONDBLCLK:
	case WM_MBUTTONDBLCLK:
	case WM_LBUTTONDOWN:
	case WM_RBUTTONDOWN:
	case WM_LBUTTONUP:
	case WM_RBUTTONUP:
	case WM_MBUTTONDOWN:
	case WM_MBUTTONUP:
		break;
	//	m_fFade = m_fMaxFade + 2.f;
	}
	return true;
}

bool CLogoScene::Initialize(CGameFrameWork * pFramework, HWND hWnd)
{
	m_bmplogo.OnCreatCimg(L"Resorce/Logo/Logo.bmp");
	RECT rctmp;
	GetClientRect(hWnd, &rctmp);
	m_bmplogo.Setmidpos(rctmp);

//	m_bmplogo.SetPos(Point{rctmp.right/2,rctmp.bottom/2});


	if (!CScene::Initialize(pFramework, hWnd)) return false;


	return true;
}

void CLogoScene::ReleaseObjects()
{
}
