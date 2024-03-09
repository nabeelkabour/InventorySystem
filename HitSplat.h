#ifndef HITSPLAT_H
#define HITSPLAT_H

#include "Particle.h"

class HitSplat : public Particle
{
public:
	int32_t value;
	float text_angle;

	HitSplat(olc::vf2d pos, int32_t val);
	void Draw(float fElapsedTime) override;
};

#endif