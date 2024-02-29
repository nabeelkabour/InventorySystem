#include "Game.h"
#include "Resources.h"
#include "Items.h"
#include "Inventory.h"

Game game;

Game::Game()
{
	sAppName = "Inventory System";
}

bool Game::OnUserCreate()
{
	srand(time(NULL));

	Resources::get();
	ItemIndex::Initialize();

	//Inventory inventory;

	return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
	return true;
}