#include "stdafx.h"
#include "GameFrameWork.h"
#include "MenuScene.h"
#include "GameScene.h"
#include "EditChildScene.h"

CGameScene::CGameScene()
{
}


CGameScene::~CGameScene()
{
}

void CGameScene::Update()
{
	if (m_ChildScenes) {
		m_ChildScenes->Update();
		//return;
	}

	m_test_player.Update();


	for (auto&q : m_listUnits)
		q.Update();


	for (int i = 0; i < 2; i++) {
		if (!m_arrbutton[i].Getselect()) continue;
		switch (i)
		{
		case 0:
			if (m_ChildScenes) {
				m_arrbutton[i].Setselect(false);
				PopChildScene();
			}
			else {

				m_arrbutton[i].Setselect(false);
				m_Framework->ChangeScene(ENUM_SCENE::MENU);

			}

			break;
		case 1:
			if (!m_ChildScenes) {
				m_arrbutton[i].Setselect(false);

				ChangeChildScene(ENUM_SCENE_CHILD::EDIT);
				m_ChildScenes->GetSceneMessge(ENUM_CHILD_MESSGE::SETORBITMAX, 1, 0);
				m_ChildScenes->GetSceneMessge(ENUM_CHILD_MESSGE::SETORBITSIZE, 0, 100);

				m_ChildScenes->GetSceneMessge(ENUM_CHILD_MESSGE::SETUNITMAX, 2, 0);
				m_ChildScenes->GetSceneMessge(ENUM_CHILD_MESSGE::SETUNITPATH, 0, (LPARAM)L"Resorce/button/bullet unit button.png");
				m_ChildScenes->GetSceneMessge(ENUM_CHILD_MESSGE::SETUNITPATH, 1, (LPARAM)m_arrUnitszPath[1]);


			}
			//	retrun;

			break;
		default:
			break;
		}
		return;
	}

}

void CGameScene::Draw(HDC hDC)
{
	//FillRect(hDC, &m_rcClient, (HBRUSH)GetStockObject(GRAY_BRUSH));
	m_bmp_backimg.draw(hDC);
	m_test_player.draw(hDC);



	m_arrbutton[0].draw(hDC);
	if (!m_ChildScenes)
		m_arrbutton[1].draw(hDC);

	for (auto&q : m_listUnits) {
		q.draw(hDC);
	}

	if (m_ChildScenes)m_ChildScenes->Draw(hDC);

}

bool CGameScene::Mouse(UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_ChildScenes) {
		if (m_ChildScenes->Mouse(message, wParam, lParam)) {
			return true;
		}
	}
	switch (message)
	{
	case WM_LBUTTONUP:
	{
		for (auto & button : m_arrbutton) {
			button.SetMouseLUp(POINT{ LOWORD(lParam),HIWORD(lParam) });
		}


		m_test_player.attack();
	}
	break;
	case WM_RBUTTONUP:
		m_test_player.cure();
		break;

	case WM_MOUSEMOVE:
		for (auto & buttonq : m_arrbutton) {
			buttonq.SetMouseMove(POINT{ LOWORD(lParam),HIWORD(lParam) });

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


	m_arrbutton[0].OnCreatCimg(L"Resorce/button/green arrow back.png");
	m_arrbutton[0].SetObjRECT(RECT{ -15,-15,15,15 });
	m_arrbutton[0].SetPos(Point{ 20,20 });
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

	m_test_player.Setdestroyedimg(L"Resorce/Test/ss4.bmp");


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
