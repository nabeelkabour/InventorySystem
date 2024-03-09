#include "Game.h"
#include "MainMenu.h"
#include "BattleArena.h"

void LMainMenu::Create()
{
	Level::Create();
}

void LMainMenu::Update(float fElapsedTime)
{
	//game.DrawStringDecal({ 35.0F, 70.0F }, "Laser Drift\n\n	2", olc::YELLOW, { 6.25F, 6.25F });
	static float logoAlpha = 0;

	if (logoAlpha < 1.f)
	{
		logoAlpha += fElapsedTime / 4.5f;
	}
	else
	{
		logoAlpha = 1.f;
	}

	game.DrawDecal(
		{ game.ScreenWidth() / 2.f - Resources::get().mainLogo.Sprite()->Size().x * 1.15f / 2.f, 100.0F},
		Resources::get().mainLogo.Decal(),
		{ 1.15f, 1.15f },
		olc::Pixel(255, 255, 255, uint8_t(logoAlpha * 255.f))
	);

	if (game.gamepadOne->getButton(olc::GPButtons::START).bPressed or game.gamepadTwo->getButton(olc::GPButtons::START).bPressed)
	{
		LevelChange(new LBattleArena);
	}

	if (showStartTime >= 3.5f)
	{
		float static alpha = 0.f;
		alpha += fElapsedTime;
		game.DrawDecal({ game.ScreenWidth() / 2.f - Resources::get().pressStart.Sprite()->Size().x / 2.f, 300.0F }, Resources::get().pressStart.Decal(), { 1.f, 1.f }, olc::Pixel(255, 255, 255, uint8_t(127 * cos(alpha * 2.f) + 127)));
	}

	showStartTime += fElapsedTime;

	Level::Update(fElapsedTime);
}