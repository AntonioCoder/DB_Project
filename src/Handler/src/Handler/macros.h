#pragma once

// Namespaces
#define _HANDLER_START namespace Handler {
#define _HANDLER_END   }

#define _HANDLER	   ::Handler::


// Defines
#ifdef _PLATFORM_WINDOWS 
	#ifdef _BUILD_DLL
		#define H_API __declspec(dllexport)
	#else
		#define H_API __declspec(dllimport)
	#endif
#else 
	#error WINDOWS ONLY SUPPORT
#endif 