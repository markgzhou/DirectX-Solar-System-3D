#include "D3DFont.h"


CD3DFont::CD3DFont(LPDIRECT3DDEVICE9 pD3DDevice /*, D3DPRESENT_PARAMETERS* pD3DPP*/)
{
	m_pd3dDevice = pD3DDevice;
//	m_FontArea.left = 30;
//	m_FontArea.top = 30;
//	m_FontArea.right = pD3DPP->BackBufferWidth;
//	m_FontArea.bottom = pD3DPP->BackBufferHeight;
}

CD3DFont::~CD3DFont(void)
{
}

bool CD3DFont::LoadFont(char *fontName, UINT fontSize)
{
	// 生成D3DXFONT_DESC结构体并初始化
	D3DXFONT_DESC d3dxFont;
	ZeroMemory(&d3dxFont,sizeof(d3dxFont));
	d3dxFont.Width = fontSize;  
	d3dxFont.Height = fontSize * 2; 
	d3dxFont.Weight = 1000;
	d3dxFont.Italic = false;
	d3dxFont.CharSet = GB2312_CHARSET;
	d3dxFont.PitchAndFamily = GB2312_CHARSET;
	// 创建字体对象
	if(FAILED(D3DXCreateFont(m_pd3dDevice,
							d3dxFont.Height,			//字体高度
							d3dxFont.Width,				//字体宽度
							d3dxFont.Weight,			//字体权重
							0,							//MipLevel，可能和MipMap一样，用于多级显示
							d3dxFont.Italic,			//字体斜体
							d3dxFont.CharSet,			//所属字符集
							0,							//输出精度
							0,							//输出质量
							d3dxFont.PitchAndFamily,	//选择的字符集（？）
							fontName,					//字体名
							&m_pFont					//字体对象
							))){		
		return false;    
	}
	return true;
}

void CD3DFont::DrawMyText(RECT clientRect, char *str )
{

	m_pFont->DrawTextA(NULL,str,-1,&clientRect,
		DT_SINGLELINE|DT_NOCLIP|DT_CENTER|DT_VCENTER,
		0XFFFFFFFF);
}
void CD3DFont::Clearup()
{
	Release(m_pFont);
}