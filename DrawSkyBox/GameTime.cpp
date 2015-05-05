#include "GameTime.h"

CGameTime::CGameTime()
{
	g_fps = 0;
	g_time = 0.0f;
	g_lastTime = 0.0f;
	g_time2 = 0.0f;
	g_lastTime2 = 0.0f;
}

CGameTime::~CGameTime(void)
{
}

void CGameTime::GetFPS(char* FPSStr)
{
	// Get the second in millisecond then multiply it to convert to seconds.
	// g_time��ȡ����ϵͳ�����������������ĺ�����������0.001f�õ�����
	g_time = GetTickCount();
	// If time - last time is > than 1, save fpt.
	// ����ʱ���Ƿ����1��
	if(g_time - g_lastTime > 1000)
	{
		// Record last time.
		// ��¼�µĳ���ʱ��
		g_lastTime = g_time;
		// Save FPS.
		// ������g_fps��ʽ��Ϊһ���ַ���������g_fpsStr�У���������ַ���
		std::sprintf(FPSStr, "FPS:%d", g_fps);
		FPSStr[20]='\0';
		// Reset the FPS counter.
		// ����֡��ֵΪ0
		g_fps = 0;
	}
	else
	{
		// Add to the frames per second.
		// ֡��ֵ����
		g_fps++;
	}
}





void CGameTime::GetText(char* FPSStr)
{
	// Get the second in millisecond then multiply it to convert to seconds.
	// g_time to get current time
	g_time2 = GetTickCount();
	// If time - last time is > than 3

	if(g_time2 - g_lastTime2 > 3000)
	{
		g_lastTime2 = g_time2;
		if(texti==0){
		std::sprintf(FPSStr, "Greetings! What a beautiful universe!");
		texti=1;
		} 
		else if(texti==1){
			std::sprintf(FPSStr, "CS 4610 7610 Computer Graphics @ Mizzou 2014");
			texti=2;
		}
		else if(texti==2){
			std::sprintf(FPSStr, "Teamleader: Guanlong Zhou");
			texti=3;
		}
		else if(texti==3){
			std::sprintf(FPSStr, "Team-members: Yuxiang Chen & Xinwei Du");
			texti=4;
		}
	    else if(texti==4){
			std::sprintf(FPSStr, "Wow! Don't you think our work is AWESOME?!");
			texti=5;
		}
		else{
			std::sprintf(FPSStr, "Please vote for our team! Thank You!");
			texti=0;
		}


	}
}