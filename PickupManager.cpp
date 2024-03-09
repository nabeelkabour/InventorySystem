#include "Game.h"
#include "PickupManager.h"
#include <cstdlib>

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
	int32_t poxY;

	do {
		posX = rand() % game.ScreenWidth();
		poxY = rand() % game.ScreenHeight();
	} while (0);


}