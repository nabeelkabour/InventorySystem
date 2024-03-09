#ifndef LEVEL_H
#define LEVEL_H

#include <list>

#include "Entity.h"
#include "ManifestedEntity.h"
#include "Actor.h"

class Level
{
public:
	std::list<Entity*> entitiesLevel;
	std::list<ManifestedEntity*> entitiesManifestedLevel;
	std::list<Actor*> actorsLevel;

	~Level();
	void virtual Create();
	void virtual Update(float fElapsedTime);
	void LevelChange(Level* newLevel);
};

#endif