#ifndef GAME_H
#define GAME_H

#include "olcPixelGameEngine.h"

class Game : public olc::PixelGameEngine
{
public:
	Game();
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
};

extern Game game;

#endif