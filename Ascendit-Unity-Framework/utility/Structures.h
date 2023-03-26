#pragma once
#include <string>

// System structs
struct Transform {};

struct Vector3 {
	float x;
	float y;
	float z;
};

// Game structs
struct ClientPlayerInstance {

};

struct MirrorClientObject {
	//char pad_0000[0xD7];
	//bool isDisplayingHudInfo;
	char pad_0000[224]; //0x0000
};

enum CursorLockMode {
	None,
	Locked,
	Confined
};

enum Character
{
	Nochar,
	Mikasa,
	Eren,
	Armin,
	Jean,
	Lana,
	Levi,
	Sasha,
	Annie,
	Hange,
	Connie,
	Reiner,
	Bertolt,
	Erwin,
	Historia
};