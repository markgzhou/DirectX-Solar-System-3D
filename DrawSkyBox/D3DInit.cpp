// D3DInit.cpp: implementation of the CD3DInit class.
//
//////////////////////////////////////////////////////////////////////

#include "D3DInit.h"


#include<Windows.h>  
#include<iostream>  
#include<process.h>  
using namespace std;  
#include <mmsystem.h>
#pragma comment(lib, "Winmm.lib")
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CD3DInit::CD3DInit()
{
	g_pD3D = NULL;
	g_pd3dDevice = NULL;

}

CD3DInit::~CD3DInit()
{
	g_pD3D->Release();
	g_pD3D = NULL;

	g_pd3dDevice->Release();
	g_pd3dDevice = NULL;
}

void myfun(PVOID arg)  
{  
	PlaySound("d:\\background.WAV",NULL,SND_LOOP);
}  



//--D3D�ĳ�ʼ��
HRESULT CD3DInit::InitD3D(HWND hWnd)
{
	//--����D3D����
	if(NULL == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
		return E_FAIL;     //--(E_FAIL)����ʧ��
	D3DDISPLAYMODE d3ddm;  //--����һ�����浱ǰ���������ԵĽṹ
	//--��õ�ǰ����������ʾģʽ
	if(FAILED(g_pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm)))
	{
		return E_FAIL;  //--���ʧ���򷵻�(FAILED:ʧ��)
	}
	//--���ô��ݸ�LPDIRECT3D9::CreateDevice�Ĳ���
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));               //--�ѽṹ�����
	d3dpp.Windowed         = false;                  //--ָ�����Ǵ���ģʽ,����ȫ�ֶ�ռģʽ
	d3dpp.SwapEffect       = D3DSWAPEFFECT_DISCARD;  //--�趨��ҳЧ��Ϊ������̨����
	d3dpp.BackBufferFormat = d3ddm.Format;           //--ɫ�����Ϊ�����ɫ�����
	d3dpp.BackBufferWidth  = d3ddm.Width;            //--�󻺳���
	windowwidth=d3ddm.Width;
	d3dpp.BackBufferHeight = d3ddm.Height;           //--�󻺳�߶�
	windowheight=d3ddm.Height;
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT; //--��Ļˢ����
	d3dpp.PresentationInterval       = D3DPRESENT_INTERVAL_ONE; //--��תģʽ
	

	d3dpp.AutoDepthStencilFormat  = D3DFMT_D16;
	d3dpp.EnableAutoDepthStencil  = true;
	
	if(FAILED( g_pD3D->CreateDevice(D3DADAPTER_DEFAULT,          //--ʹ�õ�ǰ�Կ���ע�豸
		                            D3DDEVTYPE_HAL,             //--Ӳ��������豸
									hWnd,        
									D3DCREATE_SOFTWARE_VERTEXPROCESSING, //--������ķ�������
									//--�������ݲ�����ΪD3DCREATE_HARDWARE_VERTEXPROCESSING��
									//--ʹ��Ӳ��
									&d3dpp,
									&g_pd3dDevice)))
	{
		return E_FAIL;
	}


	g_pd3dDevice->SetRenderState(D3DRS_LIGHTING ,TRUE);
	g_pd3dDevice->SetRenderState(D3DRS_CULLMODE,D3DCULL_NONE);


	 HANDLE handle=(HANDLE)_beginthread(myfun,0, NULL);  //////NEw thread



	return S_OK;
}

BOOL CD3DInit::GameInit(HWND hWnd,HINSTANCE hInstance)
{
	if(SUCCEEDED(this->InitD3D(hWnd)))
	{
		//--��ʼ����������豸
		g_pInput.InitInput(hWnd,hInstance);

		//--��ʼ����պм�����ͼ
		g_DrawSkyBox = new CDrawSkyBox(g_pd3dDevice);

		g_DrawSkyBox->InitVB();
		g_DrawSkyBox->SetTexture("pic\\bottom.jpg",0);
		g_DrawSkyBox->SetTexture("pic\\left.jpg",  1);
		g_DrawSkyBox->SetTexture("pic\\right.jpg", 2);
		g_DrawSkyBox->SetTexture("pic\\top.jpg",   3);
		g_DrawSkyBox->SetTexture("pic\\back.jpg",  4);
		g_DrawSkyBox->SetTexture("pic\\front.jpg", 5);

		//--��ʼ�����Ƶ�ͼ�μ�����ͼ
		g_DrawPlane = new CDrawPlane(g_pd3dDevice);

		g_DrawPlane->InitVB();
		g_DrawPlane->SetTexture("pic\\pic.bmp",0);

		//--��ʼ�����Ƶ����弰����ͼ
		g_DrawStars = new CDrawStars(g_pd3dDevice);
		g_DrawStars->InitVB();

		g_DrawStars->SetTexture("pic\\glow.png",0);
		g_DrawStars->SetTexture("pic\\flare1.png",1);
		g_DrawStars->SetTexture("pic\\flare2.png",2);
		g_DrawStars->SetTexture("pic\\flare3.png",3);

		//--��ʼ������
		g_pFont = new CD3DFont(g_pd3dDevice);
		g_pFont->LoadFont("Arial",10);

		GetClientRect(hWnd,&clientRect);
		//clientRect.left=30;
		clientRect.top=windowheight-100;
		//clientRect.bottom=80;
		//clientRect.right=200;
		
		
		g_pFont2 = new CD3DFont(g_pd3dDevice);
		g_pFont2->LoadFont("Arial",10);

		GetClientRect(hWnd,&clientRect2);
		//clientRect2.left=30;
		clientRect2.top=windowheight-200;
		//clientRect2.bottom=80;
		//clientRect2.right=200;


		g_pFont3 = new CD3DFont(g_pd3dDevice);
		g_pFont3->LoadFont("Arial",10);

		GetClientRect(hWnd,&clientRect3);
		clientRect3.left=10;
		clientRect3.top=30;
		clientRect3.bottom=80;
		clientRect3.right=150;



		g_pFont4 = new CD3DFont(g_pd3dDevice);
		g_pFont4->LoadFont("Arial",10);

		GetClientRect(hWnd,&clientRect4);
		clientRect4.left=windowwidth-120;
		clientRect4.top=30;
		clientRect4.bottom=80;
		clientRect4.right=windowwidth;


		g_pFont5 = new CD3DFont(g_pd3dDevice);
		g_pFont5->LoadFont("Arial",10);

		GetClientRect(hWnd,&clientRect5);
		clientRect5.left=20;
		clientRect5.top=windowheight-60;
		clientRect5.bottom=windowheight;
		clientRect5.right=320;


		g_pFont6 = new CD3DFont(g_pd3dDevice);
		g_pFont6->LoadFont("Arial",10);

		GetClientRect(hWnd,&clientRect6);
		clientRect6.left=windowwidth-300;
		clientRect6.top=windowheight-60;
		clientRect6.bottom=windowheight;
		clientRect6.right=windowwidth;

		
		g_pFont7 = new CD3DFont(g_pd3dDevice);
		g_pFont7->LoadFont("Arial",10);

		GetClientRect(hWnd,&clientRect7);
		//clientRect7.left=windowwidth-300;
		clientRect7.top=0;
		//clientRect7.bottom=windowheight;
		//clientRect7.right=windowwidth;



		std::sprintf(FPSStr2, "Loading!!");
		std::sprintf(FPSStr, "Loading!!");
		std::sprintf(FPSStr7, "Loading!!!!!");

		return true;
	}
	else
	{
		return false;
	}
	return true;
}

//--�������������
void CD3DInit::SetCamera()
{

	D3DXMATRIX   matView;
	D3DXMatrixLookAtLH(&matView, &g_Camera.g_vPos,
		&g_Camera.g_vViewAt,
		&g_Camera.g_vUp);
	g_pd3dDevice->SetTransform(D3DTS_VIEW,&matView);

	D3DXMATRIX  matProj;
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI/3, g_Camera.aspect,0.1f,1000.0f);
	g_pd3dDevice->SetTransform(D3DTS_PROJECTION,&matProj);

}

void CD3DInit::SetInput()
{
	g_pInput.ReadMouse();
	g_Camera.ProcInput(&g_pInput);
}

void CD3DInit::SetItem()
{
	if(KEYDOWN(VK_F1))
	{
		g_pd3dDevice->SetRenderState(D3DRS_FILLMODE,D3DFILL_WIREFRAME);
	}
	if(KEYDOWN(VK_F2))
	{
		g_pd3dDevice->SetRenderState(D3DRS_FILLMODE,D3DFILL_SOLID);

	}
	if(KEYDOWN(VK_F3))
	{
		g_pd3dDevice->SetRenderState(D3DRS_FILLMODE,D3DFILL_POINT);
	}
	if(KEYDOWN(VK_F4))
	{
		g_pd3dDevice->SetRenderState(D3DRS_SHADEMODE,D3DSHADE_GOURAUD);
	}
	if(KEYDOWN(VK_F5))
	{
		g_pd3dDevice->SetRenderState(D3DRS_SHADEMODE,D3DSHADE_FLAT);
	}
	if(KEYDOWN(VK_F6))
	{
		g_pd3dDevice->SetRenderState(D3DRS_SHADEMODE,D3DSHADE_PHONG);
	}

}

void CD3DInit::SetSampler(D3DTEXTUREFILTERTYPE samplerType)
{
	g_pd3dDevice->SetSamplerState(0,D3DSAMP_MINFILTER,samplerType);
	g_pd3dDevice->SetSamplerState(0,D3DSAMP_MAGFILTER,samplerType);

	g_pd3dDevice->SetSamplerState(0,D3DSAMP_MAXANISOTROPY,16); 
}

//--D3D����Ⱦ����
void CD3DInit::Render()
{
	if(NULL == g_pd3dDevice)
		return;
	//--������̨��������Ϊ��ɫ
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, 
		                       D3DCOLOR_XRGB(0,0,0),1.0f,0);
	g_pd3dDevice->BeginScene(); //--��ʼ֪ͨ�Կ�Ҫ������Ⱦ

	//��������ģʽ
	SetItem();

	//�����������ģʽ----------------------------------------------------------------//
	//SetSampler(D3DTEXF_POINT);
	SetSampler(D3DTEXF_LINEAR);
	//SetSampler(D3DTEXF_ANISOTROPIC);
	//--------------------------------------------------------------------------------//

	SetInput();
	SetCamera();	

	//��Ⱦͼ��
	g_DrawSkyBox->Render(g_Camera.g_vPos);
	//g_DrawPlane->Render();
	g_DrawStars->Render(g_Camera.g_vPos,g_Camera.g_vViewVector);
	
	//--��ʾ֡��
	g_GameTime.GetFPS(FPSStr4);	//��ȡ֡��
    g_GameTime.GetText(FPSStr);

	//g_GameTime.GetText(FPSStr2);

	g_Camera.GetState(FPSStr2);
	g_Camera.GetSpeed(FPSStr3);
	g_Camera.GetPos(FPSStr5);
	g_Camera.GetAngle(FPSStr6);
	g_Camera.Welcome(FPSStr7);
	g_pFont->DrawMyText(clientRect,FPSStr);	//�������
	g_pFont->DrawMyText(clientRect2,FPSStr2);	//�������	
	g_pFont->DrawMyText(clientRect3,FPSStr3);	//�������	
	g_pFont->DrawMyText(clientRect4,FPSStr4);	//�������	
	g_pFont->DrawMyText(clientRect5,FPSStr5);	//�������	
	g_pFont->DrawMyText(clientRect6,FPSStr6);	//�������
	g_pFont->DrawMyText(clientRect7,FPSStr7);	//�������

	g_pd3dDevice->EndScene();  //--����ͼ�ε���Ⱦ
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);//--��ҳ



}



