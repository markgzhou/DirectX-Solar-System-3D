
#pragma once

#include "header.h"
#include "GameInput.h"

class CCamera  
{
public:
	D3DXVECTOR3  g_vPos;
	D3DXVECTOR3  g_vViewAt;
	D3DXVECTOR3  g_vUp;

	D3DXVECTOR3			g_vScafeVector;

	D3DXVECTOR3			g_vViewVector;

	float				g_fRotateY;
	float				g_fDeltaY;

	float				cameraSpeed;

	float				g_vAngle;
	float				g_mouseAngle;

	float				aspect;
	float				g_time;       
	float				g_lastTime;   
	int					textcounter;
	int                 maxcounter;
	char				FPSStr2[50];

public:
	CCamera();
	virtual ~CCamera();
    void	ProcInput(CGameInput* m_Input);
	void	RotateCamera(float AngleX, float AngleY, float AngleZ);
	void	MoveCamera(float fSpeed);
	void	StrafeCamera (float fSpeed);
	void    SetPosCamera (float PosX, float PosY, float PosZ);
	void    GetPos (char* FPSStr);
	void    GetSpeed (char* FPSStr);
	void    GetAngle (char* FPSStr);
	void    Welcome (char* FPSStr);
	void    GetState (char* FPSStr);
	float   automode;
	int		musicmode;
	void    Music();
};
