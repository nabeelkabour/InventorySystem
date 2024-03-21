#include "Game.h"
#include "RayCast.h"

RayCast::RayCast(olc::vf2d start, olc::vf2d end, float lifeTime, float damage) : 
	HitBox(start, 1, 1, nullptr, lifeTime, damage),
	endPoint(end)
{}

void RayCast::Update(float fElapsedTime)
{
	Actor::Update(fElapsedTime);

	life += fElapsedTime;

	if (life >= lifeTime) remove_flag = true;
}

void RayCast::Draw(float fElapsedTime)
{
	game.DrawLineDecal(position, endPoint, olc::Pixel(255, 255, 255, uint8_t(alpha)));
}