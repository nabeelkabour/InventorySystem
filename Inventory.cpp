#include "Game.h"
#include "Inventory.h"

Inventory::Inventory()
{
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

		olc::Pixel squareColor = olc::DARK_GREY;
		if (i == selected)
		{
			squareColor = borderColor;

			game.DrawStringDecal({ x, y + 256.f * INV_SCALE + 2.5f }, inventory[i].name + "\n" + inventory[i].description);
		}

		game.DrawDecal(
			{ x + offsetX, y },
			Resources::get().slot.Decal(),
			{ INV_SCALE, INV_SCALE },
			squareColor
		);

		game.DrawDecal({ x + offsetX, y }, inventory[i].sprite, { INV_SCALE, INV_SCALE });

		if (inventory[i].stackable) 
		{
			game.DrawStringDecal(
				{ x + offsetX + 25 * INV_SCALE, y + 256.f * INV_SCALE - 256.f * INV_SCALE / 3.f },
				std::to_string(inventory[i].amount),
				olc::WHITE,
				{ INV_TEXT_SCALE * INV_SCALE, INV_TEXT_SCALE * INV_SCALE });
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

void Inventory::MoveSelectLeft()
{
	--selected;

	if (selected < 0) selected = size - 1;
}

void Inventory::MoveSelectRight()
{
	++selected;

	if (selected > (size - 1)) selected = 0;
}

bool Inventory::selectItem()
{
	borderColor = olc::GREEN;
	//switch (inventory[selected].type) 
	//{
	//	ItemType::AMMO:

	//}
	return true;
}