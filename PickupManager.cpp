#include "Game.h"
#include "PickupManager.h"
#include "Pickup.h"
#include "PowerupPickup.h"
#include <cstdlib>

#include "PickupLambdas.h"

PickupManager::PickupManager()
{
	powerupMap =
	{
		{
			Powerup::SPEED,
			{
				Resources::get().speedPowerup.Decal(),
				lambdaSpeedBuff,
				lambdaSpeedDebuff
			}
		},
		{
			Powerup::SWAP,
			{
				Resources::get().swapPowerup.Decal(),
				lambdaSwapPlaces,
				lambdaVoid
			}

		}
	};
}

void PickupManager::Create()
{

}

void PickupManager::Update(float fElapsedTime)
{
	spawnTimer += fElapsedTime;

	if (spawnTimer >= spawnInterval)
	{
		spawnTimer = 0.f;

		SpawnPickup();
	}
}

void PickupManager::SpawnPickup()
{
	int32_t posX;
	int32_t posY;

	posX = rand() % game.ScreenWidth();
	posY = rand() % game.ScreenHeight();

	if (rand() % 2)
	{
		int16_t itemId = rand() % (int16_t(ItemId::TOTAL) - 1) + 1;

		game.AddActor(new ItemPickup(
			olc::vf2d{ float(posX), float(posY) },
			ItemIndex::itemIndex[ItemId(itemId)]
		));

		return;
	}


	Powerup powerup = Powerup(rand() % (int16_t(Powerup::TOTAL) - 1));

	game.AddActor(new PowerupPickup(
		olc::vf2d{ float(posX), float(posY) },
		powerupMap[powerup].spr,
		powerupMap[powerup].apply,
		powerupMap[powerup].remove
	));
}