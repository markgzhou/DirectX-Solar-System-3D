#include "DrawPlane.h"

CDrawPlane::CDrawPlane(LPDIRECT3DDEVICE9 pD3DDevice)
{
	m_pd3dDevice = pD3DDevice;
}

CDrawPlane::~CDrawPlane()
{
	Clearup();
}

HRESULT CDrawPlane::InitVB()
{
	CUSTOMVERTEX1 g_Vertices[] = 
	{
		{2.0f, 3.0f, 0.0f, D3DCOLOR_XRGB(255,0,0), 1.0f, 0.0f},
		{2.0f, 0.0f, 0.0f, D3DCOLOR_XRGB(0,0,255), 1.0f, 1.0f},
		{-2.0f, 3.0f, 0.0f, D3DCOLOR_XRGB(0,255,0), 0.0f, 0.0f},
		{-2.0f, 0.0f, 0.0f, D3DCOLOR_XRGB(255,0,0), 0.0f, 1.0f},
	};

	if(FAILED(m_pd3dDevice->CreateVertexBuffer(sizeof(g_Vertices)
		,0
		,D3DFVF_CUSTOMVETEX1
		,D3DPOOL_DEFAULT
		,&m_pBufferVex
		,NULL)))
	{
		return E_FAIL;
	}

	VOID* pVertices;

	if(FAILED(m_pBufferVex->Lock(0,sizeof(g_Vertices),(void**)&pVertices,0)))
	{
		return E_FAIL;
	}
	memcpy(pVertices,g_Vertices,sizeof(g_Vertices));
	m_pBufferVex->Unlock();

	return S_OK;
}

bool CDrawPlane::SetTexture(const char *FileTexture, int flag)
{
	if(FAILED(D3DXCreateTextureFromFile(m_pd3dDevice, FileTexture,
		                                &m_pTexScene[flag])))
	{
		return false;
	}
	return true;

}



void CDrawPlane::MatricesRotation()
{
	D3DXMATRIX  matWorld;
	D3DXMatrixRotationY(&matWorld, timeGetTime()/100.0f);
	m_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);

}


void CDrawPlane::Render()
{
	D3DXMATRIX  matWorld;
	
	//MatricesRotation();

	m_pd3dDevice->SetStreamSource(0, m_pBufferVex,0,sizeof(CUSTOMVERTEX1));
    m_pd3dDevice->SetFVF(D3DFVF_CUSTOMVETEX1);


	m_pd3dDevice->SetTexture(0,m_pTexScene[0]);
	

    m_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,0,2);

	float i,j;
	for( i = -20/2 + 1; i < 20/2; i += 4)
	{
		for(j = -20/2 + 1; j < 20/2; j += 4)
		{
			if(( j > - 2) && ( j < 2))
				continue;
			D3DXMatrixTranslation(&matWorld, j*1.2+1, 0, i);
			m_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
			//m_pd3dDevice->SetTexture(0,NULL);

            m_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,0,2);

		}
	}

	//m_pd3dDevice->SetTexture(0,NULL);

}

//-------------------------------------------
void CDrawPlane::Clearup()
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