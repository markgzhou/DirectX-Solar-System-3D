#include <iostream>
#include <windows.h>

#pragma once

class CGameTime
{
public:CGameTime();
	  virtual ~CGameTime();
	  int texti;
private:
	int g_fps;             // FPS帧率值
	float g_time;       // 系统运行时间
	float g_lastTime;   // 持续的时间
	float g_time2;       // 系统运行时间
	float g_lastTime2;   // 持续的时间
	
public:
	void GetFPS(char* FPSStr);

	void GetText(char* FPSStr);

};