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
	m_ftitleVmoveradian += 0.5;
	if (m_ftitleVmoveradian >= 2 * PI) {
		m_ftitleVmoveradian = 0;
	}
	m_ftitleHmoveradian += 0.7;
	if (m_ftitleHmoveradian >= 2 * PI) {
		m_ftitleHmoveradian = 0;
	}
	m_back[0].SetPos(Point{ (float)(cos(m_ftitleHmoveradian)*2.0),(float)(sin(m_ftitleVmoveradian)*5.0) });
	//m_back[1].SetPos(Point{ (float)(cos(m_ftitleHmoveradian)*2.0),(float)(sin(m_ftitleVmoveradian)*5.0) });
}

void CGameOverScene::Draw(HDC hDC)
{
	//FillRect(hDC, &m_rcClient, (HBRUSH)GetStockObject(WHITE_BRUSH));

	m_back[0].draw(hDC);
	m_back[1].draw(hDC);

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

	m_ftitleVmoveradian=0;
	m_ftitleHmoveradian=0;
	m_back[0].OnCreatCimg(L"Resorce/Game/game over.png");
	m_back[1].OnCreatCimg(L"Resorce/Game/game over back.png");

	m_button[0].OnCreatCimg(L"Resorce/button/green arrow back.png");
	m_button[1].OnCreatCimg(L"Resorce/button/green arrow re.png");
	for (auto & q : m_button) {
		q.SetObjRECT(RECT{ -25,-25,25,25 });
	}
	m_button[0].SetPos(Point{ 50,m_rcClient.top + 50 });
	m_button[1].SetPos(Point{ m_rcClient.right - 50, m_rcClient.top + 50 });

	return false;
}

UINT CGameOverScene::GetSceneMessge(UINT message, WPARAM wParam, LPARAM lParam)
{

	switch ((ENUM_CHILD_MESSGE_GOVER)message)
	{
	case ENUM_CHILD_MESSGE_GOVER::GETCHANGESCENE:
		if (m_button[0].Getselect()) {
			*(ENUM_SCENE *)wParam = ENUM_SCENE::MENU;
			return true;
		}
		if (m_button[1].Getselect()) {
			*(ENUM_SCENE *)wParam = ENUM_SCENE::GAME;
			return true;
		}
		break;

	default:
		break;
	}

	return false;
}
