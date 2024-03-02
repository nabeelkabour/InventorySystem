#ifndef INVENTORY_H
#define INVENTORY_H

#include "olcPixelGameEngine.h"
#include "Items.h"

#define INV_SCALE 0.18f
#define INV_DEFAULT_SIZE 10

class Inventory 
{
public:
	std::vector<Item> inventory;

	Inventory();
	void Draw(float x, float y);
	bool GainItem(Item item);
};

#endif