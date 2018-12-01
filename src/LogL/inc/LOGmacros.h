#pragma once

// Namespaces
#define _LOG_START namespace Log {
#define _LOG_END   }

#define _LOG	   ::Log::


// Defines
#ifdef _PLATFORM_WINDOWS 
	#ifdef _BUILD_DLL
		#define LOG_API __declspec(dllexport)
	#else
		#define LOG_API __declspec(dllimport)
	#endif
#else 
	#error WINDOWS ONLY SUPPORT
#endif 