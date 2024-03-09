#ifndef ACTOR_H
#define ACTOR_H

#include "ManifestedEntity.h"
#include <cstdint>

class Player;

//Actors are anything drawn on the screen that collide with each other.
class Actor : public ManifestedEntity
{
public:
	std::string name = "";
	int32_t hp;
	int32_t hpMax;
	bool collidable = true;

	Actor(olc::vf2d pos, int32_t hp, int32_t hpMax, olc::Decal* spr, std::string name = "");
	//bool CollidesWith(Actor* other, float scaleSelf = 1.f, float scaleOther = 1.f);
	virtual bool CollidesWith(Actor* other);
	virtual void Collide(Player* player) = 0;
	virtual void Draw(float fElapsedTime) = 0;
};

#endif