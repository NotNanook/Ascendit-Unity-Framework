#include "CheatManager.h"

void CheatManager::init() {
	for (Cheat* cheat: cheats) {
		cheat->init();
	}
}

void CheatManager::onUpdate() {
	for (Cheat* cheat: cheats) {
		cheat->checkForKey();
		cheat->checkForToggle();
	}
}

std::vector<Cheat*> CheatManager::cheatsByCategory(cstring category) {
	std::vector<Cheat*> ret;

	for (Cheat* cheat: cheats) {
		if (cheat->category == category) {
			ret.push_back(cheat);
		}
	}

	return ret;
}