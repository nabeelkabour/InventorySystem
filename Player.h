#ifndef PLAYER_H
#define PLAYER_H

#include "olcPGEX_Gamepad.h"
#include "Inventory.h"
#include "ManifestedEntity.h"
#include "Actor.h"

enum class PlayerID
{
	ONE,
	TWO
};

class Player : public Actor
{
public:
	PlayerID playerId;
	Inventory playerInventory;
	int32_t hp = 300;
	int32_t hpMax = hp;
	float speed = 125.f;
	olc::Pixel colorBase, colorTurret;

	olc::GamePad* gamepad;

	Player(PlayerID id, olc::vf2d pos, int32_t hp, int32_t hpMax, olc::Decal* spr, olc::GamePad* _gamepad, std::string name = "");
	void Update(float fElapsedTime) override;
	void Draw(float fElapsedTime) override;
	void Collide(Player* player) override;
};

#endif
