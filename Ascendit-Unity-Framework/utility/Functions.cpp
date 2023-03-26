#include "Functions.h"
#include <Windows.h>
#include <iostream>

void Functions::init() {

	gameAssemblyBase = (uintptr_t)GetModuleHandle("GameAssembly.dll");

	getLockState = (_get_lockState)(gameAssemblyBase + 0x1264B70);
	setLockState = (_set_lockState)(gameAssemblyBase + 0x1264BC0);
	getClientPlayer = (_getClientPlayer)(gameAssemblyBase + 0x3DC870);
	getAlivePlayers = (_getAlivePlayers)(gameAssemblyBase + 0x52D400);
	getTransform = (_getTransform)(gameAssemblyBase + 0x434CB0);
}