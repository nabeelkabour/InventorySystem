#ifndef WINEFFECT_H
#define WINEFFECT_H

#include "ManifestedEntity.h"
#include "Player.h"

enum class WinEffectStage
{
	SLOWDOWN,
	FREEZE
};

class WinEffect : public ManifestedEntity
{
public:
	const float stageOneTime = 3.f;

	WinEffectStage stage = WinEffectStage::SLOWDOWN;
	float time = 0.f;

	WinEffect(Player* winner);
	void Update(float fElapsedTime) override;
	void Draw(float fElapsedTime) override;
};

#endif