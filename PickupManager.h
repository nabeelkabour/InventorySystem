#ifndef PICKUPMANAGER_H
#define PICKUPMANAGER_H

#include "PowerupPickup.h"
#include <unordered_map>

class PickupManager : public Entity
{
public:
	float spawnInterval = 1.f;
	float spawnTimer = 0.f;
	std::unordered_map<Powerup, PowerupPickupData> powerupMap;

	PickupManager();
	void Create() override;
	void Update(float fElapsedTime) override;
	void SpawnPickup();
};

#endif