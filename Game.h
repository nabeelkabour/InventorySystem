#ifndef GAME_H
#define GAME_H

#include "olcPixelGameEngine.h"
#include "Player.h"

class Game : public olc::PixelGameEngine
{
public:
	Player playerOne;

	Game();
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
};

extern Game game;

#endif