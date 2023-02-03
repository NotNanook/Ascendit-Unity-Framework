#include "utils.h"
#include "MinHook/Include/MinHook.h"
#include <ImGui/imgui_impl_dx11.h>
#include <ImGui/imgui_impl_win32.h>

void utils::waitBaseModuleLoaded() {
	while (!GetModuleHandleA("GameAssembly.dll")) {
		Sleep(1000);
	}
}

bool utils::CreateHook(uint16_t Index, void** Original, void* Function) {
	assert(Index >= 0 && Original != NULL && Function != NULL);
	void* target = (void*)MethodsTable[Index];
	if (MH_CreateHook(target, Function, Original) != MH_OK || MH_EnableHook(target) != MH_OK) {
		return false;
	}
	return true;
}

void utils::DisableHook(uint16_t Index) {
	assert(Index >= 0);
	MH_DisableHook((void*)MethodsTable[Index]);
}

void utils::RemoveAllHooks() {
	MH_RemoveHook(MH_ALL_HOOKS);
	MH_Uninitialize();

	free(MethodsTable);
	MethodsTable = NULL;
}

void utils::DestroyImGui() {
	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}