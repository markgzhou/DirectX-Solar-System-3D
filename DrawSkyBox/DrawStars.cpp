#include "DrawStars.h"
#include "Camera.h"
#include "math.h"
#include "D3DInit.h"

CDrawStars::CDrawStars(LPDIRECT3DDEVICE9 pD3DDevice)
{
	m_pd3dDevice = pD3DDevice;

	

	m_pLight   = new CD3DLight(m_pd3dDevice);
}

CDrawStars::~CDrawStars()
{
	Clearup();
}

HRESULT CDrawStars::InitVB()
{
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

	//初始化光晕的顶点缓冲区
	//=============================================================
	pVertices1->position = D3DXVECTOR3(8.0f, -8.0f, 0.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 1.0f;
	pVertices1->tv       = 0.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(-8.0f, -8.0f, 0.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 0.0f;
	pVertices1->tv       = 0.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(8.0f, 8.0f, 0.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 1.0f;
	pVertices1->tv       = 1.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(-8.0f, 8.0f, 0.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 0.0f;
	pVertices1->tv       = 1.0f;
	pVertices1++;

	//=============================================================
	pVertices1->position = D3DXVECTOR3(3.0f, -3.0f, 0.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 1.0f;
	pVertices1->tv       = 0.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(-3.0f, -3.0f, 0.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 0.0f;
	pVertices1->tv       = 0.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(3.0f, 3.0f, 0.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 1.0f;
	pVertices1->tv       = 1.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(-3.0f, 3.0f, 0.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 0.0f;
	pVertices1->tv       = 1.0f;
	pVertices1++;

	//=============================================================
	pVertices1->position = D3DXVECTOR3(8.0f, -8.0f, 0.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 1.0f;
	pVertices1->tv       = 0.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(-8.0f, -8.0f, 0.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 0.0f;
	pVertices1->tv       = 0.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(8.0f, 8.0f, 0.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 1.0f;
	pVertices1->tv       = 1.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(-8.0f, 8.0f, 0.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 0.0f;
	pVertices1->tv       = 1.0f;
	pVertices1++;

	//=============================================================
	pVertices1->position = D3DXVECTOR3(4.0f, -4.0f, 0.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 1.0f;
	pVertices1->tv       = 0.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(-4.0f, -4.0f, 0.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 0.0f;
	pVertices1->tv       = 0.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(4.0f, 4.0f, 0.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 1.0f;
	pVertices1->tv       = 1.0f;
	pVertices1++;

	pVertices1->position = D3DXVECTOR3(-4.0f, 4.0f, 0.0f);
	pVertices1->color    = D3DCOLOR_XRGB(0,0,255);
	pVertices1->tu       = 0.0f;
	pVertices1->tv       = 1.0f;
	pVertices1++;

	m_pBufferVex->Unlock();


	//mash模型===================================================
	g_MeshSun.SetDevice(m_pd3dDevice);
	g_MeshSun.LoadFile("sun.x");
	
	g_MeshMercury.SetDevice(m_pd3dDevice);
	g_MeshMercury.LoadFile("mercury.x");

	g_MeshVenus.SetDevice(m_pd3dDevice);
	g_MeshVenus.LoadFile("venus.x");
	
	g_MeshEarth.SetDevice(m_pd3dDevice);
	g_MeshEarth.LoadFile("earth.x");

	g_MeshMoon.SetDevice(m_pd3dDevice);
	g_MeshMoon.LoadFile("moon.x");

	g_MeshMars.SetDevice(m_pd3dDevice);
	g_MeshMars.LoadFile("mars.x");

	g_MeshAsteroid.SetDevice(m_pd3dDevice);
	g_MeshAsteroid.LoadFile("asteroid.x");

	g_MeshJupiter.SetDevice(m_pd3dDevice);
	g_MeshJupiter.LoadFile("jupiter.x");

	g_MeshSaturn.SetDevice(m_pd3dDevice);
	g_MeshSaturn.LoadFile("saturn.x");

	g_MeshUranus.SetDevice(m_pd3dDevice);
	g_MeshUranus.LoadFile("uranus.x");

	g_MeshNeptune.SetDevice(m_pd3dDevice);
	g_MeshNeptune.LoadFile("neptune.x");
	
	return S_OK;
}


bool CDrawStars::SetTexture(const char *FileTexture, int flag)
{
	if(FAILED(D3DXCreateTextureFromFile(m_pd3dDevice, FileTexture,
		                                &m_pTexScene[flag])))
	{
		return false;
	}
	return true;

}



void CDrawStars::StarMove(char *sphere, float rotationSpeed ,float revolutionSpeed ,float majorAxis, float eccentricity, float inclination)
{
	D3DXMATRIX  matWorld;
	D3DXMatrixIdentity(&matWorld);

	D3DXMATRIX  matWorld0;
	D3DXMatrixIdentity(&matWorld0);
	D3DXMatrixRotationX(&matWorld0, -90.0f/360*2*D3DX_PI);

	D3DXMATRIX  matWorld1;
	D3DXMatrixIdentity(&matWorld1);
	rotationSpeed=5*rotationSpeed;
	revolutionSpeed=10*revolutionSpeed;
	if(0 != rotationSpeed)
	{
		D3DXMatrixRotationY(&matWorld1, timeGetTime()/rotationSpeed);
	}

	float r;

	r = majorAxis*sqrt(1-pow(eccentricity,2))/sqrt(1-pow(eccentricity,2)*pow(cos(timeGetTime()/revolutionSpeed*1.0f),2));

	D3DXMATRIX  matWorld2;
	D3DXMatrixTranslation(&matWorld2,r,0,0);

	D3DXMATRIX  matWorld3;
	D3DXMatrixIdentity(&matWorld3);
	if(0 != revolutionSpeed)
	{
		D3DXMatrixRotationY(&matWorld3, timeGetTime()/revolutionSpeed);
	}

	//行星轨迹的倾角
	D3DXMATRIX  matWorld4;
	D3DXMatrixIdentity(&matWorld4);
	D3DXMatrixRotationX(&matWorld4, inclination/360*2*D3DX_PI);
	
	matWorld =matWorld0 * matWorld1 * matWorld2 * matWorld3 *matWorld4;

	//Device->SetTransform(D3DTS_WORLD, &m_Camera.g_vPos);
	//m_Camera.g_vPos=m_Camera.g_vPos * matWorld0 * matWorld1 * matWorld2 * matWorld3 *matWorld4;


	//m_Camera.g_vPos.x =  10;
	//m_Camera.g_vPos.y = 10;
 //   m_Camera.g_vPos.z =  10;

	//m_Camera.g_vViewAt.x =  10;
 //   m_Camera.g_vViewAt.y = 10;
 //   m_Camera.g_vViewAt.z =  10;

 //   m_Camera.SetPosCamera(10.0f,10.0f,10.0f);



	if(sphere == "moon")
	{
		matWorld = matWorld2 * matWorld3 *  moon;	//月球的移动
	}
	m_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);

	//判断行星名称，并绘制
	if(sphere == "sun")
	{
		g_MeshSun.DrawMash();
	}
	else if(sphere == "mercury")
	{
		g_MeshMercury.DrawMash();
	}
	else if(sphere == "venus")
	{
		g_MeshVenus.DrawMash();
	}
	else if(sphere == "earth")
	{
		g_MeshEarth.DrawMash();
	}
	else if(sphere == "moon")
	{
		g_MeshMoon.DrawMash();
	}
	else if(sphere == "mars")
	{
		g_MeshMars.DrawMash();
	}
	else if(sphere == "asteroid")
	{
		g_MeshAsteroid.DrawMash();
	}
	else if(sphere == "jupiter")
	{
		g_MeshJupiter.DrawMash();
	}
	else if(sphere == "saturn")
	{
		//实现木星光环的透明效果
		m_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
		m_pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		m_pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

		g_MeshSaturn.DrawMash();

		m_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);	
	}
	else if(sphere == "uranus")
	{
		g_MeshUranus.DrawMash();
	}
	else if(sphere == "neptune")
	{
		g_MeshNeptune.DrawMash();
	}




	m_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,0,2);

	//如果是地球，则绘制月球
	if(sphere == "earth")
	{
		moon = matWorld0 *  matWorld;	//保存地球的位置
		m_pd3dDevice->SetTexture(0,m_pTexScene[13]);
		StarMove("moon",30000,-300,1.5,0.0167);
	}
	//如果不是月球，则按正常方式画行星轨迹
	if(sphere == "moon")
	{
		m_pd3dDevice->SetTransform(D3DTS_WORLD, &moon);
		StarOrbit(majorAxis,eccentricity);
	}
	else if(sphere != "asteroid")
	{
		D3DXMatrixIdentity(&matWorld);

		//行星轨迹的倾角
		D3DXMatrixRotationX(&matWorld, inclination/360*2*D3DX_PI);

		m_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
		StarOrbit(majorAxis,eccentricity);
	}//如果是月球，则将轨道移动到地球处再画
	
	
}

void CDrawStars::StarOrbit(float majorAxis, float eccentricity, float inclination)
{
	
	//CUSTOMVERTEX1 *g_Vertices = new CUSTOMVERTEX1[361];

	for(int i =0;i<361;i++)
	{
		g_Vertices[i].x = majorAxis*cos(i*1.0f/360*2*D3DX_PI); 
		g_Vertices[i].z = majorAxis*sqrt(1-pow(eccentricity,2))*sin(i*1.0f/360*2*D3DX_PI); 
		g_Vertices[i].y = 0.0f; 
		g_Vertices[i].color = D3DCOLOR_XRGB(255,255,0);
	}

	m_pd3dDevice->SetFVF(D3DFVF_CUSTOMVETEX1);

	m_pd3dDevice->DrawPrimitiveUP(D3DPT_LINESTRIP, 360, g_Vertices, sizeof(CUSTOMVERTEX1)); 
}

void CDrawStars::Render(D3DXVECTOR3 CameraPos, D3DXVECTOR3 CameraView)
{
	//夹取寻址
	m_pd3dDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);
	m_pd3dDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);

	//给太阳制造高亮效果
	m_pd3dDevice->SetRenderState(D3DRS_AMBIENT,D3DCOLOR_XRGB(2550,2550,2550));

	StarMove("sun",0,200000,0,0);

	//创造太阳光
	m_pLight->SetPointLight(m_Camera.g_vPos);
	m_pLight->SetMaterial();

	StarMove("mercury",-58000,870,5.79,0.206,-7);
	StarMove("venus",243000,-2240,10.82,0.007,3.4);
	StarMove("earth",-1000,3650,14.96,0.0167);
	StarMove("mars",-1000,6860,22.79,0.093,1.8);

	srand(1);
	for(int i = 0; i<800; i++)
	{
		StarMove("asteroid",0,6860+i*100,35+rand()%25,0.093,1);
	}

	StarMove("jupiter",-370,43280,77.83,0.048,-1.3);
	StarMove("saturn",-430,107670,142.94,0.055,2.5);
	StarMove("uranus",10000,306600,287.09,0.05,-0.8);
	StarMove("neptune",-630,601520,450.40,0.01,1.8);
	m_pd3dDevice->SetTexture(0,NULL);
	
	///////////////////////////////////////////////////////////////////////

	m_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	m_pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	m_pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	
	D3DXMATRIX  matWorld;
	D3DXMATRIX  matWorldx;
	D3DXMATRIX  matWorldy;
	D3DXMATRIX  matWorldz;

	D3DXMatrixIdentity(&matWorld);

	if(CameraPos.z <=0)
		D3DXMatrixRotationY(&matWorldz, atanf(CameraPos.x/CameraPos.z));
	else
		D3DXMatrixRotationY(&matWorldz, D3DX_PI+atanf(CameraPos.x/(1.0f*CameraPos.z)));
	D3DXMatrixRotationX(&matWorldy, atanf(CameraPos.y/sqrt(pow(CameraPos.x,2)+pow(CameraPos.z,2))));

 	

	matWorld = matWorldy * matWorldz;
//	D3DXMatrixTranslation(&matWorld,CameraPos.x, CameraPos.y, CameraPos.z);
	m_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);

	m_pd3dDevice->SetTexture(0,m_pTexScene[0]);
	m_pd3dDevice->SetStreamSource(0, m_pBufferVex,0,sizeof(VERTEX));

	m_pd3dDevice->SetFVF(D3DFVF_VERTEX);
	m_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,0,2);
	
	
	m_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);	
	////////////////////////////////////////////////////////////////////////
	m_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	m_pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	m_pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);


	D3DXVECTOR3 ViewVec;
	ViewVec = 1.5 * CameraView + CameraPos;

	D3DXVECTOR3 temp;
	temp = -1 * CameraPos;
 	float q = 0;
	q = acos(D3DXVec3Dot(( D3DXVECTOR3* )&CameraView,( D3DXVECTOR3* )&temp)/(D3DXVec3Length(&CameraView)*D3DXVec3Length(&temp)));
	
	if(q <= D3DX_PI/3 && q >= 0 && D3DXVec3Length(&CameraPos) > 1.5 * D3DXVec3Length(&CameraView) )
	{

		D3DXMatrixIdentity(&matWorld);

		D3DXVECTOR3 flareDis;
		flareDis = 0.7 * ViewVec;
		D3DXMatrixTranslation(&matWorldx,flareDis.x,flareDis.y,flareDis.z);

		matWorld = matWorldy * matWorldz * matWorldx;

		m_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);

		m_pd3dDevice->SetTexture(0,m_pTexScene[1]);
		m_pd3dDevice->SetStreamSource(0, m_pBufferVex,4*sizeof(VERTEX),sizeof(VERTEX));

		m_pd3dDevice->SetFVF(D3DFVF_VERTEX);
		m_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,0,2);


		//==========================================================
		D3DXMatrixIdentity(&matWorld);

		flareDis = 0.8 * ViewVec;
		D3DXMatrixTranslation(&matWorldx,flareDis.x,flareDis.y,flareDis.z);

		matWorld = matWorldy * matWorldz * matWorldx;

		m_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);

		m_pd3dDevice->SetTexture(0,m_pTexScene[2]);
		m_pd3dDevice->SetStreamSource(0, m_pBufferVex,8*sizeof(VERTEX),sizeof(VERTEX));

		m_pd3dDevice->SetFVF(D3DFVF_VERTEX);
		m_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,0,2);

		//==========================================================
		D3DXMatrixIdentity(&matWorld);

		flareDis = 0.9 * ViewVec;

		D3DXMatrixTranslation(&matWorldx,flareDis.x,flareDis.y,flareDis.z);

		matWorld = matWorldy * matWorldz * matWorldx;

		m_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);

		m_pd3dDevice->SetTexture(0,m_pTexScene[3]);
		m_pd3dDevice->SetStreamSource(0, m_pBufferVex,12*sizeof(VERTEX),sizeof(VERTEX));

		m_pd3dDevice->SetFVF(D3DFVF_VERTEX);
		m_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,0,2);
		//==========================================================
	}
	m_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
	m_pd3dDevice->SetTexture(0,NULL);
}

//-------------------------------------------
void CDrawStars::Clearup()
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
	
	//Release(g_MeshAsteroid);

}