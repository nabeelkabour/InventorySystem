#include "Pickup.h"

Pickup::Pickup(float _x, float _y, float _lifeTime) :
	x(_x),
	y(_y),
	lifeTime(_lifeTime)
{}

HealthPickup::HealthPickup(float _x, float _y, float _lifeTime) : Pickup(_x, _y, _lifeTime)
{}

void HealthPickup::Effect(Player* player)
{
	player->hp += 75;
}