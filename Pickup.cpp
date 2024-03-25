#include "Game.h"
#include "Pickup.h"
#include "Particle.h"
#include "Helper.h"

Pickup::Pickup(olc::vf2d pos) :
	Actor(pos, 1, 1, nullptr)
{
	scale = { 0.25f, 0.25f };
}

void Pickup::Update(float fElapsedTime)
{
	Actor::Update(fElapsedTime);

	float decayLife = 0.8f * lifeTime;
	float decayTime = lifeTime - decayLife;

	if (life >= decayLife)
	{
		float progress = decayTimer / decayTime;
		alpha = Lerp(255.f, 0.f, progress);
		decayTimer += fElapsedTime;
	}

	if (life < growTime)
	{
		float progress = life / growTime;
		float scaleActual = Lerp(0.f, SCALE_256, progress);
		scale = { scaleActual, scaleActual };
	}
	else
	{
		grown = true;
	}

	life += fElapsedTime;

	if (life >= lifeTime) remove_flag = true;
}

ItemPickup::ItemPickup(olc::vf2d pos, Item item) : Pickup(pos), item(item)
{
	spr = item.sprite;
	scale = scaleSpawn;
}

void ItemPickup::Draw(float fElapsedTime)
{
	game.DrawRotatedDecal(
		position,
		item.sprite,
		0.f,
		{ item.sprite->sprite->width / 2.f, item.sprite->sprite->height / 2.f },
		scale,
		olc::Pixel(255, 255, 255, uint8_t(alpha))
	);

	if(grown) scale = { SCALE_256, SCALE_256 };
}

void ItemPickup::Collide(Player* player)
{
	if(grown) scale = { 0.35f, 0.35f };

	if (player->gamepad->getButton(olc::GPButtons::FACE_L).bPressed)
	{
		if (player->playerInventory.GainItem(item))
		{
			Effect(player);
			remove_flag = true;
		}
		else
		{
			game.entitiesManifested.push_back(Particles::InventoryFullEffect(player));
		}
	}
}

void ItemPickup::Effect(Player* player)
{
	game.entitiesManifested.push_back(Particles::ItemPickupEffect(player, item));

	remove_flag = true;
}