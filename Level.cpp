#include "Level.h"
#include "Game.h"
#include <unordered_set>

Level::~Level()
{
	for (Entity* entity : game.entities)
	{
		delete entity;
	}
	game.entities.clear();

	for (ManifestedEntity* entity_man : game.entitiesManifested)
	{
		delete entity_man;
	}
	game.entitiesManifested.clear();

	for (Actor* actor : game.actors)
	{
		delete actor;
	}
	game.actors.clear();
}

void Level::Create()
{
	//Load entities

	for (Entity* entity : entitiesLevel)
	{
		game.entities.push_back(entity);
	}

	for (ManifestedEntity* man_entity : entitiesManifestedLevel)
	{
		game.entitiesManifested.push_back(man_entity);
	}

	for (Actor* actor : actorsLevel)
	{
		game.actors.push_back(actor);
	}
}

void Level::Update(float fElapsedTime)
{
	//std::list<Entity*> entities_all = entities
	//entities.merge(game.entities_peristent, [&](Entity ent1, Entity ent2) { ent1.});

	for (Entity* entity_persistent : game.entitiesPeristent)
	{
		entity_persistent->Update(fElapsedTime);
	}

	for (Entity* entity : game.entities)
	{
		entity->Update(fElapsedTime);
	}

	game.entitiesManifested.sort([](const ManifestedEntity* ent1, const ManifestedEntity* ent2) { return (ent1->depth < ent2->depth); });

	for (ManifestedEntity* man_entity : game.entitiesManifested)
	{
		man_entity->Update(fElapsedTime);
	}

	std::unordered_set<const Entity*> removeSet;

	game.entitiesManifested.remove_if([&](const Entity* entity)
		{
			if (entity->remove_flag)
			{
				removeSet.insert(entity);
				//delete entity;
				return true;
			}
			else
			{
				return false;
			}
		});

	game.actors.remove_if([&](const Entity* actor)
		{
			if (actor->remove_flag)
			{
				removeSet.insert(actor);
				//delete actor;
				return true;
			}
			else
			{
				return false;
			}
		});

	for (const Entity* removeEntity : removeSet)
	{
		delete removeEntity;
	}
}

void Level::LevelChange(Level* newLevel)
{
	delete game.levelCurrent;
	game.levelCurrent = newLevel;
	game.levelCurrent->Create();
}