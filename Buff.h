#ifndef BUFF_H
#define BUFF_H

#include "Entity.h"
#include "Player.h"

using BuffEffect = std::function<bool(Player*, Player*)>;

class Buff : public Entity
{
public:
	Player* player;
	float life = 0.f;
	float lifeTime;

	Buff(Player* player, float lifeTime, BuffEffect buffApply, BuffEffect buffRemove);
	BuffEffect buffApply;
	BuffEffect buffRemove;
	void Update(float fElapsedTime) override;
	void Create() override;
};

#endif