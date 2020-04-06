#include <Pch.h>
#include <Types.h>

#include <Renderer.h>
#include <Window.h>

constexpr const WChar8* pClassName = L"Projects";

constexpr const UInt32 width = 1280;
constexpr const UInt32 height = 720;

WNDCLASSEX wcex = {};
MSG msg = {};

Renderer* pRenderer = nullptr;
Window* pWindow = nullptr;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

_Use_decl_annotations_
Int32 CALLBACK wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, Int32 nCmdShow)
{
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WindowProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = pClassName;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

	RegisterClassEx(&wcex);

	pRenderer = new Renderer(width, height);
	pWindow = new Window(wcex.hInstance, width, height, pClassName, L"Engine");

	pWindow->Show(nCmdShow);

	while (msg.message != WM_QUIT)
	{
		if (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessageW(&msg);
		}
	}

	delete pWindow;
	delete pRenderer;

	return 0;
}

LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);

		break;
	case WM_CREATE:
		break;
	case WM_KEYDOWN:
		break;
	case WM_KEYUP:
		break;
	case WM_PAINT:
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

	return 0;
}