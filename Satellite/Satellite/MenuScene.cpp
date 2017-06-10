#include "stdafx.h"
#include "GameFrameWork.h"
#include "HELPScene.h"
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


	for (int i = 0; i < m_listbutton.size(); i++) {
		if (!m_listbutton[i].Getselect())continue;
		switch (i)
		{
		case 0:
			m_Framework->ChangeScene(ENUM_SCENE::GAME);
			break;
		case 1:
			m_Framework->ChangeScene(ENUM_SCENE::HELP);
			break;
		case 2:
			PostQuitMessage(NULL);
			break;
		default:
			break;
		}
		return;

	}

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
	m_listbutton[0].OnCreatCimg(L"Resorce/Menu/start button.png");
	m_listbutton[1].OnCreatCimg(L"Resorce/Menu/help button.png");
	m_listbutton[2].OnCreatCimg(L"Resorce/Menu/exit button.png");

	for (int i = 0; i < 3; i++) {
		
		

		m_listbutton[i].SetObjRECT(RECT{ -60 * 2,-20 * 2,60 * 2,20 * 2 });
		m_listbutton[i].SetPos(Point{ 660, 350 + i * (90)   });
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
			
			m_testbutt.SetMouseMove(POINT{ LOWORD(lParam),HIWORD(lParam) });
		}
	}	break;


	case WM_LBUTTONUP:
	{

		POINT ptmouse{ LOWORD(lParam),HIWORD(lParam) };
		for (int i = 0; i < 3; i++) {
			m_listbutton[i].SetMouseLUp(ptmouse);
			
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
