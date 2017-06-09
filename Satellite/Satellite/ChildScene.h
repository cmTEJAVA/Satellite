#pragma once

class CScene;

enum class ENUM_CHILD_MESSGE;

class CChildScene
{
public:
	CChildScene();
	virtual ~CChildScene();

	virtual void Update();

	virtual void Draw(HDC hDC);

	virtual bool Keyboard(UINT message, WPARAM wParam);

	virtual bool Mouse(UINT message, WPARAM wParam, LPARAM lParam);

	virtual bool Initialize(CScene* pparentScene, HWND hWnd);

	virtual void ReleaseObjects();

	virtual UINT GetSceneMessge(ENUM_CHILD_MESSGE message, WPARAM wParam, LPARAM lParam);
protected:

	CScene		*	m_parentScene{ nullptr };
	HWND			m_hWnd{ nullptr };
};

