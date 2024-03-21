#ifndef RAYCAST_H
#define RAYCAST_H

#include "HitBox.h"

class RayCast : public HitBox
{
public:
	//olc::vf2d startPoint;
	olc::vf2d endPoint;
	float alpha = 255;

	RayCast(olc::vf2d start, olc::vf2d end, float lifeTime, float damage);
	void Update(float fElapsedTime) override;
	void Draw(float fElapsedTime) override;
};

#endif
