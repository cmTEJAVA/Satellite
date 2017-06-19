#include "stdafx.h"
#include "Scene.h"
#include "EditChildScene.h"
#include "GameOverScene.h"
#include "Sound.h"

CScene::CScene()
{
}

CScene::~CScene()
{
	ReleaseObjects();
}

void CScene::Update()
{
}

void CScene::Draw(HDC hDC)
{
}

bool CScene::Keyboard(UINT message, WPARAM wParam)
{
	return false;
}

bool CScene::Mouse(UINT message, WPARAM wParam, LPARAM lParam)
{
	return false;
}

bool CScene::Initialize(CGameFrameWork * pFramework, HWND hWnd)
{
	m_Framework = pFramework;
	m_hWnd = hWnd;
	return true;
}

void CScene::snd_init(Sound_Func*ptrs)
{
	m_snd = ptrs;
}

void CScene::ReleaseObjects()
{
}

void CScene::PopChildScene()
{
	if (m_ChildScenes) delete m_ChildScenes;
	m_ChildScenes = nullptr;
}

void CScene::ChangeChildScene(ENUM_SCENE_CHILD iID)
{
	PopChildScene();
	switch (iID)
	{
	case ENUM_SCENE_CHILD::EDIT:
		m_ChildScenes = new CEditChildScene;
		m_ChildScenes->Initialize(this, m_hWnd);

		break;

	case ENUM_SCENE_CHILD::GameOver:
		m_ChildScenes = new CGameOverScene;
		m_ChildScenes->Initialize(this, m_hWnd);

		break;


	default:
		break;
	}

}
