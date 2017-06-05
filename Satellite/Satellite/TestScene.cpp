#include "stdafx.h"
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
}

void CTestScene::Draw(HDC hDC)
{
	FillRect(hDC, &m_rcClient, (HBRUSH)GetStockObject(GRAY_BRUSH));
	m_test_sprite.draw(hDC);
}


bool CTestScene::Initialize(CGameFrameWork * pFramework, HWND hWnd)
{
	CScene::Initialize(pFramework, hWnd);
	GetClientRect(hWnd, &m_rcClient);
	m_test_sprite.OnCreatCimg(L"Spritepngtest.png");
	m_test_sprite.OnCreatSprite(2.f, 4, 0.3f);
	m_test_sprite.SetPos(Point{ 100,100 });
	return false;
}

void CTestScene::ReleaseObjects()
{
	CScene::ReleaseObjects();

}
