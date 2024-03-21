#include "Game.h"
#include "HitSplat.h"

HitSplat::HitSplat(olc::vf2d pos, int32_t val) :
	Particle(pos),
	value(val)
{
	color = olc::RED;
	color_1 = olc::RED;
	color_2 = olc::RED;
	color_3 = olc::DARK_RED;

	alpha_2 = 0.5f;
	alpha_3 = 0.25f;

	xscale_incr = -0.5f;
	yscale_incr = -0.5f;

	life = 0.75f;

	orientation = rand() % 360;
	direction = rand() % 360;
	float dir_radians = direction * 3.1415F / 180.0F;
	speed = 100;
	speed_incr = -100.f;
	//speed_x = speed * cos(dir_radians); //rand() % 90 - 45;
	//speed_y = speed * -sin(dir_radians); //rand() % 90 - 45;

	xscale = 2.5f;
	yscale = 2.5f;

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
		olc::Pixel(color.r, color.g, color.b, uint8_t(alpha * 255.f)),
		{ xscale, yscale }
	);
}