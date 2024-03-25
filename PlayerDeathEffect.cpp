#include "Particle.h"
#include "ParticleEffect.h"

ParticleEffect* Particles::PlayerDeathEffect(olc::vf2d pos)
{
	ParticleEffect* effect = new ParticleEffect(pos);

	effect->particles.push_back(Particles::ExplosionCenter(pos));

	return effect;
}

