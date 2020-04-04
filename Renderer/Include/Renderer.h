#pragma once

#include <Api.h>
#include <Types.h>

class RENDERER_API Renderer final
{
public:
	Renderer(UInt32 width, UInt32 height);
	Renderer(const Renderer&) = delete;
	Renderer(Renderer&&) = delete;
	~Renderer() = default;

public:
	auto& operator =(const Renderer&) = delete;
	auto& operator =(Renderer&&) = delete;


};