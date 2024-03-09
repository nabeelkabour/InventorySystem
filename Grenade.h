#ifndef GRENADE_H
#define GRENADE_H

#include "Actor.h"

class Grenade : public Actor
{ 
public:
	Grenade(olc::vf2d pos, int32_t hp, int32_t hpMax, olc::Decal* spr, std::string name = "");
	bool CollidesWith(Actor* other);
	void Collide(Player* player) override;
	void Draw(float fElapsedTime) override;
};

#endif
