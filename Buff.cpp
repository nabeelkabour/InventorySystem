#include "Game.h"
#include "Buff.h"

Buff::Buff(Player* player, float lifeTime, BuffEffect buffApply, BuffEffect buffRemove)
	: player(player), lifeTime(lifeTime), buffApply(buffApply), buffRemove(buffRemove)
{
	buffApply(player, game.GetOpponent(player));
}

void Buff::Update(float fElapsedTime)
{
	life += fElapsedTime;

	if (life >= lifeTime)
	{
		buffRemove(player, game.GetOpponent(player));

		remove_flag = true;
	}
}

void Buff::Create()
{}