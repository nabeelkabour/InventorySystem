#ifndef MANIFESTEDENTITY_H
#define MANIFESTEDENTITY_H

#include "olcUTIL_Geometry2D.h"
#include "olcPixelGameEngine.h"
#include "Entity.h"

//ManifestedEntities are anything drawn on the screen
class ManifestedEntity : public Entity
{
public:
	olc::vf2d position;
	bool visible = true;
	int16_t depth = 0;
	olc::Decal* spr = nullptr;
	uint32_t width = 0, height = 0;
	olc::vf2d scale = { 1.f, 1.f };

	ManifestedEntity(olc::vf2d pos, olc::Decal* spr = nullptr);
	void Create() override;
	void Update(float fElapsedTime) override;
	virtual void Draw(float fElapsedTime) = 0;
};

#endif