#pragma once

// Namespaces
#define _SQLC_START namespace SQLC {
#define _SQLC_END   }

#define _SQLC	   ::SQLC::


// Defines
#ifdef _PLATFORM_WINDOWS 
	#ifdef _BUILD_DLL
		#define SQLC_API __declspec(dllexport)
	#else
		#define SQLC_API __declspec(dllimport)
	#endif
#else 
	#error WINDOWS ONLY SUPPORT
#endif 