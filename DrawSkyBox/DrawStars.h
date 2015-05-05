
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


// 	// �������
// 	LPD3DXMESH					g_sphere;   // ����
// 	
// 	LPD3DXMESH					g_sun;   // ̫��
// 	LPD3DXMESH					g_mercury;   // ˮ��
// 	LPD3DXMESH					g_venus;   // ����
// 	LPD3DXMESH					g_earth;   // ����
// 	LPD3DXMESH					g_moon;   // ����
// 	LPD3DXMESH					g_mars;   // ����
// 	LPD3DXMESH					g_jupiter;   // ľ��
// 	LPD3DXMESH					g_saturn;   // ����
// 	LPD3DXMESH					g_uranus;   // ������
// 	LPD3DXMESH					g_neptune;   // ������

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

	D3DXMATRIX					moon;	//��¼����켣

	CUSTOMVERTEX1				g_Vertices[361];

	//�ƹ����
	D3DLIGHT9					g_light;

	CD3DLight*					m_pLight;

	//���ʶ���
	D3DMATERIAL9				g_material;

	float EarthPosX;
	float EarthPosY;
	float EarthPosZ;

public:
	CDrawStars(LPDIRECT3DDEVICE9  pD3DDevice);
	virtual ~CDrawStars();
	HRESULT		InitVB();
	void		Render(D3DXVECTOR3 CameraPos, D3DXVECTOR3 CameraView);
	void		MatricesRotation();          //������ת
	void		MatricesTransform();          //����ƽ��
	void		StarMove(char *sphere, float rotationSpeed ,float revolutionSpeed ,float majorAxis, float eccentricity ,float inclination = 0);
	void		StarOrbit(float majorAxis, float eccentricity ,float inclination = 0);
	bool		SetTexture(const char*  FileTexture,int flag);
	void		Clearup();
};


