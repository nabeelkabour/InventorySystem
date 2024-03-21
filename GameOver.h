#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "Level.h"

class GameOver : public Level
{
public:
	void Create() override;
	void Update(float fElapsedTime) override;
};

#endif