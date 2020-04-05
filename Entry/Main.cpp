#include <Pch.h>
#include <Types.h>

#include <Renderer.h>
#include <Window.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, Int32 nCmdShow)
{
	const UInt32 width = 1280;
	const UInt32 height = 720;

	Renderer renderer(width, height);
	Window window(hInstance, &WindowProc, width, height);

	return window.Show(nCmdShow);
}

LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);

		return 0;
	case WM_CREATE:
		return 0;
	case WM_KEYDOWN:
		std::wcout << L"down" << L'\n';
		return 0;
	case WM_KEYUP:
		std::wcout << L"up" << L'\n';
		return 0;
	case WM_PAINT:
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

		EndPaint(hwnd, &ps);
		return 0;
	}

	return DefWindowProc(hwnd, uMsg, lParam, wParam);
}