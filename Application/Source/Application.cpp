#include <Application.h>

Application::Application(HINSTANCE hInstance, UInt32 width, UInt32 height)
{
	WNDCLASS wc = {};
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = pClassId;

	RegisterClass(&wc);

	mHwnd = CreateWindowEx(
		0,
		pClassId,
		pWindowTitle,
		WS_OVERLAPPEDWINDOW,
		CW_DEFAULT,
		CW_DEFAULT,
		width,
		height,
		nullptr,
		nullptr,
		hInstance,
		nullptr
	);
}

Int32 Application::Run(Int32 nCmdShow)
{
	if (mHwnd)
	{
		ShowWindow(mHwnd, nCmdShow);

		MSG msg = {};

		while (msg.message != WM_QUIT)
		{
			if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
	}

	return 0;
}

APPLICATION_API LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);

		return 0;
	case WM_CREATE:


		return 0;
	case WM_KEYDOWN:
		return 0;
	case WM_KEYUP:
		return 0;
	case WM_PAINT:
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);



		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

		EndPaint(hwnd, &ps);
		return 0;
	}

	return 0;
}