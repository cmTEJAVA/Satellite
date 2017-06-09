#pragma once
#include "ChildScene.h"
#include <vector>

enum class ENUM_CHILD_MESSGE
{
	SETORBITMAX,
	SETORBITSIZE,
	FLASE
};

class CEditChildScene :
	public CChildScene
{
	RECT m_rcClinet;

	std::vector<RECT> m_vOrbit;
	
	size_t m_iSelectOrbit{0};


public:
	CEditChildScene();
	virtual ~CEditChildScene() override;

	virtual void Update() override;

	virtual void Draw(HDC hDC) override;

	virtual bool Keyboard(UINT message, WPARAM wParam) override;

	virtual bool Mouse(UINT message, WPARAM wParam, LPARAM lParam) override;

	virtual bool Initialize(CScene* pparentScene, HWND hWnd) override;

	virtual UINT GetSceneMessge(ENUM_CHILD_MESSGE message, WPARAM wParam, LPARAM lParam) override;

};

