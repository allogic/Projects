#include <Window.h>

Window::Window(HINSTANCE hInstance, WNDPROC wProc, UInt32 width, UInt32 height)
{
	WNDCLASS wc = {};
	wc.lpfnWndProc = wProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = pClassId;

	RegisterClass(&wc);

	return;

	mHwnd = CreateWindowEx(
		0,
		pClassId,
		pWindowTitle,
		WS_OVERLAPPEDWINDOW,
		CW_DEFAULT,
		CW_DEFAULT,
		width,
		height,
		NULL,
		NULL,
		hInstance,
		NULL
	);
}

Int32 Window::Show(Int32 nCmdShow)
{
	if (mHwnd)
	{
		ShowWindow(mHwnd, nCmdShow);
	}

	MSG msg = {};

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return 0;
}