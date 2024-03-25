#include "Helper.h"
#include "Missile.h"
#include "Player.h"
#include "Game.h"
#include "HitSplat.h"

Missile::Missile(olc::vf2d pos, olc::vf2d velocity, int32_t hp, int32_t hpMax, olc::Decal* spr, Player* target, Player* owner)
	: Actor(pos, hp, hpMax, spr), velocity(velocity), target(target), owner(owner)
{
	scale = { 1.75f, 1.75f };
	crosshairScale = crosshairScaleBegin;
}

void Missile::Update(float fElapsedTime)
{
	Actor::Update(fElapsedTime);

	if (target and homing)
	{
		float point_dir = atan2((-position.y + target->position.y), (-position.x + target->position.x));

		velocity.y = Helpers::turn_towards_direction(velocity.y, point_dir, rotationSpeed * fElapsedTime);

		crosshairAngle += PI / 1.25f * fElapsedTime;

		if (crosshairScale < crosshairScaleEnd) crosshairScale = crosshairScaleEnd; else crosshairScale -= 8.f * fElapsedTime;
	}

	position += velocity.cart() * fElapsedTime;
	
	if (exhaustTimer >= 1.f / exhaustFreq)
	{
		game.entitiesManifested.push_back(Particles::ExhaustSmoke(position));
		exhaustTimer = 0.f;
	}
	exhaustTimer += fElapsedTime;

	if (deathTimer >= missileLife)
	{
		game.entitiesManifested.push_back(Particles::ExplosionCenter(position));
		remove_flag = true;
	}
	deathTimer += fElapsedTime;
}

void Missile::Draw(float fElapsedTime)
{
	game.DrawLineDecal(position, target->position, olc::RED);
	olc::Decal* crosshairSprite = Resources::get().crosshair.Decal();
	game.DrawRotatedDecal(
		target->position,
		crosshairSprite,
		crosshairAngle,
		{ crosshairSprite->sprite->width / 2.f, crosshairSprite->sprite->height / 2.f },
		{ crosshairScale, crosshairScale }
	);

	game.DrawRotatedDecal(
		position,
		spr,
		velocity.y + PI / 2.f,
		{ spr->sprite->width / 2.f, float(spr->sprite->height) },
		scale
	);
}

void Missile::Collide(Player* player)
{
	if (player == owner) return;

	player->Damage(missileDamage);

	game.entitiesManifested.push_back(new HitSplat(player->position, missileDamage));

	game.entitiesManifested.push_back(Particles::ExplosionCenter(position));
	remove_flag = true;
}