#include "stdafx.h"
#include "GameFrameWork.h"
#include "MenuScene.h"


CMenuScene::CMenuScene()
{
}


CMenuScene::~CMenuScene()
{
}

void CMenuScene::Update()
{
	m_fradian += 0.2;
	if (m_fradian >= 2 * PI) {
		m_fradian = 0;
	}
	
	m_titletextpng.SetPos(Point{ 0.f,(float)(sin(m_fradian)*5.0)-9.0f });
}

void CMenuScene::Draw(HDC hDC)
{
	m_backbmp.draw(hDC);
	m_titletextpng.draw(hDC);
	for(auto& q: m_listbutton)
		q.draw(hDC);
}

bool CMenuScene::Initialize(CGameFrameWork * pFramework, HWND hWnd)
{
	m_fradian = 0;
	m_backbmp.OnCreatCimg(L"Resorce/Menu/Intro.bmp");
	m_titletextpng.OnCreatCimg(L"Resorce/Menu/Title.png");

	for (int i = 0; i < 3; i++) {
		Cbutton m_testbutt;
		m_listbutton.push_back(m_testbutt);
	}

	for (int i = 0; i < 3; i++) {
		
		m_listbutton[i].OnCreatCimg(L"Resorce/Menu/button.png");
		m_listbutton[i].SetObjRECT(RECT{ -60 * 2,-20 * 2,60 * 2,20 * 2 });
		m_listbutton[i].SetPos(Point{ 630, 320 + i * 80 + 50 });
	}

	
	CScene::Initialize(pFramework, hWnd);
	return false;
}

bool CMenuScene::Mouse(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_MOUSEMOVE:
	{
		for (auto& m_testbutt : m_listbutton)
		{

			RECT tmp = m_testbutt.GetObjRECT();
			POINT ptmouse{ LOWORD(lParam),HIWORD(lParam) };
			m_testbutt.SetOn(false);

			if (PtInRect(&tmp, ptmouse)) {
				m_testbutt.SetOn(true);
			}
		}
	}	break;


	case WM_LBUTTONUP:
	{
		
			RECT tmp = m_listbutton[0].GetObjRECT();
			POINT ptmouse{ LOWORD(lParam),HIWORD(lParam) };
			m_listbutton[0].SetOn(false);

			if (PtInRect(&tmp, ptmouse)) {
				m_Framework->ChangeScene(ENUM_SCENE::TEST);
			}
		
		
	}
		break;
	case WM_LBUTTONDOWN:
	{
		//if(m_testbutt.GetOn(true) == true)
		//{ }
		////	snd.Play_effect(ENUM_SOUND::CLICK);
	}	break;



	default:
		break;
	}
	return false;
}
