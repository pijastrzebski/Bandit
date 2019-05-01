#pragma once

#ifdef BANDIT_PLATFORM_WIN
	#ifdef BANDIT_BUILD_DLL
		#define BANDIT_API __declspec(dllexport)
	#else
		#define BANDIT_API __declspec(dllimport)
	#endif
#else
	#error Windows supported only!
#endif
