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

	//for (int i = 0; i < 153; ++i) playerOne.playerInventory.GainItem(ItemIndex::itemIndex[ItemId::COIN_BRONZE]);

	//uint8_t numGrenades = 18;
	//for (uint8_t i = 0; i < 18; ++i)
	//{
	//	if (playerOne.playerInventory.GainItem(ItemIndex::itemIndex[ItemId::GRENADE]))
	//	{
	//		--numGrenades;
	//	}
	//	else
	//	{
	//		std::cout << "Not enough inventory." << std::endl;
	//		std::cout << (uint32_t)numGrenades;
	//		break;
	//	}
	//}

	return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
	//playerOne.playerInventory.Draw(0.f, 0.f);

	return true;
}