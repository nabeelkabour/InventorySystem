#ifndef PICKUP_H
#define PICKUP_H

#include "Player.h"

class Pickup 
{
public:
	float x, y;
	float lifeTime = 7.f;
	float removeFlag = false;

	Pickup(float _x, float _y, float _lifeTime = 7.f);
	virtual void Effect(Player* player) = 0;
};

class HealthPickup : Pickup
{
public:
	HealthPickup(float _x, float _y, float _lifeTime = 7.f);
	void Effect(Player* player) override;
};

#endif