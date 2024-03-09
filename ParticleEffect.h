#ifndef PARTICLEEFFECT_H
#define PARTICLEEFFECT_H

#include "ManifestedEntity.h"
#include "Particle.h"

class ParticleEffect : public ManifestedEntity
{
public:
	std::list<Particle*> particles;

	ParticleEffect(olc::vf2d pos);
	void Create() override;
	void Update(float fElapsedTime);
	void Draw(float fElapsedTime) override;
};

#endif