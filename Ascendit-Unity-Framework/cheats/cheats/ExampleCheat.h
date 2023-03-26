#include "Cheat.h"

class ExampleCheat : public Cheat {
public:
	ExampleCheat() : Cheat("ExampleCheat", "Render", { VK_NUMPAD1 }) {}

	void onRenderUpdate() override;
	void onEnable() override;
};

extern ExampleCheat exampleCheat;