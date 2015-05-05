#include "d3dlight.h"

CD3DLight::CD3DLight(LPDIRECT3DDEVICE9 pD3DDevice)
{
	m_pd3dDevice = pD3DDevice; 

}

CD3DLight::~CD3DLight(void)
{
	Clearup();
}

void CD3DLight::SetDirectionalLight(D3DXVECTOR3 pos)
{
	D3DLIGHT9 g_light;
	D3DXVECTOR3 vecDir;
	ZeroMemory(&g_light, sizeof(D3DLIGHT9));
	// Setup the light source.
	// 设置光源属性
	g_light.Type = D3DLIGHT_DIRECTIONAL;  // 类型为方向光
	g_light.Diffuse.r = 1.0f;
	g_light.Diffuse.g = 1.0f;
	g_light.Diffuse.b = 1.0f;
	g_light.Range = 500.0f;
	vecDir = D3DXVECTOR3( cosf( timeGetTime() / 350.0f ),
		1.0f,
		sinf( timeGetTime() / 350.0f ) );
	D3DXVec3Normalize( ( D3DXVECTOR3* )&g_light.Direction, &vecDir );

	// Register the light.
	m_pd3dDevice->SetLight(0, &g_light);   // 设置该光源
	m_pd3dDevice->LightEnable(0, TRUE);    // 启用该光源

	m_pd3dDevice->SetRenderState( D3DRS_LIGHTING, TRUE );
	m_pd3dDevice->SetRenderState(D3DRS_AMBIENT,D3DCOLOR_XRGB(100,100,100));

}

void CD3DLight::SetPointLight(D3DXVECTOR3 pos)
{
	D3DLIGHT9 g_light;
	D3DXVECTOR3 vecDir;
	ZeroMemory(&g_light, sizeof(D3DLIGHT9));
	// Setup the light source.
	// 设置光源属性
	g_light.Type = D3DLIGHT_POINT;  // 类型为方向光
	g_light.Diffuse.r = 1.0f;
	g_light.Diffuse.g = 1.0f;
	g_light.Diffuse.b = 1.0f;
	g_light.Position.x = g_light.Position.y = g_light.Position.z = 0.0f;
	g_light.Specular.r = g_light.Specular.g = g_light.Specular.b = 0.5f;
	g_light.Attenuation1 =0.01;
	g_light.Range = 500.0f;

// 	vecDir = D3DXVECTOR3( cosf( timeGetTime() / 350.0f ),
// 		1.0f,
// 		sinf( timeGetTime() / 350.0f ) );
// 	D3DXVec3Normalize( ( D3DXVECTOR3* )&g_light.Direction, &vecDir );

	// Register the light.
	m_pd3dDevice->SetLight(0, &g_light);   // 设置该光源
	m_pd3dDevice->LightEnable(0, TRUE);    // 启用该光源

	m_pd3dDevice->SetRenderState( D3DRS_LIGHTING, TRUE );
	m_pd3dDevice->SetRenderState(D3DRS_AMBIENT,D3DCOLOR_XRGB(125,125,125));
	m_pd3dDevice->SetRenderState(D3DRS_SPECULARENABLE,true);
}

void CD3DLight::SetSpotLight(D3DXVECTOR3 pos)
{
	D3DLIGHT9 g_light;
	D3DXVECTOR3 vecDir;
	ZeroMemory(&g_light, sizeof(D3DLIGHT9));
	// Setup the light source.
	// 设置光源属性
	g_light.Type = D3DLIGHT_DIRECTIONAL;  // 类型为方向光
	g_light.Diffuse.r = 1.0f;
	g_light.Diffuse.g = 1.0f;
	g_light.Diffuse.b = 1.0f;

	vecDir = D3DXVECTOR3( cosf( timeGetTime() / 350.0f ),
		1.0f,
		sinf( timeGetTime() / 350.0f ) );
	D3DXVec3Normalize( ( D3DXVECTOR3* )&g_light.Direction, &vecDir );

	// Register the light.
	m_pd3dDevice->SetLight(0, &g_light);   // 设置该光源
	m_pd3dDevice->LightEnable(0, TRUE);    // 启用该光源

	m_pd3dDevice->SetRenderState( D3DRS_LIGHTING, TRUE );
	m_pd3dDevice->SetRenderState(D3DRS_AMBIENT,D3DCOLOR_XRGB(100,100,100));
	
}

void CD3DLight::SetMaterial(float specular)
{
	D3DMATERIAL9 g_material;
	ZeroMemory(&g_material, sizeof(D3DMATERIAL9));  // 将g_material对象的内存块清零
	g_material.Diffuse.r = g_material.Ambient.r = 1.0f;
	g_material.Diffuse.g = g_material.Ambient.g = 1.0f;
	g_material.Diffuse.b = g_material.Ambient.b = 1.0f;
	g_material.Diffuse.a = g_material.Ambient.a = 1.0f;
	g_material.Specular.r = g_material.Specular.g = g_material.Specular.b = specular;
//	g_material.Emissive.r = 1.0f;
	m_pd3dDevice->SetMaterial(&g_material);
}

//-------------------------------------------
void CD3DLight::Clearup()
{
	if(m_pd3dDevice)
	{
		Release(m_pd3dDevice);
		m_pd3dDevice = NULL;
	}

}