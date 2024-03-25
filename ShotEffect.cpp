#include "Game.h"
#include "ShotEffect.h"

ShotEffect::ShotEffect(olc::vf2d pos, olc::vf2d endPos, olc::Pixel color, bool hit)
	: ManifestedEntity(pos),
	endPoint(endPos),
	color(color),
	hit(hit)
{
	depth = -100000;
}


void ShotEffect::Update(float fElapsedTime)
{
	ManifestedEntity::Update(fElapsedTime);

	alpha -= 255.f * 1.5f * fElapsedTime;

	if (alpha <= 0.f) remove_flag = true;
}

void ShotEffect::Draw(float fElapsedTime)
{
	game.DrawLineDecal(position, endPoint, olc::Pixel(color.r, color.g, color.b, uint8_t(alpha)));

	if (hit)
	{
		auto decal = Resources::get().HitMarker.Decal();
		game.DrawRotatedDecal(endPoint,
			decal,
			0.f,
			{ decal->sprite->width / 2.f, decal->sprite->height / 2.f }, 
			{ 0.1f, 0.1f}, 
			olc::Pixel(255, 255, 255, uint8_t(alpha))
			);
	}
}