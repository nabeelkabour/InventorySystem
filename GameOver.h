#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "Level.h"

class GameOverOne : public Level
{
public:
	void Create() override;
	void Update(float fElapsedTime) override;
};

class GameOverTwo : public Level
{
public:
	void Create() override;
	void Update(float fElapsedTime) override;
};

#endif