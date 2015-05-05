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
	// ����D3DXFONT_DESC�ṹ�岢��ʼ��
	D3DXFONT_DESC d3dxFont;
	ZeroMemory(&d3dxFont,sizeof(d3dxFont));
	d3dxFont.Width = fontSize;  
	d3dxFont.Height = fontSize * 2; 
	d3dxFont.Weight = 1000;
	d3dxFont.Italic = false;
	d3dxFont.CharSet = GB2312_CHARSET;
	d3dxFont.PitchAndFamily = GB2312_CHARSET;
	// �����������
	if(FAILED(D3DXCreateFont(m_pd3dDevice,
							d3dxFont.Height,			//����߶�
							d3dxFont.Width,				//������
							d3dxFont.Weight,			//����Ȩ��
							0,							//MipLevel�����ܺ�MipMapһ�������ڶ༶��ʾ
							d3dxFont.Italic,			//����б��
							d3dxFont.CharSet,			//�����ַ���
							0,							//�������
							0,							//�������
							d3dxFont.PitchAndFamily,	//ѡ����ַ���������
							fontName,					//������
							&m_pFont					//�������
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