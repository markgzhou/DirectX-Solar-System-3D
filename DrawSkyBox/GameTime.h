#include <iostream>
#include <windows.h>

#pragma once

class CGameTime
{
public:CGameTime();
	  virtual ~CGameTime();
	  int texti;
private:
	int g_fps;             // FPS֡��ֵ
	float g_time;       // ϵͳ����ʱ��
	float g_lastTime;   // ������ʱ��
	float g_time2;       // ϵͳ����ʱ��
	float g_lastTime2;   // ������ʱ��
	
public:
	void GetFPS(char* FPSStr);

	void GetText(char* FPSStr);

};