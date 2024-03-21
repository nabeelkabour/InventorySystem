#include "Resources.h"
#include "Particle.h"

Particle* Particles::HpGain(olc::vf2d pos)
{
	Particle* part = new Particle(pos);

	part->spr = Resources::get().hpGainEffect.Decal();
	part->life = 1.25f;
	part->speed = 10.f;
	part->direction = -3.14159f / 2.f;
	part->alpha_2 = 0.5f;
	part->alpha_3 = 0.f;
	part->xscale = 0.075f;
	part->yscale = 0.075f;

	return part;
}