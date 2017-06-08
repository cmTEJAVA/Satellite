#include "stdafx.h"
#include "GameFrameWork.h"
#include "MenuScene.h"
#include "GameScene.h"


CGameScene::CGameScene()
{
}


CGameScene::~CGameScene()
{
}

void CGameScene::Update()
{

	m_test_player.Update();

	for (auto&q : m_listUnits)
		q.Update();

}

void CGameScene::Draw(HDC hDC)
{
	//FillRect(hDC, &m_rcClient, (HBRUSH)GetStockObject(GRAY_BRUSH));
	m_bmp_backimg.draw(hDC);
	m_test_player.draw(hDC);


	for (auto&q : m_arrbutton)
		q.draw(hDC);

	for (auto&q : m_listUnits)
		q.draw(hDC);
}

bool CGameScene::Mouse(UINT message, WPARAM wParam, LPARAM lParam)
{

	switch (message)
	{
	case WM_LBUTTONUP:
	{


		for (int i = 0; i < 2; i++) {
			RECT tmp = m_arrbutton[i].GetObjRECT();
			POINT ptmouse{ LOWORD(lParam),HIWORD(lParam) };
			m_arrbutton[i].SetOn(false);

			if (PtInRect(&tmp, ptmouse)) {
				m_arrbutton[i].SetOn(true);

				switch (i)
				{
				case 0:
					m_Framework->ChangeScene(ENUM_SCENE::MENU);
					return false;
					break;
				case 1:
					//	m_Framework->ChangeScene(ENUM_SCENE::TITLE3D);
					//	retrun;
					return false;
					break;
				default:
					break;
				}



				return false;
			}
		}
		m_test_player.attack();
	}
	break;
	case WM_RBUTTONUP:
		m_test_player.cure();
		break;

	case WM_MOUSEMOVE:
		for (auto & buttonq : m_arrbutton) {
			RECT tmp = buttonq.GetObjRECT();
			POINT ptmouse{ LOWORD(lParam),HIWORD(lParam) };
			buttonq.SetOn(false);

			if (PtInRect(&tmp, ptmouse)) {
				buttonq.SetOn(true);
				return false;
			}
		}
		break;

	default:
		break;
	}




	return false;
}


bool CGameScene::Initialize(CGameFrameWork * pFramework, HWND hWnd)
{
	if (!CScene::Initialize(pFramework, hWnd)) return false;

	GetClientRect(hWnd, &m_rcClient);

	m_arrUnitszPath[(int)ENUM_UNIT::BULLET_UNIT] = L"Resorce/Test/bullet unit.bmp";
	m_arrUnitszPath[(int)ENUM_UNIT::TESLA_UNIT] = L"Resorce/Test/tesla.png";


	m_arrbutton[0].OnCreatCimg(L"Resorce/Menu/exit button.png");
	m_arrbutton[0].SetObjRECT(RECT{ -50,-20,50,20 });
	m_arrbutton[0].SetPos(Point{ 50,20 });
	m_arrbutton[1].OnCreatCimg(L"Resorce/button/option.png");
	m_arrbutton[1].SetObjRECT(RECT{ -20,-20,20,20 });
	m_arrbutton[1].SetPos(Point{ m_rcClient.right - 30,m_rcClient.bottom - 30 });




	m_bmp_backimg.OnCreatCimg(L"Resorce/Test/testback.jpg");
	m_bmp_backimg.SetObjRECT(m_rcClient);


	m_test_player.OnCreatplayerimg
	(
		Point{ m_rcClient.right / 2,m_rcClient.bottom / 2 },
		L"Resorce/Test/ss3.bmp",
		1.f, 16, 0.6f
	);


	for (int i = 0; i < 1; i++) {
		m_listUnits.push_back(CUnit{});
		m_listUnits.back().OnCreatUnit(
			Point{ m_rcClient.right / 2 ,m_rcClient.bottom / 2 }, 100,
			m_arrUnitszPath[int(ENUM_UNIT::BULLET_UNIT)],
			0.8f, 1, 0.6f, 0.01f, 0.02f
		);
	}



	return true;
}

void CGameScene::ReleaseObjects()
{
	CScene::ReleaseObjects();

}
