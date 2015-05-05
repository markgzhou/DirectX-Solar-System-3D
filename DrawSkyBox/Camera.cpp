// Camera.cpp: implementation of the CCamera class.
//
//////////////////////////////////////////////////////////////////////

#include "Camera.h"


#include <WINDOWS.H>
#include <mmsystem.h>
#pragma comment(lib, "Winmm.lib")
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCamera::CCamera()
{
	D3DXVECTOR3  m_vPos(20.0, 15.0, -15.0);
	D3DXVECTOR3  m_vViewAt(0.0, 50.0, 0.0);
	D3DXVECTOR3  m_vUp(0.0, 1.0, 0.0);
	musicmode=0;
	g_vPos      =  m_vPos;
	g_vViewAt   =  m_vViewAt;
	g_vUp       =  m_vUp;
	g_vAngle    =  0;
	cameraSpeed =  0.10f;
	g_time =0.0f;
	g_lastTime=0.0f;
	textcounter=0;
	automode=0.01;
	aspect=1.0f*GetSystemMetrics(SM_CXSCREEN)/GetSystemMetrics(SM_CYSCREEN);//ÉèÖÃÆÁÄ»×Ýºá±È
	maxcounter=100000;
	sprintf(FPSStr2, "Buckle Up! Fly Safe!");
	musicmode=0;
}

CCamera::~CCamera()
{
}
void CCamera::ProcInput(CGameInput* m_Input)
{
	sprintf(FPSStr2, "Buckle Up! Fly Safe!");
	g_vViewVector = g_vViewAt - g_vPos;

	g_fRotateY  = m_Input->m_CurMState.pos.x - m_Input->m_OldMState.pos.x;
	g_fDeltaY   = m_Input->m_CurMState.pos.y - m_Input->m_OldMState.pos.y;
	
	g_vViewAt.y -= g_fDeltaY/50;

	//look up and down
	if(( g_vViewAt.y - g_vPos.y) >  90) 
		g_vViewAt.y  = g_vPos.y + 90;
	if(( g_vViewAt.y - g_vPos.y) < -90) 
		g_vViewAt.y  = g_vPos.y - 90;

	RotateCamera(0,-g_fRotateY/150,0);


	if(KEYDOWN(VK_SHIFT))
	{
		cameraSpeed = 0.1f;
		sprintf(FPSStr2, "Fast Speed Fly! Be Careful!");
	}else
	{
		cameraSpeed = 0.01f;
	}

	//if(KEYDOWN('='))
	//{
	//	cameraSpeed=cameraSpeed+0.01;
	//}


	if(KEYDOWN(VK_DOWN)||KEYDOWN('S'))
	{
		MoveCamera(-cameraSpeed);
			sprintf(FPSStr2, "Backwards....Beep.Beep...");
	}
	if(KEYDOWN(VK_UP)||KEYDOWN('W'))
	{
		MoveCamera(cameraSpeed);
// 		g_vPos.x  = g_vPos.x + sinf(g_vAngle)/20;
// 		g_vPos.z  = g_vPos.z + cosf(g_vAngle)/20;
// 
// 		moveL += sinf(g_vAngle)/20;
// 		g_vViewAt.x = g_vViewAt.x + sinf(g_vAngle)/20;
//         g_vViewAt.z = g_vViewAt.z + cosf(g_vAngle)/20;
		sprintf(FPSStr2, "Go...go...go...");
	}
	if(KEYDOWN(VK_RIGHT)||KEYDOWN('D'))
	{
		StrafeCamera(cameraSpeed);
// 		g_vAngle += 0.01f;
// 		g_vViewAt.x = g_vPos.x + sinf(g_vAngle); 
// 		g_vViewAt.z = g_vPos.z + cosf(g_vAngle);
		sprintf(FPSStr2, "Right translation");
	}
	if(KEYDOWN(VK_LEFT)||KEYDOWN('A'))
	{
		StrafeCamera(-cameraSpeed);
// 		g_vAngle -= 0.01f;
// 		g_vViewAt.x = g_vPos.x  + sinf(g_vAngle); 
// 		g_vViewAt.z = g_vPos. z + cosf(g_vAngle);
		sprintf(FPSStr2, "Left translation");
	}

	g_fRotateY  = 0;
	g_fDeltaY   = 0;
    
	if((g_vPos.x*g_vPos.x+g_vPos.y*g_vPos.y+g_vPos.z*g_vPos.z)<=20){
	
		
		sprintf(FPSStr2, "WoooooooooooW, collision detected!!!!!!!");

		if(KEYDOWN(VK_DOWN)||KEYDOWN('S')){
		MoveCamera(cameraSpeed);
		}
		else if(KEYDOWN(VK_UP)||KEYDOWN('W')){
		MoveCamera(-cameraSpeed);
		}
		else if(KEYDOWN(VK_RIGHT)||KEYDOWN('D')){
		StrafeCamera(-cameraSpeed);
		}
		else if(KEYDOWN(VK_LEFT)||KEYDOWN('A')){
			StrafeCamera(cameraSpeed);
		}
		else{
			MoveCamera(-cameraSpeed);
		}


	}




	if(KEYDOWN('M')){


	float totalr;
	float angle;
	totalr=g_vPos.x*g_vPos.x+g_vPos.z*g_vPos.z;
	totalr=sqrt(totalr);
	angle=asin(g_vPos.z/totalr);
	if(g_vPos.x<=0){
	automode=-automode;
	}
	angle=angle-automode;
	g_vPos.z=totalr*sin(angle);
	g_vPos.x=totalr*cos(angle);

	sprintf(FPSStr2, "Auto Fly Mode. Oh yeah~");

	}








	return ;

}



void CCamera::GetPos(char* FPSStr)
{
	sprintf(FPSStr, "Position:%.2f,%.2f,%.2f", g_vPos.x,g_vPos.y,g_vPos.z);
}


void CCamera::GetAngle(char* FPSStr)
{
	sprintf(FPSStr, "Angle:%.2f,%.2f,%.2f", g_vViewAt.x,g_vViewAt.y,g_vViewAt.z);
}


void CCamera::GetSpeed(char* FPSStr)
{
	if(cameraSpeed<=0.1)
		sprintf(FPSStr, "Speed:Slow");
	else
		sprintf(FPSStr, "Speed:FAST!");
}


void CCamera::Welcome(char* FPSStr)
{
	g_time = GetTickCount();

	if(textcounter<=maxcounter){
	if(g_time - g_lastTime > 50)
	{
		g_lastTime = g_time;

		if(textcounter<=140){
		sprintf(FPSStr, "Welcome! Introducing the most fabulous space!,%d",textcounter);
		}
		else if (textcounter<=200){
		sprintf(FPSStr, "You didn't see anything?");
		}
		else if (textcounter<=280){
		sprintf(FPSStr, " OK, let's face to the right direction");
		}
		else{
		sprintf(FPSStr, " ");
		
		if(g_vViewAt.y>0){
		g_vViewAt.y=g_vViewAt.y-0.5;
		}else{
		maxcounter=-1;
		}

		}
	}
	textcounter++;
	}else{
	sprintf(FPSStr, " ");}
	
}




void CCamera::RotateCamera(float AngleX, float AngleY, float AngleZ)
{
	if(AngleX) 
	{
		g_vViewAt.z = (float)(g_vPos.z + sin(AngleX) * g_vViewVector.y + cos(AngleX) * g_vViewVector.z);
		g_vViewAt.y = (float)(g_vPos.y + cos(AngleX) * g_vViewVector.y - sin(AngleX) * g_vViewVector.z);
	}
	if(AngleY) 
	{
		g_vViewAt.z = (float)(g_vPos.z + sin(AngleY) * g_vViewVector.x + cos(AngleY) * g_vViewVector.z);
		g_vViewAt.x = (float)(g_vPos.x + cos(AngleY) * g_vViewVector.x - sin(AngleY) * g_vViewVector.z);
	}
	if(AngleZ) 
	{
		g_vViewAt.x = (float)(g_vPos.x + sin(AngleZ) * g_vViewVector.y + cos(AngleZ) * g_vViewVector.x);		
		g_vViewAt.y = (float)(g_vPos.y + cos(AngleZ) * g_vViewVector.y - sin(AngleZ) * g_vViewVector.x);
	}
}






void CCamera::MoveCamera(float fSpeed)
{	
	g_vPos.x += g_vViewVector.x * fSpeed;
	g_vPos.z += g_vViewVector.z * fSpeed;

	g_vPos.y += g_vViewVector.y * fSpeed;

	g_vViewAt.x   += g_vViewVector.x * fSpeed;
	g_vViewAt.z   += g_vViewVector.z * fSpeed;

	g_vViewAt.y   += g_vViewVector.y * fSpeed;

}

void CCamera::StrafeCamera(float fSpeed)
{
	D3DXVec3Cross(&g_vScafeVector,&g_vUp,&g_vViewVector);

	g_vPos.x  += g_vScafeVector.x * fSpeed;
	g_vPos.z  += g_vScafeVector.z * fSpeed;

	g_vViewAt.x    += g_vScafeVector.x * fSpeed;
	g_vViewAt.z    += g_vScafeVector.z * fSpeed;
}

void CCamera::SetPosCamera(float PosX, float PosY, float PosZ)
{	
	g_vPos.x=PosX;
	g_vPos.y=PosY;
	g_vPos.z=PosZ;

	//g_vPos.x=0;
	//g_vPos.y=0;
	//g_vPos.z=0;
}


void CCamera::GetState(char* FPSStr)
{
	float showspeed;

	sprintf(FPSStr, "%s", FPSStr2);
}


void CCamera::Music()
{
	
	if(musicmode==0){
	PlaySound("d:\\background.WAV",NULL,SND_LOOP);
	musicmode++;
	}


}

