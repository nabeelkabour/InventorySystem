#ifndef PICKUPMANAGER_H
#define PICKUPMANAGER_H

class PickupManager
{
public:
	float spawnInterval = 10.f;
	float spawnTimer = 0.f;

	void Update(float fElapsedTime);
	void SpawnPickup();
};

#endif