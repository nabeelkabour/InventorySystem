#include "Game.h"
#include "Grenade.h"
#include "Resources.h"
#include "HitSplat.h"
#include "HitBox.h"

Grenade::Grenade(olc::vf2d pos, olc::vf2d velocity, int32_t hp, int32_t hpMax, std::string name) :
	velocity(velocity), Actor(pos, hp, hpMax, spr, name)
{
	spr = Resources::get().grenade.Decal();

	scale = { 0.1f, 0.1f };
}

void Grenade::Draw(float fElapsedTime)
{
	game.DrawRotatedDecal(position, spr, velocity.y, { 256.f / 2.f, 256.f / 2.f}, { 0.1f, 0.1f });
}

olc::vf2d position, speed;

void Grenade::Update(float fElapsedTime)
{
	Actor::Update(fElapsedTime);

	position += velocity.cart() * fElapsedTime;

	if (velocity.x > 0.f)
	{
		velocity.x -= 40.f * fElapsedTime;
	}
	else
	{
		velocity.x = 0.f;
	}

	fuseTime += fElapsedTime;

	if (fuseTime >= fuseTimer)
	{
		//explode (destroy and create hitbox instance)
		Particle* explosion = Particles::Explosion(position);
		game.entitiesManifested.push_back(explosion);

		Actor* hitBox = new HitBox(position - olc::vf2d{ 128.f / 2.f, 128.f / 2.f }, 1, 1, Resources::get().explodeMask.Decal(), 150);// explosion->life

		game.entitiesManifested.push_back(hitBox);
		game.actors.push_back(hitBox);

		remove_flag = true;
	}
}

//bool Grenade::CollidesWith(Actor* other)
//{
//	Actor::CollidesWith(other);
//	return false;
//}

void Grenade::Collide(Player* player)
{
	for (Player * inst : hitList)
	{
		if (inst == player) return;
	}

	player->hp -= 30;

	game.entitiesManifested.push_back(new HitSplat(player->position, 30));

	hitList.push_back(player);
}