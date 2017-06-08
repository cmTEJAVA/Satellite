#pragma once
#include "Scene.h"
#include <vector>
#include "Vector.h"
#include "Matrix.h"
#include <fstream>
//#include <>
class CLogo3DScene :
	public CScene
{
	RECT m_rcClient;


	std::vector<size_t> m_vdrawpts;
	std::vector<CVector> m_vPoints;

	void PointsInit() {
		std::ifstream ifs("Resorce/Logo/logo_model.obj", std::ios::binary);
		if (ifs.fail()) {
			//
			return;
		}

		while (!ifs.eof()) {
			char cheak = 0;
			char asdf[100];
			ifs >> cheak;
			if (cheak == '#')ifs.getline(asdf, 100);
			// >> name >> ih >> im >> is;
			else if (cheak == 'v') {
				CVector vtmp;
				float tmp;
				ifs >> tmp;
				vtmp.set_x(tmp);
				ifs >> tmp;
				vtmp.set_z(tmp);


				ifs >> tmp;
				vtmp.set_y(tmp);

				//v_vertext.push_back(tmp);
				m_vPoints.push_back(vtmp);
			}
			else if (cheak == 'f') {
				size_t tmp0 = -1;
				size_t tmp = -1;
				ifs >> tmp0;
				tmp = tmp0;

				m_vdrawpts.push_back(tmp0 - 1);
				ifs >> tmp0;
				m_vdrawpts.push_back(tmp0 - 1);

				////

				m_vdrawpts.push_back(tmp0 - 1);
				ifs >> tmp0;
				m_vdrawpts.push_back(tmp0 - 1);
				//

				m_vdrawpts.push_back(tmp0 - 1);
				ifs >> tmp0;
				m_vdrawpts.push_back(tmp0 - 1);
				//

				m_vdrawpts.push_back(tmp0 - 1);
				m_vdrawpts.push_back(tmp-1);



				ifs.getline(asdf, 100);

			}
			else {
				ifs.getline(asdf, 100);

			}
		}
	}

public:
	CLogo3DScene();
	virtual ~CLogo3DScene() override;

	virtual void Update() override;

	virtual void Draw(HDC hDC) override;

	virtual bool Initialize(CGameFrameWork* pFramework, HWND hWnd) override;

};

