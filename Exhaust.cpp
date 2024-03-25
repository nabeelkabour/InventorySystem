#include "Particle.h"

Particle* Particles::ExhaustSmoke(olc::vf2d pos)
{
	Particle* part = new Particle(pos);

	part->spr = Resources::get().PartSmoke.Decal();
	part->life = 0.65f;
	part->alpha_2 = 0.5f;
	part->alpha_3 = 0.f;
	part->xscale = 0.3f;
	part->yscale = 0.3f;
	part->orientation = float(rand() % 360);
	part->color = olc::GREY;
	part->color_1 = part->color;
	part->color_2 = part->color;
	part->color_3 = part->color;

	return part;
}