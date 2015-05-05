#pragma once
#include "header.h"


class CD3DLight
{
private:
	LPDIRECT3DDEVICE9        m_pd3dDevice;         //--…Ë÷√

public:
	CD3DLight(LPDIRECT3DDEVICE9 pD3DDevice);
	~CD3DLight(void);
	void SetMaterial(float specular = 0);
	void SetPointLight(D3DXVECTOR3 pos);
	void SetSpotLight(D3DXVECTOR3 pos);
	void SetDirectionalLight(D3DXVECTOR3 pos);
	void Clearup();


};
