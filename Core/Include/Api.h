#pragma once

#ifdef DLL_IMPORT
#define APPLICATION_IMPORT
#define RENDERER_IMPORT
#endif

#ifdef APPLICATION_IMPORT
#define APPLICATION_API __declspec(dllimport)
#else
#define APPLICATION_API __declspec(dllexport)
#endif

#ifdef RENDERER_IMPORT
#define RENDERER_API __declspec(dllimport)
#else
#define RENDERER_API __declspec(dllexport)
#endif