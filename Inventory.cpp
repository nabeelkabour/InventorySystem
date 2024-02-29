#include "Inventory.h"

Inventory::Inventory()
{
	for (uint8_t i; i < INV_DEFAULT_SIZE; ++i)
	{
		inventory.push_back(ItemIndex::itemIndex[ItemId::NONE]);
	}
}