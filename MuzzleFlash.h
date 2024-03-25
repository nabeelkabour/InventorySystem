#ifndef MUZZLEFLASH_H
#define MUZZLEFLASH_H

#include "AnimatedParticle.h"

class MuzzleFlashParticle : public AnimatedParticle
{
public:
	MuzzleFlashParticle(olc::vf2d pos, uint16_t numFrames, float angle, float animationInterval = 0.035f);
	void Draw(float fElapsedTime) override;
};

#endif
