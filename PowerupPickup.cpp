#include "Game.h"
#include "PowerupPickup.h"

PowerupPickup::PowerupPickup(olc::vf2d pos, olc::Decal* _spr, BuffEffect apply, BuffEffect remove) :
	Pickup(pos), apply(apply), remove(remove)
{
	spr = _spr;
}

void PowerupPickup::Collide(Player* player)
{
	scale = { 0.35f, 0.35f };

	if (player->gamepad->getButton(olc::GPButtons::FACE_L).bPressed)
	{
		Effect(player);
	}
}

void PowerupPickup::Effect(Player* player)
{
	game.entities.push_back(new Buff(player, lifeEffect, apply, remove));

	remove_flag = true;
}

void PowerupPickup::Draw(float fElapsedTime)
{
	game.DrawRotatedDecal(
		position,
		spr,
		0.f,
		{ spr->sprite->width / 2.f, spr->sprite->height / 2.f },
		scale,
		olc::Pixel(255, 255, 255, uint8_t(alpha))
	);

	scale = { 0.25f, 0.25f };
}