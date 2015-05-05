
#pragma once
#include "header.h"
#include "DrawSkyBox.h"
#include "DrawPlane.h"
#include "DrawStars.h"
#include "GameInput.h"
#include "D3DFont.h"
#include "GameTime.h"

class CD3DInit  
{
private:
	LPDIRECT3D9             g_pD3D;       //--Direct3D����ָ��
	LPDIRECT3DDEVICE9       g_pd3dDevice; //--Direct3D���豸

	CDrawSkyBox*            g_DrawSkyBox;
	CDrawPlane*             g_DrawPlane;
	CDrawStars*             g_DrawStars;

	CCamera                 g_Camera;
	CGameInput              g_pInput;

	CD3DFont*				g_pFont;
	RECT					clientRect;

	CD3DFont*				g_pFont2;
	RECT					clientRect2;

	CD3DFont*				g_pFont3;
	RECT					clientRect3;

	CD3DFont*				g_pFont4;
	RECT					clientRect4;

	CD3DFont*				g_pFont5;
	RECT					clientRect5;

	CD3DFont*				g_pFont6;
	RECT					clientRect6;

	CD3DFont*				g_pFont7;
	RECT					clientRect7;
		
	CGameTime				g_GameTime;
	char					FPSStr[50];
	char					FPSStr2[50];
	char					FPSStr3[50];
	char					FPSStr4[50];
	char					FPSStr5[50];
	char					FPSStr6[50];
	char					FPSStr7[50];


	float windowwidth;
	float windowheight;

public:
	CD3DInit();
	virtual ~CD3DInit();
	BOOL		GameInit(HWND hWnd,HINSTANCE hInstance);		//--������Ϸ�ĳ�ʼ������
	HRESULT		InitD3D(HWND hWnd);							//--D3D�ĳ�ʼ��
	void		SetCamera();
	void		SetInput();
	void		Render();										//--������Ϸ����Ⱦ
	void		SetItem();
	void		SetSampler(D3DTEXTUREFILTERTYPE samplerType);	//--�������ģʽ����
	void		Music();

};
