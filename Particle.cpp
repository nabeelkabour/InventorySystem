#include "Game.h"
#include "Particle.h"
#include "Helper.h"

Particles::Particles()
{

}

Particle::Particle(olc::vf2d pos) : ManifestedEntity(pos)
{
}

Particle::~Particle()
{
	if (life_current >= life)
	{
		if (death_num)
		{
			game.entitiesManifested.push_back(death_part);
		}
	}
}

void Particle::Create()
{}

void Particle::Update(float fElapsedTime)
{
	ManifestedEntity::Update(fElapsedTime);

	position.x += (speed * cos(direction) + gravity_amount * cos(gravity_direction)) * fElapsedTime;
	position.y += (speed * sin(direction) + gravity_amount * sin(gravity_direction)) * fElapsedTime;

	speed += speed_incr * fElapsedTime;
	direction += direction_incr * fElapsedTime;
	gravity_amount += gravity * fElapsedTime;

	xscale += xscale_incr * fElapsedTime;
	yscale += yscale_incr * fElapsedTime;

	float life_half = life / 2.f;
	if (life_current <= life_half)
	{
		float progress = life_current / life_half;

		color = olc::PixelLerp(color_1, color_2, progress);
		alpha = Lerp(alpha_1, alpha_2, progress);
	}
	else
	{
		float progress = (life_current - life_half) / life_half;

		color = olc::PixelLerp(color_2, color_3, progress);
		alpha = Lerp(alpha_2, alpha_3, progress);
	}

	orientation += orientation_incr * fElapsedTime;

	life_current += fElapsedTime;
	if (life_current >= life)
	{
		remove_flag = true;
	}
}

void Particle::Draw(float fElapsedTime)
{
	//game.DrawDecal({ x,y }, spr);
	if (!spr) return;

	game.DrawRotatedDecal(
		position,
		spr,
		orientation,
		olc::vf2d(spr->sprite->Size()) / 2.f,
		{ xscale, yscale },
		olc::Pixel(color.r, color.g, color.b, uint8_t(alpha * 255.f))
	);
}