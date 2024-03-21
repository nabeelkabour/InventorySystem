#ifndef INVENTORY_H
#define INVENTORY_H

#include "olcPixelGameEngine.h"
#include "Items.h"

#define INV_SCALE 0.15f
#define INV_TEXT_SCALE 7.5f
#define INV_DEFAULT_SIZE 3

class Inventory 
{
public:
	std::vector<Item> inventory;
	uint8_t size = INV_DEFAULT_SIZE;
	int8_t selected = 0;
	olc::Pixel borderColor = olc::RED;

	Inventory();
	void Draw(float x, float y);
	bool GainItem(Item item);
	bool DropItem(uint8_t slotNum);
	void MoveSelectLeft();
	void MoveSelectRight();
	bool selectItem();
};

#endif