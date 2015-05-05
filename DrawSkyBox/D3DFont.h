#include "header.h"

#pragma once

class CD3DFont
{
public:
	CD3DFont(LPDIRECT3DDEVICE9 pD3DDevice);
	virtual ~CD3DFont(void);
public:
	bool LoadFont(char *fontName, UINT fontSize);    // 加载字体
	void Clearup();                                  // 释放字体
	void DrawMyText(RECT clientRect, char *str);                                  // 释放字体

public:
	LPD3DXFONT GetFontHandle()							// 获得字体句柄
	{
		return m_pFont;
	}     
	RECT GetFontArea()									// 获得字体默认有效区域(屏幕区域)
	{
		return m_FontArea;
	}     
private:
	LPDIRECT3DDEVICE9	m_pd3dDevice;                     // 3D设备
	LPD3DXFONT			m_pFont;                          // 字体对象
	RECT				m_FontArea;                       // 字体默认有效区域
};