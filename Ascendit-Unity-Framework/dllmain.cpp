#include "CheatManager.h"
#include "DirectX.h"
#include "MinHook.h"
#include "Il2Cpp.h"
#include "utils.h"

DWORD WINAPI MainThread(LPVOID lpParameter) {
    utils::waitBaseModuleLoaded();

    IL2CPP::Initialize();

    MH_Initialize();
    CheatManager::init();

    DirectX::getWindowInformation();
    DirectX::hookDirectX();

    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        CreateThread(0, 0, MainThread, 0, 0, 0);
    }
    return TRUE;
}