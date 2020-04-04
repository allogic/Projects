#pragma once

#include <Api.h>
#include <Pch.h>
#include <Types.h>

APPLICATION_API LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class APPLICATION_API Application final
{
public:
	constexpr static const WChar8* pClassId = L"Application";
	constexpr static const WChar8* pWindowTitle = L"Engine";

public:
	Application(HINSTANCE hInstance, UInt32 width, UInt32 height);
	Application(const Application&&) = delete;
	Application(Application&&) = delete;
	~Application() = default;

public:
	auto& operator =(const Application&) = delete;
	auto& operator =(Application&&) = delete;

public:
	Int32 Run(Int32 nCmdShow);

private:
	HWND mHwnd = nullptr;
};