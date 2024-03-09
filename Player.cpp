#include "Game.h"
#include "Player.h"
#include "Actor.h"
#include "Collision.h"
#include "HitSplat.h"
#include "Items.h"

Player::Player(PlayerID id, olc::vf2d pos, int32_t hp, int32_t hpMax, olc::Decal* spr, olc::GamePad* _gamepad, std::string name) : 
	Actor(pos, hp, hpMax, spr, name),
	gamepad(_gamepad),
	playerId(id)
{
	switch (id)
	{
	case PlayerID::ONE:
		colorBase = olc::CYAN;
		colorTurret = olc::BLUE;
		break;

	case PlayerID::TWO:
		colorBase = olc::RED;
		colorTurret = olc::YELLOW;
		break;
	}

	scale = { 0.1f, 0.1f };

	uint8_t numGrenades = 3;
	for (uint8_t i = 0; i < 3; ++i)
	{
		if (playerInventory.GainItem(ItemIndex::itemIndex[ItemId::GRENADE]))
		{
			--numGrenades;
		}
		else
		{
			std::cout << "Not enough inventory." << std::endl;
			std::cout << (uint32_t)numGrenades;
			break;
		}
	}
}

void Player::Update(float fElapsedTime)
{
	//Player Input
	if (gamepad->getButton(olc::GPButtons::DPAD_L).bPressed)
	{
		playerInventory.MoveSelectLeft();
	}

	if (gamepad->getButton(olc::GPButtons::DPAD_R).bPressed)
	{
		playerInventory.MoveSelectRight();
	}

	if (gamepad->getButton(olc::GPButtons::FACE_D).bPressed)
	{
		//Select Item
		playerInventory.selectItem();
	}

	if (gamepad->getButton(olc::GPButtons::L1).bHeld)
	{
		//playerInventory.inventory[playerInventory.selected].use(this);
		//playerInventory.inventory[playerInventory.selected].amount--;
	}

	ManifestedEntity::Update(fElapsedTime);

	float gamepadX = gamepad->getAxis(olc::GPAxes::LX);
	float gamepadY = gamepad->getAxis(olc::GPAxes::LY);
	olc::vf2d velocity = { gamepadX, gamepadY };
	float velocityMag = velocity.mag();

	olc::vf2d vel = velocity;
	if (velocityMag > 1.f) vel = velocity.norm();
	position += vel * fElapsedTime * speed;


	for (Actor* other : game.actors)
	{
		if (other == this or !other->collidable) continue;

		if (CollidesWith(other))
		{
			other->Collide(this);
		}
	}
}

void Player::Draw(float fElaspedTime) 
{
	float gamepadTurretX = gamepad->getAxis(olc::GPAxes::RX);
	float gamepadTurretY = gamepad->getAxis(olc::GPAxes::RY);

	float turretAngle = 0.f;

	if (playerId == PlayerID::TWO and gamepadTurretX == 0.f and gamepadTurretY == 0.f)
	{
		turretAngle = 3.14159f;
	}
	else
	{
		olc::vf2d turretVector = { gamepadTurretX, gamepadTurretY };
		if (turretVector.mag() > 1.f) turretVector = turretVector.norm();
		turretAngle = atan2(turretVector.y, turretVector.x);
	}

	game.DrawRotatedDecal(position, Resources::get().base.Decal(), 0.f, { 256.f / 2.f, 256.f / 2.f }, scale, colorBase);
	game.DrawRotatedDecal(position, Resources::get().turret.Decal(), turretAngle, { 0.f, 32.f }, scale, colorTurret);

	float posX = 0.f;

	switch (playerId)
	{
	case PlayerID::ONE:
		posX = 25.f;
		break;

	case PlayerID::TWO:
		posX = float(game.ScreenWidth()) * 0.65f;
		break;
	}

	playerInventory.Draw(posX, 0.f);

	//Draw hp bar
#define HP_BAR_HEIGHT 15.f
#define HP_BAR_WIDTH 300.f
	switch (playerId)
	{
	case PlayerID::ONE:
		game.FillRectDecal(
			{ 0.f, game.ScreenHeight() - HP_BAR_HEIGHT },
			{ float(hp), game.ScreenHeight() - HP_BAR_HEIGHT },
			colorBase
		);
		break;

	case PlayerID::TWO:
		game.FillRectDecal(
			{ float(game.ScreenWidth()) - float(hp), game.ScreenHeight() - HP_BAR_HEIGHT },
			{ float(game.ScreenWidth()), game.ScreenHeight() - HP_BAR_HEIGHT },
			colorBase
		);
		break;
	}
}

void Player::Collide(Player* player)
{
	static float timer = 2.f;
	static bool canHit = true;
	timer += game.GetElapsedTime();

	if (timer >= 2.f)
	{
		hp--;
		player->hp--;

		game.entitiesManifested.push_back(new HitSplat(position, 1));
		game.entitiesManifested.push_back(new HitSplat(player->position, 1));

		timer = 0.f;
	}
}