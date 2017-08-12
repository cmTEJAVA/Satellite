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
	SETERRORORBIT,
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
	
	std::vector<Cbutton>m_vUnitButton;

	int m_OnOrbit{ -1 };
	int m_selectOrbit{ -1 };

	int m_AccessErrorOrbit{ -1 };
	int m_AccessErrorOrbittime{ -1 };

	
	Point m_ptmouseOrbit;

	CString				m_arrstrUnitPRICE[int(ENUM_UNIT::END) + 1];


	std::vector<idUnit>m_vinsert_ID_Units;


public:
	CEditChildScene();
	virtual ~CEditChildScene() override;

	virtual void Update() override;

	virtual void Draw(HDC hDC) override;

	virtual bool Keyboard(UINT message, WPARAM wParam) override;

	//�޼����� ó�� ���� �ʾ����� false�� ��ȯ
	virtual bool Mouse(UINT message, WPARAM wParam, LPARAM lParam) override;

	virtual bool Initialize(CScene* pparentScene, HWND hWnd) override;

	virtual UINT GetSceneMessge(UINT message, WPARAM wParam, LPARAM lParam) override;

};

