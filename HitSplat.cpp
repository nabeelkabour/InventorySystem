#include "Game.h"
#include "HitSplat.h"

HitSplat::HitSplat(olc::vf2d pos, int32_t val) :
	Particle(pos),
	value(val)
{
	life = 0.75f;

	orientation = rand() % 360;
	direction = rand() % 360;
	float dir_radians = direction * 3.1415F / 180.0F;
	speed = 100;
	//speed_x = speed * cos(dir_radians); //rand() % 90 - 45;
	//speed_y = speed * -sin(dir_radians); //rand() % 90 - 45;

	text_angle = rand() % 40 - 20;
}

void HitSplat::Draw(float fElapsedTime)
{
	Particle::Draw(fElapsedTime);

	game.DrawRotatedStringDecal(
		position,
		std::to_string(value),
		orientation,
		{ 0.5F, 0.5F },
		olc::RED,
		{ xscale, yscale }
	);
}