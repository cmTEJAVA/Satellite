#include "stdafx.h"
#include "GameFrameWork.h"
#include "MenuScene.h"
#include "TestScene.h"


CTestScene::CTestScene()
{
}


CTestScene::~CTestScene()
{
	if (m_SceneLayer) delete m_SceneLayer; m_SceneLayer = nullptr;
}

void CTestScene::Update()
{
	m_test_sprite.Update();
}

void CTestScene::Draw(HDC hDC)
{
	FillRect(hDC, &m_rcClient, (HBRUSH)GetStockObject(GRAY_BRUSH));
	m_test_sprite.draw(hDC);


	if (m_SceneLayer) {
		HDC Slhdc = CreateCompatibleDC(hDC);
		HBITMAP slhbmp = CreateCompatibleBitmap(hDC, WIDTH, HEIGHT);
		HBITMAP oldbmp=(HBITMAP)SelectObject(Slhdc, slhbmp);
		m_SceneLayer->Draw(Slhdc);
		
		StretchBlt(hDC, WIDTH / 4, HEIGHT / 4, WIDTH / 2, HEIGHT / 2, Slhdc, 0, 0, WIDTH, HEIGHT, SRCCOPY);
		DeleteObject( SelectObject(Slhdc, oldbmp));
		DeleteDC(Slhdc);
	}
}

bool CTestScene::Mouse(UINT message, WPARAM wParam, LPARAM lParam)
{
	//m_Framework
	switch (message)
	{
	case WM_LBUTTONUP:
	//	m_Framework->ChangeScene(ENUM_SCENE::MENU);
		break;
	case WM_RBUTTONUP:

		m_SceneLayer = new CMenuScene;
		m_SceneLayer->Initialize(m_Framework, m_hWnd);
		break;
	default:
		break;
	}
	return false;
}


bool CTestScene::Initialize(CGameFrameWork * pFramework, HWND hWnd)
{
	if (!CScene::Initialize(pFramework, hWnd)) return false;

	m_SceneLayer = nullptr;

	GetClientRect(hWnd, &m_rcClient);
	m_test_sprite.OnCreatCimg(L"Resorce/Test/Spritepngtest.png");
	m_test_sprite.OnCreatSprite(2.f, 4, 0.3f);
	m_test_sprite.SetPos(Point{ 100,100 });
	return true;
}

void CTestScene::ReleaseObjects()
{
	CScene::ReleaseObjects();

}
