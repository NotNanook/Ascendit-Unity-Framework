#pragma once

#include "Cheat.h"
#include "utils.h"

#include <vector>
#include <array>

namespace CheatManager {
	constexpr std::array<cstring, 3> categories { "Combat", "Render", "Misc" };
	const std::array<Cheat*, 0> cheats {
	};

	void init();
	void onUpdate();
	std::vector<Cheat*> cheatsByCategory(cstring category);
};