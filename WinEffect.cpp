#include "Game.h"
#include "WinEffect.h"
#include "Helper.h"

WinEffect::WinEffect(Player* winner) : ManifestedEntity({ SCREENWIDTH / 2.f, SCREENHEIGHT / 2.f })
{
	if (winner == game.playerOne)
	{
		spr = Resources::get().playerOneWins.Decal();
	}
	else
	{
		spr = Resources::get().playerTwoWins.Decal();
	}

	winner->hp = 99999.f;

	depth = -99999;
}

void WinEffect::Update(float fElapsedTime)
{
	float realElapsedTime;

	if (game.timeMultiplier > 0.f)
	{
		realElapsedTime = fElapsedTime / game.timeMultiplier;
	}
	else
	{
		realElapsedTime = 0.f;
	}

	ManifestedEntity::Update(realElapsedTime);

	switch (stage)
	{
	case WinEffectStage::SLOWDOWN:
		game.timeMultiplier = Lerp(0.75f, 0.f, time / stageOneTime);
		//game.timeMultiplier = 0.25f;
		//if (time >= stageOneTime) stage = WinEffectStage::FREEZE;
		break;

	case WinEffectStage::FREEZE:
		game.timeMultiplier = 0.f;
		break;
	}

	time += realElapsedTime;
}

void WinEffect::Draw(float fElapsedTime)
{
	game.DrawRotatedDecal(
		position,
		spr,
		0.f,
		{ spr->sprite->width / 2.f, spr->sprite->height / 2.f }
	);
}