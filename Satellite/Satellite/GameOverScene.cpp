#include "stdafx.h"
#include "Scene.h"
#include "GameOverScene.h"


CGameOverScene::CGameOverScene()
{
}


CGameOverScene::~CGameOverScene()
{
}

void CGameOverScene::Update()
{
	//for (int i = 0; i < 2; i++) {
	//	if (!m_button[i].Getselect())continue;
	//	switch (i)
	//	{
	//	case 0:
	//		//m_parentScene->ChangeScene(ENUM_SCENE::MENU);
	//		//m_FrameWork.ChangeScene(ENUM_SCENE::MENU);
	//		break;

	//	case 1:
	//		// xx
	//		break;

	//	default:
	//		break;
	//	}
	//	return;
	//}
}

void CGameOverScene::Draw(HDC hDC)
{
	FillRect(hDC, &m_rcClient, (HBRUSH)GetStockObject(WHITE_BRUSH));

	m_back.draw(hDC);
	m_button[0].draw(hDC);
	m_button[1].draw(hDC);
}

bool CGameOverScene::Mouse(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{

	case WM_MOUSEMOVE:
		for (auto &buttonq : m_button) {
			buttonq.SetMouseMove(POINT{ LOWORD(lParam),HIWORD(lParam) });
		}
	break;

	case WM_LBUTTONUP:
		for (auto & buttonq : m_button) {
			buttonq.SetMouseLUp(POINT{ LOWORD(lParam),HIWORD(lParam) });
		}
	break;

	default:
		return false;
		break;
	}
	return false;

}

bool CGameOverScene::Initialize(CScene * pparentScene, HWND hWnd)
{
	CChildScene::Initialize(pparentScene, hWnd);
	GetClientRect(hWnd, &m_rcClient);

	m_back.OnCreatCimg(L"Resorce/Game/game over.png");
	m_button[0].OnCreatCimg(L"Resorce/button/green arrow back.png");
	m_button[1].OnCreatCimg(L"Resorce/button/green arrow re.png");
	for (auto & q : m_button) {
		q.SetObjRECT(RECT{ -30,-30,30,30 });
	}
	m_button[0].SetPos(Point{ 220,m_rcClient.bottom - 100 });
	m_button[1].SetPos(Point{ m_rcClient.right - 220, m_rcClient.bottom - 100 });

	return false;
}

UINT CGameOverScene::GetSceneMessge(UINT message, WPARAM wParam, LPARAM lParam)
{

	switch ((ENUM_CHILD_MESSGE_GOVER)message)
	{
	case ENUM_CHILD_MESSGE_GOVER::GETCHANGESCENE_MENU:
		if (m_button[0].Getselect()) {
			return true;

		}
		break;
	default:
		break;
	}

	return false;
}
