#include "Game.h"
#include "Resources.h"
#include "Items.h"
#include "Inventory.h"

Game game;

Game::Game()
{
	sAppName = "Laser Drift 2";
}

bool Game::OnUserCreate()
{
	srand(time(NULL));
	
	Resources::get();
	ItemIndex::Initialize();

	olc::GamePad::init();

	levelCurrent->Create();

	//for (int i = 0; i < 153; ++i) playerOne->playerInventory.GainItem(ItemIndex::itemIndex[ItemId::COIN_BRONZE]);

	//uint8_t numGrenades = 18;
	//for (uint8_t i = 0; i < 18; ++i)
	//{
	//	if (playerOne->playerInventory.GainItem(ItemIndex::itemIndex[ItemId::GRENADE]))
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
	Clear(olc::BLACK);

	if(GetGamepad(fElapsedTime)) return true;

	levelCurrent->Update(fElapsedTime);

	return true;
}

bool Game::GetGamepad(float fElapsedTime)
{
	if (gamepadOne == nullptr or !gamepadOne->stillConnected)
	{
		//DrawString(30, 30, "Player 1 press the select\n\nbutton on a gamepad.", olc::WHITE, 2);
		float static alpha = 0.f;
		alpha += fElapsedTime;
		DrawDecal({ 45.f, 45.f }, Resources::get().playerOnePress.Decal(), { 1.f, 1.f }, olc::Pixel(255, 255, 255, uint8_t(64 * cos(alpha * 3.f) + 191)));
		if (gamepadTwo == nullptr)
		{
			gamepadOne = olc::GamePad::selectWithButton(olc::GPButtons::SELECT);
		}
		else if (!gamepadTwo->getButton(olc::GPButtons::SELECT).bPressed)
		{
			gamepadOne = olc::GamePad::selectWithButton(olc::GPButtons::SELECT);
		}

		return true;
	}

	if (gamepadTwo == nullptr or !gamepadTwo->stillConnected)
	{
		float static alpha = 0.f;
		alpha += fElapsedTime;
		DrawDecal({ 45.f, 45.f }, Resources::get().playerTwoPress.Decal(), { 1.f, 1.f }, olc::Pixel(255, 255, 255, uint8_t(64 * cos(alpha * 3.f) + 191)));

		if (gamepadOne == nullptr)
		{
			gamepadTwo = olc::GamePad::selectWithButton(olc::GPButtons::SELECT);
		}
		else if (!gamepadOne->getButton(olc::GPButtons::SELECT).bPressed)
		{
			gamepadTwo = olc::GamePad::selectWithButton(olc::GPButtons::SELECT);
		}
		return true;
	}

	return false;
}
