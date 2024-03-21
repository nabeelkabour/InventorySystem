#include "Game.h"
#include "Player.h"
#include "HitBox.h"
#include "HitSplat.h"

HitBox::HitBox(olc::vf2d pos, int32_t hp, int32_t hpMax, olc::Decal* spr, float lifeTime, float damage, std::string name) :
	Actor(
		pos,
		hp,
		hpMax,
		spr,
		name
	),
	lifeTime(lifeTime),
	damage(damage)
{}

void HitBox::Update(float fElapsedTime)
{
	Actor::Update(fElapsedTime);

	life += fElapsedTime;

	if (life >= lifeTime) remove_flag = true;
}

void HitBox::Draw(float fElapsedTime)
{
	//game.DrawRotatedDecal(position, spr, 0.f, { spr->sprite->width / 2.f, spr->sprite->height / 2.f}, {1.f, 1.f}, olc::Pixel(255, 255, 255, 50)); // { 128.f / 2.f, 128.f / 2.f }
}

void HitBox::Collide(Player* player)
{
	for (Player* inst : hitList)
	{
		if (inst == player) return;
	}

	player->Damage(damage);

	game.entitiesManifested.push_back(new HitSplat(player->position, damage));

	hitList.push_back(player);
}