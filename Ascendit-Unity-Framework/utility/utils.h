#pragma once
#include <iostream>
#include <Windows.h>
#include <cassert>

typedef const char* cstring;

namespace utils {

	void waitBaseModuleLoaded();

	inline uint64_t* MethodsTable;
	bool CreateHook(uint16_t Index, void** Original, void* Function);
	void DisableHook(uint16_t Index);
	void RemoveAllHooks();
	void DestroyImGui();
}

