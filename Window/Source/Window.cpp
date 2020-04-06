#include <Window.h>

Window::Window(HINSTANCE hInstance, UInt32 width, UInt32 height, const WChar8* pClassName, const WChar8* pWindowTitle)
{
	mHwnd = CreateWindowEx(
		0,
		pClassName,
		pWindowTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		width,
		height,
		NULL,
		NULL,
		hInstance,
		NULL
	);
}

void Window::Show(Int32 nCmdShow)
{
	ShowWindow(mHwnd, nCmdShow);
}