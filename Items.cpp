#include "Game.h"
#include "Items.h"
#include "Resources.h"
#include "ManifestedEntity.h"
#include "Grenade.h"
#include "Player.h"
#include "ItemLambdas.h"

Item::Item() :
	iid(ItemId::NONE),
	type(ItemType::NONE),
	name(""),
	description(""),
	sprite(Resources::get().bronze_coin.Decal()),
	stackable(false),
	amount(0),
	amount_max(0),
	use([&](Player* playerCalling, Player* playerOther) { return false; })
{}

Item::Item(ItemId _id, ItemType _type, std::string _name, std::string _description, olc::Decal* _sprite, bool _stackable,
	uint32_t _amount, uint32_t _amount_max, std::function<bool(Player*, Player*)> _use) :
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
	itemIndex =
	{
		{
			ItemId::NONE,
			{
				ItemId::NONE,
				ItemType::NONE,
				"",
				"",
				Resources::get().empty_slot.Decal(),
				false,
				0,
				0,
				[&](Player* playerCalling, Player* playerOther) {return false; }
			}
		},
		{
			ItemId::POTION,
			{
				ItemId::POTION,
				ItemType::CONSUMABLE,
				"HP potion",
				"Heals",
				Resources::get().hpPotion.Decal(),
				false,
				1,
				1,
				lambdaHpPotion
			}
		},
		{
			ItemId::GRENADE,
			{
				ItemId::GRENADE,
				ItemType::WEAPON,
				"Grenade",
				"Goes boom",
				Resources::get().grenade.Decal(),
				true,
				1,
				3,
				lambdaGrenade
			}
		},
		{
			ItemId::AMMO,
			{
				ItemId::AMMO,
				ItemType::WEAPON,
				"Ammo",
				"shoots",
				Resources::get().ammo.Decal(),
				true,
				5,
				15,
				lambdaAmmo
			}
		},
		{
			ItemId::AMMOSILVER,
			{
				ItemId::AMMOSILVER,
				ItemType::WEAPON,
				"Silver ammo",
				"heavy impact",
				Resources::get().ammoSilver.Decal(),
				true,
				3, 
				9,
				lambdaAmmoSilver
			}
		
		},
		{
			ItemId::MISSILE,
			{
				ItemId::MISSILE,
				ItemType::WEAPON,
				"Homing missile",
				"missile",
				Resources::get().rocketBasic.Decal(),
				true,
				2,
				6,
				lambdaMissile
			}
		}
		//{
		//	ItemId::SHIELD,
		//	{
		//		ItemId::SHIELD,
		//		ItemType::WEAPON,
		//		"Shield",
		//		"heavy duty",
		//		Resources::get().base.Decal(),
		//		false,
		//		1,
		//		1,
		//		lambdaItemVoid
		//	}
		//}
	};
}


