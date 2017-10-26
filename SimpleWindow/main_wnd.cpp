#include "stdafx.h"
#include "main_wnd.h"

ATOM MainWnd::wnd_class_ = 0;
const wchar_t MainWnd::kClassName[] = L"Simple Window";

MainWindow::MainWindow()
{
}


MainWindow::~MainWindow()
{
}

MainWnd::MainWnd(){

}

MainWnd::~MainWnd() {

}

bool MainWnd::Create() {

	if (!RegisterWindowClass()) {
		return false;
	}

	HWND hwnd = ::CreateWindowExW(
								WS_EX_OVERLAPPEDWINDOW, 
								kClassName,
								L"Simple Window",
								WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_CLIPCHILDREN,
								CW_USEDEFAULT, //只有 WS_OVERLAPPEDWINDOW风格窗口才可以用 CW_USEDEFAULT
								CW_USEDEFAULT, 
								CW_USEDEFAULT, 
								CW_USEDEFAULT,
								NULL, 
								NULL, 
								GetModuleHandle(NULL), 
								this);
	
	wnd_ = hwnd;

	//显示窗口
	::ShowWindow(wnd_, SW_SHOW);

	return true;
}

bool MainWnd::Destroy() {
	return true;
}

LRESULT CALLBACK MainWnd::WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
	
	LRESULT result = 0;

	result = ::DefWindowProc(hwnd, msg, wp, lp);

	/*
	MainWnd* me = reinterpret_cast<MainWnd*>(
		::GetWindowLongPtr(hwnd, GWLP_USERDATA));

	if (!me && WM_CREATE == msg) {
		CREATESTRUCT* cs = reinterpret_cast<CREATESTRUCT*>(lp);
		me->wnd_ = hwnd;
		::SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(me));
	}

	switch (msg) {
	case WM_CLOSE:
		::DestroyWindow(hwnd);
	default:
		printf("default....");
	}
	*/
	return result;
}

bool MainWnd::RegisterWindowClass(){

	if (wnd_class_) return true;

	WNDCLASSEX wcex = { sizeof(WNDCLASSEX) }; //初始化数据结构

	wcex.hInstance = GetModuleHandle(NULL);
	wcex.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
	wcex.hCursor = ::LoadCursor(NULL, IDC_ARROW);
	wcex.lpfnWndProc = &WndProc;
	wcex.lpszClassName = kClassName;
	wnd_class_ = ::RegisterClassEx(&wcex);

	return (wnd_class_ != 0);

}

