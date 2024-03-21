#include "Game.h"
#include "GameOver.h"

void GameOver::Create()
{
}

void GameOver::Update(float fElapsedTime)
{
	game.DrawStringDecal(olc::vf2d{ 100.f,100.f }, "Player x Wins!");
}