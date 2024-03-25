#include "Particle.h"
#include "ParticleEffect.h"

ParticleEffect* Particles::TeleportEffect(olc::vf2d pos)
{
	ParticleEffect* teleEffect = new ParticleEffect(pos);

	teleEffect->particles.push_back(Particles::TelePartRing(pos));
	teleEffect->particles.push_back(Particles::TelePartRingIn(pos));

	for (uint16_t i = 0; i < 15; ++i)
	{
		teleEffect->particles.push_back(Particles::TelePartOne(pos));
	}

	return teleEffect;
}

Particle* Particles::TelePartOne(olc::vf2d pos)
{
	Particle* part = new Particle(pos);

	part->spr = Resources::get().PartRing.Decal();
	part->life = 2.f;
	part->speed = float(rand() % 50 + 50);
	part->speed_incr = -float((rand() % 40) + 5);
	part->direction = float(rand() % 360);
	part->xscale = 0.3f;
	part->yscale = 0.3f;
	part->color = olc::Pixel(255, 0, 255);
	part->color_1 = part->color;
	part->color_2 = part->color;
	part->color_3 = part->color;
	part->alpha_2 = 0.5f;
	part->alpha_3 = 0.f;

	return part;
}

Particle* Particles::TelePartRing(olc::vf2d pos)
{
	Particle* part = new Particle(pos);

	part->spr = Resources::get().PartCircle.Decal();
	part->life = 2.f;
	part->xscale = 1.f;
	part->yscale = 1.f;
	part->xscale_incr = 1.f;
	part->yscale_incr = 1.f;
	part->color = olc::Pixel(200, 0, 200);
	part->color_1 = part->color;
	part->color_2 = part->color;
	part->color_3 = part->color;
	part->alpha_2 = 0.5f;
	part->alpha_3 = 0.f;

	return part;
}

Particle* Particles::TelePartRingIn(olc::vf2d pos)
{
	Particle* part = new Particle(pos);

	part->spr = Resources::get().PartCircle.Decal();
	part->life = 2.f;
	part->xscale = 3.f;
	part->yscale = 3.f;
	part->xscale_incr = -2.f;
	part->yscale_incr = -2.f;
	part->color = olc::Pixel(100, 0, 200);
	part->color_1 = part->color;
	part->color_2 = part->color;
	part->color_3 = part->color;
	part->alpha_2 = 0.5f;
	part->alpha_3 = 0.f;

	return part;
}