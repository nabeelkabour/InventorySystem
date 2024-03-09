#ifndef BATTLEARENA_H
#define BATTLEARENA_H

#include "Level.h"

class LBattleArena : public Level
{
public:
	void Create() override;
	void Update(float fElapsedTime) override;
};

#endif