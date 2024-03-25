#ifndef MISSILE_H
#define MISSILE_H

#include "Actor.h"
#include "Helper.h"

class Missile : public Actor
{
public:
	const uint32_t missileDamage = 30;
	const float crosshairScaleBegin = 7.f;
	const float crosshairScaleEnd = 3.f;
	const float missileLife = 3.f;
	const float exhaustFreq = 30.f;

	Player* owner = nullptr;
	Player* target;
	bool homing = true;
	float crosshairAngle = 0.f;
	float crosshairScale = 5.f;
	olc::vf2d velocity;
	float rotationSpeed = PI / 3.f;
	float deathTimer = 0.f;
	float exhaustTimer = 0.f;

	Missile(olc::vf2d pos, olc::vf2d velocity, int32_t hp, int32_t hpMax, olc::Decal* spr, Player* target, Player* owner);
	void Collide(Player* player) override;
	void Update(float fElapsedTime) override;
	void Draw(float fElapsedTime) override;
};

#endif
