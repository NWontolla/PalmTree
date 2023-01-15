#pragma once

#ifdef PT_PLATFORM_WINDOWS
	#ifdef PT_BUILD_DLL
		#define PALMTREE_API __declspec(dllexport)
	#else
		#define PALMTREE_API __declspec(dllimport)
	#endif
#else
	#error PalmTree only supports windows
#endif