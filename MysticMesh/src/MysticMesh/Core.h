#pragma once

#ifdef MM_PLATFORM_WINDOWS
	#ifdef MM_BUILD_DLL
		#define MYSTICMESH_API __declspec(dllexport)
	#else
		#define MYSTICMESH_API __declspec(dllimport)
	#endif
#else
	#error MysticMesh only supports Windows!
#endif

#define BIT(x) (1 << x)