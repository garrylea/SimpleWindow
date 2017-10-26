#pragma once

#include <string.h>

#include <Windows.h>
#include <WinUser.h>

class MainWindow
{
public:
	MainWindow();
	virtual ~MainWindow();
};

class MainWnd : public MainWindow {

public:
	static const wchar_t kClassName[];

	MainWnd();
	~MainWnd();

public:

	bool Create();
	bool Destroy();

protected:

	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
	static bool RegisterWindowClass();

private:
	HWND wnd_;
	static ATOM wnd_class_;
};
