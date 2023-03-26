#include "ExampleCheat.h"
#include "ImGui/imgui.h"
#include "Functions.h"

ExampleCheat exampleCheat;

void ExampleCheat::onRenderUpdate() {
	ImDrawList* drawList = ImGui::GetBackgroundDrawList();
	drawList->AddLine(ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y), ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2), ImColor(255, 255, 255, 255), 2.0f);
}

void ExampleCheat::onEnable() {
	std::vector<MirrorClientObject*>* playerList = Functions::getAlivePlayers(NULL, NULL);
	std::cout << playerList << std::endl;
}