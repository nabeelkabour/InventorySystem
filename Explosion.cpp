#include "Explosion.h"

Particle* Particles::Explosion(olc::vf2d pos)
{
	AnimatedParticle* explosion = new AnimatedParticle(pos, 11);

	explosion->spr = Resources::get().explodeEffect.Decal();
	explosion->width = explosion->spr->sprite->width;
	explosion->height = explosion->spr->sprite->height / 11;
	explosion->orientation = (rand() % 360) * 3.14159f / 180.f;

	return explosion;
}