#pragma once
enum ENUM_SCENE
{
	TITLE,
	MENU,
	GAME,
	END
};

class CScene;

class CGameFrameWork
{
public:
	CGameFrameWork();
	~CGameFrameWork();

public:
	bool Create(HWND hWnd, HINSTANCE hInstance);

	void Render();
	void Update(const float &frame_time = 0.017f);

	//KeyÇÔ¼ö
	void Key_Event(UINT iMessage, WPARAM wParam);
	void Key_Down(WPARAM wParam);
	void Key_Up(WPARAM wParam);
	void Key_CHAR(WPARAM wParam);

	void Mouse_Event(UINT iMessage, WPARAM wParam, LPARAM lParam);

	void Command(WPARAM wParam);

	bool Release();

	void PopScene();
	
	void ChangScene(ENUM_SCENE iID);

	RECT GetClientRect() const { return m_rcClient; }

private:

	HINSTANCE m_hInstance;
	PAINTSTRUCT m_ps;
	HWND m_hWnd{ nullptr };
	HDC m_hdc{ nullptr };
	HDC m_memDC{ nullptr };
	HBITMAP m_hBit{ nullptr };
	HBITMAP m_hOldBit{ nullptr };

	RECT			m_rcClient{};

	CScene			*m_Scenes;
	//int				 m_nCurrentScene{ 0 };
	//CScene			*m_pCurrentScene{ nullptr };
	
	void CGameFrameWork::EndPaint() {
		BitBlt(m_hdc, 0, 0, m_rcClient.right, m_rcClient.bottom, m_memDC, 0, 0, SRCCOPY);
		SelectObject(m_memDC, m_hOldBit);
		DeleteObject(m_hBit);
		DeleteDC(m_memDC);
		::EndPaint(m_hWnd, &m_ps);
	}

	void CGameFrameWork::BeginPaint() {
		m_hdc = ::BeginPaint(m_hWnd, &m_ps);
		m_memDC = CreateCompatibleDC(m_hdc);
		m_hBit = CreateCompatibleBitmap(m_hdc, m_rcClient.right, m_rcClient.bottom);
		m_hOldBit = (HBITMAP)SelectObject(m_memDC, m_hBit);
	}

};

