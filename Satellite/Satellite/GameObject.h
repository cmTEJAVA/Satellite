#pragma once
#include "stdafx.h"


class CGameObject
{
public:
	CGameObject();
	virtual ~CGameObject();

public:
	void Paint_Nemo(HDC hdc, int color);	
	void Render(HDC hdc) {};
	void Update(float frame_time);
	void OnCreate(float sizex, float sizey
	, float x, float y, float spd)
	{
		m_sizex = sizex; m_sizey = sizey;
		m_x = x; m_y = y; m_spd = spd;
	}

	void SetPosX(float x) { m_x = x; }
	void SetPosY(float y) { m_y = y; }
	float GetPosX() { return m_x; }
	float GetPosY() { return m_y; }
	// 위치

	void SetSize(float x, float y) { m_sizex = x; m_sizey = y; }
	float GetSizeY() { return m_sizey; }
	float GetSizeX() { return m_sizex; }
	// 크기

	void SetDirX(float x) { dir_x = x; }
	void SetDirY(float y) { dir_y = y; }
	float GetDirX() { return dir_x; }
	float GetDirY() { return dir_y; }
	// 방향

	void SetSpd(float s) { m_spd = s; }
	float GetSpd() { return m_spd; }
	// 속도

	void SetAngle(float a) { angle = a; }
	float GetAngle() { return angle; }
	float GetAngleSpd() { return rotate_spd; }
	// 각도

	void SetShow(bool s) { show = s; }
	bool GetShow() { return show; }

	void Rotate(float center_x, float center_y
		, float center_size_x, float center_size_y);


protected:
	float m_x{ 0 }; float m_y{ 0 };
	float m_sizex{ 10 }; float m_sizey{ 10 };
	float dir_x{ 0 }; float dir_y{ 0 };
	float m_spd{ 0 };
	float rotate_spd{ 8 }; float angle{ 0 };
	bool show{ false };
};