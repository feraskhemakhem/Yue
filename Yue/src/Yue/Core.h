#pragma once
// if running on windows and a dll (engine), export, otherwise import (application)
#ifdef YUE_PLATFORM_WINDOWS
	#ifdef YUE_BUILD_DLL
		#define YUE_API __declspec(dllexport)
	#else
		#define YUE_API __declspec(dllimport)
	#endif
#else
	#error Yue only supports Windows
#endif