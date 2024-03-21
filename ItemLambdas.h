#ifndef ITEMLAMBDAS_H
#define ITEMLAMBDAS_H

#include "Game.h"
#include "olcUTIL_Geometry2D.h"
#include "olcPixelGameEngine.h"
#include "HitSplat.h"
#include "ShotEffect.h"

using namespace olc::utils::geom2d;

auto lambdaHpPotion = [&](Player* playerCalling, Player* playerOther)
{
	playerCalling->hp += 75;
	if (playerCalling->hp > playerCalling->hpMax) playerCalling->hp = playerCalling->hpMax;

	game.entitiesManifested.push_back(Particles::HpGain(playerCalling->position));

	return true;
};

auto lambdaGrenade = [&](Player* playerCalling, Player* playerOther)
{	// Create grenade in direction of player turret
	ManifestedEntity* grenade = new Grenade(
		/*player->position + olc::vf2d{ 256.f * cos(player->turretAngle), 256.f * sin(player->turretAngle) } * player->scale,*/
		playerCalling->position + olc::vf2d{ 256.f, playerCalling->turretAngle}.cart() * playerCalling->scale,
		{ 80.f, playerCalling->turretAngle }
	);

	game.entitiesManifested.push_back(grenade);
	game.actors.push_back((Actor*)grenade);
	return true;
};

auto lambdaAmmo = [&](Player* playerCalling, Player* playerOther)
{
	olc::vf2d turretPoint = playerCalling->position + olc::vf2d{ 256.f, playerCalling->turretAngle }.cart() * playerCalling->scale;
	olc::vf2d endPoint = turretPoint + olc::vf2d{ game.ScreenWidth() / 2.f, playerCalling->turretAngle }.cart();

	line<float> lineCast(turretPoint, endPoint);

	circle<float> target(playerOther->position, 256.f * 0.5f * playerOther->scale.x);

	olc::vf2d effectEndPoint = endPoint;
	olc::Pixel color = olc::WHITE;
	bool hitFlag = false;

	if (overlaps(target, lineCast))
	{
		color = olc::RED;
		hitFlag = true;

		std::vector points = intersects(target, lineCast);

		if (points.size() > 1)
		{
			effectEndPoint = points[1];
		}
		else
		{
			effectEndPoint = points[0];
		}



		playerOther->Damage(15.f);
		game.entitiesManifested.push_back(new HitSplat(playerOther->position, 15));
	}

	game.entitiesManifested.push_back(new ShotEffect(turretPoint, effectEndPoint, color, hitFlag));

	return true;
};

auto lambdaAmmoSilver = [&](Player* playerCalling, Player* playerOther)
{
	olc::vf2d turretPoint = playerCalling->position + olc::vf2d{ 256.f, playerCalling->turretAngle }.cart() * playerCalling->scale;
	olc::vf2d endPoint = turretPoint + olc::vf2d{ game.ScreenWidth() / 3.5f, playerCalling->turretAngle }.cart();

	line<float> lineCast(turretPoint, endPoint);

	circle<float> target(playerOther->position, 256.f * 0.5f * playerOther->scale.x);

	olc::vf2d effectEndPoint = endPoint;
	olc::Pixel color = olc::YELLOW;
	bool hitFlag = false;

	if (overlaps(target, lineCast))
	{
		color = olc::RED;
		hitFlag = true;

		std::vector points = intersects(target, lineCast);

		if (points.size() > 1)
		{
			effectEndPoint = points[1];
		}
		else
		{
			effectEndPoint = points[0];
		}

		playerOther->Damage(10.f);
		game.entitiesManifested.push_back(new HitSplat(playerOther->position, 10));
	}

	game.entitiesManifested.push_back(new ShotEffect(turretPoint, effectEndPoint, color, hitFlag));

	return true;
};

#endif
