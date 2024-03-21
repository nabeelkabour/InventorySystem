#include "Game.h"
#include "PickupManager.h"
#include "Pickup.h"
#include <cstdlib>

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

	int16_t itemId = rand() % (int16_t(ItemId::TOTAL) - 1) + 1;
	//int16_t itemId = int16_t(ItemId::AMMOSILVER);

	game.AddActor(new ItemPickup(
		olc::vf2d{ float(posX), float(posY) },
		ItemIndex::itemIndex[ItemId(itemId)]
	));
}