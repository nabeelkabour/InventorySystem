#ifndef ANIMATEDPARTICLE_H
#define ANIMATEDPARTICLE_H

#include "olcUTIL_Geometry2D.h"
#include "Particle.h"

//enum class SpriteSheetOrientation
//{
//	HORIZONTAL,
//	VERTICAL
//};

class AnimatedParticle : public Particle
{
public:
	float animationTimer = 0.f;
	float animationInterval = 0.035f;
	int16_t animationIndex = 0;
	uint16_t numFrames = 1;
	
	AnimatedParticle(olc::vf2d pos, uint16_t numFrames, float animationInterval = 0.035f);
	void Update(float fElapsedTime) override;
	void Draw(float fElapsedTime) override;
};

#endif
