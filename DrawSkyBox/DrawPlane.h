
#pragma once

#include "header.h"
#include "Camera.h"


class CDrawPlane  
{
public:
	LPDIRECT3DDEVICE9          m_pd3dDevice;
	LPDIRECT3DVERTEXBUFFER9    m_pBufferVex;
	LPDIRECT3DTEXTURE9         m_pTexScene[6];
	CCamera                    m_Camera;

public:
	CDrawPlane(LPDIRECT3DDEVICE9  pD3DDevice);
	virtual ~CDrawPlane();
	HRESULT  InitVB();
	void     Render();
	void     MatricesRotation();          //ÉèÖÃÐý×ª
	bool     SetTexture(const char*  FileTexture,int flag);
	void     Clearup();
};


