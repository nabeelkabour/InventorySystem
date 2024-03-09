#include "Items.h"
#include "Resources.h"

Item::Item() :
	iid(ItemId::NONE),
	type(ItemType::NONE),
	name(""),
	description(""),
	sprite(Resources::get().bronze_coin.Decal()),
	stackable(false),
	amount(0),
	amount_max(0),
	use([&](Player* player) {return false; })
{}

Item::Item(ItemId _id, ItemType _type, std::string _name, std::string _description, olc::Decal* _sprite, bool _stackable,
	uint32_t _amount, uint32_t _amount_max, std::function<bool(Player*)> _use) :
	iid(_id),
	type(_type),
	name(_name),
	description(_description),
	sprite(_sprite),
	stackable(_stackable),
	amount(_amount),
	amount_max(_amount_max),
	use(_use)
{}

std::unordered_map<ItemId, Item> ItemIndex::itemIndex;

void ItemIndex::Initialize()
{
	itemIndex = {
		{
			ItemId::NONE, {
				ItemId::NONE,
				ItemType::NONE,
				"",
				"",
				Resources::get().empty_slot.Decal(),
				false,
				0,
				0,
				[&](Player* player) {return false; }
			}
		},
		{
			ItemId::COIN_BRONZE, {
				ItemId::COIN_BRONZE,
				ItemType::COLLECTABLE,
				"Bronze Coin",
				"Worth a little",
				Resources::get().bronze_coin.Decal(),
				true,
				1,
				25,
				[&](Player* player) {return false; }
			}
		},
		{
			ItemId::GRENADE, {
				ItemId::GRENADE,
				ItemType::WEAPON,
				"Grenade",
				"Goes boom",
				Resources::get().grenade.Decal(),
				true,
				1,
				5,
				[&](Player* player) 
				{
					
					return true; 
				}
			}
		}
	};
}

