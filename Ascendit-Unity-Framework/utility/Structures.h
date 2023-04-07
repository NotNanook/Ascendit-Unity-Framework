#pragma once
#include <string>

// ----------- System structs -----------
struct Transform {};

struct Vector3 {
	float x;
	float y;
	float z;
};

template <typename T>
class Content {
public:
	char pad_0000[24];
	uint64_t sizeBuffer;
	T buffer[64];
};

template <typename T>
class List {
public:
	char pad_0000[16];
	class Content<T>* content;
};

// ----------- Game structs -----------
struct ClientPlayerInstance {};

struct Camera {};

struct HoldableItem {
	char pad_0000[48]; //0x0000
	int maxAmmo; //0x0030
	bool N0000015C; //0x0034
	char pad_0035[2]; //0x0035
	bool infiniteAmmo; //0x0037
	bool hasSharedAmmoAndDurability; //0x0038
	char pad_0039[119]; //0x0039
	int isLeftLoaded; //0x00B0
	int isRightLoaded; //0x00B4
}; //Size: 0x00B8

struct CharacterObject {
	char pad_0000[104]; //0x0000
	struct Transform* RigRootTransform; //0x0068
	char pad_0070[24]; //0x0070
	int8_t militaryRegiment; //0x0088
	char pad_0089[55]; //0x0089
	struct HoldableItem* equipedItem; //0x00C0
}; //Size: 0x00C8

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