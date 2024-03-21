#include "Particle.h"
#include "Items.h"
#include "Player.h"

Particle* Particles::ItemPickupEffect(Player* player, Item item)
{
	Particle* part = new Particle((player->position) + olc::vf2d{ 0.f, float(player->spr->sprite->height * player->scale.y / 2.f) } );

	part->spr = item.sprite;
	part->xscale = 0.25f;
	part->yscale = part->xscale;
	part->alpha_2 = 0.5f;
	part->alpha_3 = 0.f;
	
	part->life = 1.f;
	part->speed = 100.f;
	part->direction = -3.14159f / 2.f;

	return part;
}