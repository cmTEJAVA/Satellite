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

	Rectangle(hDC, 10, 10, 50, 50);

}

bool CMenuScene::Initialize(CGameFrameWork * pFramework, HWND hWnd)
{
	CScene::Initialize(pFramework, hWnd);
	return false;
}
