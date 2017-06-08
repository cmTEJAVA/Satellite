#include "stdafx.h"
#include "Logo3DScene.h"


CLogo3DScene::CLogo3DScene()
{
}


CLogo3DScene::~CLogo3DScene()
{
}

void CLogo3DScene::Update()
{

}

void CLogo3DScene::Draw(HDC hDC)
{
	FillRect(hDC, &m_rcClient, (HBRUSH)GetStockObject(GRAY_BRUSH));
	TCHAR asdf[100]{ L"3dLogo" };
	DrawText(hDC, asdf, lstrlen(asdf), &m_rcClient, DT_TOP | DT_LEFT);
	//	POINT tmp[2];
		CVector Pos[2];
		CVector halfv{
			m_rcClient.right / 2.f,
		m_rcClient.bottom / 2.f,0
		};

		for (int i = 0; i < m_vdrawpts.size();i+=2)
	{
		Pos[0] = m_vPoints[m_vdrawpts[i]];
		Pos[1] = m_vPoints[m_vdrawpts[i+1]];
		for (auto &q : Pos) {
			q.set_x(q.get_x() / q.get_z());
			q.set_y(q.get_y() / q.get_z());
		}


		MoveToEx(hDC, Pos[0].get_x()+halfv.get_x(), Pos[0].get_y()+halfv.get_y(),nullptr);
		LineTo(hDC	, Pos[1].get_x()+halfv.get_x(), Pos[1].get_y()+halfv.get_y());
	}

}

bool CLogo3DScene::Initialize(CGameFrameWork * pFramework, HWND hWnd)
{
	CScene::Initialize(pFramework, hWnd);
	PointsInit();
	GetClientRect(hWnd, &m_rcClient);

	
	return false;
}
