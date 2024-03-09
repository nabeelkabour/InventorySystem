#ifndef MAINMENU_H
#define MAINMENU_H

#include "Level.h"

class LMainMenu : public Level
{
public:
	float showStartTime = 0.f;

	void Create() override;
	void Update(float fElapsedTime) override;
};

#endif