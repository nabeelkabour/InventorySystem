#ifndef INVENTORY_H
#define INVENTORY_H

#include "olcPixelGameEngine.h"
#include "Items.h"

#define INV_DEFAULT_SIZE 10

class Inventory 
{
public:
	std::vector<Item> inventory;

	Inventory();
};

#endif