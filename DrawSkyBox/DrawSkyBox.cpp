#include "DrawSkyBox.h"

CDrawSkyBox::CDrawSkyBox(LPDIRECT3DDEVICE9 pD3DDevice)
{
	m_pd3dDevice = pD3DDevice;
}

CDrawSkyBox::~CDrawSkyBox()
{
	Clearup();
}

HRESULT CDrawSkyBox::InitVB()
{
	//////////////////


	if(FAILED(m_pd3dDevice->CreateVertexBuffer(32*sizeof(VERTEX)
		,0
		,D3DFVF_VERTEX
		,D3DPOOL_DEFAULT
		,&m_pBufferVex
		,NULL)))
	{
		return E_FAIL;
	}
	VERTEX* pVertices1;
	if(FAILED(m_pBufferVex->Lock(0, 32*sizeof(VERTEX),(void**)&pVertices1,
		0)))
	{
		return E_FAIL;
	}

	//初始化天空盒的顶点缓冲区
	//=============================================================下表面
	pVertices1->position = D3DXVECTOR3(12.0f, -12.0f, 12.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 1.0f;
	pVertices1->tv       = 0.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(-12.0f, -12.0f, 12.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 0.0f;
	pVertices1->tv       = 0.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(12.0f, -12.0f, -12.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 1.0f;
	pVertices1->tv       = 1.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(-12.0f, -12.0f, -12.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 0.0f;
	pVertices1->tv       = 1.0f;
	pVertices1++;


	//==========================================================================左表面 
	pVertices1->position = D3DXVECTOR3(-12.0f, 12.0f, 12.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 1.0f;
	pVertices1->tv       = 0.0f;
	pVertices1++;
	
	pVertices1->position = D3DXVECTOR3(-12.0f, 12.0f, -12.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 0.0f;
	pVertices1->tv       = 0.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(-12.0f, -12.0f, 12.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 1.0f;
	pVertices1->tv       = 1.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(-12.0f, -12.0f, -12.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 0.0f;
	pVertices1->tv       = 1.0f;
	pVertices1++;

	

	//==========================================================================右表面
	pVertices1->position = D3DXVECTOR3(12.0f, 12.0f, -12.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 1.0f;
	pVertices1->tv       = 0.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(12.0f, 12.0f, 12.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 0.0f;
	pVertices1->tv       = 0.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(12.0f, -12.0f, -12.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 1.0f;
	pVertices1->tv       = 1.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(12.0f, -12.0f, 12.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 0.0f;
	pVertices1->tv       = 1.0f;
	pVertices1++;

// 	//==========================================================================上表面
	pVertices1->position = D3DXVECTOR3(-12.0f, 12.0f, 12.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 0.0f;
	pVertices1->tv       = 1.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(12.0f, 12.0f, 12.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 1.0f;
	pVertices1->tv       = 1.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(-12.0f, 12.0f, -12.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 0.0f;
	pVertices1->tv       = 0.0f;
	pVertices1++;

	

	pVertices1->position = D3DXVECTOR3(12.0f, 12.0f, -12.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 1.0f;
	pVertices1->tv       = 0.0f;
	pVertices1++;

// 
// 	//==========================================================================后表面
	pVertices1->position = D3DXVECTOR3(-12.0f, -12.0f, 12.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 0.0f;
	pVertices1->tv       = 1.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(12.0f, -12.0f, 12.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 1.0f;
	pVertices1->tv       = 1.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(-12.0f, 12.0f, 12.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 0.0f;
	pVertices1->tv       = 0.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(12.0f, 12.0f, 12.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 1.0f;
	pVertices1->tv       = 0.0f;
	pVertices1++;
// 
// 	//==========================================================================前表面
	pVertices1->position = D3DXVECTOR3(12.0f, -12.0f, -12.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 0.0f;
	pVertices1->tv       = 1.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(-12.0f, -12.0f, -12.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 1.0f;
	pVertices1->tv       = 1.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(12.0f, 12.0f, -12.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 0.0f;
	pVertices1->tv       = 0.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(-12.0f, 12.0f, -12.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 1.0f;
	pVertices1->tv       = 0.0f;
	pVertices1++;

	


	m_pBufferVex->Unlock();




	return S_OK;
}

bool CDrawSkyBox::SetTexture(const char *FileTexture, int flag)
{
	if(FAILED(D3DXCreateTextureFromFile(m_pd3dDevice, FileTexture,
		                                &m_pTexScene[flag])))
	{
		return false;
	}
	return true;

}


void CDrawSkyBox::Render(D3DXVECTOR3 CameraPos)
{
	//矩阵单位化
	//D3DXMatrixIdentity(&matWorld);

	//--关闭深度缓存，不渲染平面的反面
	m_pd3dDevice->SetRenderState(D3DRS_ZENABLE,FALSE);
	m_pd3dDevice->SetRenderState(D3DRS_CULLMODE,D3DCULL_CW);
	
	//--坐标转换
	D3DXMATRIX  matWorld;
	D3DXMatrixTranslation(&matWorld,CameraPos.x, CameraPos.y, CameraPos.z);
	m_pd3dDevice->SetTransform(D3DTS_WORLD,&matWorld );

	//夹取寻址
	m_pd3dDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP);
	m_pd3dDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);


	m_pd3dDevice->SetRenderState(D3DRS_AMBIENT,D3DCOLOR_XRGB(200,200,200));

	//渲染6个面==========================================================================下左右上前后
	for(int i=0;i<6;i++)
	{
		m_pd3dDevice->SetTexture(0,m_pTexScene[i]);


		m_pd3dDevice->SetStreamSource(0, m_pBufferVex,4*i*sizeof(VERTEX),sizeof(VERTEX));

		m_pd3dDevice->SetFVF(D3DFVF_VERTEX);
		m_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,0,2);
	}

	//关闭夹取寻址
	m_pd3dDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);
	m_pd3dDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);

	//--打开深度缓存，面的切割方式恢复默认
	m_pd3dDevice->SetRenderState(D3DRS_ZENABLE,TRUE);
	m_pd3dDevice->SetRenderState(D3DRS_CULLMODE,D3DCULL_NONE);

}

//-------------------------------------------
void CDrawSkyBox::Clearup()
{
	if(m_pd3dDevice)
	{
		Release(m_pd3dDevice);
		m_pd3dDevice = NULL;
	}
	if(m_pBufferVex)
	{
		Release(m_pBufferVex);
		m_pBufferVex = NULL;
	}
	if(*m_pTexScene)
	{
		Release(*m_pTexScene);
		*m_pTexScene = NULL;
	}
	
}