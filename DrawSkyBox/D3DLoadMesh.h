#pragma once

#include "header.h"

class CD3DLoadMesh
{
public:
	CD3DLoadMesh(void);
	~CD3DLoadMesh(void);

public:
	LPDIRECT3DDEVICE9         m_pd3dDevice;
	LPDIRECT3DVERTEXBUFFER9   m_pBufferVex;
	LPD3DXMESH               m_pMesh;
	LPDIRECT3DTEXTURE9*       m_pTexture;
	D3DMATERIAL9*            m_pMaterial; //材质
	DWORD                    m_dwMrtlNum; //材质数量
public:
	HRESULT LoadFile(char *strFileName);
	void SetDevice(LPDIRECT3DDEVICE9 pDevice);
	void DrawMash();
	void Clearup();
};