#ifndef PARTICLE_H
#define PARTICLE_H

#include "olcUTIL_Geometry2D.h"
#include "ManifestedEntity.h"
#include "Player.h"

class ParticleEffect;

class Particle : public ManifestedEntity
{
public:
	float life = 0.f;
	float life_current = 0.f;
	float speed = 0.f;
	float speed_incr = 0.f;
	float direction = 0.f;
	float direction_incr = 0.f;
	float orientation = 0.f;
	float orientation_incr = 0.f;
	float xscale = 1.f;
	float yscale = 1.f;
	float xscale_incr = 0.f;
	float yscale_incr = 0.f;
	float size = 1.f;
	float size_incr = 0.f;
	float gravity = 0.f;
	float gravity_amount = 0.f;
	float gravity_direction = 0.f;
	float alpha_1 = 1.f;
	float alpha_2 = 1.f;
	float alpha_3 = 1.f;
	float alpha = 1.f;
	int32_t death_num = 0;
	Particle* death_part = nullptr;
	olc::Pixel color = olc::WHITE;
	olc::Pixel color_1 = olc::WHITE;
	olc::Pixel color_2 = olc::WHITE;
	olc::Pixel color_3 = olc::WHITE;

	//olc::Decal* spr = nullptr;

	Particle(olc::vf2d pos);
	~Particle();
	void Create() override;
	void Update(float fElapsedTime) override;
	void Draw(float fElapsedTime) override;
};

class Particles
{
	Particles();

public:
	static Particles& get()
	{
		static Particles res;
		return res;
	}

	Particles(Particles&&) = delete;
	Particles(const Particles&) = delete;
	Particles& operator=(const Particles&) = delete;
	Particles& operator=(Particles&&) = delete;

	//Particle effects
	//Particle* hitSplat;
	static Particle* Explosion(olc::vf2d pos);
	static Particle* ExhaustSmoke(olc::vf2d pos);
	static Particle* ExplosionCenter(olc::vf2d pos);
	static Particle* MuzzleFlash(olc::vf2d polar);
	static Particle* HpGain(olc::vf2d pos);
	static Particle* ItemPickupEffect(Player* player, Item item);
	static Particle* InventoryFullEffect(Player* player);

	static Particle* TelePartOne(olc::vf2d pos);
	static Particle* TelePartRing(olc::vf2d pos);
	static Particle* TelePartRingIn(olc::vf2d pos);
	//static Particle* particle_smoke;

	//Simple

	//Compound
	//static ParticleEffect* create_explosion_effect(float _x, float _y);
	static ParticleEffect* TeleportEffect(olc::vf2d pos);
	static ParticleEffect* PlayerDeathEffect(olc::vf2d pos);
};

#endif