#pragma once

#include <Api.h>
#include <Pch.h>
#include <Types.h>

class WINDOW_API Window final
{
public:
	constexpr static const WChar8* pClassId = L"Window";
	constexpr static const WChar8* pWindowTitle = L"Engine";

public:
	Window(HINSTANCE hInstance, WNDPROC wProc, UInt32 width, UInt32 height);
	Window(const Window&&) = delete;
	Window(Window&&) = delete;
	~Window() = default;

public:
	auto& operator =(const Window&) = delete;
	auto& operator =(Window&&) = delete;

public:
	Int32 Show(Int32 nCmdShow);

private:
	HWND mHwnd = nullptr;
};