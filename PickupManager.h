#ifndef PICKUPMANAGER_H
#define PICKUPMANAGER_H

class PickupManager : public Entity
{
public:
	float spawnInterval = 2.f;
	float spawnTimer = 0.f;

	void Create() override;
	void Update(float fElapsedTime) override;
	void SpawnPickup();
};

#endif