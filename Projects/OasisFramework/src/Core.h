#pragma once

#define OASIS_INTERFACE class
#define OA_ENABLE_ASSERT 0

#ifdef OASIS_PLATFORM_WINDOWS	
	#ifdef OASIS_BUILD_DLL
		#define OAPI __declspec(dllexport)
	#else
		#define OAPI __declspec(dllimport)
	#endif
#else
	#error Only Windows Supported!
#endif

#if (OA_ENABLE_ASSERT)
	#define OA_CORE_ASSERT(X, ...) { if(!X) { OA_CORE_ERROR("Assertion Failed : {0}", __VA_ARGS__); __debugbreak(); }  }
	#define OA_CLIENT_ASSERT(X, ...) { if(!X) { OA_CLIENT_ERROR("Assertion Failed : {0}", __VA_ARGS__); __debugbreak(); }  }
#else
	#define OA_CORE_ASSERT(X, ...)
	#define OA_CLIENT_ASSERT(X, ...)
#endif

