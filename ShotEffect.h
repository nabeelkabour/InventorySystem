#ifndef SHOTEFFECT_H
#define SHOTEFFECT_H

#include "ManifestedEntity.h"

class ShotEffect : public ManifestedEntity
{
public:
	olc::vf2d endPoint;
	float alpha = 255.f;
	olc::Pixel color;
	bool hit = false;

	ShotEffect(olc::vf2d pos, olc::vf2d endPos, olc::Pixel color, bool hit = false);
	void Update(float fElapsedTime) override;
	void Draw(float fElapsedTime) override;
};

#endif