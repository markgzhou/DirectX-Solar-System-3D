#include "header.h"
#include "D3DInit.h"

CD3DInit* g_D3DInit = new CD3DInit();
POINT mouseNewPos;

//--windows����Ϣ�ص�����
long FAR PASCAL WindowProc(HWND hWnd,UINT message,
						   WPARAM wParam,LPARAM lParam)
{

	
	switch(message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_KEYDOWN:                            //--������Ϣ
		switch(wParam)
		{
		case VK_ESCAPE:                         //--������ESC��ʱ�򴥷��رմ��ڵ���Ϣ
			PostMessage(hWnd, WM_CLOSE,0,0);
			break;
		}
		break;
	}
	return DefWindowProc(hWnd,message,wParam,lParam);
}

//--windows��������
int CALLBACK WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,
					 LPSTR lpCmdLine,int nCmdShow)
{
	MSG      msg;                                //--����һ����Ϣ�Ķ���
	HWND     hWnd;                               //--���ھ��
	WNDCLASS wc;                                 //--���崰����
	//--����������
	wc.style       = CS_HREDRAW | CS_VREDRAW;    //--֧��ˮƽ�ʹ�ֱ�ػ�
	wc.lpfnWndProc = WindowProc;                 //--��Ӧ����Ϣ������
	wc.cbClsExtra  = 0;                          //--�����ڴ�ռ�
	wc.cbWndExtra  = 0;                          //--�����ڴ�ռ�
	wc.hInstance   = hInstance;                  //--���ڵ�ʵ�����
	wc.hIcon       = NULL;                       //--���ڵ�Сͼ��
	wc.hCursor     = NULL;                       //--���ڵ������״
	//--������ɫ
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName  = NULL;                     //--���ڲ˵�
	wc.lpszClassName = "createwindows";          //--��������
	
	RegisterClass(&wc);                          //--ע�ᴰ�ھ��
	hWnd = CreateWindowEx(WS_EX_TOPMOST,         //--��������ʾ�ڶ���
		                  "createwindows",       //--���ڵ�����
						  "create window title", //--���ڵı���
						  WS_OVERLAPPEDWINDOW,   //--���ڵķ��
						  0,                    //--X��ĳ�ʼ���趨����
						  0,                    //--Y��ĳ�ʼ���趨����
// 						  200,                   //--�߶ȳ�ʼ��
// 						  300,                   //--��ȳ�ʼ��
						  GetSystemMetrics(SM_CXSCREEN), 
						  GetSystemMetrics(SM_CYSCREEN), 
						  NULL,                  //--�����ھ��
						  NULL,                  //--���ڲ˵��ľ�� 
						  hInstance,             //--ʵ�����
						  NULL);                 //--������Ϣ
	if(!hWnd)
	{
		return FALSE;
	}
	g_D3DInit->GameInit(hWnd,hInstance);

	ShowWindow(hWnd,nCmdShow);                   //--��ʾ����
	UpdateWindow(hWnd);                          //--���´���
	while(true)
	{
		//--����ϵͳ��Ϣ(&msgΪMSG���͵���Ϣ�ṹ��,NULL���ھ��),
		//--0,0��ʾ�������еĴ�����Ϣ)
		if(PeekMessage(&msg,NULL,0U,0U,PM_REMOVE))
		{
			if(msg.message == WM_QUIT)
				break;
			TranslateMessage(&msg);              //--ת����Ϣ
			DispatchMessage(&msg);               //--������Ϣ����Ӧ����Ϣ������windowProc��
		}
		else
		{
			g_D3DInit->Render();                 //--��ȾD3D
		}
	}

	return 1;
}