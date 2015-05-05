#include "D3DLoadMesh.h"

CD3DLoadMesh::CD3DLoadMesh(void)
{
	m_pd3dDevice=NULL;
	m_pBufferVex=NULL;
	m_pMaterial=NULL;
	m_pMesh=NULL;
	m_pTexture=NULL;
	m_dwMrtlNum=0L;
}

CD3DLoadMesh::~CD3DLoadMesh(void)
{
	Clearup();
}

void CD3DLoadMesh::SetDevice(LPDIRECT3DDEVICE9 pDevice)
{
	m_pd3dDevice = pDevice;
}

HRESULT CD3DLoadMesh::LoadFile(char *strFileName)
{
	LPD3DXBUFFER pXBuffer;
	if(FAILED(D3DXLoadMeshFromX(strFileName,D3DXMESH_SYSTEMMEM,m_pd3dDevice,
		NULL,&pXBuffer,NULL,&m_dwMrtlNum,&m_pMesh)))
		return E_FAIL;
	D3DXMATERIAL *Material=(D3DXMATERIAL *)pXBuffer->GetBufferPointer();
	m_pMaterial=new D3DMATERIAL9[m_dwMrtlNum];
	m_pTexture= new LPDIRECT3DTEXTURE9[m_dwMrtlNum];
	for(DWORD i=0;i<m_dwMrtlNum;i++)
	{
		m_pMaterial[i]= Material[i].MatD3D;
		m_pMaterial[i].Ambient=m_pMaterial[i].Diffuse;

		if(FAILED(D3DXCreateTextureFromFile(m_pd3dDevice,Material[i].pTextureFilename,&m_pTexture[i])))
		{
			m_pTexture[i]=NULL;
		}
	}
	pXBuffer->Release();
	return S_OK;
}

void CD3DLoadMesh::DrawMash()
{
	for(DWORD i=0;i<m_dwMrtlNum;i++)
	{
		m_pd3dDevice->SetMaterial(&m_pMaterial[i]);
		m_pd3dDevice->SetTexture(0,m_pTexture[i]);
		m_pMesh->DrawSubset(i);
	}
}

void CD3DLoadMesh::Clearup()
{
	if( m_pMaterial != NULL ) 
		delete[] m_pMaterial;

	if(m_pd3dDevice)
	{
		Release(m_pd3dDevice);
	}

	if( m_pTexture )
	{
		for( DWORD i = 0; i < m_dwMrtlNum; i++ )
		{
			if( m_pTexture[i] )
				m_pTexture[i]->Release();
		}
		delete[] m_pTexture;
	}
	if( m_pMesh != NULL )
		m_pMesh->Release();
}