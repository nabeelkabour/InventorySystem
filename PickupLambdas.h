#ifndef PICKUPLAMBDAS_H
#define PICKUPLAMBDAS_H

#include "Buff.h"
#include "Particle.h"
#include "ParticleEffect.h"

auto lambdaVoid = [&](Player* playerCalling, Player* playerOther)
{
	return true;
};

auto lambdaSpeedBuff = [&](Player* playerCalling, Player* playerOther)
{
	playerCalling->speed += 350.f;

	return true;
};

auto lambdaSpeedDebuff = [&](Player* playerCalling, Player* playerOther)
{
	playerCalling->speed -= 350.f;

	return true;
};

auto lambdaSwapPlaces = [&](Player* playerCalling, Player* playerOther)
{
	olc::vf2d temp = playerCalling->position;
	playerCalling->position = playerOther->position;
	playerOther->position = temp;

	game.entitiesManifested.push_back(Particles::TeleportEffect(playerCalling->position));
	game.entitiesManifested.push_back(Particles::TeleportEffect(playerOther->position));

	return true;
};

//auto lambdaReverseControls = [&](Player* playerCalling, Player* playerOther)
//{
//	return true;
//};

#endif