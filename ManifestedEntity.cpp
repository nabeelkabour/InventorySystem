#include "ManifestedEntity.h"

ManifestedEntity::ManifestedEntity(olc::vf2d pos, olc::Decal* spr) : position(pos), spr(spr)  {}

void ManifestedEntity::Create()
{

}

void ManifestedEntity::Update(float fElapsedTime)
{
	if (visible)
	{
		Draw(fElapsedTime);
	}
}