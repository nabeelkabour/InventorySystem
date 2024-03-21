#ifndef PICKUP_H
#define PICKUP_H

#include "Player.h"

class Pickup : public Actor
{
public:
	float life = 0.f;
	float lifeTime = 5.f;
	bool hovered = false;
	float alpha = 255.f;

	Pickup(olc::vf2d pos);
	virtual void Update(float fElapsedTime) override;
	virtual void Effect(Player* player) = 0;
};

class ItemPickup : public Pickup
{
public:
	Item item;

	ItemPickup(olc::vf2d pos, Item item);
	void Draw(float fElapsedTime);
	void Collide(Player* player);
	void Effect(Player* player);
};

class PowerupPickup : public Pickup
{
public:
	PowerupPickup(olc::vf2d pos);
	//void Effect(Player* player) override;
};

//class HealthPickup : public Pickup
//{
//public:
//	HealthPickup(olc::vf2d pos);
//	void Effect(Player* player) override;
//	bool CollidesWith(Actor* other) override;
//	void Collide(Player* player) override;
//	void Draw(float fElapsedTime) override;
//};

#endif