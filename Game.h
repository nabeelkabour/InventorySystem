#ifndef GAME_H
#define GAME_H

#include "olcPixelGameEngine.h"
#include "olcPGEX_Gamepad.h"
#include "Player.h"
#include "PickupManager.h"
#include "ManifestedEntity.h"
#include "MainMenu.h"

class Game : public olc::PixelGameEngine
{
public:
	Player* playerOne = nullptr;
	Player* playerTwo = nullptr;
	olc::GamePad* gamepadOne = nullptr;
	olc::GamePad* gamepadTwo = nullptr;

	Level* levelCurrent = new LMainMenu;

	PickupManager* pickupManager = nullptr;

	std::list<Entity*> entitiesPeristent;

	std::list<Entity*> entities;
	std::list<ManifestedEntity*> entitiesManifested;
	std::list<Actor*> actors;

	Game();
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;

	void LevelChange(Level* newLevel);

	void AddActor(Actor* actor);

	bool GetGamepad(float fElaspedTime);
	Player* GetOpponent(Player* player);
};

extern Game game;

#endif