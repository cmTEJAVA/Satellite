#include "stdafx.h"
#include "MenuScene.h"


CMenuScene::CMenuScene()
{
}


CMenuScene::~CMenuScene()
{
}

void CMenuScene::Update()
{
}

void CMenuScene::Draw(HDC hDC)
{

	RECT q{ 10,10,50,50 };
	FillRect(hDC, &q, (HBRUSH)GetStockObject(WHITE_BRUSH));

}

bool CMenuScene::Initialize(CGameFrameWork * pFramework, HWND hWnd)
{
	CScene::Initialize(pFramework, hWnd);
	return false;
}
