#include "header.h"

#pragma once

class CD3DFont
{
public:
	CD3DFont(LPDIRECT3DDEVICE9 pD3DDevice);
	virtual ~CD3DFont(void);
public:
	bool LoadFont(char *fontName, UINT fontSize);    // ��������
	void Clearup();                                  // �ͷ�����
	void DrawMyText(RECT clientRect, char *str);                                  // �ͷ�����

public:
	LPD3DXFONT GetFontHandle()							// ���������
	{
		return m_pFont;
	}     
	RECT GetFontArea()									// �������Ĭ����Ч����(��Ļ����)
	{
		return m_FontArea;
	}     
private:
	LPDIRECT3DDEVICE9	m_pd3dDevice;                     // 3D�豸
	LPD3DXFONT			m_pFont;                          // �������
	RECT				m_FontArea;                       // ����Ĭ����Ч����
};