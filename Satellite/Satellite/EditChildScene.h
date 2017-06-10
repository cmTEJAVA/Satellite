#pragma once
#include "ChildScene.h"
#include <vector>
#include "Button.h"

enum class ENUM_CHILD_MESSGE_EDIT
{
	SETORBITMAX,
	SETORBITSIZE,
	SETUNITMAX,
	SETUNITPATH,
	GETINSERTUNIT,
	FLASE
};

struct idUnit{
	int orbit;
	int unitID;
};

class CEditChildScene :
	public CChildScene
{
	RECT m_rcClient;
	RECT m_rcEditWindow;

	std::vector<RECT> m_vOrbit;
	
	std::vector<Cbutton>m_vUnits;

	int m_selectOrbit{ -1 };
	
	std::vector<idUnit>m_vinsert_ID_Units;


public:
	CEditChildScene();
	virtual ~CEditChildScene() override;

	virtual void Update() override;

	virtual void Draw(HDC hDC) override;

	virtual bool Keyboard(UINT message, WPARAM wParam) override;

	//메세지가 처리 되지 않았으면 false가 반환
	virtual bool Mouse(UINT message, WPARAM wParam, LPARAM lParam) override;

	virtual bool Initialize(CScene* pparentScene, HWND hWnd) override;

	virtual UINT GetSceneMessge(UINT message, WPARAM wParam, LPARAM lParam) override;

};

