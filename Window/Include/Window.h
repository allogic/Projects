#pragma once

#include <Api.h>
#include <Pch.h>
#include <Types.h>

class WINDOW_API Window final
{
public:
	Window(HINSTANCE hInstance, UInt32 width, UInt32 height, const WChar8* pClassName, const WChar8* pWindowTitle);
	Window(const Window&&) = delete;
	Window(Window&&) = delete;
	~Window() = default;

public:
	auto& operator =(const Window&) = delete;
	auto& operator =(Window&&) = delete;

public:
	void Show(Int32 nCmdShow);

private:
	HWND mHwnd = nullptr;
};