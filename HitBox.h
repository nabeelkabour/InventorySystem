#ifndef HITBOX_H
#define HITBOX_H

#include "Actor.h"

class HitBox : public Actor
{
public:
	std::list<Player*> hitList;
	float life = 0.f;
	float lifeTime = 0.f;
	float damage = 0;

	HitBox(olc::vf2d pos, int32_t hp, int32_t hpMax, olc::Decal* spr, float lifeTime, float damage, std::string name = "");
	void Update(float fElapsedTime) override;
	void Draw(float fElapasedTime) override;
	void Collide(Player* player) override;
};

#endif
