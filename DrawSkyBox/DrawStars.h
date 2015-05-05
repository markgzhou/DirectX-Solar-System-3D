
#pragma once

#include "header.h"
#include "Camera.h"
#include "D3DLight.h"
#include "D3DLoadMesh.h"




class CDrawStars 
{
public:
	LPDIRECT3DDEVICE9			m_pd3dDevice;
	LPDIRECT3DVERTEXBUFFER9		m_pBufferVex;
	LPDIRECT3DTEXTURE9			m_pTexScene[4];
	CCamera						m_Camera;


// 	// 网格对象
// 	LPD3DXMESH					g_sphere;   // 球体
// 	
// 	LPD3DXMESH					g_sun;   // 太阳
// 	LPD3DXMESH					g_mercury;   // 水星
// 	LPD3DXMESH					g_venus;   // 金星
// 	LPD3DXMESH					g_earth;   // 地球
// 	LPD3DXMESH					g_moon;   // 月球
// 	LPD3DXMESH					g_mars;   // 火星
// 	LPD3DXMESH					g_jupiter;   // 木星
// 	LPD3DXMESH					g_saturn;   // 土星
// 	LPD3DXMESH					g_uranus;   // 天王星
// 	LPD3DXMESH					g_neptune;   // 海王星

	CD3DLoadMesh				g_MeshSun;
	CD3DLoadMesh				g_MeshMercury;
	CD3DLoadMesh				g_MeshVenus;
	CD3DLoadMesh				g_MeshEarth;
	CD3DLoadMesh				g_MeshMoon;
	CD3DLoadMesh				g_MeshMars;
	CD3DLoadMesh				g_MeshJupiter;
	CD3DLoadMesh				g_MeshSaturn;
	CD3DLoadMesh				g_MeshUranus;
	CD3DLoadMesh				g_MeshNeptune;

	CD3DLoadMesh				g_MeshAsteroid;

	D3DXMATRIX					moon;	//记录地球轨迹

	CUSTOMVERTEX1				g_Vertices[361];

	//灯光对象
	D3DLIGHT9					g_light;

	CD3DLight*					m_pLight;

	//材质对象
	D3DMATERIAL9				g_material;

	float EarthPosX;
	float EarthPosY;
	float EarthPosZ;

public:
	CDrawStars(LPDIRECT3DDEVICE9  pD3DDevice);
	virtual ~CDrawStars();
	HRESULT		InitVB();
	void		Render(D3DXVECTOR3 CameraPos, D3DXVECTOR3 CameraView);
	void		MatricesRotation();          //设置旋转
	void		MatricesTransform();          //设置平移
	void		StarMove(char *sphere, float rotationSpeed ,float revolutionSpeed ,float majorAxis, float eccentricity ,float inclination = 0);
	void		StarOrbit(float majorAxis, float eccentricity ,float inclination = 0);
	bool		SetTexture(const char*  FileTexture,int flag);
	void		Clearup();
};


