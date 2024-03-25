#include "Game.h"
#include "AnimatedParticle.h"

AnimatedParticle::AnimatedParticle(olc::vf2d pos, uint16_t numFrames, float animationInterval) :
	Particle(pos),
	numFrames(numFrames),
	animationInterval(animationInterval)
{
	life = numFrames * animationInterval;
}

void AnimatedParticle::Update(float fElapsedTime)
{
	Particle::Update(fElapsedTime);

	animationTimer += fElapsedTime;

	if (animationTimer >= animationInterval)
	{
		++animationIndex;

		animationTimer = 0.f;
		if (animationIndex > (numFrames - 1)) remove_flag = true;
	}
}

void AnimatedParticle::Draw(float fElapsedTime)
{
	olc::vf2d source_pos = { float(0.f), float(height * animationIndex) };

	game.DrawPartialRotatedDecal(
		position,
		spr,
		orientation,
		{ float(width) / 2.f, float(height) / 2.f },
		source_pos,
		{ float(width), float(height) },
		{ xscale, yscale }
	);
}