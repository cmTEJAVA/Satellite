#pragma once
#include "ChildScene.h"

class CGameFrameWork;

class CScene
{
public:
	CScene();
	virtual ~CScene();

	virtual void Update();

	virtual void Draw(HDC hDC);

	virtual bool Keyboard(UINT message, WPARAM wParam);

	virtual bool Mouse(UINT message, WPARAM wParam, LPARAM lParam);

	virtual bool Initialize(CGameFrameWork* pFramework, HWND hWnd);

	virtual void ReleaseObjects();


	void PopChildScene();

	void ChangeChildScene(ENUM_SCENE_CHILD iID);

protected:

	CGameFrameWork	*	m_Framework{ nullptr };
	HWND				m_hWnd{ nullptr };
	CChildScene		*	m_ChildScenes{ nullptr };

};

