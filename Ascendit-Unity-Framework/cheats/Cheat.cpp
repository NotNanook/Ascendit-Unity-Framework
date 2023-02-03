#include "Cheat.h"

void Cheat::checkForKey() {
	for (int key: keys) {
		if (GetAsyncKeyState(key) & 1) {
			isEnabled = !isEnabled;
			isToggled = !isToggled;

			if (isEnabled) {
				onEnable();
			} else {
				onDisable();
			}
		}

		if (isEnabled) {
			onUpdate();
		}
	}
}

void Cheat::checkForToggle() {
	if (isToggled && !isEnabled) {
		onEnable();
		isEnabled = true;
	} else if (!isToggled && isEnabled) {
		onDisable();
		isEnabled = false;
	}
}

void Cheat::addKey(int key) {
	if (!std::count(keys.begin(), keys.end(), key)) {
		keys.push_back(key);
		return;
	}
}