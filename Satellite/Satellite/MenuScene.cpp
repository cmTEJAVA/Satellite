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
	m_backbmp.draw(hDC);

}

bool CMenuScene::Initialize(CGameFrameWork * pFramework, HWND hWnd)
{
	m_backbmp.OnCreatCimg(L"Intro.bmp");
	CScene::Initialize(pFramework, hWnd);
	return false;
}
