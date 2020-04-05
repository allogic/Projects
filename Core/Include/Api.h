#pragma once

#ifdef DLL_IMPORT
#define RENDERER_IMPORT
#define WINDOW_IMPORT
#endif

#ifdef RENDERER_IMPORT
#define RENDERER_API __declspec(dllimport)
#else
#define RENDERER_API __declspec(dllexport)
#endif

#ifdef WINDOW_IMPORT
#define WINDOW_API __declspec(dllimport)
#else
#define WINDOW_API __declspec(dllexport)
#endif