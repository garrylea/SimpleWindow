// TestApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "main_wnd.h"


int PASCAL wWinMain(  HINSTANCE instance,
					HINSTANCE prev_instance,
					wchar_t* cmd_line, 
					int cmd_show ) 
{
	MainWnd *main_wnd = new MainWnd();
	main_wnd->Create();

	MSG msg;
	BOOL gm;
	while ((gm = ::GetMessage(&msg, NULL, 0, 0)) !=0 && gm != -1) {
		TranslateMessage(&msg); //
		DispatchMessage(&msg);
	}

	printf("program over!");
    return 0;
}

