#include "Game.h"
#include "Particle.h"
#include "AnimatedParticle.h"
#include "MuzzleFlash.h"

MuzzleFlashParticle::MuzzleFlashParticle(olc::vf2d pos, uint16_t numFrames, float angle, float animationInterval)
	: AnimatedParticle(pos, numFrames, animationInterval)
{
	spr = Resources::get().muzzleFlash.Decal();
	life = 10.25f;
	width = spr->sprite->width / 3;
	height = spr->sprite->height;
	xscale = 3.f;
	yscale = 3.f;
	orientation = angle + 3.14159f / 2.f;
}

void MuzzleFlashParticle::Draw(float fElapsedTime)
{
	olc::vf2d source_pos = { float(width * animationIndex), 0.f };

	game.DrawPartialRotatedDecal(
		position,
		spr,
		orientation,
		{ float(width) / 2.f, float(height)},
		source_pos,
		{ float(width), float(height) },
		{ xscale, yscale }
	);
}

//Particle* Particles::MuzzleFlash(olc::vf2d pos)
//{
//	AnimatedParticle* flash = new AnimatedParticle(pos, 3, SpriteSheetOrientation::HORIZONTAL, 1.f);
//
//	flash->spr = Resources::get().muzzleFlash.Decal();
//	flash->life = 10.25f;
//	flash->width = flash->spr->sprite->width / 3;
//	flash->height = flash->spr->sprite->height;
//	flash->xscale = 3.f;
//	flash->yscale = 3.f;
//	flash->orientation = pos.polar().y;
//
//	return flash;
//}