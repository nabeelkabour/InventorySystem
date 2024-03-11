#include "Explosion.h"

Particle* Particles::Explosion(olc::vf2d pos)
{
	AnimatedParticle* explosion = new AnimatedParticle(pos, 11);

	explosion->spr = Resources::get().explodeEffect.Decal();
	explosion->width = explosion->spr->sprite->width;
	explosion->height = explosion->spr->sprite->height;
	explosion->orientation = rand() % 360;

	return explosion;
}