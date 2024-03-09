#include "Grenade.h"

Grenade::Grenade(olc::vf2d pos, int32_t hp, int32_t hpMax, olc::Decal* spr, std::string name) :
	Actor(pos, hp, hpMax, spr, name)
{}

void Grenade::Draw(float fElapsedTime)
{

}

bool Grenade::CollidesWith(Actor* other)
{
	return false;
}

void Grenade::Collide(Player* player)
{

}