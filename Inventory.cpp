#include "Game.h"
#include "Inventory.h"

Inventory::Inventory()
{
	Resources::get();
	ItemIndex::Initialize();

	for (uint8_t i = 0; i < INV_DEFAULT_SIZE; ++i)
	{
		inventory.push_back(ItemIndex::itemIndex[ItemId::NONE]);
	}
}

void Inventory::Draw(float x, float y)
{
	for (uint8_t i = 0; i < inventory.size(); ++i) //(Item i : inv.inventory)
	{
		float offsetX = i * 256.f * INV_SCALE;

		//game.DrawRectDecal({ x + offsetX, y }, { 256 * INV_SCALE, 256 * INV_SCALE }, olc::DARK_GREY);
		game.DrawDecal({ x + offsetX, y }, Resources::get().slot.Decal(), { INV_SCALE, INV_SCALE }, olc::DARK_GREY);

		game.DrawDecal({ x + offsetX, y }, inventory[i].sprite, { INV_SCALE, INV_SCALE });

		if (inventory[i].stackable) 
		{
			game.DrawStringDecal(
				{ x + offsetX + 25 * INV_SCALE, y + 256.f * INV_SCALE - 25 * INV_SCALE },
				std::to_string(inventory[i].amount),
				olc::WHITE,
				{ 10.f * INV_SCALE, 10.f * INV_SCALE });
		}
	}
}

bool Inventory::GainItem(Item item)
{
	bool isStackable = item.stackable;

	if (!isStackable)
	{
		for (Item& i : inventory)
		{
			if (i.iid != ItemId::NONE) continue;

			i = item;
			return true;
		}
	}
	else 
	{
		for (Item& i : inventory)
		{
			if (i.iid != item.iid or i.amount >= i.amount_max) continue;

			if (i.amount < i.amount_max)
			{
				i.amount += item.amount;

				if (i.amount > i.amount_max)
				{
					uint32_t difference = i.amount - i.amount_max;

					for (uint32_t j = 0; j < difference; ++j)
					{
						GainItem(i);
					}

					i.amount = i.amount_max;
				}

				return true;
			}
			else
			{
				return false;
			}
		}

		for (Item& i : inventory)
		{
			if (i.iid != ItemId::NONE) continue;

			i = item;
			return true;
		}
	}

	return false;
}