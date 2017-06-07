#include "stdafx.h"
#include "GameFrameWork.h"
#include "MenuScene.h"
#include "TestScene.h"


CTestScene::CTestScene()
{
}


CTestScene::~CTestScene()
{
}

void CTestScene::Update()
{
	m_test_sprite.Update();
	m_test_player.Update();


}

void CTestScene::Draw(HDC hDC)
{
	FillRect(hDC, &m_rcClient, (HBRUSH)GetStockObject(GRAY_BRUSH));
	m_test_sprite.draw(hDC);
	m_test_player.draw(hDC);


}

bool CTestScene::Mouse(UINT message, WPARAM wParam, LPARAM lParam)
{
	//m_Framework
	switch (message)
	{
	case WM_LBUTTONUP:
		m_test_player.attack(0.05f);
	//	m_Framework->ChangeScene(ENUM_SCENE::MENU);
		break;
	default:
		break;
	}
	return false;
}


bool CTestScene::Initialize(CGameFrameWork * pFramework, HWND hWnd)
{
	if (!CScene::Initialize(pFramework, hWnd)) return false;

	GetClientRect(hWnd, &m_rcClient);
	m_test_sprite.OnCreatCimg(L"Resorce/Test/Spritepngtest.png");
	m_test_sprite.OnCreatSprite(2.f, 4, 0.3f);
	m_test_sprite.SetPos(Point{ 100,100 });

	m_test_player.OnCreatplayerimg
		(
			Point{ m_rcClient.right / 2,m_rcClient.bottom / 2 },
			L"Resorce/Test/ss3.png",
			1.f, 16, 0.6f
			);


	return true;
}

void CTestScene::ReleaseObjects()
{
	CScene::ReleaseObjects();

}
