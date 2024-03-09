#include "Game.h"
#include "BattleArena.h"

void LBattleArena::Create()
{
	game.playerOne = new Player(PlayerID::ONE, { 150.f, 150.f }, 300, 300, Resources::get().base.Decal(), game.gamepadOne, "Player One");
	game.playerTwo = new Player(PlayerID::TWO, { 350.f, 150.f }, 300, 300, Resources::get().base.Decal(), game.gamepadTwo, "Player Two");

	entitiesManifestedLevel.push_back(game.playerOne);
	entitiesManifestedLevel.push_back(game.playerTwo);

	actorsLevel.push_back(game.playerOne);
	actorsLevel.push_back(game.playerTwo);

	Level::Create();
}

void LBattleArena::Update(float fElapsedTime)
{
	Level::Update(fElapsedTime);
}