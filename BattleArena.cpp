#include "Game.h"
#include "BattleArena.h"
#include "PickupManager.h"
#include "Pickup.h"

void LBattleArena::Create()
{
	game.playerOne = new Player(PlayerID::ONE, { 150.f, 150.f }, 300, 300, Resources::get().base.Decal(), game.gamepadOne, "Player One");
	game.playerTwo = new Player(PlayerID::TWO, { 550.f, 150.f }, 300, 300, Resources::get().base.Decal(), game.gamepadTwo, "Player Two");

	entitiesManifestedLevel.push_back(game.playerOne);
	entitiesManifestedLevel.push_back(game.playerTwo);

	actorsLevel.push_back(game.playerOne);
	actorsLevel.push_back(game.playerTwo);

	//Actor* hpPickup = new ItemPickup(olc::vf2d{ 400.f, 200.f }, ItemIndex::itemIndex[ItemId::POTION]);
	//entitiesManifestedLevel.push_back(hpPickup);
	//actorsLevel.push_back(hpPickup);

	entitiesLevel.push_back(new PickupManager());

	Level::Create();
}

void LBattleArena::Update(float fElapsedTime)
{
	Level::Update(fElapsedTime);
}