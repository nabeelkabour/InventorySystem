#include "Particle.h"

Particle* Particles::ExplosionCenter(olc::vf2d pos)
{
	Particle* part = new Particle(pos);

	part->spr = Resources::get().PartExplosionCenter.Decal();
	part->orientation = float(rand() % 360);
	part->life = 0.35f;
	part->alpha_2 = 0.5f;
	part->alpha_3 = 0.f;

	return part;
}