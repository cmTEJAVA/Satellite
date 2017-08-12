#include "stdafx.h"
#include "EditChildScene.h"


CEditChildScene::CEditChildScene()
{
}


CEditChildScene::~CEditChildScene()
{
}

void CEditChildScene::Update()
{
	for (int i = 0; i < m_vUnitButton.size(); i++) {
		if (i == m_vUnitButton.size() - 1&& m_vUnitButton[i].Getselect()) {
			m_vinsert_ID_Units.push_back(idUnit());
			m_vinsert_ID_Units.back().unitID = -1;//orbit일 경우 사이즈를 가지고?
			m_vinsert_ID_Units.back().orbit = m_vOrbit.size();

			//RECT tmp = m_vOrbit.back();
			//
			//m_vOrbit.push_back(RECT{});
			//
			//tmp.left -= ORBIT_DISTANCE;
			//tmp.top -= ORBIT_DISTANCE;
			//tmp.bottom += ORBIT_DISTANCE;
			//tmp.right += ORBIT_DISTANCE;
			//m_vOrbit.back() = tmp;

			m_selectOrbit = -1;

			m_vUnitButton[i].Setselect(false);
			continue;
		}


		if (m_vUnitButton[i].Getselect() && (m_selectOrbit >= 0)) {
			m_vinsert_ID_Units.push_back(idUnit());
			m_vinsert_ID_Units.back().unitID = i;
			m_vinsert_ID_Units.back().orbit = m_selectOrbit;

			m_selectOrbit = -1;

			m_vUnitButton[i].Setselect(false);
		}
	}


	if (m_AccessErrorOrbit>=0) {

		m_AccessErrorOrbittime--;
		if (m_AccessErrorOrbittime <= 0) {
			m_AccessErrorOrbit = -1;
		}
	}
}

void CEditChildScene::Draw(HDC hDC)
{
#pragma region alphahdc_draw
	HDC alphahdc = CreateCompatibleDC(hDC);
	HBITMAP alphahbmp = CreateCompatibleBitmap(hDC, m_rcClient.right, m_rcClient.bottom);
	HBITMAP alphaoldbmp = (HBITMAP)SelectObject(alphahdc, alphahbmp);


//	TCHAR asdf[50] = L"EditChildScene";
//	DrawText(alphahdc, asdf, lstrlen(asdf), &m_rcClient,DT_TOP|DT_LEFT);


	Rectangle(alphahdc, m_rcEditWindow.left, m_rcEditWindow.top, m_rcEditWindow.right, m_rcEditWindow.bottom+20);




	BLENDFUNCTION bf;
	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.SourceConstantAlpha = (255/5);
	bf.AlphaFormat = 0;
	AlphaBlend(hDC, 0, 0, m_rcClient.right, m_rcClient.bottom, alphahdc, 0, 0, m_rcClient.right, m_rcClient.bottom, bf);

	SelectObject(alphahdc, alphaoldbmp);
	DeleteObject(alphahbmp);
	DeleteDC(alphahdc);

#pragma endregion





	HBRUSH old = (HBRUSH)SelectObject(hDC, GetStockObject(NULL_BRUSH));
	HPEN hpen = CreatePen(PS_SOLID, 3, RGB(0, 100, 180));
	HPEN oldpen = (HPEN)SelectObject(hDC, hpen);
	for (int i = 0; i < m_vOrbit.size(); i++) {
		HPEN hpenselect = nullptr;
		HPEN hpenselectold = nullptr;
		if (m_AccessErrorOrbit == i) {

			hpenselect = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
			hpenselectold = (HPEN)SelectObject(hDC, hpenselect);


		}
		else if (m_OnOrbit ==i) {
			hpenselect = CreatePen(PS_SOLID, 3, RGB(255, 150, 0));
			hpenselectold = (HPEN)SelectObject(hDC, hpenselect);

		}
		//m_selectOrbbit
		Ellipse(hDC, m_vOrbit[i].left, m_vOrbit[i].top, m_vOrbit[i].right, m_vOrbit[i].bottom);
		if (m_OnOrbit ==i|| m_AccessErrorOrbit == i) {
			SelectObject(hDC, hpenselectold);
			DeleteObject(hpenselect);
			hpenselect = nullptr;

		}
	}




	HFONT myFont = CreateFont(20, 0, 0, 0, 800, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, L"Arial Narrow");
	HFONT oldFont = (HFONT)SelectObject(hDC, myFont);

	COLORREF textColor;
	textColor = RGB(10, 10, 10);


	auto oldtxtcolor = SetTextColor(hDC, textColor);
	auto oldBk = SetBkMode(hDC, TRANSPARENT);


	for (int i = 0; i < m_vUnitButton.size(); i++) {
		HPEN hpenselect=nullptr;
		HPEN hpenselectold= nullptr;
		if (m_vUnitButton[i].Getselect()) {
			hpenselect = CreatePen(PS_SOLID, 3, RGB(255, 150, 0));
			hpenselectold=(HPEN)SelectObject(hDC, hpenselect);

		}
		Cbutton &m_testbutt = m_vUnitButton[i];

		RECT rctmp = m_testbutt.GetObjRECT();
		m_testbutt.draw(hDC);
		Rectangle(hDC, rctmp.left, rctmp.top, rctmp.right, rctmp.bottom);
		if (m_vUnitButton[i].Getselect()) {
			SelectObject(hDC, hpenselectold);
			DeleteObject(hpenselect);
			hpenselect = nullptr;

		}

		rctmp.top = rctmp.bottom;
		rctmp.bottom = m_rcClient.bottom;

		DrawText(hDC, m_arrstrUnitPRICE[i], lstrlen(m_arrstrUnitPRICE[i]), &rctmp, DT_TOP | DT_CENTER);


	}


	SelectObject(hDC, old);
	SelectObject(hDC, oldpen);
	DeleteObject(hpen);




		SelectObject(hDC, oldFont);
		DeleteObject(myFont);
		myFont = nullptr;
	


}

bool CEditChildScene::Keyboard(UINT message, WPARAM wParam)
{
	return false;
}

bool CEditChildScene::Mouse(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{

	case WM_MOUSEMOVE:
	{
		Point mousetmp{ LOWORD(lParam),HIWORD(lParam) };
		Point midpos{ m_rcClient.right / 2,m_rcClient.bottom / 2 };

		mousetmp = mousetmp - midpos;
		int size = mousetmp.length();
		m_OnOrbit = -1;
		for (int i = 0; i < m_vOrbit.size(); i++) {
			int tmpsize = (m_vOrbit[i].bottom - m_vOrbit[i].top) / 2;
			tmpsize -= size;
			tmpsize = abs(tmpsize);
			if (tmpsize <= 15)
			{
				mousetmp = Point{ LOWORD(lParam),HIWORD(lParam) };
				m_OnOrbit = i;
				return true;
			}


		}
		for (auto &button : m_vUnitButton) {
			button.SetMouseMove(POINT{ LOWORD(lParam),HIWORD(lParam) });
		}

	}

	break;
	case WM_LBUTTONUP:
	{
		Point mousetmp{ LOWORD(lParam),HIWORD(lParam) };
		Point midpos{ m_rcClient.right / 2,m_rcClient.bottom / 2 };
		
		mousetmp = mousetmp - midpos;
		int size = mousetmp.length();
		m_selectOrbit = -1;
		for (int i = 0; i < m_vOrbit.size();i++) {
			int tmpsize = (m_vOrbit[i].bottom - m_vOrbit[i].top)/2;
			tmpsize -= size;
			tmpsize=abs(tmpsize);
			if (tmpsize <=15)
			{
				mousetmp= Point{ LOWORD(lParam),HIWORD(lParam) };
				m_selectOrbit = i;
				m_ptmouseOrbit = mousetmp- midpos;
				m_ptmouseOrbit.normalize();
				m_ptmouseOrbit=m_ptmouseOrbit*((m_vOrbit[i].bottom - m_vOrbit[i].top) / 2);
				m_ptmouseOrbit = m_ptmouseOrbit + midpos;
				return true;
			}


		}

		for (auto &button : m_vUnitButton) {
			button.SetMouseLUp(POINT{ LOWORD(lParam),HIWORD(lParam) });
		}

		

	}
	


		break;




	default:
		return false;
		//메세지가 처리 되지 않았으면 false가 반환
		break;
	}
	return false;

}

bool CEditChildScene::Initialize(CScene * pparentScene, HWND hWnd)
{
	CChildScene::Initialize(pparentScene, hWnd);
	GetClientRect(hWnd, &m_rcClient);


	RECT tmp = m_rcClient;
	tmp.top = (m_rcClient.bottom / 4) * 3;
	tmp.bottom -= 30;
	m_rcEditWindow = tmp;

	m_arrstrUnitPRICE[(int)ENUM_UNIT::BULLET_UNIT].Format(L"%d", PRICE_UNIT_B);
	m_arrstrUnitPRICE[(int)ENUM_UNIT::TESLA_UNIT].Format(L"%d", PRICE_UNIT_T);
	m_arrstrUnitPRICE[(int)ENUM_UNIT::LASER_UNIT].Format(L"%d", PRICE_UNIT_L);
	m_arrstrUnitPRICE[(int)ENUM_UNIT::SHOCKWAVE_UNIT].Format(L"%d", PRICE_UNIT_S);
	m_arrstrUnitPRICE[(int)ENUM_UNIT::END].Format(L"%d", PRICE_ORBIT);

	for (auto&q : m_arrstrUnitPRICE) {
		q = L"★" + q;
	}

//	m_rcEditWindow
	return false;
}

UINT CEditChildScene::GetSceneMessge(UINT message, WPARAM wParam, LPARAM lParam)
{

	switch ((ENUM_CHILD_MESSGE_EDIT)message)
	{
	case ENUM_CHILD_MESSGE_EDIT::SETORBITMAX:
	{
		m_vOrbit.clear();
		for (int i = 0; i < wParam; i++) {
			m_vOrbit.push_back(RECT{});
		}
	}
		break;
	case ENUM_CHILD_MESSGE_EDIT::SETORBITSIZE:
	{
		LONG tmp = lParam;
		m_vOrbit[wParam] = 
			RECT{ WIDTH / 2 - tmp,HEIGHT / 2 - tmp
			,WIDTH / 2 + tmp,HEIGHT / 2 + tmp };
	}
		break;
	case ENUM_CHILD_MESSGE_EDIT::SETUNITMAX:
		m_vUnitButton.clear();
		for (int i = 0; i < wParam; i++) {
			m_vUnitButton.push_back(Cbutton{});
		}
		{

			m_vUnitButton.push_back(Cbutton{});// 추가 궤도add orbit button.bmp
			m_vUnitButton[wParam].OnCreatCimg(
				L"Resorce/button/add orbit button.png"
				);
			LONG sizetmp = m_rcEditWindow.bottom - m_rcEditWindow.top;
			sizetmp /= 2;
			int interval = 10;
			sizetmp -= interval;

			m_vUnitButton[wParam].SetObjRECT(RECT{ -sizetmp,-sizetmp,sizetmp,sizetmp });
			LONG ltmp = m_rcEditWindow.bottom + m_rcEditWindow.top;
			ltmp /= 2;


			m_vUnitButton[wParam].SetPos(
				Point{
				((int)(wParam)* 2 + 1)*(sizetmp + interval)
				,ltmp });

		}
		break;
	case ENUM_CHILD_MESSGE_EDIT::SETUNITPATH:
	{
		m_vUnitButton[wParam].OnCreatCimg(
			(LPCTSTR)lParam
			);
		LONG sizetmp = m_rcEditWindow.bottom - m_rcEditWindow.top;
		sizetmp /= 2;
		int interval=10;
		sizetmp -= interval;
	
		m_vUnitButton[wParam].SetObjRECT(RECT{ -sizetmp,-sizetmp,sizetmp,sizetmp });
		LONG ltmp = m_rcEditWindow.bottom + m_rcEditWindow.top;
		ltmp /= 2;

		
		m_vUnitButton[wParam].SetPos(
			Point{ 
			((int)(wParam)*2+1)*( sizetmp+ interval) 
			,ltmp });
	}
		break;

	case ENUM_CHILD_MESSGE_EDIT::GETINSERTUNIT:
	if(m_vinsert_ID_Units.size()){
	//	if (m_selectOrbit < 0)return false;

		if(m_vinsert_ID_Units.back().unitID>=0){
		RECT tmp = m_vOrbit[m_vinsert_ID_Units.back().orbit];
		int size = tmp.right - tmp.left;
		size /= 2;
		((Point *)wParam)->x= m_ptmouseOrbit.x;
		((Point *)wParam)->y= m_ptmouseOrbit.y;
		}
		*((int *)lParam) = m_vinsert_ID_Units.back().unitID;

		m_vinsert_ID_Units.pop_back();

		return true;
	}
	
		break;
	case ENUM_CHILD_MESSGE_EDIT::SETERRORORBIT:
		m_AccessErrorOrbit = *(char*)wParam;
		m_AccessErrorOrbittime = 15;
		break;


	default:
		break;
	}

	return 0;
}
