#include "ParticleEffect.h"

ParticleEffect::ParticleEffect(olc::vf2d pos) : ManifestedEntity(pos)
{

}

void ParticleEffect::Create()
{

}

void ParticleEffect::Update(float fElapsedTime)
{
	ManifestedEntity::Update(fElapsedTime);

	for (Particle* part : particles)
	{
		part->Update(fElapsedTime);
	}

	particles.remove_if([&](const Particle* part)
		{
			if (part->remove_flag)
			{
				delete part;
				return true;
			}
			else
			{
				return false;
			}
		});

	if (particles.empty())
	{
		remove_flag = true;
	}
}

void ParticleEffect::Draw(float fElapsedTime)
{
	for (Particle* part : particles)
	{
		part->Draw(fElapsedTime);
	}
}