#ifndef POWERUPPICKUP_H
#define POWERUPPICKUP_H

#include "Pickup.h"
#include "Buff.h"

enum class Powerup
{
	SPEED,
	SWAP,
	DAMAGE,
	TOTAL
};

struct PowerupPickupData
{
	olc::Decal* spr;
	BuffEffect apply, remove;
};

class PowerupPickup : public Pickup
{
public:
	BuffEffect apply, remove;

	PowerupPickup(olc::vf2d pos, olc::Decal* _spr, BuffEffect apply, BuffEffect remove);
	void Draw(float fElapsedTime) override;
	void Collide(Player* player);
	void Effect(Player* player) override;
};


#endif