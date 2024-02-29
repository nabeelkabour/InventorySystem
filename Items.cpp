#include "Items.h"
#include "Resources.h"

Item::Item(ItemId _id, ItemType _type, std::string _name, std::string _description, olc::Decal* _sprite) :
	iid(_id),
	type(_type),
	name(_name),
	description(_description),
	sprite(_sprite)
{}


void ItemIndex::Initialize()
{
	itemIndex = {
		{
			ItemId::NONE, {
				ItemId::NONE,
				ItemType::NONE,
				"",
				"",
				Resources::get().bronze_coin.Decal()
			}
		},
		{
			ItemId::COIN_BRONZE, {
				ItemId::COIN_BRONZE,
				ItemType::COLLECTABLE,
				"Bronze Coin",
				"Worth a little",
				Resources::get().bronze_coin.Decal()
			}
		},
		{
			ItemId::GRENADE, {
				ItemId::GRENADE,
				ItemType::WEAPON,
				"Grenade",
				"Goes boom",
				Resources::get().grenade.Decal()
			}
		}
	};

	//itemIndex[ItemId::COIN_BRONZE] = Item(
	//	ItemId::COIN_BRONZE,
	//	ItemType::COLLECTABLE,
	//	"Bronze Coin",
	//	"Worth a little",
	//	Resources::get().cash_pickup.Decal()
	//);

	//itemIndex[ItemId::NONE][ItemStat::ID] = ItemId::NONE;

	//itemIndex[ItemId::NONE] = Item(ItemId::NONE, ItemType::NONE, Resources::get().enemy_basic.Decal());
	//itemIndex[ItemId::COIN_BRONZE] = Item(ItemId::COIN_BRONZE, ItemType::NONE, Resources::get().enemy_basic.Decal());
	//itemIndex[ItemId::COIN_SILVER] = Item(ItemId::NONE, ItemType::NONE, Resources::get().enemy_basic.Decal());
	//itemIndex[ItemId::COIN_GOLD] = Item(ItemId::NONE, ItemType::NONE, Resources::get().enemy_basic.Decal());
	//itemIndex[ItemId::GREEN_LEAF] = Item(ItemId::NONE, ItemType::NONE, Resources::get().enemy_basic.Decal());
	//itemIndex[ItemId::SMALL_HP] = Item(ItemId::NONE, ItemType::NONE, Resources::get().enemy_basic.Decal());
	//itemIndex[ItemId::POTION] = Item(ItemId::NONE, ItemType::NONE, Resources::get().enemy_basic.Decal());
	//itemIndex[ItemId::AMMO] = Item(ItemId::NONE, ItemType::NONE, Resources::get().enemy_basic.Decal());
	//itemIndex[ItemId::GRENADE] = Item(ItemId::NONE, ItemType::NONE, Resources::get().enemy_basic.Decal());
	//itemIndex[ItemId::SHIELD] = Item(ItemId::NONE, ItemType::NONE, Resources::get().enemy_basic.Decal());
	//itemIndex[ItemId::TOTAL] = Item(ItemId::NONE, ItemType::NONE, Resources::get().enemy_basic.Decal());
}

