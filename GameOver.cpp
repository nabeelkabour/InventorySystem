#include "Game.h"
#include "GameOver.h"

void GameOverOne::Create()
{
}

void GameOverOne::Update(float fElapsedTime)
{
	olc::Decal* spr = Resources::get().playerOneWins.Decal();
	game.DrawRotatedDecal(
		{ game.ScreenWidth() / 2.f, game.ScreenHeight() / 2.f },
		spr,
		0.f,
		{ spr->sprite->width / 2.f, spr->sprite->height / 2.f }
	);
}

void GameOverTwo::Create()
{
}

void GameOverTwo::Update(float fElapsedTime)
{
	olc::Decal* spr = Resources::get().playerTwoWins.Decal();
	game.DrawRotatedDecal(
		{ game.ScreenWidth() / 2.f, game.ScreenHeight() / 2.f },
		spr,
		0.f,
		{ spr->sprite->width / 2.f, spr->sprite->height / 2.f }
	);
}