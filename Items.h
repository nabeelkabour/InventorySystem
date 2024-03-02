#ifndef ITEMS_H
#define ITEMS_H

#include "olcPixelGameEngine.h"
#include "Resources.h"
#include <unordered_map>
//#include <variant> 

enum class ItemId
{
	NONE,
	COIN_BRONZE,
	COIN_SILVER,
	COIN_GOLD,
	GREEN_LEAF,
	SMALL_HP,
	POTION,
	AMMO,
	GRENADE,
	SHIELD,
	TOTAL
};

enum ItemType
{
	NONE,
	COLLECTABLE,
	CONSUMABLE,
	WEAPON,
	AMMO
};

//enum ItemStat
//{
//	NONE,
//	ID,
//	TYPE,
//	SPRITE,
//	SPRITE_SELECTED,
//	NAME,
//	DESCRIPTION,
//	STACKABLE,
//	AMOUNT,
//	AMOUNT_MAX,
//	TOTAL
//};

class Item
{
public:
	ItemId iid;
	ItemType type;
	std::string name;
	std::string description;
	olc::Decal* sprite;
	bool stackable;
	uint32_t amount;
	uint32_t amount_max;

	Item();
	Item(
		ItemId _id,
		ItemType _type,
		std::string _name,
		std::string _description,
		olc::Decal* _sprite,
		bool _stackable,
		uint32_t _amount,
		uint32_t _amount_max
	);
};

class ItemIndex
{
public:
	static std::unordered_map<ItemId, Item> itemIndex;

	static void Initialize();
};

#endif
