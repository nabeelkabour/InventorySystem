#ifndef GRENADE_H
#define GRENADE_H

#include "Actor.h"

constexpr float grenadeDamage = 30.f;

class Grenade : public Actor
{ 
public:

	olc::vf2d velocity;
	float fuseTimer = 3.f;
	float fuseTime = 0.f;
	std::list<Player*> hitList;

	Grenade(
		olc::vf2d pos,
		olc::vf2d velocity,
		int32_t hp = 1, 
		int32_t hpMax = 1,
		std::string name = ""
	);

	//bool CollidesWith(Actor* other) override;
	void Collide(Player* player) override;
	void Update(float fElapsedTime) override;
	void Draw(float fElapsedTime) override;
};

#endif
