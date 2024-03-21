#ifndef ITEMS_H
#define ITEMS_H

#include "olcPixelGameEngine.h"
#include "Resources.h"
#include <unordered_map>
#include <functional>

class Player;

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
	AMMOSILVER,
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

class Item
{
public:
	ItemId iid = ItemId::NONE;
	ItemType type;
	std::string name;
	std::string description;
	olc::Decal* sprite;
	bool stackable;
	uint32_t amount;
	uint32_t amount_max;
	std::function<bool(Player*, Player*)> use;

	Item();
	Item(
		ItemId _id,
		ItemType _type,
		std::string _name,
		std::string _description,
		olc::Decal* _sprite,
		bool _stackable,
		uint32_t _amount,
		uint32_t _amount_max,
		std::function<bool(Player*, Player*)> _use
	);
};

class ItemIndex
{
public:
	static std::unordered_map<ItemId, Item> itemIndex;

	static void Initialize();
};


#endif
