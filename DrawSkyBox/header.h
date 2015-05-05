#pragma once

#include <windows.h>
#include <stdio.h>

//--D3D用的头文件
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>
#include <d3dx9core.h>

//--D3D用的lib库
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "winmm.lib")

#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"dinput8.lib")

template<class COM> 
void Release(COM t)
{
	if( t )
	{
		t->Release();
		t = NULL;
	}
}

template<class POINT> 
void Delete(POINT t)
{
	if( t )
	{
		delete t;
		t = NULL;
	}
}

#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEYUP(vk_code)   ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)

typedef struct MouseState
{
	bool   left;   //左键是否按下
	bool   right;  //右键是否按下
	POINT  pos;    //鼠标当前的位置
}MSTATE, *PMSTATE;
//---------------------------------------------------------------------------

#define  DINPUT_BUFFERSIZE 16

struct CUSTOMVERTEX1
{
	FLOAT  x,y,z;
	DWORD  color;
	FLOAT  tu,tv;
};

#define D3DFVF_CUSTOMVETEX1 (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1)


struct VERTEX
{
	D3DXVECTOR3		position;
	D3DXVECTOR3		normalize ;
	DWORD        color;
	FLOAT        tu,tv;
};

#define D3DFVF_VERTEX (D3DFVF_XYZ |D3DFVF_NORMAL|D3DFVF_TEX1| D3DFVF_DIFFUSE)

struct LIGHTVERTEX
{
	D3DXVECTOR3 pos ;    // Vertex position
	D3DXVECTOR3 normal ;    // Vertex normal
	float tu ;            // Texture coordinate u
	float tv ;            // Texture coordinate v
} ;

#define D3DFVF_LIGHTVERTEX (D3DFVF_XYZ |D3DFVF_NORMAL|D3DFVF_TEX1)


//////////////////////////////////////////////////////////////////
//alpha混合
#define SPRITEBLENDMODE_NONE            0
#define SPRITEBLENDMODE_ALPHABLEND		1
#define SPRITEBLENDMODE_ADDITIVE		2