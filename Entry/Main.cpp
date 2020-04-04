#include <Pch.h>
#include <Types.h>

#include <Application.h>
#include <Renderer.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, Int32 nCmdShow)
{
	const UInt32 width = 1280;
	const UInt32 height = 720;

	Renderer renderer(width, height);
	Application application(hInstance, width, height);

	return application.Run(nCmdShow);
}